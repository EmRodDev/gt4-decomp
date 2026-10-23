/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Seconds since an epoch (64-bit, shifted by half a day) -> calendar date and time of day. */
struct D4 { short year; unsigned char month, day; };
struct T4 { unsigned char hour, min, sec, spare; };
struct DT { D4 d; T4 t; };
extern "C" D4 func_00579898(int days);
extern "C" T4 func_00579AA0(int seconds);

extern "C" DT *func_00579BD8(DT *out, long t)
{
    DT r;
    t += 43200;
    int days = t / 86400;
    int seconds = t % 86400;
    r.d = func_00579898(days);
    r.t = func_00579AA0(seconds);
    *out = r;
    return out;
}
