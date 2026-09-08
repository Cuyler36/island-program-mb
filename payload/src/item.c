#include "item.h"
#include "global.h"

s32 Item_IsFossil(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((item == ITM_FOSSIL) || ((mActor_name_t)(item - FTR_DINO_START) <= (FTR_DINO_END - FTR_DINO_START)) ||
        (item == RSV_ISLAND_FOSSIL)) {
        result = 1;
    }
    return result;
}

/* Ghidra name: ItemIsGryoidOrUnk (differs; corrected typo and reserve-alias wording). */
s32 Item_IsGyroid(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)((item) - HANIWA_START)) <= ((HANIWA_END - HANIWA_START)) || item == RSV_ISLAND_HANIWA) {
        result = 1;
    }
    return result;
}

s32 Item_IsNES(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - FTR_FAMICOM_START) <= (FTR_FAMICOM_END - FTR_FAMICOM_START)) ||
        (item == RSV_ISLAND_FAMICOM)) {
        result = 1;
    }
    return result;
}

s32 Item_IsFurniture(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((item != ITM_FOSSIL) && ((mActor_name_t)(item - FTR_DINO_START) > (FTR_DINO_END - FTR_DINO_START)) && (item != RSV_ISLAND_FOSSIL) &&
        ((mActor_name_t)((item - HANIWA_START)) > ((HANIWA_END - HANIWA_START))) && (item != RSV_ISLAND_HANIWA) &&
        ((mActor_name_t)(item - FTR_FAMICOM_START) > (FTR_FAMICOM_END - FTR_FAMICOM_START)) && (item != RSV_ISLAND_FAMICOM) &&
        (ITEM_IS_FTR(item) || (item == RSV_ISLAND_FTR_COMMON) || (item == RSV_ISLAND_FTR_RARE) || (item == RSV_ISLAND_FTR_EVENT) || (item == RSV_ISLAND_FTR_ISLAND))) {
        result = 1;
    }
    return result;
}

s32 Item_IsApple(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_APPLE) {
        result = 1;
    }
    return result;
}

s32 Item_IsOrange(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_ORANGE) {
        result = 1;
    }
    return result;
}

s32 Item_IsPeach(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_PEACH) {
        result = 1;
    }
    return result;
}

s32 Item_IsPear(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_PEAR) {
        result = 1;
    }
    return result;
}

s32 Item_IsCherry(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_CHERRY) {
        result = 1;
    }
    return result;
}

s32 Item_IsTurnip(mActor_name_t item) {
    s32 result;
    u32 shifted_item;

    shifted_item = item << 16;
    result = 0;
    if (((shifted_item & 0xF0000000) == (NAME_TYPE_ITEM1 << 28)) &&
        (((shifted_item >> 24) & 0xF) == ITEM1_CAT_KABU)) {
        result = 1;
    }
    return result;
}

s32 Item_IsMushroom(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_MUSHROOM) {
        result = 1;
    }
    return result;
}

s32 Item_IsCandy(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_CANDY) {
        result = 1;
    }
    return result;
}

s32 Item_Is100Bells(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_MONEY_100) {
        result = 1;
    }
    return result;
}

s32 Item_Is1KBells(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_MONEY_1000) {
        result = 1;
    }
    return result;
}

s32 Item_Is10KBells(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_MONEY_10000) {
        result = 1;
    }
    return result;
}

s32 Item_Is30KBells(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_MONEY_30000) {
        result = 1;
    }
    return result;
}

s32 Item_IsFlowerBag(mActor_name_t item) {
    if (((mActor_name_t)(item - ITM_WHITE_PANSY_BAG) <= (ITM_YELLOW_TULIP_BAG - ITM_WHITE_PANSY_BAG)) ||
        (item == RSV_ISLAND_FLOWER_BAG)) {
        return 1;
    }
    return 0;
}

s32 Item_IsSeedlingDiaryTicketGrabBag(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((Item_IsFlowerBag(item) == 0) && ITEM_NAME_CHK_TYPE(item, NAME_TYPE_ITEM1)) {
        if ((ITEM_NAME_GET_CAT(item) == ITEM1_CAT_PAPER) ||
            (ITEM_NAME_GET_CAT(item) == ITEM1_CAT_PLANT) ||
            (ITEM_NAME_GET_CAT(item) == ITEM1_CAT_TICKET) ||
            (ITEM_NAME_GET_CAT(item) == ITEM1_CAT_DUMMY) ||
            (ITEM_NAME_GET_CAT(item) == ITEM1_CAT_HUKUBUKURO)) {
            result = 1;
        }
    }
    return result;
}

s32 Item_IsNet(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_NET) {
        result = 1;
    }
    return result;
}

s32 Item_IsGoldenNet(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_GOLDEN_NET) {
        result = 1;
    }
    return result;
}

s32 Item_IsAxe(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == ITM_AXE) || (item_no == ITM_AXE_USE_7) || (item_no == ITM_AXE_USE_6) ||
        (item_no == ITM_AXE_USE_5) || (item_no == ITM_AXE_USE_4) || (item_no == ITM_AXE_USE_3) ||
        (item_no == ITM_AXE_USE_2) || (item_no == ITM_AXE_USE_1)) {
        result = 1;
    }
    return result;
}

s32 Item_IsGoldenAxe(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_GOLDEN_AXE) {
        result = 1;
    }
    return result;
}

s32 Item_IsShovel(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_SHOVEL) {
        result = 1;
    }
    return result;
}

s32 Item_IsGoldenShovel(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_GOLDEN_SHOVEL) {
        result = 1;
    }
    return result;
}

s32 Item_IsFishingRod(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_ROD) {
        result = 1;
    }
    return result;
}

s32 Item_IsGoldenRod(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_GOLDEN_ROD) {
        result = 1;
    }
    return result;
}

s32 Item_IsUmbrella(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - ITM_UMBRELLA_START) <= (ITM_UMBRELLA31 - ITM_UMBRELLA_START)) ||
        (item == RSV_ISLAND_UMBRELLA)) {
        result = 1;
    }
    return result;
}

s32 Item_IsPaint(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - ITM_RED_PAINT) <= (ITM_BROWN_PAINT - ITM_RED_PAINT)) {
        result = 1;
    }
    return result;
}

s32 Item_IsBalloon(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - ITM_BALLOON_START) <= (ITM_BUNNY_O_BALLOON - ITM_BALLOON_START)) {
        result = 1;
    }
    return result;
}

s32 Item_IsPinwheel(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - ITM_YELLOW_PINWHEEL) <= (ITM_FANCY_PINWHEEL - ITM_YELLOW_PINWHEEL)) {
        result = 1;
    }
    return result;
}

s32 Item_IsHandFan(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - ITM_BLUEBELL_FAN) <= (ITM_LEAF_FAN - ITM_BLUEBELL_FAN)) {
        result = 1;
    }
    return result;
}

s32 Item_IsSignboard(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_SIGNBOARD) {
        result = 1;
    }
    return result;
}

s32 Item_IsShirt(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;
    u32 shifted_item;

    shifted_item = item << 16;
    item_no = shifted_item >> 16;
    result = 0;
    if ((((item_no & 0xF000) == (NAME_TYPE_ITEM1 << 12)) &&
         (((shifted_item >> 24) & 0xF) == ITEM1_CAT_CLOTH)) ||
        (item_no == RSV_ISLAND_CLOTH_COMMON) || (item_no == RSV_ISLAND_CLOTH_RARE)) {
        result = 1;
    }
    return result;
}

s32 Item_IsCarpet(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;
    u32 shifted_item;

    shifted_item = item << 16;
    item_no = shifted_item >> 16;
    result = 0;
    if ((((item_no & 0xF000) == (NAME_TYPE_ITEM1 << 12)) &&
         (((shifted_item >> 24) & 0xF) == ITEM1_CAT_CARPET)) ||
        (item_no == RSV_ISLAND_CARPET_COMMON) || (item_no == RSV_ISLAND_CARPET_RARE)) {
        result = 1;
    }
    return result;
}

s32 Item_IsWallpaper(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;
    u32 shifted_item;

    shifted_item = item << 16;
    item_no = shifted_item >> 16;
    result = 0;
    if ((((item_no & 0xF000) == (NAME_TYPE_ITEM1 << 12)) &&
         (((shifted_item >> 24) & 0xF) == ITEM1_CAT_WALL)) ||
        (item_no == RSV_ISLAND_WALL_COMMON) || (item_no == RSV_ISLAND_WALL_RARE)) {
        result = 1;
    }
    return result;
}

s32 Item_IsAirCheck(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;
    u32 shifted_item;

    shifted_item = item << 16;
    item_no = shifted_item >> 16;
    result = 0;
    if ((((item_no & 0xF000) == (NAME_TYPE_ITEM1 << 12)) &&
         (((shifted_item >> 24) & 0xF) == ITEM1_CAT_MINIDISK)) ||
        (item_no == RSV_ISLAND_MINIDISK)) {
        result = 1;
    }
    return result;
}

s32 Item_IsTrash(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - ITM_DUST0_EMPTY_CAN) <= (ITM_DUST2_OLD_TIRE - ITM_DUST0_EMPTY_CAN)) ||
        (item == RSV_ISLAND_TRASH)) {
        result = 1;
    }
    return result;
}

s32 Item_IsPitfall(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_PITFALL) {
        result = 1;
    }
    return result;
}

s32 Item_IsConchSeaShellIcon(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - ITM_SHELL1) <= (ITM_SHELL3 - ITM_SHELL1)) || (item == ITM_SHELL6)) {
        result = 1;
    }
    return result;
}

s32 Item_IsLionsPawShellIcon(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == ITM_SHELL0) || (item_no == ITM_SHELL4) || (item_no == ITM_SHELL5)) {
        result = 1;
    }
    return result;
}

s32 Item_IsCoral(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_SHELL7) {
        result = 1;
    }
    return result;
}

s32 Item_IsFlowerLeaves(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - FLOWER_LEAVES_PANSIES0) <= (FLOWER_LEAVES_TULIP2 - FLOWER_LEAVES_PANSIES0)) {
        result = 1;
    }
    return result;
}

s32 Item_IsPurpleCosmos(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_COSMOS1) {
        result = 1;
    }
    return result;
}

s32 Item_IsBlueCosmos(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_COSMOS2) {
        result = 1;
    }
    return result;
}

s32 Item_IsYellowCosmos(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_COSMOS0) {
        result = 1;
    }
    return result;
}

s32 Item_IsRedTulips(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_TULIP0) {
        result = 1;
    }
    return result;
}

s32 Item_IsWhiteTulips(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_TULIP1) {
        result = 1;
    }
    return result;
}

s32 Item_IsYellowTulips(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_TULIP2) {
        result = 1;
    }
    return result;
}

s32 Item_IsWhitePansies(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_PANSIES0) {
        result = 1;
    }
    return result;
}

s32 Item_IsPurplePansies(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_PANSIES1) {
        result = 1;
    }
    return result;
}

s32 Item_IsYellowPansies(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_PANSIES2) {
        result = 1;
    }
    return result;
}

s32 Item_IsCoconut(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_COCONUT) {
        result = 1;
    }
    return result;
}

s32 Item_IsCabana(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == COTTAGE_MY) {
        result = 1;
    }
    return result;
}

s32 Item_IsIslanderHouse(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == COTTAGE_NPC) {
        result = 1;
    }
    return result;
}

s32 Item_IsSapling(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == TREE_SAPLING) || (item_no == TREE_APPLE_SAPLING) || (item_no == TREE_ORANGE_SAPLING) ||
        (item_no == TREE_PEACH_SAPLING) || (item_no == TREE_PEAR_SAPLING) || (item_no == TREE_CHERRY_SAPLING) ||
        (item_no == TREE_1000BELLS_SAPLING) || (item_no == TREE_10000BELLS_SAPLING) ||
        (item_no == TREE_30000BELLS_SAPLING) || (item_no == TREE_100BELLS_SAPLING)) {
        result = 1;
    }
    return result;
}

s32 Item_IsSmallTree(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == TREE_S0) || (item_no == TREE_APPLE_S0) || (item_no == TREE_ORANGE_S0) ||
        (item_no == TREE_PEACH_S0) || (item_no == TREE_PEAR_S0) || (item_no == TREE_CHERRY_S0) ||
        (item_no == TREE_1000BELLS_S0) || (item_no == TREE_10000BELLS_S0) ||
        (item_no == TREE_30000BELLS_S0) || (item_no == TREE_100BELLS_S0)) {
        result = 1;
    }
    return result;
}

s32 Item_IsMediumTree(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == TREE_S1) || (item_no == TREE_APPLE_S1) || (item_no == TREE_ORANGE_S1) ||
        (item_no == TREE_PEACH_S1) || (item_no == TREE_PEAR_S1) || (item_no == TREE_CHERRY_S1) ||
        (item_no == TREE_1000BELLS_S1) || (item_no == TREE_10000BELLS_S1) ||
        (item_no == TREE_30000BELLS_S1) || (item_no == TREE_100BELLS_S1)) {
        result = 1;
    }
    return result;
}

s32 Item_IsLargeTree(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == TREE_S2) || (item_no == TREE_APPLE_S2) || (item_no == TREE_ORANGE_S2) ||
        (item_no == TREE_PEACH_S2) || (item_no == TREE_PEAR_S2) || (item_no == TREE_CHERRY_S2) ||
        (item_no == TREE_1000BELLS_S2) || (item_no == TREE_10000BELLS_S2) ||
        (item_no == TREE_30000BELLS_S2) || (item_no == TREE_100BELLS_S2)) {
        result = 1;
    }
    return result;
}

s32 Item_IsFullyGrownTree(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    result = 0;
    item_no = item;
    if (((mActor_name_t)(item - TREE_BEES) <= (TREE_FTR - TREE_BEES)) || (item_no == TREE_BELLS) || (item_no == TREE) ||
        ((mActor_name_t)(item_no - TREE_APPLE_NOFRUIT_0) <= (TREE_APPLE_NOFRUIT_2 - TREE_APPLE_NOFRUIT_0)) ||
        ((mActor_name_t)(item_no - TREE_ORANGE_NOFRUIT_0) <= (TREE_ORANGE_NOFRUIT_2 - TREE_ORANGE_NOFRUIT_0)) ||
        ((mActor_name_t)(item_no - TREE_PEACH_NOFRUIT_0) <= (TREE_PEACH_NOFRUIT_2 - TREE_PEACH_NOFRUIT_0)) ||
        ((mActor_name_t)(item_no - TREE_PEAR_NOFRUIT_0) <= (TREE_PEAR_NOFRUIT_2 - TREE_PEAR_NOFRUIT_0)) ||
        ((mActor_name_t)(item_no - TREE_CHERRY_NOFRUIT_0) <= (TREE_CHERRY_NOFRUIT_2 - TREE_CHERRY_NOFRUIT_0)) ||
        (item_no == TREE_1000BELLS) || (item_no == TREE_10000BELLS) || (item_no == TREE_30000BELLS) ||
        (item_no == TREE_100BELLS)) {
        result = 1;
    }
    return result;
}

s32 Item_IsDeadSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == DEAD_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitAppleTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_APPLE_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitOrangeTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_ORANGE_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitPeachTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PEACH_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsPearFruitTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PEAR_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitCherryTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_CHERRY_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsSmallStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_STUMP001) {
        result = 1;
    }
    return result;
}

s32 Item_IsMediumStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_STUMP002) {
        result = 1;
    }
    return result;
}

s32 Item_IsLargeStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_STUMP003) {
        result = 1;
    }
    return result;
}

s32 Item_IsFullyGrownStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_STUMP004) {
        result = 1;
    }
    return result;
}

s32 Item_IsPalmSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsSmallPalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_S0) {
        result = 1;
    }
    return result;
}

s32 Item_IsMediumPalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_S1) {
        result = 1;
    }
    return result;
}

s32 Item_IsLargePalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_S2) {
        result = 1;
    }
    return result;
}

s32 Item_IsPalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - TREE_PALM_NOFRUIT_0) <= (TREE_PALM_NOFRUIT_2 - TREE_PALM_NOFRUIT_0)) {
        result = 1;
    }
    return result;
}

s32 Item_IsDeadPalmSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == DEAD_PALM_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitPalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsSmallPalmStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_STUMP001) {
        result = 1;
    }
    return result;
}

s32 Item_IsMediumPalmStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_STUMP002) {
        result = 1;
    }
    return result;
}

s32 Item_IsLargePalmStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_STUMP003) {
        result = 1;
    }
    return result;
}

s32 Item_IsFullyGrownPalmStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_STUMP004) {
        result = 1;
    }
    return result;
}

s32 Item_IsIslandFlag(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLAG) {
        result = 1;
    }
    return result;
}

s32 Item_IsHole(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - HOLE_START) <= (HOLE_END - HOLE_START)) || (item == RSV_ISLAND_HOLE)) {
        result = 1;
    }
    return result;
}

s32 Item_IsBuriedPitfall(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - BURIED_PITFALL_HOLE_START) <=
        (BURIED_PITFALL_HOLE_RSV_END - BURIED_PITFALL_HOLE_START)) {
        result = 1;
    }
    return result;
}

s32 Item_IsCedarSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == CEDAR_TREE_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsDeadCedarSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == DEAD_CEDAR_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsWeed(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - GRASS_A) <= (GRASS_C - GRASS_A)) {
        result = 1;
    }
    return result;
}

s32 Item_IsRock(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - ROCK_A) <= (ROCK_E - ROCK_A)) ||
        ((mActor_name_t)(item - MONEY_ROCK_A) <= (MONEY_ROCK_E - MONEY_ROCK_A))) {
        result = 1;
    }
    return result;
}

/* Ghidra name: ItemCheckFunc (differs; this specifically tests reserved item 0xFFFF). */
s32 Item_IsReserved(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == RSV_NO) {
        result = 1;
    }
    return result;
}


typedef int (*Item_CHK_PROC)(mActor_name_t);

typedef struct item_type_entry_s {
    Item_CHK_PROC chk_proc;
    mActor_name_t item;
} Item_TypeEntry_c;

extern ItemGroupStruct g_ItemDefinitions[ITEM_TYPE_COUNT];

extern Item_TypeEntry_c Item_TypeEntries[ITEM_TYPE_COUNT];

/* Ghidra name: Item_GetTileId (differs; this returns the matching predicate-table index). */
s32 Item_GetTypeIndex(mActor_name_t item) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(Item_TypeEntries); i++) {
        if (Item_TypeEntries[i].chk_proc(item) != 0) {
            return i;
        }
    }
    return -1;
}

mActor_name_t Item_GetItemFromTypeIndex(u32 idx) {
    if (idx < ARRAY_COUNT(Item_TypeEntries)) {
        return Item_TypeEntries[idx].item;
    }
    return EMPTY_NO;
}

extern mActor_name_t gc_rsv_island_item_table[18];

mActor_name_t Item_TypeToIslandItem(u32 idx) {
    if (idx < ARRAY_COUNT(gc_rsv_island_item_table)) {
        return gc_rsv_island_item_table[idx];
    }
    return EMPTY_NO;
}
