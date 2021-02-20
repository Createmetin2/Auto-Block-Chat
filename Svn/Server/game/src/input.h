//Find
		int			Chat(LPCHARACTER ch, const char * data, size_t uiBytes);

///Add
#ifdef AUTO_BLOCK_CHAT
		void 		BlockChatInsult(LPCHARACTER ch, const char * data);
#endif