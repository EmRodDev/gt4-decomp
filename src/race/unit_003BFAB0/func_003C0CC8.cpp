/* Picks entry number 'index' from the table in the sub-object, prepares it with param (func_003B6A30), then combines its record
 * (at entry+0x119C) with the shared record at self+0x928 through func_003BB958 and returns that result. With copyBack set the
 * entry record is also copied over the shared one (func_003BB8C8). The record type is unknown (empty struct in the source). */

typedef int s32;
struct Obj003BB958
{
  char pad0[4];
};
struct Sub003C0CC8
{
  char pad0[8];
  s32 *tbl;
};
struct Ctx003C0CC8
{
  char pad0[0x60];
  struct Sub003C0CC8 *sub;
};
extern s32 func_003B6A30(s32 self, s32 index, s32 param);
extern s32 func_003BB8C8(struct Obj003BB958 *dst, const struct Obj003BB958 *src);
extern s32 func_003BB958(struct Obj003BB958 *self, struct Obj003BB958 *index);
inline int inline_fn(s32 self)
{
  return self != 0;
}

extern s32 func_003C0CC8(struct Ctx003C0CC8 *self, s32 index, s32 param, s32 copyBack)
{
  struct Sub003C0CC8 *sub;
  struct Obj003BB958 *sharedRecord;
  s32 entry;
  s32 entryRecord;
  s32 result;
  sub = self->sub;
  sharedRecord = (struct Obj003BB958 *) (((char *) self) + 0x928);
  entry = *((s32 *) (((char *) sub->tbl) + (index * 4)));
  func_003B6A30(entry, param, 1);
  entryRecord = entry + 0x119C;
  result = func_003BB958((struct Obj003BB958 *) entryRecord, sharedRecord);
  if (inline_fn(copyBack))
  {
    func_003BB8C8(sharedRecord, (const struct Obj003BB958 *) entryRecord);
  }
  return result;
}
