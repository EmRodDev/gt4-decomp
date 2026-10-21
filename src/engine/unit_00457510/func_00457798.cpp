/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Computes a start/end pair of V coordinates along a course (names from GT4Course::RunwayData::getVCoord). The field at +0x0C
 * becomes 0.0 when 'flag' is set and 1.0 otherwise; +0x1C and +0x2C are cleared. With the flag set, the V coordinate of the two
 * entries at +0x10 and +0x20 is looked up; if both are non-zero they are stored at +0x1C and +0x2C, swapped when they straddle the
 * course-length wrap (their distance is larger than half of the length at +0x14 of the course; inferred from that comparison).
 * 'dead' is a throw-away local that only exists to match the stack layout. */
struct Pair { short a, b; };
struct W { char pad[0x2C]; Pair p; };
struct R { int ok; float v; };
struct Obj { char pad[0xC]; float f0C; char pad2[0xC]; float f1C; char pad3[0xC]; float f2C; };
struct Cs { char pad[0x14]; float f14; };
extern "C" float GT4Course__RunwayData__getVCoord(Cs *, void *, Pair *);
extern "C" void func_00457798(Obj *self, Cs *course, int flag)
{
    if (flag)
        self->f0C = 0.0f;
    else
        self->f0C = 1.0f;
    self->f1C = 0.0f;
    self->f2C = 0.0f;
    if (flag) {
        float zero = self->f1C;
        W dead;
        R coord[2];
        Pair q;
        dead.p.a = -1;
        dead.p.b = -1;
        int i = 0;
        for (; i < 2; i++) {
            Pair *pq = &q;
            void *entry = (char *)self + 0x10 + i*0x10;
            pq->a = -1;
            q.b = -1;
            float v = GT4Course__RunwayData__getVCoord(course, entry, pq);
            coord[i].ok = v != zero;
            coord[i].v = v;
        }
        if (coord[0].ok && coord[1].ok) {
            float first = coord[0].v;
            float second = coord[1].v;
            if ((second < first && (first - second) < course->f14 * 0.5f) || (first < second && course->f14 * 0.5f < (second - first))) {
                float swap = first;
                first = second;
                second = swap;
            }
            self->f1C = first;
            self->f2C = second;
        }
    }
}
