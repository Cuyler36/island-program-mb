#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include "gba/gba.h"
#include "anim.h"
#include "item.h"

// global.h from pokemon ruby

// IDE support
#if __INTELLISENSE__
#define _(x) x
#define __(x) x
#define INCBIN(x) {0}
#define INCBIN_U8(x) INCBIN(x)
#define INCBIN_U16(x) INCBIN(x)
#define INCBIN_U32(x) INCBIN(x)
#define INCBIN_S8(x) INCBIN(x)
#define INCBIN_S16(x) INCBIN(x)
#define INCBIN_S32(x) INCBIN(x)
#endif

#define TRUE 1
#define FALSE 0

#define ARRAY_COUNT(arr) ((int)(sizeof(arr) / sizeof((arr)[0])))

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")

#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided\n")

#define NAKED __attribute__((naked))
#define ATTRIBUTE_ALIGN(n) __attribute__((aligned(n)))


#define NELEMS(arr) (sizeof(arr)/sizeof(*(arr)))


#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

// why does GF hate 2d arrays
#define MULTI_DIM_ARR(x, dim, y) ((x) * dim + (y))

// dim access enums
enum
{
    B_8 = 1,
    B_16 = 2,
    B_32 = 4
};

// There are many quirks in the source code which have overarching behavioral differences from
// a number of other files. For example, diploma.c seems to declare rodata before each use while
// other files declare out of order and must be at the beginning. There are also a number of
// macros which differ from one file to the next due to the method of obtaining the result, such
// as these below. Because of this, there is a theory (Two Team Theory) that states that these
// programming projects had more than 1 "programming team" which utilized different macros for
// each of the files that were worked on.
#define T1_READ_8(ptr)  ((ptr)[0])
#define T1_READ_16(ptr) ((ptr)[0] | ((ptr)[1] << 8))
#define T1_READ_32(ptr) ((ptr)[0] | ((ptr)[1] << 8) | ((ptr)[2] << 16) | ((ptr)[3] << 24))
#define T1_READ_PTR(ptr) (u8*) T1_READ_32(ptr)

// T2_READ_8 is a duplicate to remain consistent with each group.
#define T2_READ_8(ptr)  ((ptr)[0])
#define T2_READ_16(ptr) ((ptr)[0] + ((ptr)[1] << 8))
#define T2_READ_32(ptr) ((ptr)[0] + ((ptr)[1] << 8) + ((ptr)[2] << 16) + ((ptr)[3] << 24))
#define T2_READ_PTR(ptr) (void*) T2_READ_32(ptr)

// Credits to Made (dolphin emoji)
#define S16TOPOSFLOAT(val)   \
({                           \
    s16 v = (val);           \
    float f = (float)v;      \
    if(v < 0) f += 65536.0f; \
    f;                       \
})


#define RGB(r, g, b) (((b & 0x1F) << 10) | ((g & 0x1F) << 5) | (r & 0x1F))
#define COLOR_R(color) (color & 0x1F)
#define COLOR_G(color) ((color >> 5) & 0x1F)
#define COLOR_B(color) ((color >> 10) & 0x1F)

#define OAM_ENTRY(attr0, attr1, attr2, affine_param) \
{ \
    (attr0) & 0xFF, ((attr0) >> 8) & 3, ((attr0) >> 10) & 3, \
    ((attr0) >> 12) & 1, ((attr0) >> 13) & 1, ((attr0) >> 14) & 3, \
    (attr1) & 0x1FF, ((attr1) >> 9) & 7, ((attr1) >> 12) & 1, \
    ((attr1) >> 13) & 1, ((attr1) >> 14) & 3, (attr2) & 0x3FF, \
    ((attr2) >> 10) & 3, ((attr2) >> 12) & 0xF, (affine_param) \
}

#define mISL_ISLAND_NAME_LEN 8

#define mISL_FG_BLOCK_X_NUM 2
#define mISL_FG_BLOCK_Z_NUM 1

#define LAND_NAME_SIZE 8
#define PLAYER_NAME_LEN 8

#define PLAYER_NUM 4

#define mHm_LAYER_NUM 4

#define UT_X_NUM 16
#define UT_Z_NUM 16

#define mNW_ORIGINAL_DESIGN_NAME_LEN 16 /* length of design name */
#define mNW_ORIGINAL_DESIGN_WIDTH 32 /* width */
#define mNW_ORIGINAL_DESIGN_HEIGHT 32 /* height */
#define mNW_DESIGN_TEX_SIZE (mNW_ORIGINAL_DESIGN_HEIGHT * (mNW_ORIGINAL_DESIGN_WIDTH / 2)) /* total texture data size */
#define mNW_PALETTE_SIZE (16 * sizeof(u16))
#define mNW_PALETTE_COUNT 16 /* number of design palettes */

#define MAIL_HEADER_BASE_LEN 32
#define MAIL_HEADER_LEN (MAIL_HEADER_BASE_LEN - PLAYER_NAME_LEN)
#define MAIL_FOOTER_LEN 32
#define MAIL_BODY_LEN 192

#define ANIMAL_NUM_MIN 5
#define ANIMAL_NUM_MAX 15 /* Maximum number of villagers possible in town */
#define ANIMAL_MEMORY_NUM 7
#define ANIMAL_CATCHPHRASE_LEN 10
#define ANIMAL_HP_MAIL_NUM PLAYER_NUM
#define mNpc_ISLAND_FTR_SAVE_NUM 4

enum {
    mISL_ISLAND_BLOCK_LEFT,
    mISL_ISLAND_BLOCK_RIGHT,
  
    mISL_ISLAND_BLOCK_NUM
};

typedef struct OSRTCTime { // from lbrtc library in N64
    u8 sec;
    u8 min;
    u8 hour;
    u8 day;
    u8 weekday;
    u8 month;
    u16 year;
} OSRTCTime; 
  
typedef u8 lbRTC_sec_t;
typedef u8 lbRTC_min_t;
typedef u8 lbRTC_hour_t;
typedef u8 lbRTC_day_t;
typedef u8 lbRTC_weekday_t;
typedef u8 lbRTC_month_t;
typedef u16 lbRTC_year_t;

  typedef OSRTCTime lbRTC_time_c; /* Name leaked in lbRTC_time_c_save_data_check */
  
typedef struct lbRTC_ymd_s {
    lbRTC_year_t year;
    lbRTC_month_t month;
    lbRTC_day_t day;
} lbRTC_ymd_c; /* Name leaked in mTM_ymd_2_time */

/* sizeof(TempoBeat_c) == 2 */
typedef struct audio_tempo_beat_s {
    /* 0x00 */ u8 tempo;
    /* 0x01 */ s8 beat;
} TempoBeat_c;

/* sizeof(PersonalID_c) == 0x14 */
typedef struct personal_id_s {
    /* 0x00 */ u8 player_name[PLAYER_NAME_LEN];
    /* 0x08 */ u8 land_name[LAND_NAME_SIZE];
    /* 0x10 */ u16 player_id;
    /* 0x12 */ u16 land_id;
} PersonalID_c;

enum {
    mNpc_LOOKS_GIRL, // 'normal'
    mNpc_LOOKS_KO_GIRL, // 'peppy'
    mNpc_LOOKS_BOY, // 'lazy'
    mNpc_LOOKS_SPORT_MAN, // 'jock'
    mNpc_LOOKS_GRIM_MAN, // 'cranky'
    mNpc_LOOKS_NANIWA_LADY, // 'snooty'
    mNpc_LOOKS_UNSET,
  
    mNpc_LOOKS_NUM = mNpc_LOOKS_UNSET
};
  
/* sizeof(AnmPersonalID_c) == 0xE */
typedef struct animal_personal_id_s {
    /* 0x00 */ mActor_name_t npc_id; /* id */
    /* 0x02 */ u16 land_id; /* town id */
    /* 0x04 */ u8 land_name[LAND_NAME_SIZE]; /* town name */
    /* 0x0C */ u8 name_id; /* lower byte of the id */
    /* 0x0D */ u8 looks; /* internal name for personality */
} AnmPersonalID_c;

/* sizeof(mHm_lyr_c) == 0x228 */
typedef struct home_layer_s {
    /* 0x000 */ mActor_name_t items[UT_Z_NUM][UT_X_NUM]; /* Furniture item actors */
    /* 0x200 */ u64 ftr_switch;     /* Bitfield for controlling which furniture items are active, max of 64 */
    /* 0x208 */ u32 haniwa_step[8]; /* Only referenced in mISL_gc_to_agb_layer */
} mHm_lyr_c;

/* sizeof(mHm_wf_c) == 2 */
typedef struct home_wall_floor_s {
    /* 0x00 */ u8 flooring_idx;
    /* 0x01 */ u8 wallpaper_idx;
} mHm_wf_c;

/* sizeof(mHm_goki_c) == 0xA */
typedef struct home_goki_s {
    /* 0x00 */ lbRTC_time_c time; /* last time updated */
    /* 0x08 */ u8 num;            /* number of cockroaches in the house */
    /* 0x09 */ u8 pad;            /* unused outside of being initalized to 0 */
} mHm_goki_c;

/* sizeof(Anmlnd_c) == 0xA */
typedef struct animal_land_mem_s {
    /* 0x00 */ u8 name[LAND_NAME_SIZE];
    /* 0x08 */ u16 id;
} Anmlnd_c;

typedef struct island_animal_best_ftr_s {
    u32 check;
    u16 have_bitfield;
} Anm_bestFtr_c;

/* sizeof(memuni_u) == 0xC */
typedef union {
    Anmlnd_c land;        /* size = 0xA */
    Anm_bestFtr_c island; /* size = 6 */
} memuni_u;

/* sizeof(anmuni) == 8 */
typedef union {
    u8 previous_land_name[LAND_NAME_SIZE];
    mActor_name_t island_ftr[mNpc_ISLAND_FTR_SAVE_NUM];
} anmuni_u;

/* sizeof(AnmHPMail_c) == 0x1C */
typedef struct animal_password_mail_s {
    /* 0x00 */ lbRTC_time_c receive_time;
    /* 0x08 */ u8 password[20]; /* TODO: this should not be a hardcoded length */
} AnmHPMail_c;

/* sizeof(Anmhome_c) == 5 */
typedef struct animal_home_s {
    /* 0x00 */ u8 type_unused; /* Likely the house type, but seems to be unused outside of SChk_Anmhome_c_sub */
    /* 0x01 */ u8 block_x;     /* acre x position */
    /* 0x02 */ u8 block_z;     /* acre y position */
    /* 0x03 */ u8 ut_x;        /* unit x position */
    /* 0x04 */ u8 ut_z;        /* unit z position */
} __attribute__((packed)) Anmhome_c;

/* sizeof(mQst_contest_info_u) == 4 */
typedef union quest_contest_info_s {
    struct {
        /* 0x00 */ u8 flowers_requested; /* number of flowers village requests be planted in acre */
    } flower_data;

    struct {
        /* 0x00 */ u8 score;              /* score rank of letter */
        /* 0x02 */ mActor_name_t present; /* present sent with letter */
    } letter_data;
} mQst_contest_info_u;

/* sizeof(mFM_fg_c) == 0x200 */
typedef struct fg_items_s {
    /* 0x000 */ mActor_name_t items[UT_Z_NUM][UT_X_NUM];
} mFM_fg_c;

typedef struct original_texture_s {
    u8 data[mNW_DESIGN_TEX_SIZE];
} ATTRIBUTE_ALIGN(32) mNW_original_tex_c;
  
/* sizeof(mNW_original_design_c) == 0x220 */
typedef struct original_data_s {
    /* 0x000 */ u8 name[mNW_ORIGINAL_DESIGN_NAME_LEN];
    /* 0x010 */ u8 palette;
    /* 0x011 */ u8 flag_design_set;
    /* 0x020 */ mNW_original_tex_c design; /* this is aligned to 32 bytes for ARAM transfer */
} mNW_original_design_c;

typedef struct agb_landinfo_s {
    u8 name[LAND_NAME_SIZE];
    s8 exists;
    u16 id;
    u8 _pad[4];
} mISL_landinfo_agb_c;

typedef struct agb_floor_s {
    /* 0x000 */ mHm_lyr_c layers[mHm_LAYER_NUM];
    /* 0x8A0 */ mHm_wf_c wall_floor;
    /* 0x8A2 */ u16 pad_8A2;
    /* 0x8A4 */ TempoBeat_c tempo_beat;
    /* 0x8A8 */ u32 floor_bit_info;
} mISL_flr_agb_c;

typedef struct agb_cottage_s {
    /* 0x000 */ mHm_wf_c unused_wall_floor; /* Has wallpaper & flooring bounds checks in sChk_CheckSaveData_Cattage */
    /* 0x002 */ u8 pad_2[2];
    /* 0x004 */ u8 unk_2[2]; /* struct/array that is two bytes long, maybe another wall floor? */
    /* 0x008 */ mISL_flr_agb_c room; /* Cottage room */
    /* 0x8B8 */ u8 unk_8B8; // unk_4
    /* 0x8B9 */ u8 unk_8B9; // unk_5
    /* 0x8BA */ u8 pad_8BA;
    /* 0x8BB */ u8 pad_8BB;
    /* 0x8BC */ mHm_goki_c goki; /* Cottage cockroaches */
    /* 0x8C8 */ u32 pad_8C8;
    /* 0x8CC */ u32 music_box[2]; /* Cottage music storage... separate from main home? */
} mISL_cottage_agb_c;

typedef struct agb_anmplayermail_s {
    /* 0x000 */ u8 font; /* 'font' to use for letter info */
    /* 0x001 */ u8 paper_type; 
    /* 0x002 */ mActor_name_t present;
    /* 0x004 */ u8 header_back_start; /* position for name insertion in header */
    /* 0x005 */ u8 pad_5[3]; /* likely pad */
    /* 0x008 */ u8 header[MAIL_HEADER_LEN];
    /* 0x020 */ u8 body[MAIL_BODY_LEN];
    /* 0x0E0 */ u8 footer[MAIL_FOOTER_LEN];
    /* 0x100 */ lbRTC_ymd_c date; /* sent date */
} mISL_Anmplmail_agb_c;

typedef struct agb_anmmem_s {
    PersonalID_c player_id;
    lbRTC_time_c last_speak_time;
    memuni_u memuni;
    u64 saved_town_tune;
    s8 friendship;
    u32 letter_info;
    mISL_Anmplmail_agb_c letter;
    u8 __align[4];
} mISL_Anmmem_agb_c;

typedef struct agb_quest_base_s {
    /* 0x00 */ u32 info;
    /* 0x04 */ lbRTC_time_c time_limit;
} mISL_quest_base_c;

typedef struct agb_quest_contest_s {
    /* 0x00 */ mISL_quest_base_c base; /* quest base struct */
    /* 0x0C */ mActor_name_t requested_item; /* item (if any) requested by the villager */
    /* 0x0E */ u8 pad_0E[2];
    /* 0x10 */ PersonalID_c player_id; /* personal id of the player */
    /* 0x24 */ s8 type; /* type of quest, seems to be repeat of data in quest base */
    /* 0x25 */ u8 pad_25[3];
    /* 0x28 */ mQst_contest_info_u info; /* contest info for flower & letter quests */
} mISL_quest_contest_c;

typedef struct agb_animal_s {
    /* 0x000 */ AnmPersonalID_c id; /* this villager's ID */
    /* 0x010 */ mISL_Anmmem_agb_c memories[ANIMAL_MEMORY_NUM]; /* memories of players who've spoken to this villager */
    /* 0x8D0 */ Anmhome_c home_info; /* home position info */
    /* 0x8D5 */ u8 pad_8D5[3];
    /* 0x8D8 */ u8 catchphrase[ANIMAL_CATCHPHRASE_LEN]; /* may be called 'word_ending' */
    /* 0x8E2 */ u8 pad_8E2[2];
    /* 0x8E4 */ mISL_quest_contest_c contest_quest; /* current contest quest information */
    /* 0x910 */ u8 parent_name[PLAYER_NAME_LEN]; /* name of the player who 'spawned' the villager in, unsure why this is tracked */
    /* 0x918 */ u8 pad_918[4];
    /* 0x91C */ anmuni_u anmuni; /* name of the last town the villager lived in or saved island ftr */
    /* 0x924 */ u8 pad_924[4]; /* may include last_land_id */
    /* 0x928 */ u8 mood; /* probably called 'feel' based on code */
    /* 0x929 */ u8 mood_time; /* probably called 'feel_tim' based on code */
    /* 0x92A */ mActor_name_t cloth; /* shirt the villager is wearing */
    /* 0x92C */ u16 remove_info; /* info about villager moving between towns? kinda stubbed */
    /* 0x92D */ u8 is_home; /* TRUE when the villager is home, otherwise FALSE */
    /* 0x92E */ u8 moved_in; /* TRUE when the villager moved in after town creation, FALSE if they started out in town */
    /* 0x92F */ u8 removing; /* TRUE when the villager is leaving town, FALSE otherwise */
    /* 0x930 */ u8 cloth_original_id; /* 0xFF when not wearing an Able Sister's pattern, otherwise 0-3 indicating which pattern */
    /* 0x931 */ s8 umbrella_id; /* 0xFF when no umbrella, 0-31 when a standard umbrella, 32-35 when using an Able Sister's pattern */
    /* 0x932 */ u8 unk_932; /* Exists according to mISL_gc_to_agb_animal, but seems unused in practice */
    /* 0x934 */ mActor_name_t present_cloth; /* The most recently received shirt from a letter which the villager may change into */
    /* 0x936 */ u8 pad_936[6];
    /* 0x93C */ u8 animal_relations[ANIMAL_NUM_MAX]; /* relationships between all villagers in town, starts at 128 which is neutral */
    /* 0x94B */ u8 pad_94B[5];
    /* 0x950 */ AnmHPMail_c hp_mail[ANIMAL_HP_MAIL_NUM]; /* mail password info storage */
    /* 0x9C0 */ u8 _9C0[24]; /* unknown usage/unused */
} mISL_Animal_agb_c;

typedef struct island_agb_s {
    /* 0x0000 */ u8 _0000[8];
    /* 0x0008 */ u8 name[mISL_ISLAND_NAME_LEN]; /* island name */
    /* 0x0010 */ u8 grass_tex_type; /* grass type */
    /* 0x0011 */ u8 _0011[2];
    /* 0x0013 */ u8 in_use; /* Set on the GBA when the island has been transferred already */
    /* 0x0014 */ mISL_landinfo_agb_c landinfo; /* land info for town */
    /* 0x0024 */ mFM_fg_c fgblock[mISL_FG_BLOCK_Z_NUM][mISL_FG_BLOCK_X_NUM]; /* island item actor data */
    /* 0x0424 */ u8 _0424[4];
    /* 0x0428 */ mISL_cottage_agb_c cottage; /* player shared cottage data */
    /* 0x0D00 */ mNW_original_design_c flag_design; /* island flag design */
    /* 0x0F20 */ mISL_Animal_agb_c animal; /* islander info */
    /* 0x18F8 */ u16 deposit[mISL_FG_BLOCK_X_NUM * mISL_FG_BLOCK_Z_NUM][UT_Z_NUM]; /* buried item bitfield */
    /* 0x1938 */ u8 bg_data[mISL_ISLAND_BLOCK_NUM]; /* island acre ids */
    /* 0x193A */ u8 weather;
    /* 0x193C */ lbRTC_time_c renew_time; /* last time island was visited? */
    /* 0x1944 */ int npc_idx;
    /* 0x1948 */ u32 earth_tex[1024];
    /* 0x2948 */ u32 npc_tex[1024];
    /* 0x3948 */ u16 npc_pal[16];
    /* 0x3968 */ u8 _3968[20];
    /* 0x397C */ u8 _397C;
    /* 0x397D */ u8 last_song_to_island; /* last song kapp'n sang for a male character */
    /* 0x397E */ u8 last_song_from_island; /* last song kapp'n sang for a female character */
    /* 0x397F */ u8 checksum;
  } Island_agb_c;

/* Pointer to the island save/runtime image currently being edited. */
extern Island_agb_c* gIslandData; // @0x03001B40

enum {
    mEnv_WEATHER_CLEAR,
    mEnv_WEATHER_RAIN,

    mEnv_WEATHER_NUM
};

#define DmaSetSrc(dmaNum, src)     \
{                                                 \
    vu32 *dmaRegs = (vu32 *)REG_ADDR_DMA##dmaNum; \
    dmaRegs[0] = (vu32)(src);                     \
}

#define DmaSet(dmaNum, src, dest, control)        \
{                                                 \
    vu32 *dmaRegs = (vu32 *)REG_ADDR_DMA##dmaNum; \
    dmaRegs[0] = (vu32)(src);                     \
    dmaRegs[1] = (vu32)(dest);                    \
    dmaRegs[2] = (vu32)(control);                 \
    dmaRegs[2];                                   \
}

#define S_DmaSet(dmaNum, src, dest, control)      \
{                                                 \
    dmaRegs = (vu32 *)REG_ADDR_DMA##dmaNum;       \
    dmaRegs[0] = (vu32)(src);                     \
    dmaRegs[1] = (vu32)(dest);                    \
    dmaRegs[2] = (vu32)(control);                 \
    dmaRegs[2];                                   \
}

#define S_DMA_FILL(dmaNum, value, dest, size, bit)                                            \
{                                                                                             \
    vu32 *dmaRegs;                                                                            \
    vu##bit tmp = (vu##bit)(value);                                                           \
    S_DmaSet(dmaNum,                                                                          \
           &tmp,                                                                              \
           dest,                                                                              \
           (DMA_ENABLE | DMA_START_NOW | DMA_##bit##BIT | DMA_SRC_FIXED | DMA_DEST_INC) << 16 \
         | ((size)/(bit/8)));                                                                 \
}

#define S_DmaFill16(dmaNum, value, dest, size) S_DMA_FILL(dmaNum, value, dest, size, 16)
#define S_DmaFill32(dmaNum, value, dest, size) S_DMA_FILL(dmaNum, value, dest, size, 32)

#define DMA_COPY(dmaNum, src, dest, size, bit)                                              \
    DmaSet(dmaNum,                                                                          \
           src,                                                                             \
           dest,                                                                            \
           (DMA_ENABLE | DMA_START_NOW | DMA_##bit##BIT | DMA_SRC_INC | DMA_DEST_INC) << 16 \
         | ((size)/(bit/8)))

#define DmaCopy16(dmaNum, src, dest, size) DMA_COPY(dmaNum, src, dest, size, 16)
#define DmaCopy32(dmaNum, src, dest, size) DMA_COPY(dmaNum, src, dest, size, 32)

#if 0
/* Original address: 0x02000000 */
extern u16 gBgPaletteBuffer[256];
/* Original address: 0x02000200 */
extern u16 gObjPaletteBuffer[256];
#else
#define gBgPaletteBuffer ((u16*)0x02000000)
#define gObjPaletteBuffer ((u16*)0x02000200)
#endif

extern ItemGroupStruct g_ItemDefinitions[ITEM_TYPE_COUNT];
/* Original address: 0x02000102 */
extern u16 current_time_of_day_palette0[4];
/* Original address: 0x02000122 */
extern u16 current_time_of_day_palette1[4];

/* Original address: 0x02000190 */
extern u16 current_time_of_day_palette2[8];
/* Original address: 0x020001D6 */
extern u16 current_time_of_day_palette3[5];
/* Original address: 0x02000100 */
extern u16 time_of_day_palette_buffer0[16];
/* Original address: 0x02000120 */
extern u16 time_of_day_palette_buffer1[16];
/* Original address: 0x02000180 */
extern u16 time_of_day_palette_buffer2[16];
/* Original address: 0x020001C0 */
extern u16 time_of_day_palette_buffer3[16];
/* Original address: 0x02034EE4 */
extern u16 time_of_day_palettes[24 * 4];

/* Original address: 0x03002410 */
extern OAMData GameOAMData[128]; // OAM

/* Original address: 0x03002970 */
extern Island_agb_c* gIslandTransferData;

/* Original address: 0x020357F4 */
extern u16 sBgPalettes[16][16];

/* Original address: 0x02000000 */
#define gFieldPaletteBuffer ((u16 *)0x02000000)
/* Original address: 0x02000040 */
#define gFieldPaletteBuffer2 ((u16 *)0x02000040)

int _start(void);
void _intr(void);

#endif
