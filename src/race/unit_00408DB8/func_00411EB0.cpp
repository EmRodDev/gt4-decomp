/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Computes a 2D position for gear `gear` in a gate layout selected by shifterKind. Kind 4 gives (0, +-1) by the sign of the gear; kind 1 maps the
 * gear (capped at a3, with a1 and a2 shifting or replacing the index, roles not known) to a column ((n - 1) / 2 - 1) * 0.5 and a row of
 * +1 or -1 by parity, i.e. odd and even gears sit on opposite sides of a column, which is the H-pattern shift gate (inferred); kinds 2, 3 and
 * the rest give (0, 0). Used by the shift animation 00412018, where the same kind values 1 and 4 are tested. */
typedef int s32;
typedef float f32;

extern "C" void func_00411EB0(s32 shifterKind, s32 a1, s32 a2, s32 a3, s32 gear, f32 *outAcross, f32 *outAlong) {
    switch (shifterKind) {
    case 4:
        *outAcross = 0.0f;
        if (gear > 0) {
            *outAlong = -1.0f;
        } else {
            *outAlong = 1.0f;
        }
        return;
    case 1:
        if (gear >= a3) {
            gear = a3;
        }
        if (gear <= 0) {
            gear = a2;
        } else {
            gear = gear + a1 - 1;
        }
        if (gear > 0) {
            *outAcross = (f32)((gear - 1) / 2 - 1) * 0.5f;
            if ((gear & 1) == 0) {
                *outAlong = -1.0f;
            } else {
                *outAlong = 1.0f;
            }
        } else {
            *outAcross = (f32)(gear / 2 - 2) * 0.5f;
            if ((gear & 1) == 0) {
                *outAlong = -1.0f;
            } else {
                *outAlong = 1.0f;
            }
        }
        return;
    case 2:
    case 3:
    default:
        *outAcross = 0.0f;
        *outAlong = 0.0f;
        return;
    }
}
