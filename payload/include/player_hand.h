#ifndef PLAYER_HAND_H
#define PLAYER_HAND_H

#include "gba/types.h"
#include "m_name_table.h"

#ifdef __cplusplus
extern "C" {
#endif

/* State for the hand controlled by the player. */
/* sizeof(Player) == 0x2C */
typedef struct Player {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 saved_x; /* initialized with x; consumer unknown */
    /* 0x0C */ s32 saved_y; /* initialized with y; consumer unknown */
    /* 0x10 */ s32 work_x; /* tile-aligned target, distance, or draw position */
    /* 0x14 */ s32 work_y; /* tile-aligned target, distance, or draw position */
    /* 0x18 */ u16 held_item_oam_attr2;
    /* 0x1A */ mActor_name_t held_item;
    /* 0x1C */ u8 left_neighbor_tile_idx;
    /* 0x1D */ u8 right_neighbor_tile_idx;
    /* 0x1E */ u8 tile_idx;
    /* 0x1F */ u8 action_state;
    /* 0x20 */ u8 anim_id;
    /* 0x21 */ u8 anim_frame;
    /* 0x22 */ u8 anim_timer;
    /* 0x23 */ u8 interaction_attempt_active;
    /* 0x24 */ u8 held_item_type_idx;
    /* 0x25 */ u8 placement_input_delay;
    /* 0x26 */ u8 near_house_door;
    /* 0x27 */ u8 interaction_cooldown_timer;
    /* 0x28 */ u8 held_item_layer;
    /* 0x29 */ u8 held_item_tile_idx;
    /* 0x2A */ u8 reserved_2A[2];
} Player;

s32 PlayerHand_IsItemPlacementBlocked(void);
s32 PlayerHand_IsNearInteractionTarget(s32 arg0, s32 arg1, u16 arg2);
s32 PlayerHand_CheckHouseDoorInteraction(void);
s32 PlayerHand_TryInteractWithIslander(void);
s32 PlayerHand_TrySelectIslanderTarget(void);
void PlayerHand_Init(void);
void PlayerHand_UpdateMovement(void);
void PlayerHand_ResetToIdle(void);
void PlayerHand_UpdateIdle(void);
void Field_RestoreNeighborTreeTile(u16 tile_idx, s32 x, u8 neighbor_tile, u8 acre, u8 right_side);
void Field_RestoreAdjacentTreeTiles(u16 arg0, s32 arg1);
void PlayerHand_BeginCarrying(void);
void PlayerHand_UpdateCarrying(void);
void PlayerHand_BeginPlacing(void);
void PlayerHand_UpdatePlacing(void);
void PlayerHand_Update(void);
void PlayerHand_Draw(void);

extern Player gPlayer; // @0x03004B80

#ifdef __cplusplus
}
#endif

#endif // PLAYER_HAND_H