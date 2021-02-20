//Find
void CInputMain::ItemUse(LPCHARACTER ch, const char * data)
{
	if (ch)
		ch->UseItem(((struct command_item_use *) data)->Cell);
}

///Add
#ifdef AUTO_BLOCK_CHAT
void CInputMain::BlockChatInsult(LPCHARACTER ch, const char* data)
{
	if (!ch)
		return;

	if (ch->FindAffect(AFFECT_BLOCK_CHAT))
		return;
	
	if (ch->IsGM())
		return;

	const long lBlockDuration = 60;

	ch->AddAffect(AFFECT_BLOCK_CHAT, POINT_NONE, 0, AFF_NONE, lBlockDuration, 0, true);

	sys_log(0, "AUTO BLOCK CHAT %s %d", ch->GetName(), lBlockDuration);
}
#endif

//Find
		case HEADER_CG_ITEM_USE:
			if (!ch->IsObserverMode())
				ItemUse(ch, c_pData);
			break;
			
///Add
#ifdef AUTO_BLOCK_CHAT
		case HEADER_CG_INSULT_BLOCK:
            if (!ch->IsObserverMode())
                BlockChatInsult(ch, c_pData);
        break;
#endif