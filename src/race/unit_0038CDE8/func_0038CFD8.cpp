/* compiler: ee-gcc2.96-nogcse */
/* Looks up the model of an owner in the world's record table and caches the answer of a virtual query. It stores
 * newValue in self+4 and clears the result at self+8; then it follows owner+4 (link) to the world to its table at
 * +0x60, walks the table entries (count at table+0, pointer array at table+8) until a record whose owner pointer
 * at +0x18 equals owner, and, if that record has a model at +0x2880, calls virtual slot 10 of the model (8-byte
 * entries with a this-adjustment, so offset 0x50 into the table at model+8) and stores its int result in self+8.
 * Any missing link along the way leaves the result 0.  It is compiled with the no-gcse compiler variant named in the marker. */
struct VEnt { short delta,index; int (*fn)(void *); };
struct Model { char pad[8]; VEnt *vt; };
struct Owner;
struct Rec { char pad[0x18]; Owner *owner; char p1c[0x2880-0x1c]; Model *model; };
struct Table { int n; int unk4; Rec **entries; };
struct World { char pad[0x60]; Table *table; };
struct Link { World *world; };
struct Owner { int unk0; Link *link; };
struct Self { int unk0; int value; int result; };
extern "C" void func_0038CFD8(Self *self,Owner *owner,int newValue) {
    self->value=newValue;
    self->result=0;
    Link *link=(Link *)((int *)owner)[1];
    if(link) {
        World *world=link->world;
        if(world) {
            Table *table=world->table;
            if(table) {
                int count=table->n;
                int i=0;
                if(i<count) do {
                    Rec *rec=table->entries[i++];
                    if(rec->owner==owner) {
                        Model *model=rec->model;
                        if(model) {
                            VEnt *slot=model->vt+10;
                            self->result=slot->fn((char *)model+slot->delta);
                            return;
                        }
                    }
                } while(i<count);
            }
        }
    }
}
