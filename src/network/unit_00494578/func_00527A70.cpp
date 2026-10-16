struct Record { char data[0x44]; };
struct Self { char pad[0x84]; Record *records; };
struct Segment { void *data; int size; };
struct Message { unsigned short type,a,b; };
struct Packet {
 Segment segments[8]; int total,count; char pad[8]; Message message;
 void init() { count=0; total=0; }
 void add(void *data) { segments[count].data=data; segments[count].size=6; total+=6; ++count; }
};
extern "C" int func_00525648(int,int) throw() __attribute__((const));
extern "C" int func_00523DA8(Self *,unsigned short *) throw();
extern "C" int func_00527488(Self *,Record *,unsigned short,Packet *) throw();
extern "C" void func_00527A70(Self *self,unsigned short a,unsigned short b) {
 Packet packet;
 unsigned short index;
 packet.message.type=func_00525648(13,6);
 packet.message.a=a;
 packet.message.b=b;
 func_00523DA8(self,&index);
 Record *record = &self->records[index];
 packet.init();
 packet.add(&packet.message);
 func_00527488(self,record,0xF000,&packet);
}
