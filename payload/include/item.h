#ifndef ITEM_H
#define ITEM_H

#include "gba/types.h"
#include "m_name_table.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum ItemType {
    ITEM_TYPE_FOSSIL = 0x00,
    ITEM_TYPE_FURNITURE = 0x01,
    ITEM_TYPE_GYROID = 0x02,
    ITEM_TYPE_APPLE = 0x03,
    ITEM_TYPE_ORANGE = 0x04,
    ITEM_TYPE_PEACH = 0x05,
    ITEM_TYPE_PEAR = 0x06,
    ITEM_TYPE_CHERRY = 0x07,
    ITEM_TYPE_TURNIP = 0x08,
    ITEM_TYPE_MUSHROOM = 0x09,
    ITEM_TYPE_CANDY = 0x0A,
    ITEM_TYPE_100_BELLS = 0x0B,
    ITEM_TYPE_SEEDLING_DIARY_TICKET_GRAB_BAG = 0x0C,
    ITEM_TYPE_SIGNBOARD = 0x0D,
    ITEM_TYPE_SHIRT = 0x0E,
    ITEM_TYPE_TRASH = 0x0F,
    ITEM_TYPE_PITFALL = 0x10,
    ITEM_TYPE_CONCH_SEA_SHELL_ICON = 0x11,
    ITEM_TYPE_LIONS_PAW_SHELL_ICON = 0x12,
    ITEM_TYPE_CORAL = 0x13,
    ITEM_TYPE_PURPLE_COSMOS = 0x14,
    ITEM_TYPE_BLUE_COSMOS = 0x15,
    ITEM_TYPE_YELLOW_COSMOS = 0x16,
    ITEM_TYPE_RED_TULIPS = 0x17,
    ITEM_TYPE_WHITE_TULIPS = 0x18,
    ITEM_TYPE_YELLOW_TULIPS = 0x19,
    ITEM_TYPE_WHITE_PANSIES = 0x1A,
    ITEM_TYPE_PURPLE_PANSIES = 0x1B,
    ITEM_TYPE_YELLOW_PANSIES = 0x1C,
    ITEM_TYPE_FLOWER_LEAVES = 0x1D,
    ITEM_TYPE_COCONUT = 0x1E,
    ITEM_TYPE_CABANA = 0x1F,
    ITEM_TYPE_ISLANDER_HOUSE = 0x20,
    ITEM_TYPE_SAPLING = 0x21,
    ITEM_TYPE_SMALL_TREE = 0x22,
    ITEM_TYPE_MEDIUM_TREE = 0x23,
    ITEM_TYPE_LARGE_TREE = 0x24,
    ITEM_TYPE_FULLY_GROWN_TREE = 0x25,
    ITEM_TYPE_DEAD_SAPLING = 0x26,
    ITEM_TYPE_FRUIT_APPLE_TREE = 0x27,
    ITEM_TYPE_FRUIT_ORANGE_TREE = 0x28,
    ITEM_TYPE_FRUIT_PEACH_TREE = 0x29,
    ITEM_TYPE_FRUIT_PEAR_TREE = 0x2A,
    ITEM_TYPE_FRUIT_CHERRY_TREE = 0x2B,
    ITEM_TYPE_SMALL_STUMP = 0x2C,
    ITEM_TYPE_MEDIUM_STUMP = 0x2D,
    ITEM_TYPE_LARGE_STUMP = 0x2E,
    ITEM_TYPE_FULLY_GROWN_STUMP = 0x2F,
    ITEM_TYPE_PALM_SAPLING = 0x30,
    ITEM_TYPE_SMALL_PALM_TREE = 0x31,
    ITEM_TYPE_MEDIUM_PALM_TREE = 0x32,
    ITEM_TYPE_LARGE_PALM_TREE = 0x33,
    ITEM_TYPE_PALM_TREE = 0x34,
    ITEM_TYPE_DEAD_PALM_SAPLING = 0x35,
    ITEM_TYPE_FRUIT_PALM_TREE = 0x36,
    ITEM_TYPE_SMALL_PALM_STUMP = 0x37,
    ITEM_TYPE_MEDIUM_PALM_STUMP = 0x38,
    ITEM_TYPE_LARGE_PALM_STUMP = 0x39,
    ITEM_TYPE_FULLY_GROWN_PALM_STUMP = 0x3A,
    ITEM_TYPE_ISLAND_FLAG = 0x3B,
    ITEM_TYPE_HOLE = 0x3C,
    ITEM_TYPE_BURIED_PITFALL = 0x3D,
    ITEM_TYPE_CEDAR_SAPLING = 0x3E,
    ITEM_TYPE_DEAD_CEDAR_SAPLING = 0x3F,
    ITEM_TYPE_WEED = 0x40,
    ITEM_TYPE_ROCK = 0x41,
    ITEM_TYPE_1K_BELLS = 0x42,
    ITEM_TYPE_10K_BELLS = 0x43,
    ITEM_TYPE_30K_BELLS = 0x44,
    ITEM_TYPE_NET = 0x45,
    ITEM_TYPE_GOLDEN_NET = 0x46,
    ITEM_TYPE_AXE = 0x47,
    ITEM_TYPE_GOLDEN_AXE = 0x48,
    ITEM_TYPE_SHOVEL = 0x49,
    ITEM_TYPE_GOLDEN_SHOVEL = 0x4A,
    ITEM_TYPE_FISHING_ROD = 0x4B,
    ITEM_TYPE_GOLDEN_ROD = 0x4C,
    ITEM_TYPE_UMBRELLA = 0x4D,
    ITEM_TYPE_PAINT = 0x4E,
    ITEM_TYPE_BALLOON = 0x4F,
    ITEM_TYPE_PINWHEEL = 0x50,
    ITEM_TYPE_HAND_FAN = 0x51,
    ITEM_TYPE_CARPET = 0x52,
    ITEM_TYPE_WALLPAPER = 0x53,
    ITEM_TYPE_AIR_CHECK = 0x54,
    ITEM_TYPE_NES = 0x55,
    ITEM_TYPE_FLOWER_BAG = 0x56,
    ITEM_TYPE_RESERVED = 0x57,
    ITEM_TYPE_COUNT = 0x58
} ItemType;

#define IS_ITEM_TYPE_TOOL(type) ( \
    ((type) == ITEM_TYPE_NET) || \
    ((type) == ITEM_TYPE_GOLDEN_NET) || \
    ((type) == ITEM_TYPE_AXE) || \
    ((type) == ITEM_TYPE_GOLDEN_AXE) || \
    ((type) == ITEM_TYPE_SHOVEL) || \
    ((type) == ITEM_TYPE_GOLDEN_SHOVEL) || \
    ((type) == ITEM_TYPE_FISHING_ROD) || \
    ((type) == ITEM_TYPE_GOLDEN_ROD) || \
    ((type) == ITEM_TYPE_UMBRELLA) || \
    ((type) == ITEM_TYPE_PAINT) || \
    ((type) == ITEM_TYPE_BALLOON) || \
    ((type) == ITEM_TYPE_PINWHEEL) || \
    ((type) == ITEM_TYPE_HAND_FAN))

#define IS_ITEM_TYPE_FRUIT(type) ( \
    ((type) == ITEM_TYPE_APPLE) || \
    ((type) == ITEM_TYPE_ORANGE) || \
    ((type) == ITEM_TYPE_PEACH) || \
    ((type) == ITEM_TYPE_PEAR) || \
    ((type) == ITEM_TYPE_CHERRY) || \
    ((type) == ITEM_TYPE_COCONUT))

/* Per-item-type field rendering and interaction data. */
/* sizeof(ItemGroupStruct) == 0xC */
typedef struct ItemGroupStruct {
    /* 0x00 */ u16 field_tile_id;
    /* 0x02 */ u16 field_entity_type;
    /* 0x04 */ u16 held_item_oam_attr2;
    /* 0x06 */ u16 default_generator_idx;
    /* 0x08 */ u16 interaction_type;
    /* 0x0A */ u16 unk_0A;
} ItemGroupStruct;

/* Indices into gItemGeneratorDefs. */
typedef enum ItemGeneratorType {
    ITEM_GENERATOR_APPLE = 0x00,
    ITEM_GENERATOR_ORANGE,
    ITEM_GENERATOR_PEACH,
    ITEM_GENERATOR_PEAR,
    ITEM_GENERATOR_CHERRY,
    ITEM_GENERATOR_COCONUT,
    ITEM_GENERATOR_MUSHROOM,
    ITEM_GENERATOR_CANDY,
    ITEM_GENERATOR_100_BELLS,
    ITEM_GENERATOR_1K_BELLS,
    ITEM_GENERATOR_10K_BELLS,
    ITEM_GENERATOR_30K_BELLS,
    ITEM_GENERATOR_PITFALL,
    ITEM_GENERATOR_PURPLE_COSMOS,
    ITEM_GENERATOR_BLUE_COSMOS,
    ITEM_GENERATOR_YELLOW_COSMOS,
    ITEM_GENERATOR_RED_TULIPS,
    ITEM_GENERATOR_WHITE_TULIPS,
    ITEM_GENERATOR_YELLOW_TULIPS,
    ITEM_GENERATOR_WHITE_PANSIES,
    ITEM_GENERATOR_PURPLE_PANSIES,
    ITEM_GENERATOR_YELLOW_PANSIES,
    ITEM_GENERATOR_FURNITURE_COMMON,
    ITEM_GENERATOR_FURNITURE_RARE,
    ITEM_GENERATOR_FURNITURE_EVENT,
    ITEM_GENERATOR_FURNITURE_ISLAND,
    ITEM_GENERATOR_CARPET_COMMON,
    ITEM_GENERATOR_CARPET_RARE,
    ITEM_GENERATOR_WALLPAPER_COMMON,
    ITEM_GENERATOR_WALLPAPER_RARE,
    ITEM_GENERATOR_SHIRT_COMMON,
    ITEM_GENERATOR_SHIRT_RARE,
    ITEM_GENERATOR_FOSSIL,
    ITEM_GENERATOR_GYROID,
    ITEM_GENERATOR_UMBRELLA,
    ITEM_GENERATOR_AIR_CHECK,
    ITEM_GENERATOR_NES,
    ITEM_GENERATOR_TRASH,

    ITEM_GENERATOR_COUNT
} ItemGeneratorType;

typedef struct ItemGeneratorDef {
    mActor_name_t item;
    u8 item_type; /* ItemType */
    u8 use_island_id;
} ItemGeneratorDef;

s32 Item_IsFossil(mActor_name_t arg0);
s32 Item_IsGyroid(mActor_name_t arg0);
s32 Item_IsNES(mActor_name_t arg0);
s32 Item_IsFurniture(mActor_name_t arg0);
s32 Item_IsApple(mActor_name_t arg0);
s32 Item_IsOrange(mActor_name_t arg0);
s32 Item_IsPeach(mActor_name_t arg0);
s32 Item_IsPear(mActor_name_t arg0);
s32 Item_IsCherry(mActor_name_t arg0);
s32 Item_IsTurnip(mActor_name_t arg0);
s32 Item_IsMushroom(mActor_name_t arg0);
s32 Item_IsCandy(mActor_name_t arg0);
s32 Item_Is100Bells(mActor_name_t arg0);
s32 Item_Is1KBells(mActor_name_t arg0);
s32 Item_Is10KBells(mActor_name_t arg0);
s32 Item_Is30KBells(mActor_name_t arg0);
s32 Item_IsFlowerBag(mActor_name_t arg0);
s32 Item_IsSeedlingDiaryTicketGrabBag(mActor_name_t arg0);
s32 Item_IsNet(mActor_name_t arg0);
s32 Item_IsGoldenNet(mActor_name_t arg0);
s32 Item_IsAxe(mActor_name_t arg0);
s32 Item_IsGoldenAxe(mActor_name_t arg0);
s32 Item_IsShovel(mActor_name_t arg0);
s32 Item_IsGoldenShovel(mActor_name_t arg0);
s32 Item_IsFishingRod(mActor_name_t arg0);
s32 Item_IsGoldenRod(mActor_name_t arg0);
s32 Item_IsUmbrella(mActor_name_t arg0);
s32 Item_IsPaint(mActor_name_t arg0);
s32 Item_IsBalloon(mActor_name_t arg0);
s32 Item_IsPinwheel(mActor_name_t arg0);
s32 Item_IsHandFan(mActor_name_t arg0);
s32 Item_IsSignboard(mActor_name_t arg0);
s32 Item_IsShirt(mActor_name_t arg0);
s32 Item_IsCarpet(mActor_name_t arg0);
s32 Item_IsWallpaper(mActor_name_t arg0);
s32 Item_IsAirCheck(mActor_name_t arg0);
s32 Item_IsTrash(mActor_name_t arg0);
s32 Item_IsPitfall(mActor_name_t arg0);
s32 Item_IsConchSeaShellIcon(mActor_name_t arg0);
s32 Item_IsLionsPawShellIcon(mActor_name_t arg0);
s32 Item_IsCoral(mActor_name_t arg0);
s32 Item_IsFlowerLeaves(mActor_name_t arg0);
s32 Item_IsPurpleCosmos(mActor_name_t arg0);
s32 Item_IsBlueCosmos(mActor_name_t arg0);
s32 Item_IsYellowCosmos(mActor_name_t arg0);
s32 Item_IsRedTulips(mActor_name_t arg0);
s32 Item_IsWhiteTulips(mActor_name_t arg0);
s32 Item_IsYellowTulips(mActor_name_t arg0);
s32 Item_IsWhitePansies(mActor_name_t arg0);
s32 Item_IsPurplePansies(mActor_name_t arg0);
s32 Item_IsYellowPansies(mActor_name_t arg0);
s32 Item_IsCoconut(mActor_name_t arg0);
s32 Item_IsCabana(mActor_name_t arg0);
s32 Item_IsIslanderHouse(mActor_name_t arg0);
s32 Item_IsSapling(mActor_name_t arg0);
s32 Item_IsSmallTree(mActor_name_t arg0);
s32 Item_IsMediumTree(mActor_name_t arg0);
s32 Item_IsLargeTree(mActor_name_t arg0);
s32 Item_IsFullyGrownTree(mActor_name_t arg0);
s32 Item_IsDeadSapling(mActor_name_t arg0);
s32 Item_IsFruitAppleTree(mActor_name_t arg0);
s32 Item_IsFruitOrangeTree(mActor_name_t arg0);
s32 Item_IsFruitPeachTree(mActor_name_t arg0);
s32 Item_IsPearFruitTree(mActor_name_t arg0);
s32 Item_IsFruitCherryTree(mActor_name_t arg0);
s32 Item_IsSmallStump(mActor_name_t arg0);
s32 Item_IsMediumStump(mActor_name_t arg0);
s32 Item_IsLargeStump(mActor_name_t arg0);
s32 Item_IsFullyGrownStump(mActor_name_t arg0);
s32 Item_IsPalmSapling(mActor_name_t arg0);
s32 Item_IsSmallPalmTree(mActor_name_t arg0);
s32 Item_IsMediumPalmTree(mActor_name_t arg0);
s32 Item_IsLargePalmTree(mActor_name_t arg0);
s32 Item_IsPalmTree(mActor_name_t arg0);
s32 Item_IsDeadPalmSapling(mActor_name_t arg0);
s32 Item_IsFruitPalmTree(mActor_name_t arg0);
s32 Item_IsSmallPalmStump(mActor_name_t arg0);
s32 Item_IsMediumPalmStump(mActor_name_t arg0);
s32 Item_IsLargePalmStump(mActor_name_t arg0);
s32 Item_IsFullyGrownPalmStump(mActor_name_t arg0);
s32 Item_IsIslandFlag(mActor_name_t arg0);
s32 Item_IsHole(mActor_name_t arg0);
s32 Item_IsBuriedPitfall(mActor_name_t arg0);
s32 Item_IsCedarSapling(mActor_name_t arg0);
s32 Item_IsDeadCedarSapling(mActor_name_t arg0);
s32 Item_IsWeed(mActor_name_t arg0);
s32 Item_IsRock(mActor_name_t arg0);
s32 Item_IsReserved(mActor_name_t arg0);
s32 Item_GetTypeIndex(mActor_name_t arg0);
mActor_name_t Item_GetItemFromTypeIndex(u32 idx);
mActor_name_t Item_TypeToIslandItem(u32 idx);

extern ItemGeneratorDef gItemGeneratorDefs[ITEM_GENERATOR_COUNT];

#ifdef __cplusplus
}
#endif

#endif // ITEM_H
