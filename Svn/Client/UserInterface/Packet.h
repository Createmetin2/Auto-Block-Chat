//Find
	HEADER_CG_QUEST_CONFIRM                     = 31,
	
///Add
#ifdef AUTO_BLOCK_CHAT
	HEADER_CG_INSULT_BLOCK						= 35,
#endif

//Find
typedef struct command_item_pickup
{
	BYTE header;
	DWORD vid;
} TPacketCGItemPickUp;

///Add
#ifdef AUTO_BLOCK_CHAT
typedef struct commond_block_insult
{
	BYTE	header;
} TPacketCGChatInsult;
#endif