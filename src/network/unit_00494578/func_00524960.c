struct Entry {
    void *data;
    int size;
};

struct Packet {
    struct Entry e[8];
    int size;
    int count;
};

struct Message;

struct Record {
    int type;
    struct Message *first, *second;
    int firstValid, secondValid;
    int active;
    int special;
    char pad[0x44 - 0x1C];
};

struct Owner;

struct Self {
    struct Owner *owner;
    char pad4[0x80];
    struct Record *records;
    char pad88[0x8];
    struct Record **selected;
    char pad94[0x8];
    unsigned short count;
    char pad9E[0x16];
    int special;
};

unsigned short func_00525648(int, unsigned short);
int func_00527488(struct Self *, struct Record *, unsigned short, struct Packet *);
int func_00527510(struct Self *, struct Record **, unsigned, unsigned short, struct Packet *);
int func_00529FD0(struct Owner *, unsigned short, struct Packet *);

static inline void pop(struct Packet *p)
{
    p->count--;
    p->size -= p->e[p->count].size;
}

int func_00524960(struct Self *self, unsigned short index, unsigned short flags, struct Packet *packet)
{
    int result = 0;
    unsigned count = 0;
    int special = 0;
    unsigned short header;
    struct Record *r;

    if (!self) return 2;
    flags |= 0x8000;
    header = func_00525648(10, (unsigned short)(packet->size + 2));
    if (packet->count < 8) {
        int n = packet->count;
        packet->e[n].data = &header;
        packet->e[n].size = 2;
        packet->size += 2;
        packet->count++;
    }
    if (index == 0xFFFF) {
        unsigned short i = 0;
        r = self->records;
        if (self->count) {
            struct Record **out = self->selected;
            do {
                if (r->active) {
                    if (r->special && !(flags & 0x4000) && self->special)
                        special = 1;
                    else if (r->type == 3 || r->type == 4) {
                        *out++ = r;
                        count++;
                    }
                }
                i++;
                r++;
            } while (i < self->count);
        }
        result = func_00527510(self, self->selected, count, flags, packet);
        if (result != 0 && result != 0xD2F3) return result;
        result = 0;
        if (special) {
            result = func_00529FD0(self->owner, flags, packet);
            if (result != 0) return result;
        }
    } else {
        if (index >= self->count) return 0xD4E6;
        r = &self->records[index];
        if (r->type == 3 || r->type == 4)
            result = func_00527488(self, r, flags, packet);
    }
    pop(packet);
    return result;
}
