/* Shows the A-spec race result on the HUD. When the virtual at vtable +0x150 is nonzero and both resource texts (D_006A0558, D_006A0568)
 * exist, the organization's score for the player's slot (byte at +0x2F) is formatted into scoreText with the second text as format string
 * (0057DA20 behaves like sprintf, inferred from its use), and two RaceMessageDisplay blocks (+0x267C label, +0x27CC score) are set up
 * with a font, a colour word at +0x20 (0x80C8C8C8 for the label, 0x800086E6 for the score; they look like ARGB values, inferred),
 * the same values 0.1 and 0.3 at +0x18 / +0x1C (probably position, not confirmed) and a message with 2.7 and 1.0. The hex float
 * literals are what matched. */
#include "types.h"

struct VEntryR {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

static inline s32 vcall150(char *o) {
    VEntryR *e = (VEntryR *)(*(char **)o + 0x150);
    return e->fn(o + e->delta);
}

extern char D_006A0540[];
extern char D_006A0548[];
extern char D_006A0558[];
extern char D_006A0568[];

extern "C" s32 DisplayRText__getRTextStr(s32 arg0);
extern "C" s32 RaceOrganization__getScore(char *arg0, s8 arg1);
extern "C" void func_0057DA20(char *arg0, char *arg1, s32 arg2);
extern "C" void RaceMessageDisplay__setFont(char *arg0, s32 arg1, s32 arg2);
extern "C" void RaceMessageDisplay__setMessage(char *arg0, char *arg1, f32 f12, f32 f13);

extern "C" void RaceDisplay__put_aspec_race_result(char *self) {
    char scoreText[0x80];
    char *labelDisplay;
    char *scoreDisplay;
    s32 labelText;
    s32 scoreFormat;
    s32 score;
    s32 labelColour;
    s32 scoreColour;
    f32 value18;
    f32 value1C;
    f32 messageArgA;
    f32 messageArgB;

    if (vcall150(self) != 0) {
        labelText = DisplayRText__getRTextStr((s32)D_006A0558);
        scoreFormat = DisplayRText__getRTextStr((s32)D_006A0568);
        if (labelText != 0) {
            if (scoreFormat != 0) {
                labelDisplay = self + 0x267C;
                value18 = 0x1.999998p-4f;
                score = RaceOrganization__getScore(*(char **)(self + 4), *(s8 *)(self + 0x2F));
                scoreDisplay = self + 0x27CC;
                func_0057DA20(scoreText, (char *)scoreFormat, score);
                value1C = 0x1.333332p-2f;
                RaceMessageDisplay__setFont(labelDisplay, (s32)D_006A0540, 1);
                labelColour = 0x80C8C8C8;
                messageArgA = 0x1.599998p+1f;
                messageArgB = 0x1p+0f;
                *(s32 *)(labelDisplay + 0x20) = labelColour;
                *(f32 *)(labelDisplay + 0x18) = value18;
                *(f32 *)(labelDisplay + 0x1C) = value1C;
                RaceMessageDisplay__setMessage(labelDisplay, (char *)labelText, messageArgA, messageArgB);
                RaceMessageDisplay__setFont(scoreDisplay, (s32)D_006A0548, 1);
                scoreColour = 0x800086E6;
                *(f32 *)(scoreDisplay + 0x18) = value18;
                *(s32 *)(scoreDisplay + 0x20) = scoreColour;
                *(f32 *)(scoreDisplay + 0x1C) = value1C;
                RaceMessageDisplay__setMessage(scoreDisplay, scoreText, messageArgA, messageArgB);
            }
        }
    }
}
