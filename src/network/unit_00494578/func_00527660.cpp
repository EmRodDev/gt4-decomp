struct Self { char pad0[0x84]; char *records; char pad88[0x14]; unsigned short count; char pad9e[0x12]; unsigned char b0; };
struct Payload { unsigned short command; unsigned char byte; };
struct Entry { void *ptr; int size; };
struct Packet {
    Entry entries[8]; int size, count;
    Packet() { count=0; size=0; }
    void add(void * const p, const int n) {
        entries[count].ptr=p;
        entries[count].size=n;
        size = size+n;
        count = count+1;
    }
};
extern "C" int func_00525648(int,int) throw() __attribute__((const));
extern "C" int func_00527488(Self *,void *,unsigned short,Packet *) throw();
extern "C" int func_00527660(Self *self,unsigned short index) {
    if (index >= self->count) return 0xD4E6;
    Payload data;
    data.command=func_00525648(2,4);
    Packet packet;
    data.byte=self->b0;
    packet.add(&data,4);
    return func_00527488(self,self->records+index*0x44,0xF000,&packet);
}
