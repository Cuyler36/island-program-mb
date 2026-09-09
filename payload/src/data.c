#include "global.h"
#include "islander.h"
#include "anim.h"
#include "game.h"
#include "joyboot.h"
#include "island_field.h"
#include "m_msg.h"
#include "building.h"
#include "entity.h"
#include "player_hand.h"
#include "player_hand.h"
#include "falling_fruit.h"

// Common data section definitions

/* Original address: 0x03001B40 */
Island_agb_c* gIslandData; // common

/* Original address: 0x03001B50 */
GameState gGameState ATTRIBUTE_ALIGN(8); // common

/* Original address: 0x030023C0 */
INTERRUPT_HANDLER_PROC gIntrTable[16];

/* Original address: 0x03002400 */
mISL_landinfo_agb_c gIslandLandInfo;

/* Original address: 0x03002410 */
OAMData GameOAMData[128];

/* Original address: 0x03002810 */
u32 gFontGlyphBlitterCode[0x58];

/* Original address: 0x03002970 */
Island_agb_c* gIslandTransferData;

/* Original address: 0x03002980 */
mMsg_Window_c gMsgWindowNotice ATTRIBUTE_ALIGN(32);
/* Original address: 0x03002A20 */
mMsg_Window_c sMsgWindows[9];
/* Original address: 0x03002FC0 */
mMsg_Window_c gMsgWindowMain;
/* Original address: 0x03003060 */
mMsg_Window_c gMsgWindowPrompt;
/* Original address: 0x03003100 */
mFont_GlyphDraw_c gMsgGlyph;

/* Original address: 0x03003120 */
JoybusTransferWork gTransWork;
/* Original address: 0x03003160 */
u8 sBssPadding_03003160[0x5B0];
/* Original address: 0x03003710 */
IslandFieldWork gIslandFieldWork;
/* Original address: 0x03003BB0 */
IslandBuilding gIslandBuildings[ISLAND_BUILDING_COUNT];
/* Original address: 0x03003BD8 */
u8 sBssPadding_03003BD8[0x28];
/* Original address: 0x03003C00 */
FieldObject gFieldObjects[FIELD_OBJECT_COUNT];
/* Original address: 0x030041A0 */
Islander_AGB gIslander;
/* Original address: 0x03004260 */
FallingFruit gFallingFruit[30];
/* Original address: 0x03004788 */
u8 sBssPadding_03004788[8];
/* Original address: 0x03004790 */
Entity g_EntityTable[12];
/* Original address: 0x03004B80 */
Player gPlayer;
