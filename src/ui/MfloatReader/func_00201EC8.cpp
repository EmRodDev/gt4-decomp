/* Initialises a record with defaults: floats 50.0 (+0x4), 0.1 (+0x8, written in hex form), 32.0 (+0xC) and 4.0 (+0x18); every other field is cleared.
 * The store order (0x24 first, then 0, 0x10, 0x14, 0x1C, 0x20) is the original's, and the empty do-while keeps the scheduling the compiler produced. Meaning of the fields is unknown. */

typedef int s32;
typedef float f32;
struct func_00201EC8_arg0
{
  s32 unk0;
  f32 unk4;
  f32 unk8;
  f32 unkC;
  s32 unk10;
  s32 unk14;
  f32 unk18;
  s32 unk1C;
  s32 unk20;
  s32 unk24;
};
extern void func_00201EC8(struct func_00201EC8_arg0 *reader)
{
  reader->unk4 = 50.0f;
  reader->unk8 = 0x1.9999980000000p-4f;
  reader->unkC = 32.0f;
  reader->unk18 = 4.0f;
  reader->unk24 = 0;
  reader->unk0 = 0;
  reader->unk10 = 0;
  reader->unk14 = 0;
  reader->unk1C = 0;
 do { } while (0);
  reader->unk20 = 0;
}
