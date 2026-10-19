/* compiler: ee-gcc2.96-no-strict-aliasing */
/* The slice loop of the MPEG video decoder, modelled on the MPEG Software
   Simulation Group's mpeg2decode slice() (getpic.c), with the block decoding
   done by the IPU into scratchpad memory. */

/* Per-macroblock prediction state shared with the motion vector and
   prediction helpers. */
struct MacroblockState {
    int unknown00[3];
    int motion_type;                     /* 0x0C */
    int stwtype;                         /* 0x10 */
    int unknown14[7];
    int PMV[2][2][2];                    /* 0x30 */
    int motion_vertical_field_select[2][2]; /* 0x50 */
};

/* Parameters handed to the IPU block decoder. */
struct BlockRequest {
    unsigned char *blocks;               /* 0x00 */
    int macroblock_type;                 /* 0x04 */
    int picture_coding_type;             /* 0x08 */
    int coded_block_pattern;             /* 0x0C */
    int quantizer_scale;                 /* 0x10 */
    int unknown14[4];
    int reset_dc_predictors;             /* 0x24 */
};

#define SCRATCHPAD ((unsigned char *)0x70000000)
#define MACROBLOCK_INTRA 1
#define MACROBLOCK_MOTION_BACKWARD 4
#define MACROBLOCK_MOTION_FORWARD 8
#define MACROBLOCK_QUANT 0x10
#define I_TYPE 1
#define P_TYPE 2
#define D_TYPE 4
#define BOTTOM_FIELD 2
#define FRAME_PICTURE 3
#define MC_FIELD 1
#define MC_FRAME 2

extern int D_00654D7C;                   /* current frame buffer */
extern int D_00654D80;                   /* mb_width */
extern int D_00654D84;                   /* mb_height */
extern int D_00654DA0;                   /* picture_coding_type */
extern int D_00654DA8[2][2];             /* f_code */
extern int D_00654DB8;                   /* picture_structure */
extern BlockRequest D_00654DC8;

extern "C" int func_00564558(int *MBA, int *MBAinc);
extern "C" unsigned func_00563198(int bits);
extern "C" int func_00568568(void);
extern "C" void func_00564368(int *macroblock_type, int *coded_block_pattern, MacroblockState *mb);
extern "C" int func_00563158(int bits);
extern "C" int func_005686B0(MacroblockState *mb, int s, int h_r_size, int v_r_size);
extern "C" int func_00568248(BlockRequest *request);
extern "C" void func_00563258(unsigned bits);
extern "C" int func_00568940(MacroblockState *mb, int macroblock_type, int bx, int by);
extern "C" void func_00563E10(int dest, unsigned char *blocks, int add);
extern "C" void *func_005A48D8(void *, int, unsigned int);

/* Decodes the macroblocks of one slice; returns -1 when MBAmax macroblocks
   are done, 0 at the next start code and other values on errors. */
extern "C" int func_00563F98(int MBAmax)
{
    MacroblockState mb;
    int MBA;
    int MBAinc;
    int macroblock_type;
    int coded_block_pattern;
    unsigned char *blocks;
    int ret;

    MBA = 0;
    MBAinc = 0;
    ret = func_00564558(&MBA, &MBAinc);
    blocks = SCRATCHPAD;
    blocks = SCRATCHPAD + 0x780;
    if (ret != 1)
        return ret;

    D_00654DC8.reset_dc_predictors = ret;
    mb.PMV[0][1][0] = mb.PMV[0][1][1] = mb.PMV[1][1][0] = mb.PMV[1][1][1] = 0;
    mb.PMV[0][0][0] = mb.PMV[0][0][1] = mb.PMV[1][0][0] = mb.PMV[1][0][1] = 0;

    while (MBA < MBAmax) {
        if (MBAinc == 0) {
            if (!func_00563198(23))
                return 0;
            MBAinc = func_00568568();
        }

        if (MBAinc == 1) {
            func_00564368(&macroblock_type, &coded_block_pattern, &mb);
            mb.stwtype = 0;
            if (macroblock_type & MACROBLOCK_QUANT)
                D_00654DC8.quantizer_scale = func_00563158(5);
            if (macroblock_type & MACROBLOCK_MOTION_FORWARD) {
                ret = func_005686B0(&mb, 0, D_00654DA8[0][0] - 1, D_00654DA8[0][1] - 1);
                if (ret != 0)
                    return ret;
            }
            if (macroblock_type & MACROBLOCK_MOTION_BACKWARD) {
                ret = func_005686B0(&mb, 1, D_00654DA8[1][0] - 1, D_00654DA8[1][1] - 1);
                if (ret != 0)
                    return ret;
            }
            func_005A48D8(SCRATCHPAD + 0x780, 0, 0x300);
            D_00654DC8.picture_coding_type = D_00654DA0;
            D_00654DC8.macroblock_type = macroblock_type;
            D_00654DC8.coded_block_pattern = coded_block_pattern;
            D_00654DC8.blocks = blocks;
            if (func_00568248(&D_00654DC8) == 3)
                return 0;
            D_00654DC8.reset_dc_predictors = 0;
            if (D_00654DA0 == D_TYPE)
                func_00563258(1);
            if ((macroblock_type & MACROBLOCK_INTRA) == 0) {
                D_00654DC8.reset_dc_predictors = 1;
            } else {
                mb.PMV[0][1][0] = mb.PMV[0][1][1] = mb.PMV[1][1][0] = mb.PMV[1][1][1] = 0;
                mb.PMV[0][0][0] = mb.PMV[0][0][1] = mb.PMV[1][0][0] = mb.PMV[1][0][1] = 0;
            }
            if (D_00654DA0 == P_TYPE
                && !(macroblock_type & (MACROBLOCK_MOTION_FORWARD | MACROBLOCK_INTRA))) {
                mb.PMV[0][0][0] = mb.PMV[0][0][1] = mb.PMV[1][0][0] = mb.PMV[1][0][1] = 0;
                if (D_00654DB8 == FRAME_PICTURE) {
                    mb.motion_type = MC_FRAME;
                } else {
                    mb.motion_type = MC_FIELD;
                    mb.motion_vertical_field_select[0][0] = (D_00654DB8 == BOTTOM_FIELD);
                }
            }
        } else {
            /* skipped macroblock */
            func_005A48D8(SCRATCHPAD + 0x780, 0, 0x300);
            D_00654DC8.reset_dc_predictors = 1;
            if (D_00654DA0 == P_TYPE)
                mb.PMV[0][0][0] = mb.PMV[0][0][1] = mb.PMV[1][0][0] = mb.PMV[1][0][1] = 0;
            if (D_00654DB8 == FRAME_PICTURE) {
                mb.motion_type = MC_FRAME;
            } else {
                mb.motion_type = MC_FIELD;
                mb.motion_vertical_field_select[0][0] = mb.motion_vertical_field_select[0][1] =
                    (D_00654DB8 == BOTTOM_FIELD);
            }
            if (D_00654DA0 == I_TYPE)
                mb.stwtype = 8;
            macroblock_type &= ~MACROBLOCK_INTRA;
        }

        int bx = MBA % D_00654D80;
        int by = MBA / D_00654D80;
        int add = !(macroblock_type & MACROBLOCK_INTRA);        if (add)
            func_00568940(&mb, macroblock_type, bx, by);
        func_00563E10(D_00654D7C + (bx * D_00654D84 + by) * 0x180, SCRATCHPAD + 0x780, add);
        MBA++;
        MBAinc--;
    }
    return -1;
}
