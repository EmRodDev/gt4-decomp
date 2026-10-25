struct Message;
struct Packet;
struct Record {
    int type;
    struct Message *first, *second;
    int firstValid, secondValid;
    char pad[0x44 - 0x14];
};
struct Owner;
struct Self {
    struct Owner *owner;
    char pad4[0x80];
    struct Record *records;
    char pad88[0xC];
    struct Message **list;
    char pad98[4];
    unsigned short count;
};
int func_00529A78(struct Owner *, struct Message **, unsigned, unsigned short, struct Packet *);

int func_00527510(struct Self *self, struct Record **records, unsigned count, unsigned short flags, struct Packet *packet)
{
    unsigned i;
    int ret;
    if (records != 0) {
        for (i = 0; i < count; i++) {
            if (records[i]->first && records[i]->firstValid)
                self->list[i] = records[i]->first;
            else if (records[i]->second && records[i]->secondValid)
                self->list[i] = records[i]->second;
            else
                self->list[i] = 0;
        }
    } else {
        struct Record *r = self->records;
        count = 0;
        for (i = 0; i < self->count; i++, r++) {
            if (r->type == 3 || r->type == 4) {
                if (r->first && r->firstValid)
                    self->list[count++] = r->first;
                else if (r->second && r->secondValid)
                    self->list[count++] = r->second;
            }
        }
    }
    if (count != 0)
        ret = func_00529A78(self->owner, self->list, count, flags, packet);
    else
        ret = 0xD2F3;
    return ret;
}
