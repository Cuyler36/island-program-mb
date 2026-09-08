#include "m_msg.h"

void mMsg_ReplaceChar(u8 *data, u8 from, u8 to, s32 length) {
    s32 i = 0;

    if (length > 0) {
        for (; i < length; i++) {
            if (data[i] == from) {
                data[i] = to;
            }
        }
    }
}

s32 mMsg_TrimTrailingSpaces(u8 *data, s32 length) {
    s32 trimmed_length;

    trimmed_length = 0;
    if (length > 0) {
        trimmed_length = length;
        while (trimmed_length > 0 && *(data + trimmed_length - 1) == CHAR_SPACE_GBA) {
            trimmed_length--;
        }
    }
    return trimmed_length;
}

s32 mMsg_StringsDiffer(u8 *lhs, u8 *rhs, s32 length) {
    s32 i = 0;

    if (length > 0) {
        for (; i < length; i++) {
            if (lhs[i] != rhs[i]) {
                break;
            }
        }
    }

    return i != length;
}

/* Ghidra name: mMsg_memcpy (differs from the existing contextual name). */
void mMsg_Copy(u8 *src, u8 *dest, s32 length) {
    s32 i;

    if (length > 0) {
        for (i = 0; i < length; i++) {
            dest[i] = src[i];
        }
    }
}

void mMsg_Fill(u8 value, u8 *dest, s32 length) {
    s32 i;

    if (length > 0) {
        for (i = 0; i < length; i++) {
            dest[i] = value;
        }
    }
}
