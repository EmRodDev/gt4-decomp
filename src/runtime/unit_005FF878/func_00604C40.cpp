/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_00688780[];
struct Inner { int word; Inner() {} };
struct Blank { Inner inner; char pad[0x48]; };
struct Row { float x,y,z; Row() { x=0.0f; y=1.0f; z=0.0f; } };
struct Group { char pad[12]; Blank blanks[4]; Row rows[4]; };
struct Base { void *vt; Base() { vt=D_00688780; } };
struct Obj : Base { Group groups[2]; int field2dc, field2e0; Obj() __asm__("func_00604C40"); };
Obj::Obj() { field2dc=0; field2e0=0; }
