//Find
	HEADER_CG_QUEST_CONFIRM			= 31,

///Add
#ifdef AUTO_BLOCK_CHAT
	HEADER_CG_INSULT_BLOCK			= 35,
#endif

//Find
typedef struct command_player_create_success
{
	BYTE		header;
	BYTE		bAccountCharacterIndex;
	TSimplePlayer	player;
} TPacketGCPlayerCreateSuccess;

///Add
#ifdef AUTO_BLOCK_CHAT
typedef struct commond_block_insult
{
	BYTE	header;
} TPacketCGChatInsult;
#endif