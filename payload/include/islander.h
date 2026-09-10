#ifndef ISLANDER_H
#define ISLANDER_H

#include "global.h"
#include "m_name_table.h"
#include "field_obj.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum IslanderMoveAction {
    ISLANDER_MOVE_ACTION_START_HOUSE_TRANSITION = 0,
    ISLANDER_MOVE_ACTION_MOVE_INDOORS_OR_OUTDOORS,
    ISLANDER_MOVE_ACTION_START_WANDERING,
    ISLANDER_MOVE_ACTION_UPDATE_WANDERING,
    ISLANDER_MOVE_ACTION_MOVE_TO_TARGET,
    ISLANDER_MOVE_ACTION_START_FOOD_PROCESSING,
    ISLANDER_MOVE_ACTION_PROCESS_FOOD,
    ISLANDER_MOVE_ACTION_UPDATE_EMOTION,
    ISLANDER_MOVE_ACTION_UPDATE_EMOTION_ANIMATION,
    ISLANDER_MOVE_ACTION_START_CLICK_REACTION,
    ISLANDER_MOVE_ACTION_CHECK_CLICKED_ON_TIMER,
    ISLANDER_MOVE_ACTION_START_FIELD_OBJECT_INTERACTION,
    ISLANDER_MOVE_ACTION_UPDATE_FIELD_OBJECT_INTERACTION,
    ISLANDER_MOVE_ACTION_INIT_FISHING,
    ISLANDER_MOVE_ACTION_FISHING,
    ISLANDER_MOVE_ACTION_INIT_RECEIVE_ITEM,
    ISLANDER_MOVE_ACTION_RECEIVE_ITEM,
    ISLANDER_MOVE_ACTION_DIG,
    ISLANDER_MOVE_ACTION_BURY,
    ISLANDER_MOVE_ACTION_INIT_CARRY_TRANSITION,
    ISLANDER_MOVE_ACTION_CARRY_TRANSITION,

    ISLANDER_MOVE_ACTION_NUM
} IslanderMoveAction;

typedef enum IslanderFieldObjectInteractionState {
    ISLANDER_FIELD_OBJECT_INTERACTION_SHAKE = 0,
    ISLANDER_FIELD_OBJECT_INTERACTION_CHOP,
    ISLANDER_FIELD_OBJECT_INTERACTION_COOLDOWN,

    ISLANDER_FIELD_OBJECT_INTERACTION_STATE_NUM
} IslanderFieldObjectInteractionState;

typedef enum IslanderFishingState {
    ISLANDER_FISHING_CAST_LINE = 0,
    ISLANDER_FISHING_WAIT_FOR_BITE,
    ISLANDER_FISHING_NOTICE_BITE,
    ISLANDER_FISHING_WAIT_TO_REEL_IN,
    ISLANDER_FISHING_REEL_IN,
    ISLANDER_FISHING_FINISH_FAILED_CATCH,
    ISLANDER_FISHING_REACT_TO_CATCH,
    ISLANDER_FISHING_FINISH_SUCCESSFUL_CATCH,

    ISLANDER_FISHING_STATE_NUM
} IslanderFishingState;

typedef enum IslanderReceiveItemState {
    ISLANDER_RECEIVE_ITEM_CATCH = 0,
    ISLANDER_RECEIVE_ITEM_STORE,
    ISLANDER_RECEIVE_ITEM_FINISH,

    ISLANDER_RECEIVE_ITEM_STATE_NUM
} IslanderReceiveItemState;

typedef enum IslanderDiggingState {
    ISLANDER_DIGGING_DIG_HOLE = 0,
    ISLANDER_DIGGING_BURY_IN_EMPTY_HOLE,
    ISLANDER_DIGGING_REACT_TO_DUG_ITEM,
    ISLANDER_DIGGING_SELECT_REPLACEMENT_ITEM,
    ISLANDER_DIGGING_FILL_HOLE,
    ISLANDER_DIGGING_FINISH_ITEM_REACTION,

    ISLANDER_DIGGING_STATE_NUM
} IslanderDiggingState;

typedef enum IslanderCarryTransitionState {
    ISLANDER_CARRY_TRANSITION_WAIT_FOR_PICKUP = 0,
    ISLANDER_CARRY_TRANSITION_MOSAIC_IN,
    ISLANDER_CARRY_TRANSITION_MOSAIC_OUT,
    ISLANDER_CARRY_TRANSITION_WAIT_FOR_PLACEMENT,
    ISLANDER_CARRY_TRANSITION_CHECK_PLACEMENT,

    ISLANDER_CARRY_TRANSITION_STATE_NUM
} IslanderCarryTransitionState;

typedef enum IslanderPlacementCheckPhase {
    ISLANDER_PLACEMENT_CHECK_REACT = 0,
    ISLANDER_PLACEMENT_CHECK_ANIM_02,
    ISLANDER_PLACEMENT_CHECK_ANIM_06,
    ISLANDER_PLACEMENT_CHECK_ANIM_00,
    ISLANDER_PLACEMENT_CHECK_POSITION,
    ISLANDER_PLACEMENT_CHECK_RETURN_HOME,

    ISLANDER_PLACEMENT_CHECK_PHASE_NUM
} IslanderPlacementCheckPhase;

typedef void (*IslanderDiggingStateProc)(void);
extern IslanderDiggingStateProc sIslanderDiggingStateProcs[ISLANDER_DIGGING_STATE_NUM];

/* Original address: 0x0203380C */
extern void (*IslanderMoveProcTable[ISLANDER_MOVE_ACTION_NUM])(void);

typedef enum IslanderEmotion {
    ISLANDER_EMOTION_NEUTRAL = 0,
    ISLANDER_EMOTION_ANGRY,
    ISLANDER_EMOTION_SAD,
    ISLANDER_EMOTION_HAPPY,

    ISLANDER_EMOTION_NUM
} IslanderEmotion;

typedef union IslanderItemWork {
    struct {
        u16 type_idx;
        u16 tile_no;
    } held_item;
    struct {
        u16 phase;
        u16 timer;
    } carry_transition;
} __attribute__((packed, aligned(2))) IslanderItemWork;

typedef enum IslanderAnim_1_e {
    ISLANDER_ANIM_00=0,
    ISLANDER_ANIM_01=1,
    ISLANDER_ANIM_02=2,
    ISLANDER_ANIM_03=3,
    ISLANDER_ANIM_04=4,
    ISLANDER_ANIM_05=5,
    ISLANDER_ANIM_06=6,
    ISLANDER_ANIM_07=7,
    ISLANDER_ANIM_08=8,
    ISLANDER_ANIM_09=9,
    ISLANDER_ANIM_0A=10,
    ISLANDER_ANIM_0B=11,
    ISLANDER_ANIM_0C=12,
    ISLANDER_ANIM_0D=13,
    ISLANDER_ANIM_0E=14,
    ISLANDER_ANIM_0F=15,
    ISLANDER_ANIM_10=16,
    ISLANDER_ANIM_11=17,
    ISLANDER_ANIM_12=18,
    ISLANDER_ANIM_13=19,
    ISLANDER_ANIM_14=20,
    ISLANDER_ANIM_15=21,
    ISLANDER_ANIM_16=22,
    ISLANDER_ANIM_17=23,
    ISLANDER_ANIM_18=24,
    ISLANDER_ANIM_19=25,
    ISLANDER_ANIM_1A=26,
    ISLANDER_ANIM_1B=27,
    ISLANDER_ANIM_1C=28,
    ISLANDER_ANIM_1D=29,
    ISLANDER_ANIM_1E=30,
    ISLANDER_ANIM_1F=31,
    ISLANDER_ANIM_20=32,
    ISLANDER_ANIM_21=33,
    ISLANDER_ANIM_22=34,
    ISLANDER_ANIM_23=35,
    ISLANDER_ANIM_24=36,
    ISLANDER_ANIM_25=37,
    ISLANDER_ANIM_26=38,
    ISLANDER_ANIM_27=39,
    ISLANDER_ANIM_28=40,
    ISLANDER_ANIM_29=41,
    ISLANDER_ANIM_2A=42,
    ISLANDER_ANIM_2B=43,
    ISLANDER_ANIM_2C=44,
    ISLANDER_ANIM_2D=45,
    ISLANDER_ANIM_2E=46,
    ISLANDER_ANIM_2F=47,
    ISLANDER_ANIM_30=48,
    ISLANDER_ANIM_31=49,
    ISLANDER_ANIM_32=50,
    ISLANDER_ANIM_33=51,
    ISLANDER_ANIM_34=52,
    ISLANDER_ANIM_35=53,
    ISLANDER_ANIM_36=54,
    ISLANDER_ANIM_37=55,
    ISLANDER_ANIM_38=56,
    ISLANDER_ANIM_39=57,
    ISLANDER_ANIM_3A=58,
    ISLANDER_ANIM_3B=59,
    ISLANDER_ANIM_3C=60,
    ISLANDER_ANIM_3D=61,
    ISLANDER_ANIM_3E=62,
    ISLANDER_ANIM_3F=63,
    ISLANDER_ANIM_40=64,
    ISLANDER_ANIM_41=65,
    ISLANDER_ANIM_42=66,
    ISLANDER_ANIM_43=67,
    ISLANDER_ANIM_44=68,
    ISLANDER_ANIM_45=69,
    ISLANDER_ANIM_46=70,
    ISLANDER_ANIM_47=71,
    ISLANDER_ANIM_48=72,
    ISLANDER_ANIM_49=73,
    ISLANDER_ANIM_4A=74,
    ISLANDER_ANIM_4B=75,
    ISLANDER_ANIM_4C=76,
    ISLANDER_ANIM_4D=77,
    ISLANDER_ANIM_4E=78,
    ISLANDER_ANIM_4F=79,
    ISLANDER_ANIM_50=80,
    ISLANDER_ANIM_51=81,
    ISLANDER_ANIM_52=82,
    ISLANDER_ANIM_53=83,
    ISLANDER_ANIM_54=84,
    ISLANDER_ANIM_55=85,
    ISLANDER_ANIM_56=86,
    ISLANDER_ANIM_57=87,
    ISLANDER_ANIM_58=88,
    ISLANDER_ANIM_59=89,
    ISLANDER_ANIM_5A=90,
    ISLANDER_ANIM_ANGRY=91,
    ISLANDER_ANIM_SAD=92,
    ISLANDER_ANIM_5D=93,
    ISLANDER_ANIM_5E=94,
    ISLANDER_ANIM_5F=95,
    ISLANDER_ANIM_60=96,
    ISLANDER_ANIM_61=97,
    ISLANDER_ANIM_NUM=98
} IslanderAnim_1_e;

typedef enum IslanderTool_e {
    ISLANDER_TOOL_NONE,
    ISLANDER_TOOL_NET,
    ISLANDER_TOOL_AXE,
    ISLANDER_TOOL_SHOVEL,
    ISLANDER_TOOL_ROD,
    ISLANDER_TOOL_GOLD_NET,
    ISLANDER_TOOL_GOLD_AXE,
    ISLANDER_TOOL_GOLD_SHOVEL,
    ISLANDER_TOOL_GOLD_ROD,

    ISLANDER_TOOL_NUM
} IslanderTool_e;

#define ISLANDER_TOOL_STATE_DROP 0x40

typedef void (*Islander_SUB_MOVE_PROC)(void);

typedef struct IslanderFoodPreference {
    u8 preferences[18][9];
    u8 layout[9];
} __attribute__((packed, aligned(2))) IslanderFoodPreference;

typedef struct IslanderDirectionSector {
    u16 max_angle;
    u8 direction;
    u8 pad;
} IslanderDirectionSector;

/* sizeof(Islander_AGB) == 0xC0 */
typedef struct Islander_AGB {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 accepted_x;
    /* 0x0C */ s32 accepted_y;
    /* 0x10 */ s32 target_x;
    /* 0x14 */ s32 target_y;
    /* 0x18 */ s32 next_target_x;
    /* 0x1C */ s32 next_target_y;
    /* 0x20 */ s32 work_x; /* target delta, distance, or draw position */
    /* 0x24 */ s32 work_y; /* target delta, distance, or draw position */
    /* 0x28 */ s32 tree_approach_eval[2]; /* tile indices, then horizontal distance scores */
    /* 0x30 */ s32 tree_approach_x[2]; /* right and left approach positions */
    /* 0x38 */ s32 flying_item_x;
    /* 0x3C */ s32 flying_item_y;
    /* 0x40 */ u32 held_item_sprite; /* packed OAM attr2 and display flag */
    /* 0x44 */ u16 *collision_tilemap;
    /* 0x48 */ u16 surrounding_item_types[4];
    /* 0x50 */ u16 surrounding_tile_indices[4];
    /* 0x58 */ u16 wander_timer;
    /* 0x5A */ u16 stored_item_type_plus_one[5];
    /* 0x64 */ mActor_name_t stored_item_ids[5];
    /* 0x6E */ IslanderItemWork item_work;
    /* 0x72 */ mActor_name_t removed_tool_item;
    /* 0x74 */ u16 fishing_cooldown_timer;
    /* 0x76 */ u16 flying_item_spawn_timer;
    /* 0x78 */ u16 digging_cooldown_timer;
    /* 0x7A */ u16 interaction_tile; /* tile index plus layer flag 0x8000 */
    /* 0x7C */ u16 buried_item_tile_base;
    /* 0x7E */ u16 tree_action_cooldown_timer;
    /* 0x80 */ u16 carry_wait_timer;
    /* 0x82 */ u16 equipped_tool_timer;
    /* 0x84 */ u8 carry_state;
    /* 0x85 */ u8 removed_tool_layer;
    /* 0x86 */ u8 removed_tool_tile_idx;
    /* 0x87 */ u8 move_action; /* IslanderMoveAction */
    /* 0x88 */ u8 anim_id; /* IslanderAnim_1_e */
    /* 0x89 */ u8 anim_frame;
    /* 0x8A */ u8 anim_timer;
    /* 0x8B */ u8 direction;
    /* 0x8C */ u8 previous_direction;
    /* 0x8D */ u8 equipped_tool_state; /* tool in low nibble; flags in high nibble */
    /* 0x8E */ u8 tile_idx;
    /* 0x8F */ u8 terrain_tile_idx;
    /* 0x90 */ u8 emotion; /* EMOTION_TYPE */
    /* 0x91 */ u8 blink_frame;
    /* 0x92 */ u8 blink_timer;
    /* 0x93 */ u8 mood_level;
    /* 0x94 */ u8 direction_change_cooldown_timer;
    /* 0x95 */ u8 stored_item_slot;
    /* 0x96 */ u8 islander_npc_idx;
    /* 0x97 */ u8 reaction_anim_id; /* IslanderAnim_1_e */
    /* 0x98 */ u8 click_cooldown_timer;
    /* 0x99 */ u8 target_action;
    /* 0x9A */ u8 collision_bypass_timer;
    /* 0x9B */ u8 target_field_object_idx;
    /* 0x9C */ u8 action_state;
    /* 0x9D */ u8 player_interaction_tile_idx;
    /* 0x9E */ u8 floating_balloon_target_entity_id;
    /* 0x9F */ u8 interaction_target_is_islander;
    /* 0xA0 */ u8 immediate_item_type_plus_one;
    /* 0xA1 */ u8 reward_adjust;
    /* 0xA2 */ u8 blocked_directions[8];
    /* 0xAA */ u8 direction_candidates[8];
    /* 0xB2 */ u8 collision_retry_count;
    /* 0xB3 */ u8 collision_recovery_timer;
    /* 0xB4 */ u8 favorite_hour_item_spawned;
    /* 0xB5 */ u8 tree_action_skipped;
    /* 0xB6 */ u8 removed_field_item_type;
    /* 0xB7 */ u8 dig_target_layer;
    /* 0xB8 */ u8 dig_target_tile_idx;
    /* 0xB9 */ u8 reserved_B9[7];
} Islander_AGB;

#define Islander_GET_TOOL_TYPE(islander) ((islander)->equipped_tool_state & 0xF)

/* Maps an item type and Islander emotion to a base in the buried-item RNG table. */
typedef struct BuriedItemRngTileGroup {
    u16 item_type;
    u16 generator_table_offsets[4];
} __attribute__((packed, aligned(2))) BuriedItemRngTileGroup;

typedef struct BuriedItemUpdateGroup {
    u16 item_type;
    mActor_name_t buried_item;
} BuriedItemUpdateGroup;

extern AnimFrameData** gIslanderAnimData[ISLANDER_ANIM_NUM+1];
extern u8 gIslanderAnimMirrorFlags[ISLANDER_ANIM_NUM+1];

/* Original address: 0x02033FB6 */
extern IslanderFoodPreference ISLANDER_FOOD_PREFERENCES;
/* Original address: 0x020338DC */
extern IslanderDirectionSector gIslanderDirectionSectors[8];

extern Islander_AGB gIslander;

/* Original address: 0x02024AEC */
mActor_name_t Item_TypeToIslandItem(u32 idx);
/* Original address: 0x02024F08 */
void Entity_Reset(s32 entity_index);
/* Original address: 0x020262DC */
void Field_RestoreAdjacentTreeTiles(u16 tile_idx, s32 x);

s32 Islander_StoreItem(u16 item_type, u16 generator_idx);
s16 Islander_GetFishingItem(void);
s32 Islander_SetupDigApproach(u8 tile_offset);
s32 Islander_CanDigHere(void);
s32 Islander_ChangeMoveDir(s32 target_x, s32 target_y, u8 move_mode);
void Islander_UpdateCollisionTiles(u8 direction);
void WriteItemToTile(s32 x, u8 tile_idx, u16 item, u16 item_tile);
s32 CheckSurroundingCollision(u16 arg0, u16 *arg1);
s32 Islander_ChooseNewMoveDirection(u8 arg0);
s32 Islander_CanMoveInDirection(u8 direction);
void Islander_BuryRandomItem(s32 arg0);
void Islander_PlantRandomFlower(void);
void Islander_UpdateBlink(void);
s32 Islander_FaceTargetAndCheckArrival(s32 arg0, s32 arg1);
s32 Islander_PlayAnim(u8 arg0);
void Islander_ClearStoredItem(s32 arg0);
s32 Islander_SpawnReactionEffect(u8 arg0, u8 arg1);
s32 SpawnEntity(u8 spawn_flag, u8 spawn_mode, u16 item_type, u16 item);
s32 Islander_SelectTreeApproach(FieldObject *object, s32 right_x, s32 left_x);
s32 Islander_SetupTreeApproach(FieldObject *object);
s32 Islander_DecideTreeAction(void);
void Islander_MoveWithCollision(void);
void Islander_AdjustAnimForTool(void);
s32 Islander_MoveTowardX(u8 keep_facing, s32 target);
s32 Islander_MoveTowardY(u8 keep_facing, s32 target);
s32 Islander_FindNearbyTree(void);
s32 Islander_TryInteractWithBuriedItem(u8 layer);
void Islander_OnMoodChanged(void);
void WriteItemTileToVRAM(u16 *tilemap, u16 tile_base);
u16 Item_GetItemIdFromTileId(s32 arg0);
s32 Islander_TryDropTool(void);
void Islander_Init(void);
s32 Island_GetFloatingItem(void);
void Islander_StepFlyingItem(void);
s32 Islander_TryStartFishing(void);
u16 Islander_TakeCurrentTileItem(void);
s32 Islander_TryInteractWithCurrentTile(void);
s32 Islander_TryStartDigging(void);
void RestoreHeldItemsToField(void);
void Islander_UpdateMovement(void);
void Islander_StartHouseTransition(void);
void Islander_MoveIndoorsOrOutdoors(void);
void Islander_StartWandering(void);
void Islander_UpdateWandering(void);
void IslanderMoveAction_MoveToTarget(void);
void Islander_StartFoodProcessing(void);
void Islander_ProcessFood(void);
void IslanderMoveAction_UpdateEmotion(void);
void Islander_UpdateEmotionAnimation(void);
void Islander_StartClickReaction(void);
void Islander_CheckClickedOnTimer(void);
void Islander_StartFieldObjectInteraction(void);
void Islander_ShakeFieldObject(void);
void Islander_ChopFieldObject(void);
void Islander_FinishFieldObjectInteraction(void);
void Islander_UpdateFieldObjectInteraction(void);
void Islander_Fishing_Init(void);
void Islander_CastFishingLine(void);
void Islander_WaitForFishBite(void);
void Islander_NoticeFishBite(void);
void Islander_WaitToReelIn(void);
void Islander_ReelInFish(void);
void Islander_FinishFailedCatch(void);
void Islander_ReactToFishingResult(void);
void Islander_FinishSuccessfulCatch(void);
void IslanderMoveAction_Fishing(void);
void Islander_ReceiveItem_Init(void);
void IslanderMoveAction_ReceiveItem(void);
void Islander_CatchFlyingItem(void);
void Islander_StoreHeldItem(void);
void Islander_FinishReceivingItem(void);
void IslanderMoveAction_Dig(void);
void Islander_DigHole(void);
void Islander_BuryItemInEmptyHole(void);
void Islander_ReactToDugItem(void);
void Islander_SelectReplacementBuriedItem(void);
void Islander_FillHole(void);
void Islander_FinishDugItemReaction(void);
void IslanderMoveAction_Bury(void);
void Islander_StartCarryTransition(void);
void Islander_WaitForPickup(void);
void Islander_ReturnHomeMosaicIn(void);
void Islander_ReturnHomeMosaicOut(void);
void Islander_WaitForPlacement(void);
void Islander_CheckPlacement(void);
void Islander_UpdateCarryTransition(void);
void Islander_Draw(void);

#ifdef __cplusplus
}
#endif

#endif
