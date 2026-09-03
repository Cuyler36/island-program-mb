/* Source corresponding to libc.a:memcpy.o in pret/agbcc. */

#include <_ansi.h>
#include <stddef.h>
#include <limits.h>

/* Nonzero if either X or Y is not aligned on a long boundary. */
#define UNALIGNED(X, Y) \
    (((long)(X) & (sizeof(long) - 1)) | ((long)(Y) & (sizeof(long) - 1)))

#define BIGBLOCKSIZE (sizeof(long) << 2)
#define LITTLEBLOCKSIZE (sizeof(long))
#define TOO_SMALL(LEN) ((LEN) < BIGBLOCKSIZE)

_PTR
_DEFUN(memcpy, (dst0, src0, len0),
       _PTR dst0 _AND
       _CONST _PTR src0 _AND
       size_t len0)
{
#if defined(PREFER_SIZE_OVER_SPEED) || defined(__OPTIMIZE_SIZE__)
    char* dst = (char*)dst0;
    char* src = (char*)src0;
    _PTR save = dst0;

    while (len0--) {
        *dst++ = *src++;
    }

    return save;
#else
    char* dst = dst0;
    _CONST char* src = src0;
    long* aligned_dst;
    _CONST long* aligned_src;
    int len = len0;

    if (!TOO_SMALL(len) && !UNALIGNED(src, dst)) {
        aligned_dst = (long*)dst;
        aligned_src = (long*)src;

        while (len >= BIGBLOCKSIZE) {
            *aligned_dst++ = *aligned_src++;
            *aligned_dst++ = *aligned_src++;
            *aligned_dst++ = *aligned_src++;
            *aligned_dst++ = *aligned_src++;
            len -= BIGBLOCKSIZE;
        }

        while (len >= LITTLEBLOCKSIZE) {
            *aligned_dst++ = *aligned_src++;
            len -= LITTLEBLOCKSIZE;
        }

        dst = (char*)aligned_dst;
        src = (char*)aligned_src;
    }

    while (len--) {
        *dst++ = *src++;
    }

    return dst0;
#endif
}
