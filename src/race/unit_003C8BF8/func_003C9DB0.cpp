/* Point-in-polygon test with the even-odd crossing rule: polygon[0] is the vertex count followed by (x, y) float pairs, and the
 * function returns 1 when the point lies inside. Each edge is oriented bottom to top, then the cross product decides whether a
 * ray from the point crosses it. */

typedef int s32;
typedef float f32;
struct func_003C9DB0_pt
{
  f32 x;
  f32 y;
};
extern s32 func_003C9DB0(s32 *polygon, struct func_003C9DB0_pt *point)
{
  s32 vertexCount = polygon[0];
  struct func_003C9DB0_pt *p;
  struct func_003C9DB0_pt *q;
  struct func_003C9DB0_pt *hi;
  s32 inside = 0;
  f32 *new_var;
  s32 remaining;
  q = (struct func_003C9DB0_pt *) (((char *) polygon) + 4);
  p = (struct func_003C9DB0_pt *) ((((char *) polygon) + (vertexCount * 8)) - 4);
  if (vertexCount > 0)
  {
    remaining = vertexCount;
    do
    {
      if ((*(new_var = &p->y)) != q->y)
      {
        hi = q;
        if (!(p->y < q->y))
        {
          hi = p;
          p = q;
        }
        if (p->y <= point->y)
        {
          if (point->y < hi->y)
          {
            f32 cross = ((point->x - p->x) * (hi->y - p->y)) - ((point->y - p->y) * (hi->x - p->x));
            if (0.0f < cross)
            {
              inside ^= 1;
            }
          }
        }
      }
      remaining--;
      p = q;
      q++;
    }
    while (remaining != 0);
  }
  return inside;
}
