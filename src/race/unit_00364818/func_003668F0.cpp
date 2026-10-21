/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Hands each tire slot's ground position to func_003667A8 together with a reordered vector (inferred: x, z, -y of the
 * three floats at +0x648, a coordinate-axis swap). The position is the slot's x/z (+0x0C/+0x10) shifted by the car offset at +0x104, with
 * the +0x8C value as height and z negated. When the object byte at +0x32 is 6 only the two slot pairs from the table func_00359510 returns are
 * used, each pair collapsing to the average position of its two slots and the call made for the one whose value at +0x7CC is larger
 * (meaning of 6 and of that value unknown); otherwise every slot is handed over separately. */
typedef unsigned char u8;
typedef float f32;

struct Obj { char pad0[0x32]; u8 b32; };
struct Pr {
    char pad0;
    u8 n;
    char pad2[0xA];
    u8 a[2];
    char pad0E[0x16];
    u8 c[2];
};
struct Slot {
    char pad0[0xC];
    f32 fC;
    f32 f10;
    char pad14[0x78];
    f32 f8C;
    char pad90[0x5C];
};
struct Q { f32 f[13]; };
struct Win { f32 x, y; };
struct Car {
    char pad0[0x10];
    Obj *obj;
    char pad14[0xF0];
    Win win;
    char pad10C[0x58];
    Slot slots[1];
};
struct Vec3 { f32 x, y, z; };

extern "C" Pr *func_00359510(Obj *);
extern "C" void func_003667A8(Car *, int, Vec3 *, Vec3 *) throw();

extern "C" void func_003668F0(Car *self) {
    Win *carOffset = &self->win;
    Obj *carObject = self->obj;
    Pr *slotTable = func_00359510(carObject);
    f32 *vec648 = (f32 *)((char *)self + 0x648);
    Vec3 axisSwapped;
    Vec3 position;
    axisSwapped.x = vec648[0];
    axisSwapped.y = vec648[2];
    axisSwapped.z = -vec648[1];
    int i;
    if (carObject->b32 == 6) {
        i = 0;
        u8 *pairStarts = slotTable->a;
        for (; i < 2;) {
            u8 firstSlot = pairStarts[i++];
            u8 partnerIndex = slotTable->c[firstSlot];
            u8 slotIndex = firstSlot;
            char *recordA = (char *)self + slotIndex * 0x34;
            char *recordB = (char *)self + partnerIndex * 0x34;
            if (*(float *)(recordA + 0x7CC) < *(float *)(recordB + 0x7CC)) {
                slotIndex = partnerIndex;
                partnerIndex = firstSlot;
            }
            Slot *slotA = &self->slots[slotIndex];
            Slot *slotB = &self->slots[partnerIndex];
            position.x = carOffset->x + (slotA->fC + slotB->fC) * 0.5f;
            position.y = (slotA->f8C + slotB->f8C) * 0.5f;
            position.z = -(carOffset->y + (slotA->f10 + slotB->f10) * 0.5f);
            func_003667A8(self, slotIndex, &position, &axisSwapped);
        }
    } else {
        for (i = 0; i < slotTable->n; i++) {
            Slot *slot = &self->slots[i];
            position.x = carOffset->x + slot->fC;
            position.y = slot->f8C;
            position.z = -(carOffset->y + slot->f10);
            func_003667A8(self, i, &position, &axisSwapped);
        }
    }
}
