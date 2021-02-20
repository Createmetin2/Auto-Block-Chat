//Find
	Set(HEADER_CG_ITEM_USE, sizeof(TPacketCGItemUse), "ItemUse", true);

///Add
#ifdef AUTO_BLOCK_CHAT
	Set(HEADER_CG_INSULT_BLOCK, sizeof(TPacketCGChatInsult), "AutoBlockInsult", true);
#endif