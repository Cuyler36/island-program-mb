/* Source corresponding to libc.a:memset.o in pret/agbcc. */

#include <string.h>

#define LBLOCKSIZE (sizeof(long))
#define UNALIGNED(X) ((long)(X) & (LBLOCKSIZE - 1))
#define TOO_SMALL(LEN) ((LEN) < LBLOCKSIZE)

_PTR
_DEFUN(memset, (m, c, n),
       _PTR m _AND
       int c _AND
       size_t n)
{
#if defined(PREFER_SIZE_OVER_SPEED) || defined(__OPTIMIZE_SIZE__)
    char* s = (char*)m;

    while (n-- != 0) {
        *s++ = (char)c;
    }

    return m;
#else
    char* s = (char*)m;
    int count, i;
    unsigned long buffer;
    unsigned long* aligned_addr;
    unsigned char* unaligned_addr;

    if (!TOO_SMALL(n) && !UNALIGNED(m)) {
        aligned_addr = (unsigned long*)m;

        c &= 0xff;
        if (LBLOCKSIZE == 4) {
            buffer = (c << 8) | c;
            buffer |= buffer << 16;
        } else {
            buffer = 0;
            for (i = 0; i < LBLOCKSIZE; i++) {
                buffer = (buffer << 8) | c;
            }
        }

        while (n >= LBLOCKSIZE * 4) {
            *aligned_addr++ = buffer;
            *aligned_addr++ = buffer;
            *aligned_addr++ = buffer;
            *aligned_addr++ = buffer;
            n -= 4 * LBLOCKSIZE;
        }

        while (n >= LBLOCKSIZE) {
            *aligned_addr++ = buffer;
            n -= LBLOCKSIZE;
        }

        s = (char*)aligned_addr;
    }

    while (n--) {
        *s++ = (char)c;
    }

    return m;
#endif
}
