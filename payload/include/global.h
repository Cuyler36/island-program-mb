#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include "gba/gba.h"

// global.h from pokemon ruby

// IDE support
#if defined(__APPLE__) || defined(__CYGWIN__)
#define _(x) x
#define __(x) x
#define INCBIN(x) {0}
#define INCBIN_U8 INCBIN
#define INCBIN_U16 INCBIN
#define INCBIN_U32 INCBIN
#define INCBIN_S8 INCBIN
#define INCBIN_S16 INCBIN
#define INCBIN_S32 INCBIN
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

typedef u16 mActor_name_t;

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

#define CHAR_INVERT_EXCLAMATION 0
#define CHAR_INVERT_QUESTIONMARK 1
#define CHAR_DIAERESIS_A 2
#define CHAR_GRAVE_A 3
#define CHAR_ACUTE_A 4
#define CHAR_CIRCUMFLEX_A 5
#define CHAR_TILDE_A 6
#define CHAR_ANGSTROM_A 7
#define CHAR_CEDILLA 8
#define CHAR_GRAVE_E 9
#define CHAR_ACUTE_E 10
#define CHAR_CIRCUMFLEX_E 11
#define CHAR_DIARESIS_E 12
#define CHAR_GRAVE_I 13
#define CHAR_ACUTE_I 14
#define CHAR_CIRCUMFLEX_I 15
#define CHAR_DIARESIS_I 16
#define CHAR_ETH 17
#define CHAR_TILDE_N 18
#define CHAR_GRAVE_O 19
#define CHAR_ACUTE_O 20
#define CHAR_CIRCUMFLEX_O 21
#define CHAR_TILDE_O 22
#define CHAR_DIARESIS_O 23
#define CHAR_OE 24
#define CHAR_GRAVE_U 25
#define CHAR_ACUTE_U 26
#define CHAR_CIRCUMFLEX_U 27
#define CHAR_DIARESIS_U 28
#define CHAR_LOWER_BETA 29
#define CHAR_THORN 30
#define CHAR_GRAVE_a 31
#define CHAR_SPACE 32
#define CHAR_EXCLAMATION 33
#define CHAR_QUOTATION 34
#define CHAR_ACUTE_a 35
#define CHAR_CIRCUMFLEX_a 36
#define CHAR_PERCENT 37
#define CHAR_AMPERSAND 38
#define CHAR_APOSTROPHE 39
#define CHAR_OPEN_PARENTHESIS 40
#define CHAR_CLOSE_PARENTHESIS 41
#define CHAR_TILDE 42
#define CHAR_SYMBOL_HEART 43
#define CHAR_COMMA 44
#define CHAR_DASH 45
#define CHAR_PERIOD 46
#define CHAR_SYMBOL_MUSIC_NOTE 47
#define CHAR_ZERO 48
#define CHAR_ONE 49
#define CHAR_TWO 50
#define CHAR_THREE 51
#define CHAR_FOUR 52
#define CHAR_FIVE 53
#define CHAR_SIX 54
#define CHAR_SEVEN 55
#define CHAR_EIGHT 56
#define CHAR_NINE 57
#define CHAR_COLON 58
#define CHAR_SYMBOL_DROPLET 59
#define CHAR_LESS_THAN 60
#define CHAR_EQUALS 61
#define CHAR_GREATER_THAN 62
#define CHAR_QUESTIONMARK 63
#define CHAR_AT_SIGN 64
#define CHAR_A 65
#define CHAR_B 66
#define CHAR_C 67
#define CHAR_D 68
#define CHAR_E 69
#define CHAR_F 70
#define CHAR_G 71
#define CHAR_H 72
#define CHAR_I 73
#define CHAR_J 74
#define CHAR_K 75
#define CHAR_L 76
#define CHAR_M 77
#define CHAR_N 78
#define CHAR_O 79
#define CHAR_P 80
#define CHAR_Q 81
#define CHAR_R 82
#define CHAR_S 83
#define CHAR_T 84
#define CHAR_U 85
#define CHAR_V 86
#define CHAR_W 87
#define CHAR_X 88
#define CHAR_Y 89
#define CHAR_Z 90
#define CHAR_TILDE_a 91
#define CHAR_SYMBOL_ANNOYED 92
#define CHAR_DIARESIS_a 93
#define CHAR_ANGSTROM_a 94
#define CHAR_UNDERSCORE 95
#define CHAR_LOWER_CEDILLA 96
#define CHAR_a 97
#define CHAR_b 98
#define CHAR_c 99
#define CHAR_d 100
#define CHAR_e 101
#define CHAR_f 102
#define CHAR_g 103
#define CHAR_h 104
#define CHAR_i 105
#define CHAR_j 106
#define CHAR_k 107
#define CHAR_l 108
#define CHAR_m 109
#define CHAR_n 110
#define CHAR_o 111
#define CHAR_p 112
#define CHAR_q 113
#define CHAR_r 114
#define CHAR_s 115
#define CHAR_t 116
#define CHAR_u 117
#define CHAR_v 118
#define CHAR_w 119
#define CHAR_x 120
#define CHAR_y 121
#define CHAR_z 122
#define CHAR_GRAVE_e 123
#define CHAR_ACUTE_e 124
#define CHAR_CIRCUMFLEX_e 125
#define CHAR_DIARESIS_e 126
#define CHAR_CONTROL_CODE 127
#define CHAR_MESSAGE_TAG 128
#define CHAR_GRAVE_i 129
#define CHAR_ACUTE_i 130
#define CHAR_CIRCUMFLEX_i 131
#define CHAR_DIARESIS_i 132
#define CHAR_INTERPUNCT 133
#define CHAR_LOWER_ETH 134
#define CHAR_TILDE_n 135
#define CHAR_GRAVE_o 136
#define CHAR_ACUTE_o 137
#define CHAR_CIRCUMFLEX_o 138
#define CHAR_TILDE_o 139
#define CHAR_DIARESIS_o 140
#define CHAR_oe 141
#define CHAR_GRAVE_u 142
#define CHAR_ACUTE_u 143
#define CHAR_HYPHEN 144
#define CHAR_CIRCUMFLEX_u 145
#define CHAR_DIARESIS_u 146
#define CHAR_ACUTE_y 147
#define CHAR_DIARESIS_y 148
#define CHAR_LOWER_THORN 149
#define CHAR_ACUTE_Y 150
#define CHAR_BROKEN_BAR 151
#define CHAR_SILCROW 152
#define CHAR_FEMININE_ORDINAL 153
#define CHAR_MASCULINE_ORDINAL 154
#define CHAR_DOUBLE_VERTICAL_BAR 155
#define CHAR_LATIN_MU 156
#define CHAR_SUPERSCRIPT_THREE 157
#define CHAR_SUPERSCRIPT_TWO 158
#define CHAR_SUPRESCRIPT_ONE 159
#define CHAR_MACRON_SYMBOL 160
#define CHAR_LOGICAL_NEGATION 161
#define CHAR_ASH 162
#define CHAR_LOWER_ASH 163
#define CHAR_INVERT_QUOTATION 164
#define CHAR_GUILLEMET_OPEN 165
#define CHAR_GUILLEMET_CLOSE 166
#define CHAR_SYMBOL_SUN 167
#define CHAR_SYMBOL_CLOUD 168
#define CHAR_SYMBOL_UMBRELLA 169
#define CHAR_SYMBOL_WIND 170
#define CHAR_SYMBOL_SNOWMAN 171
#define CHAR_LINES_CONVERGE_RIGHT 172
#define CHAR_LINES_CONVERGE_LEFT 173
#define CHAR_FORWARD_SLASH 174
#define CHAR_INFINITY 175
#define CHAR_CIRCLE 176
#define CHAR_CROSS 177
#define CHAR_SQUARE 178
#define CHAR_TRIANGLE 179
#define CHAR_PLUS 180
#define CHAR_SYMBOL_LIGTNING 181 // ?? maybe electric also?
#define CHAR_MARS_SYMBOL 182 // aka male symbol
#define CHAR_VENUS_SYMBOL 183 // aka female symbol
#define CHAR_SYMBOL_FLOWER 184
#define CHAR_SYMBOL_STAR 185
#define CHAR_SYMBOL_SKULL 186
#define CHAR_SYMBOL_SURPRISE 187
#define CHAR_SYMBOL_HAPPY 188
#define CHAR_SYMBOL_SAD 189
#define CHAR_SYMBOL_ANGRY 190
#define CHAR_SYMBOL_SMILE 191
#define CHAR_DIMENSION_SIGN 192 // multiplication character
#define CHAR_OBELUS_SIGN 193 // division character
#define CHAR_SYMBOL_HAMMER 194
#define CHAR_SYMBOL_RIBBON 195
#define CHAR_SYMBOL_MAIL 196
#define CHAR_SYMBOL_MONEY 197
#define CHAR_SYMBOL_PAW 198
#define CHAR_SYMBOL_SQUIRREL 199 // might be dog? would make a bit more sense ig
#define CHAR_SYMBOL_CAT 200
#define CHAR_SYMBOL_RABBIT 201
#define CHAR_SYMBOL_OCTOPUS 202 // could also be bird...?
#define CHAR_SYMBOL_COW 203
#define CHAR_SYMBOL_PIG 204
#define CHAR_NEW_LINE 205
#define CHAR_SYMBOL_FISH 206
#define CHAR_SYMBOL_BUG 207
#define CHAR_SEMICOLON 208
#define CHAR_HASHTAG 209
#define CHAR_SPACE_2 210 // Short space
#define CHAR_SPACE_3 211 // Wide space
#define CHAR_SYMBOL_KEY 212
/* Begin EU-only symbols, unused in AC */
#define CHAR_LEFT_QUOTATION 213
#define CHAR_RIGHT_QUOTATION 214
#define CHAR_LEFT_APOSTROPHE 215
#define CHAR_RIGHT_APOSTROPHE 216
#define CHAR_ETHEL 217
#define CHAR_LOWER_ETHEL 218
#define CHAR_ORDINAL_e 219
#define CHAR_ORDINAL_er 220
#define CHAR_ORDINAL_re 221
#define CHAR_BACKSLASH 222
/* Unused characters */
#define CHAR_223 223
#define CHAR_224 224
#define CHAR_225 225
#define CHAR_226 226
#define CHAR_227 227
#define CHAR_228 228
#define CHAR_229 229
#define CHAR_230 230
#define CHAR_231 231
#define CHAR_232 232
#define CHAR_233 233
#define CHAR_234 234
#define CHAR_235 235
#define CHAR_236 236
#define CHAR_237 237
#define CHAR_238 238
#define CHAR_239 239
#define CHAR_240 240
#define CHAR_241 241
#define CHAR_242 242
#define CHAR_243 243
#define CHAR_244 244
#define CHAR_245 245
#define CHAR_246 246
#define CHAR_247 247
#define CHAR_248 248
#define CHAR_249 249
#define CHAR_250 250
#define CHAR_251 251
#define CHAR_252 252
#define CHAR_253 253
#define CHAR_254 254
#define CHAR_255 255

#define TOTAL_CHARS 256

enum {
    mFont_CONT_CODE_BEGIN = 0,
    mFont_CONT_CODE_LAST = mFont_CONT_CODE_BEGIN,
    mFont_CONT_CODE_CONTINUE,
    mFont_CONT_CODE_CLEAR,
    mFont_CONT_CODE_CURSOR_SET_TIME,
    mFont_CONT_CODE_BUTTON,
    mFont_CONT_CODE_COLOR,
    mFont_CONT_CODE_ABLE_CANCEL,
    mFont_CONT_CODE_UNABLE_CANCEL,
    mFont_CONT_CODE_SET_DEMO_ORDER_PLAYER,
    mFont_CONT_CODE_SET_DEMO_ORDER_NPC0,
    mFont_CONT_CODE_SET_DEMO_ORDER_NPC1,
    mFont_CONT_CODE_SET_DEMO_ORDER_NPC2,
    mFont_CONT_CODE_SET_DEMO_ORDER_QUEST,
    mFont_CONT_CODE_SET_SELECT_WINDOW,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_F,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_0,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_1,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_2,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_3,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_2,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_3,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_4,
    mFont_CONT_CODE_SET_SELECT_STRING_2,
    mFont_CONT_CODE_SET_SELECT_STRING_3,
    mFont_CONT_CODE_SET_SELECT_STRING_4,
    mFont_CONT_CODE_SET_FORCE_NEXT,
    mFont_CONT_CODE_PUT_STRING_PLAYER_NAME,
    mFont_CONT_CODE_PUT_STRING_TALK_NAME,
    mFont_CONT_CODE_PUT_STRING_TAIL,
    mFont_CONT_CODE_PUT_STRING_YEAR,
    mFont_CONT_CODE_PUT_STRING_MONTH,
    mFont_CONT_CODE_PUT_STRING_WEEK,
    mFont_CONT_CODE_PUT_STRING_DAY,
    mFont_CONT_CODE_PUT_STRING_HOUR,
    mFont_CONT_CODE_PUT_STRING_MIN,
    mFont_CONT_CODE_PUT_STRING_SEC,
    mFont_CONT_CODE_PUT_STRING_FREE0,
    mFont_CONT_CODE_PUT_STRING_FREE1,
    mFont_CONT_CODE_PUT_STRING_FREE2,
    mFont_CONT_CODE_PUT_STRING_FREE3,
    mFont_CONT_CODE_PUT_STRING_FREE4,
    mFont_CONT_CODE_PUT_STRING_FREE5,
    mFont_CONT_CODE_PUT_STRING_FREE6,
    mFont_CONT_CODE_PUT_STRING_FREE7,
    mFont_CONT_CODE_PUT_STRING_FREE8,
    mFont_CONT_CODE_PUT_STRING_FREE9,
    mFont_CONT_CODE_PUT_STRING_DETERMINATION,
    mFont_CONT_CODE_PUT_STRING_COUNTRY_NAME,
    mFont_CONT_CODE_PUT_STRING_RANDOM_NUMBER_2,
    mFont_CONT_CODE_PUT_STRING_ITEM0,
    mFont_CONT_CODE_PUT_STRING_ITEM1,
    mFont_CONT_CODE_PUT_STRING_ITEM2,
    mFont_CONT_CODE_PUT_STRING_ITEM3,
    mFont_CONT_CODE_PUT_STRING_ITEM4,
    mFont_CONT_CODE_PUT_STRING_FREE10,
    mFont_CONT_CODE_PUT_STRING_FREE11,
    mFont_CONT_CODE_PUT_STRING_FREE12,
    mFont_CONT_CODE_PUT_STRING_FREE13,
    mFont_CONT_CODE_PUT_STRING_FREE14,
    mFont_CONT_CODE_PUT_STRING_FREE15,
    mFont_CONT_CODE_PUT_STRING_FREE16,
    mFont_CONT_CODE_PUT_STRING_FREE17,
    mFont_CONT_CODE_PUT_STRING_FREE18,
    mFont_CONT_CODE_PUT_STRING_FREE19,
    mFont_CONT_CODE_PUT_STRING_MAIL,
    mFont_CONT_CODE_SET_PLAYER_DESTINY0,
    mFont_CONT_CODE_SET_PLAYER_DESTINY1,
    mFont_CONT_CODE_SET_PLAYER_DESTINY2,
    mFont_CONT_CODE_SET_PLAYER_DESTINY3,
    mFont_CONT_CODE_SET_PLAYER_DESTINY4,
    mFont_CONT_CODE_SET_PLAYER_DESTINY5,
    mFont_CONT_CODE_SET_PLAYER_DESTINY6,
    mFont_CONT_CODE_SET_PLAYER_DESTINY7,
    mFont_CONT_CODE_SET_PLAYER_DESTINY8,
    mFont_CONT_CODE_SET_PLAYER_DESTINY9,
    mFont_CONT_CODE_SET_MESSAGE_CONTENTS_NORMAL,
    mFont_CONT_CODE_SET_MESSAGE_CONTENTS_ANGRY,
    mFont_CONT_CODE_SET_MESSAGE_CONTENTS_SAD,
    mFont_CONT_CODE_SET_MESSAGE_CONTENTS_FUN,
    mFont_CONT_CODE_SET_MESSAGE_CONTENTS_SLEEPY,
    mFont_CONT_CODE_SET_COLOR_CHAR,
    mFont_CONT_CODE_SOUND_CUT,
    mFont_CONT_CODE_SET_LINE_OFFSET,
    mFont_CONT_CODE_SET_LINE_TYPE,
    mFont_CONT_CODE_SET_CHAR_SCALE,
    mFont_CONT_CODE_BUTTON2,
    mFont_CONT_CODE_BGM_MAKE,
    mFont_CONT_CODE_BGM_DELETE,
    mFont_CONT_CODE_MSG_TIME_END,
    mFont_CONT_CODE_SOUND_TRG_SYS,
    mFont_CONT_CODE_SET_LINE_SCALE,
    mFont_CONT_CODE_SOUND_NO_PAGE,
    mFont_CONT_CODE_VOICE_TRUE,
    mFont_CONT_CODE_VOICE_FALSE,
    mFont_CONT_CODE_SELECT_NO_B,
    mFont_CONT_CODE_GIVE_OPEN,
    mFont_CONT_CODE_GIVE_CLOSE,
    mFont_CONT_CODE_SET_MESSAGE_CONTENTS_GLOOMY,
    mFont_CONT_CODE_SELECT_NO_B_CLOSE,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_SECTION,
    mFont_CONT_CODE_UNKNOWN_100,
    mFont_CONT_CODE_UNKNOWN_101,
    mFont_CONT_CODE_SET_TEMPORARY_COLOR,
    mFont_CONT_CODE_SPACE,
    mFont_CONT_CODE_MOVE_DOWN,
    mFont_CONT_CODE_RESTORE_CACHED_MESSAGE,
    mFont_CONT_CODE_MALE_FEMALE_CHECK,
    mFont_CONT_CODE_SET_CHOICE_COUNT_2,
    mFont_CONT_CODE_SET_CHOICE_COUNT_3,
    mFont_CONT_CODE_SET_CHOICE_TEXT_0,
    mFont_CONT_CODE_SET_CHOICE_TEXT_1,
    mFont_CONT_CODE_SET_CHOICE_TEXT_2,
    mFont_CONT_CODE_CHECK_CHOICE,
  
    mFont_CONT_CODE_NUM,
    mFont_CONT_CODE_END = 256
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
} Anmhome_c;

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
    /* 0x0020 */ u8 _0020[4];
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


typedef struct GameState {
    u32 unk_000;
    u8 pad_004[0x8];
    u32 rngValue;
    u32 game_time_frames; // time of day represented by number of frames
    u8 pad_014[0x814 - 0x14];
    vu16 unk_814; // thanks jiang
    u16 unk_816;
    u16 keys_held;
    u16 keys_pressed;
    u16 unk_81C;
    u16 unk_81E;
    u16 unk_820;
    u16 unk_822;
    u16 unk_824;
    u16 unk_826;
    u16 unk_828;
    u16 unk_82A;
    u8 pad_82C[0x10];
    u16 unk_83C;
    u16 unk_83E;
    u16 unk_840;
    u16 unk_842;
    u16 unk_844;
    u16 unk_846;
    u16 unk_848;
    u16 bg3_vofs;
    u8 unk_84C;
    u8 unk_84D;
    u8 unk_84E;
    u8 unk_84F;
    u8 unk_850;
    u8 unk_851;
    u8 unk_852;
    u8 unk_853;
    u8 unk_854;
    u8 unk_855;
    u8 unk_856;
    u8 unk_857;
    u8 unk_858;
    u8 unk_859;
    u8 unk_85A;
    u8 unk_85B;
    u8 unk_85C;
    u8 unk_85D;
    u8 unk_85E;
    u8 unk_85F;
    u8 unk_860;
} GameState;

typedef struct Entity {
    int x;
    int y;
    int _08;
    int _0C;
    int _10;
    int _14;
    int _18;
    int _1C;
    int _20;
    int _24;
    u16 item_tile_no[5];
    u16 item[5];
    u16 _3C;
    u16 _3E;
    u16 _40;
    u16 _42;
    u16 _44;
    u16 _46;
    u16 _48;
    u16 _4A;
    u8 item_tile_frame;
    u8 _4D;
    u8 type;
    u8 _4F;
    u8 _50;
    u8 _51;
    u8 _52;
    u8 _53;
} Entity;

typedef struct unk_struct_03000E30 {
    s8 *unk0;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u8 unkE;
    u8 unkF;
    u64 unk10;
    u64 unk18;
} unk_struct_03000E30;

typedef struct unk_struct_03000E50 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u8 pad[0x16];
    u8 unk26;
} unk_struct_03000E50;

enum {
    mMsg_MODE_HIDE = 1,
    mMsg_MODE_APPEAR,
    mMsg_MODE_CURSOR,
    mMsg_MODE_NORMAL,
    mMsg_MODE_CHOICE,
    mMsg_MODE_DISAPPEAR,
    mMsg_MODE_DISAPPEAR_WAIT,
    mMsg_MODE_APPEAR_WAIT,
};

#define mMsg_STATUS_KEEP_OPEN (1 << 1)
#define mMsg_STATUS_END_REACHED (1 << 2)
#define mMsg_STATUS_LAST_DELAY (1 << 8)

typedef struct m_msg_choice_entry_s {
    int line;
    int x;
    u8 text[10];
    u8 length;
    u8 _13[5];
} mMsg_ChoiceEntry_c;

/*
 * Objects allocated by sub_0201C310 for the message UI.  Only the fields
 * touched by the message code are known so far; the allocation is 0x60 bytes.
 */
typedef struct m_msg_sprite_s {
    u32 _00;
    u32 _04;
    u32 _08;
    u32 _0C;
    u8 _10[4];
    s32 _14;
    u8 _18[0x14];
    s32 _2C;
    s32 _30;
    u8 _34[0x23];
    u8 _57;
    u8 _58[8];
} m_msg_sprite_c;

/* Scratch description used while drawing one eight-row message glyph. */
typedef struct mFont_GlyphDraw_s {
    u8* tile_data;
    u16 tile_offset;
    u16 row;
    u16 tile_stride;
    u8 _0A[4];
    u8 palette;
    u8 _0F;
    u8 glyph_lower_rows[8];
    u8 glyph_upper_rows[8];
} mFont_GlyphDraw_c;

typedef struct mFont_ControlCodeInfo_s {
    u8 size;
    u8 _01;
    u8 _02;
    u8 _03;
} mFont_ControlCodeInfo_c;

typedef union mMsg_U32Bytes_u {
    u32 word;
    u8 bytes[4];
} mMsg_U32Bytes_c;

typedef struct mMsg_Window_s {
    mMsg_ChoiceEntry_c choices[3];
    m_msg_sprite_c* choice_cursor;
    m_msg_sprite_c* continue_prompt;
    u8* tile_data;
    u8* text;
    int next_message_id;
    int message_id;
    int text_delay_timer;
    int end_timer;
    u32 status_flags;
    s16 text_offset;
    s16 message_length;
    s8 current_mode;
    s8 requested_mode;
    u8 saved_mode;
    s8 tile_stride;
    s8 text_row;
    u8 text_start_x;
    s8 transition_frame;
    s8 selected_choice;
    u8 text_x;
    u8 force_next;
    u8 lock_continue;
    u8 cancel_continue;
    u8 draw_enabled;
    u8 temporary_color;
    u8 temporary_color_length;
    u8 choice_count;
    u8 choice_index;
    u8 _81[0xA0 - 0x81];
} mMsg_Window_c;

typedef void (*mMsg_Callback)(mMsg_Window_c*);


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


extern u8* g0201B3A4;
extern u8* g0201D3A4;
extern u32 g0203b000;


extern u8* g0201F3A4;
extern u8* g020213A4;
extern u8* g020293a4;

extern u8* g020313A4;
extern u8* g020315A4;
extern u8* g020317a4;
extern u8* g02038000;
extern u8* g02038200;
extern u32* gUnk_30008C0;
extern GameState gGameState;
extern u64 gUnk_30008D0[0x80];
extern unk_struct_03000E30 gUnk_3000E30;
extern unk_struct_03000E50 g03000E50;
void mFont_GetGlyphRows(void* lower_rows, void* upper_rows, u8 character);
int mFont_GetGlyphWidth(u32 character);
int mFont_GetCodeWidth(u32 character);
int mMsg_ProcessControlCode(mMsg_Window_c* msg, s16* offset);
s32 mMsg_CheckChoiceNext(mMsg_Window_c* msg);
s32 mMsg_CheckChoicePrevious(mMsg_Window_c* msg);
void mMsg_UpdateChoiceCursorPosition(mMsg_Window_c* msg);
void mMsg_UpdateChoiceHighlight(mMsg_Window_c* msg);
void mMsg_MainSetup_Choice(mMsg_Window_c* msg);
void mMsg_Main_Choice(mMsg_Window_c* msg);
void mMsg_MainSetup_DisappearWait(mMsg_Window_c* msg);
void mMsg_Main_DisappearWait(mMsg_Window_c* msg);
void mMsg_MainSetup_AppearWait(mMsg_Window_c* msg);
void mMsg_Main_AppearWait(mMsg_Window_c* msg);
void mMsg_CopyTilesToVram(s32 tile, s32 count, u8* tile_data);
s32 mMsg_GetWindowScrollOffset(s8* frame);
s8 mMsg_RequestMode(mMsg_Window_c* msg, s8 mode);
s8 mMsg_RequestDisappear(mMsg_Window_c* msg);
s8 mMsg_RequestAppear(mMsg_Window_c* msg, s32 message_id);
s8 mMsg_RequestCursor(mMsg_Window_c* msg);
s8 mMsg_RequestNormal(mMsg_Window_c* msg);
s8 mMsg_RequestHide(mMsg_Window_c* msg);
s8 mMsg_RequestChoice(mMsg_Window_c* msg);
s8 mMsg_RequestDisappearWait(mMsg_Window_c* msg);
s8 mMsg_RequestAppearWait(mMsg_Window_c* msg);
s8 mMsg_GetMessageBody(u32 index, u8** data, u16* size);
s16 mMsg_GetMessageLength(u8* text);
s8 mFont_CodeSize_get(u8* code);
s16 mMsg_LoadMessage(u8* text, s32 index);
void mMsg_ClearText(mMsg_Window_c* msg);
s32 mMsg_ChangeMsgData(mMsg_Window_c* msg, s32 index);
void mMsg_SetTimer(mMsg_Window_c* msg, s32 frames);
s32 mMsg_TimerDec(mMsg_Window_c* msg);
void mMsg_SetEndTimer(mMsg_Window_c* msg, s32 frames);
s32 mMsg_EndTimerDec(mMsg_Window_c* msg);
void mMsg_DestroySprites(mMsg_Window_c* msg);
s32 mMsg_CheckControlCode(u8* text, u8 type, s16 offset);
s32 mMsg_ProcessText(mMsg_Window_c* msg, u8* tile_data, s32 max_characters);
void mMsg_Init(void);
void mMsg_MainSetup_Window(mMsg_Window_c* msg);
void mMsg_InitWindow(mMsg_Window_c* msg, u8* text, u8* tile_data);
void mMsg_Main_Window(mMsg_Window_c* msg);
s32 mFont_DrawStringToTiles(u8* tile_data, u16* cursor, u32 packed_position,
                            u16 glyph_height, u8* text, s32 length, u8 palette,
                            u8 stop_at_newline, u8 fixed_width);
void mFont_DrawCharToTiles(u8* tile_data, u16 tile_offset, u16 row,
                           u16 tile_stride, u8 character, u8 palette, s32 width);
void sub_020198B8(s8 index);
void sub_02019910(u8 value, s8 index);
void mFont_BlitGlyphToTiles(mFont_GlyphDraw_c* glyph, s32 width);
s16 sub_02019ABC(s16 lhs, s16 rhs);
s16 sub_02019AD8(s16 numerator, s16 denominator);
u16 sub_02019AF0(GameState* state);
void sub_02019B18(GameState* state, u32 seed);
void sub_02019B1C(GameState* state, u16 target, u16 blend_control,
                  u16 intensity);
u16 sub_02019B58(GameState* state, u8 direction, u8 amount);
void sub_02019BA8(u16* palette, u8 x, u8 y, u8* red, u8* green, u8* blue);
void sub_02019BD8(u8 palette, u8 x, u8 y, u8 red, u8 green, u8 blue);
void sub_02019C3C(void);
void sub_02019C88(void);
void sub_02019CC0(void);
void sub_02019CFC(void);
void sub_02019D28(void);
void sub_02019D34(void);
void sub_02019D40(void);
void sub_02019D4C(void);
void sub_02019D58(u16 value);
void sub_02019D68(u16 value);
void sub_02019D78(u16 value);
void sub_02019D88(u16 value);
void sub_02019D98(u16 value);
void mMsg_ReplaceChar(u8* data, u8 from, u8 to, s32 length);
s32 mMsg_TrimTrailingSpaces(u8* data, s32 length);
s32 mMsg_StringsDiffer(u8* lhs, u8* rhs, s32 length);
void mMsg_Copy(u8* src, u8* dest, s32 length);
void mMsg_Fill(u8 value, u8* dest, s32 length);
void sub_02019E88(void);

void sub_0202930C(void* object, void (*callback)(void*));
s32 sub_02029344(s32 numerator, s32 denominator);
void* sub_020295E4(void* dest, void* src, u32 size);
void* sub_02029644(void* dest, s32 value, u32 size);
m_msg_sprite_c* sub_0201C310(u8 type, s32 x, s32 y, s32 param);
void sub_0201C300(m_msg_sprite_c* sprite);
void sub_020269C8(void);
void sub_020269E0(void);
void sub_02026A38(u16 value);
void sub_02026B48(u16 value);
void sub_02026BC8(u16 value);
void sub_02026C10(u16 value);
void sub_02026C68(u16 value);
void sub_02026F0C(void);
void sub_02026F18(void);
void _intr(void);

#endif
