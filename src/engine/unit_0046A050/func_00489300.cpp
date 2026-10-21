/* Transforms the 3D vector v by the 3x3 matrix m (columns at m[0..2], m[3..5], m[6..8]) into out; same as func_004893E8 but
 * without translation. */

typedef float f32;
inline const f32 inline_fn(const f32 *arg0)
{
  return arg0[0];
}

extern void func_00489300(f32 *out, const f32 *m, const f32 *v)
{
  int k = 4;
  int k2 = 8;
  f32 *o1 = (f32 *) (((char *) out) + k);
  f32 *o2 = (f32 *) (((char *) out) + k2);
  const f32 *vz = (const f32 *) (((const char *) v) + k2);
  const f32 *vy = (const f32 *) (((const char *) v) + k);
  out[0] = ((inline_fn(m) * inline_fn(v)) + (m[3] * inline_fn(vy))) + (m[6] * inline_fn(vz));
  o1[0] = ((m[1] * inline_fn(v)) + (m[4] * inline_fn(vy))) + (m[7] * inline_fn(vz));
  o2[0] = ((m[2] * inline_fn(v)) + (m[5] * inline_fn(vy))) + (m[8] * inline_fn(vz));
}
