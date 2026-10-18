/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio 2.8.0 (gcc 2000-10-03 snapshot): _IO_getline_info from iogetline.c, placed at 0x00596640
 * by tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */

typedef struct {
    int flags;
    char *read_ptr;
    char *read_end;
} IOFilePrefix;

extern int func_005949A8(IOFilePrefix *);
extern int _IO_sputbackc(IOFilePrefix *, int);
extern void *func_005A4644(const void *, int, unsigned int);
extern void *func_005A4724(void *, const void *, unsigned int);

unsigned int _IO_getline_info(IOFilePrefix *file, char *buffer, unsigned int count,
                           int delimiter, int extract_delimiter, int *eof)
{
    char *cursor = buffer;

    if (eof)
        *eof = 0;

    while (count != 0) {
        long available = file->read_end - file->read_ptr;

        if (available <= 0) {
            int c = func_005949A8(file);

            if (c == -1) {
                if (eof)
                    *eof = c;
                break;
            }
            if (c == delimiter) {
                if (extract_delimiter > 0)
                    *cursor++ = c;
                else if (extract_delimiter < 0)
                    _IO_sputbackc(file, c);
                return cursor - buffer;
            }
            *cursor++ = c;
            count--;
        } else {
            char *match;
            unsigned int old_length;

            if ((unsigned int)available >= count)
                available = count;
            match = (char *)func_005A4644(file->read_ptr, delimiter,
                                          (unsigned int)available);
            if (match != 0) {
                old_length = cursor - buffer;
                available = match - file->read_ptr;
                if (extract_delimiter >= 0) {
                    ++match;
                    if (extract_delimiter > 0)
                        ++available;
                }
                func_005A4724(cursor, file->read_ptr, (unsigned int)available);
                file->read_ptr = match;
                return old_length + (unsigned int)available;
            }

            func_005A4724(cursor, file->read_ptr, (unsigned int)available);
            file->read_ptr += available;
            cursor += available;
            count -= (unsigned int)available;
        }
    }

    return cursor - buffer;
}
