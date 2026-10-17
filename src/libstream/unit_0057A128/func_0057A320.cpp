/* compiler: ee-gcc2.96-no-strict-aliasing */

typedef struct Obj Obj;
typedef unsigned char u8;
typedef int s32;
struct Obj
{
  u8 *base;
  s32 pad4;
  s32 pad8;
  u8 *table;
};
extern s32 func_0057A2B8(s32 key, u8 *entry);
extern s32 func_0057AB48(struct Obj *o);
inline static s32 rd16(const u8 *p)
{
  return p[0] | (p[1] << 8);
}

inline static s32 rd32(const u8 *p)
{
  return ((p[0] | (p[1] << 8)) | (p[2] << 16)) | (p[3] << 24);
}

extern s32 func_0057A320(struct Obj *o, s32 key, s32 *found)
{
  u8 *t;
  *found = 0;
  t = o->table;
  if (!t)
  {
    return 0;
  }
  const u8 *hdr = t + 8;
  s32 i = 0;
  const u8 *first = hdr + 2;
  s32 count = rd16(hdr);
  if (count)
  {
    const u8 *e = first;
    do
    {
      s32 off = rd32(e);
      e += 4;
      if (func_0057A2B8(key, o->base + off) == 0)
      {
        u8 *r = o->base + off;
        s32 v = rd32(r - 5);
        if (r[-1])
        {
          v += func_0057AB48(o);
        }
        *found = 1;
        return v;
      }
      i++;
    }
    while (i < count);
  }
  return 0;
}
