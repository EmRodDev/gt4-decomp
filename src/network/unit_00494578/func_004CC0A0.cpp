/* compiler: ee-gcc2.96-nsa-as2004 */
typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct __attribute__((packed)) U32 {
    u32 v;
};
struct Fs {
    char pad[4];
    void *unk4;
};
struct Dent {
    char pad[0xB];
    u8 attr;
    char padC[0x1C - 0xC];
    U32 u1C;
};
struct Out {
    s32 unk0;
    u16 *unk4;
    Dent *unk8;
    s32 unkC;
    u32 unk10;
    char blk14[16];
};

extern "C" {
void func_004CA938(void *, void *) throw();
void func_004CB1F0(void *, void *) throw();
void func_004CB490(void *) throw();
s32 func_004CB558(void *) throw();
s32 func_004CBA30(Fs *, s32, s32, void *) throw();
s32 func_004CBCF0(Fs *, s32, void *, u16 **, Dent **) throw();
s32 func_004CBE08(Fs *, s32, u16 **, Dent **) throw();
s32 func_004CBFC0(Fs *, char *, void *) throw();
void *memset(void *, int, unsigned int);
}

extern "C" s32 func_004CC0A0(Fs *fs, Out *o, char *path, u32 flags)
{
    u16 *sp0;
    Dent *sp4;
    char sp10[0x10];
    s32 err = 0;
    s32 idx;
    s32 r;
    s32 v;

    idx = func_004CBFC0(fs, path, sp10);
    if (idx < 0) {
        return idx;
    }
    r = func_004CBCF0(fs, idx, sp10, &sp0, &sp4);
    if (r >= 0) {
        if ((flags & 0xA00) == 0xA00) {
            err = -0x11;
        } else {
            u8 at = sp4->attr;
            if (at & 0x10) {
                err = -0x15;
            } else {
                u8 ro = at & 1;
                if (ro) {
                    err = (flags & 0x403) ? -0xD : 0;
                }
            }
        }
        if (err != 0) {
            func_004CA938(fs->unk4, sp0);
            return err;
        }
    } else if (r == -2 && (flags & 0x200) != 0) {
        v = func_004CB558(sp10);
        if (v < 0) {
            return v;
        }
        v = func_004CBE08(fs, idx, &sp0, &sp4);
        if (v < 0) {
            return v;
        }
        memset(sp4, 0, sizeof(Dent));
        func_004CB1F0(sp4, sp10);
        sp4->attr = 0x20;
        func_004CB490(sp4);
        r = 0;
        *sp0 |= 1;
        o->unk0 = 1;
    } else {
        return r;
    }
    o->unk4 = sp0;
    o->unkC = r;
    o->unk8 = sp4;
    o->unk10 = (flags & 8) ? sp4->u1C.v : 0;
    return func_004CBA30(fs, o->unkC, o->unk10, o->blk14);
}
