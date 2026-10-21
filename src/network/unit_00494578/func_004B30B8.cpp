/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Looks up the record for (id, key) in a paged store (inferred from the buffer layout and the handle loop). Builds the query as the id
 * in four big-endian bytes followed by the key, walks the handle forward while the page tag at its data is 1, then asks
 * func_004B27D0 to locate the entry; on a hit it returns a Result built from the id and the entry's data pointer, otherwise an empty
 * Result. The meaning of the store and of the `outCount` value (used as outCount*8 from the end of the page) is not known. */
typedef unsigned char u8;
typedef signed char s8;

struct VEnt {
    short delta;
    short pad;
    int (*fn)(void *);
};
struct VT {
    char pad0[0x10];
    VEnt e10;
    VEnt e18;
};
struct Src {
    VT *vt;
};

extern "C" void *func_005A4724(void *, const void *, unsigned int);

struct Handle {
    Src *src;
    int id;
    u8 *data;
    Handle(Src *s, int id) throw() __asm__("func_004B2388");
    void assign(int id) throw() __asm__("func_004B23F0");
    ~Handle() __asm__("func_004B22D8");
    static void operator delete(void *) __asm__("func_005C1628");
};

extern "C" {
int func_004B2518(Handle *, char *, int) throw();
int func_004B27D0(Handle *, char *, int, unsigned *) throw();

}

struct Result {
    int x[3];
    Result() throw() __asm__("func_004B2A18");
    Result(int, u8 *) throw() __asm__("func_004B2A80");
};

static inline unsigned rd16(const u8 *p)
{
    return p[0] | (p[1] << 8);
}

extern "C" Result func_004B30B8(Src *store, int id, char *key, int keyLength)
{
    char *query = (char *)__builtin_alloca(keyLength + 4);
    int queryLength = keyLength + 4;
    query[0] = id >> 24;
    query[1] = id >> 16;
    query[2] = id >> 8;
    query[3] = id;
    func_005A4724(query + 4, key, keyLength);
    VEnt *idSlot = &store->vt->e18;
    Handle handle(store, idSlot->fn((char *)store + idSlot->delta));
    if (rd16(handle.data) == 1) {
        do {
            handle.assign(func_004B2518(&handle, query, queryLength));
        } while (rd16(handle.data) == 1);
    }
    unsigned outCount = 0;
    if (func_004B27D0(&handle, query, queryLength, &outCount) == 0) {
        return Result();
    } else {
        VEnt *endSlot = &handle.src->vt->e10;
        int pageEnd = endSlot->fn((char *)handle.src + endSlot->delta);
        u8 *pageData = handle.data;
        int entryOffset = pageEnd - outCount * 8;
        entryOffset -= 4;
        struct Bytes { u8 bytes[1]; };
        u8 *entryPtr = &((Bytes *)pageData)->bytes[entryOffset];
        return Result(id, pageData + rd16(entryPtr));
    }
}
