//Find
					if (m_isEnableChatInsultFilter)
					{
						if (false == pkInstChatter->IsNPC() && false == pkInstChatter->IsEnemy())
						{
							__FilterInsult(p, strlen(p));
						}
					}

///Change
					if (m_isEnableChatInsultFilter)
					{
						if (false == pkInstChatter->IsNPC() && false == pkInstChatter->IsEnemy())
						{
#ifdef AUTO_BLOCK_CHAT
							if (CPythonNetworkStream::Instance().IsInsultIn(p))
							{
								CPythonNetworkStream::Instance().SendInsultBanPacket();
								return true;
							}
#else
							__FilterInsult(p, strlen(p));
#endif
						}
					}
	
//Find
			if (p)
			{
				if (m_isEnableChatInsultFilter)
					__FilterInsult(p, strlen(p));
			}
///Change
			if (p)
			{
#ifdef AUTO_BLOCK_CHAT
				if (m_isEnableChatInsultFilter && CPythonNetworkStream::Instance().IsInsultIn(p))
				{
					CPythonNetworkStream::Instance().SendInsultBanPacket();
					return true;
				}
#else
				if (m_isEnableChatInsultFilter)
					__FilterInsult(p, strlen(p));
#endif
			}

//Find
bool CPythonNetworkStream::SendQuestConfirmPacket(BYTE byAnswer, DWORD dwPID)
{
	TPacketCGQuestConfirm kPacket;
	kPacket.header = HEADER_CG_QUEST_CONFIRM;
	kPacket.answer = byAnswer;
	kPacket.requestPID = dwPID;

	if (!Send(sizeof(kPacket), &kPacket))
	{
		Tracen("SendQuestConfirmPacket Error");
		return false;
	}

	Tracenf(" SendQuestConfirmPacket : %d, %d", byAnswer, dwPID);
	return SendSequence();
}

///Add
#ifdef AUTO_BLOCK_CHAT
bool CPythonNetworkStream::SendInsultBanPacket()
{
	if (!__CanActMainInstance())
		return true;
	
	TPacketCGChatInsult kPacket;
	kPacket.header = HEADER_CG_INSULT_BLOCK;

	if (!Send(sizeof(kPacket), &kPacket))
	{
		Tracen("SendInsultBanPacket Error");
		return false;
	}

	return SendSequence();
}
#endif