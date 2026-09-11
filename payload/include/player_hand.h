#ifndef PLAYER_HAND_H
#define PLAYER_HAND_H

#include "gba/types.h"
#include "m_name_table.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Values dispatched by the player-hand update table. */
typedef enum PlayerHandActionState {
    PLAYER_HAND_ACTION_RESET_TO_IDLE,
    PLAYER_HAND_ACTION_IDLE,
    PLAYER_HAND_ACTION_BEGIN_CARRYING,
    PLAYER_HAND_ACTION_CARRYING,
    PLAYER_HAND_ACTION_BEGIN_PLACING,
    PLAYER_HAND_ACTION_PLACING,
    PLAYER_HAND_ACTION_COUNT,
} PlayerHandActionState;

/* Animation sequences used by the player hand. */
typedef enum PlayerHandAnimation {
    PLAYER_HAND_ANIM_IDLE,
    PLAYER_HAND_ANIM_CARRYING,
    PLAYER_HAND_ANIM_PLACING,
    PLAYER_HAND_ANIM_BLOCKED,
    PLAYER_HAND_ANIM_COUNT,
} PlayerHandAnimation;

/* State for the on-screen hand controlled by the player. */
/* sizeof(Player) == 0x2C */
typedef struct Player {
    /* 0x00 */ s32 x;                         /* 8.8 fixed-point field cursor X */
    /* 0x04 */ s32 y;                         /* 8.8 fixed-point field cursor Y */
    /* 0x08 */ s32 saved_x;                   /* initialized with x; consumer unknown */
    /* 0x0C */ s32 saved_y;                   /* initialized with y; consumer unknown */
    /* 0x10 */ s32 work_x;                    /* tile target, distance, or draw X */
    /* 0x14 */ s32 work_y;                    /* tile target, distance, or draw Y */
    /* 0x18 */ u16 held_item_oam_attr2;        /* held item's tile and palette attributes */
    /* 0x1A */ mActor_name_t held_item;        /* actor name removed from the field */
    /* 0x1C */ u8 left_neighbor_tile_idx;      /* wrapped tile index to the left */
    /* 0x1D */ u8 right_neighbor_tile_idx;     /* wrapped tile index to the right */
    /* 0x1E */ u8 tile_idx;                    /* current target within a 16x16 acre */
    /* 0x1F */ u8 action_state;                /* PlayerHandActionState */
    /* 0x20 */ u8 anim_id;                     /* PlayerHandAnimation */
    /* 0x21 */ u8 anim_frame;                  /* current animation-frame index */
    /* 0x22 */ u8 anim_timer;                  /* ticks remaining on the current frame */
    /* 0x23 */ u8 interaction_attempt_active;  /* playing the idle interaction animation */
    /* 0x24 */ u8 held_item_type_idx;           /* index into g_ItemDefinitions */
    /* 0x25 */ u8 placement_input_delay;        /* delay before accepting the place input */
    /* 0x26 */ u8 near_house_door;              /* cursor is within the door interaction box */
    /* 0x27 */ u8 interaction_cooldown_timer;   /* delay before accepting another interaction */
    /* 0x28 */ u8 held_item_layer;              /* acre containing the lifted item */
    /* 0x29 */ u8 held_item_tile_idx;           /* original tile of the lifted item */
    /* 0x2A */ u8 reserved_2A[2];
} Player;

s32 PlayerHand_IsItemPlacementBlocked(void);
s32 PlayerHand_IsNearInteractionTarget(s32 x, s32 y, u16 range);
s32 PlayerHand_CheckHouseDoorInteraction(void);
s32 PlayerHand_TryInteractWithIslander(void);
s32 PlayerHand_TrySelectIslanderTarget(void);
void PlayerHand_Init(void);
void PlayerHand_UpdateMovement(void);
void PlayerHand_ResetToIdle(void);
void PlayerHand_UpdateIdle(void);
void Field_RestoreNeighborTreeTile(u16 tile_idx, s32 x, u8 neighbor_tile, u8 acre, u8 right_side);
void Field_RestoreAdjacentTreeTiles(u16 tile_idx, s32 x);
void PlayerHand_BeginCarrying(void);
void PlayerHand_UpdateCarrying(void);
void PlayerHand_BeginPlacing(void);
void PlayerHand_UpdatePlacing(void);
void PlayerHand_Update(void);
void PlayerHand_Draw(void);

/* Original address: 0x03004B80 */
extern Player gPlayer;

#ifdef __cplusplus
}
#endif

#endif // PLAYER_HAND_H
