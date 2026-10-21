/* Handles the end of one race for the results flow (shape inferred from the callees and arguments; many meanings unknown). It reads the
 * race label of the session's race spec, looks up a per-race record in the global block D_00622F4C (+0x13E28) and posts a message to the
 * queue at +0x568 (the same queue func_00110800 writes to). When the config byte at +0x5B6 is zero it only refreshes the screen
 * (func_00110898), resets the record at +0x348 and posts a message. Otherwise the entries are sorted (RaceEntryBase::sortByRank), the
 * player's rank is taken from func_00110570, an amount from func_004475A8 is added to the 64-bit total at +0x48 of the record and
 * stored at +0x4A4 of the screen, and *bestRank keeps the smallest rank seen so far (inferred from the c < *arg test).
 * For session modes 0 and 2 the score from RaceOrganization::getScore is also recorded. */
#include "types.h"

struct Cfg { char pad[0x5B6]; u8 b5B6; };
struct C0 { char pad[0x18]; Cfg *p18; };
struct B8 { C0 *p0; };
struct A60 { char pad[8]; B8 *p8; };
struct S1 { char pad[0x60]; A60 *p60; char pad64[0xC]; void *p70; };
struct Arg1 { char pad[0x6C]; S1 *p6C; };
struct Arg1b { char pad[0xCC8]; s32 fCC8; };
struct Arg0 { char pad[0x4A4]; s32 f4A4; };
struct Rec { char pad[0x48]; s64 f48; };
struct G { char pad4[4]; };

extern char *D_00622F4C;
extern char D_0068D568[];

extern "C" s32 func_00110570(S1 *, s32);
extern "C" void func_00110898(Arg0 *, S1 *);
extern "C" void func_00114390(Arg0 *, Arg1 *);
extern "C" s32 func_0035E3F0(Cfg *);
extern "C" void RaceEntryBase__sortByRank(A60 *);
extern "C" u8 RaceOrganization__getScore(S1 *, s32);
extern "C" void func_0042F270(void *, s32, u8, u8, s32);
extern "C" void func_0042F448(void *, void *, s32, u8, u8, s32);
extern "C" s32 func_00430A20(void *, s32);
extern "C" void func_00430A58(void *, s32, u8);
extern "C" void *func_00430D20(void *, s32);
extern "C" void func_0043AFF0(void *, u32);
extern "C" s32 SPEC_DATABASE__RaceSpec__getRaceLabel(void *);
extern "C" s32 func_004475A8(void *, u32);
extern "C" s32 func_0057F238(s32, const char *);

extern "C" void func_00114498(Arg0 *screen, Arg1 *session, u8 *bestRank) {
    s32 flag = 0;
    S1 *state;
    s32 name;
    char *globals;
    char *messageQueue, *resultRecord;
    void *raceRecord;
    s32 mode = ((Arg1b *)session)->fCC8;
    if (mode == 0 || mode == 2) flag = 1;
    state = session->p6C;
    name = SPEC_DATABASE__RaceSpec__getRaceLabel(state->p70);
    globals = D_00622F4C;
    resultRecord = globals + 0x348;
    raceRecord = func_00430D20(globals + 0x13E28, name);
    messageQueue = globals + 0x568;
    if (state->p60->p8->p0->p18->b5B6 == 0) {
        func_00110898(screen, state);
        func_0043AFF0(resultRecord, 0);
        if (func_0057F238(name, D_0068D568) == 0) {
            return func_0042F448(messageQueue, D_00622F4C + 4, 2, 0xF, 0xE, 0x157529FF);
        }
        return func_0042F270(messageQueue, name, 0xF, 0xE, 0x157529FF);
    } else {
        A60 *entries = state->p60;
        s32 value, rank, amount;
        RaceEntryBase__sortByRank(entries);
        value = func_0035E3F0(state->p60->p8->p0->p18);
        rank = func_00110570(state, 0);
        amount = func_004475A8(state->p70, rank);
        func_0043AFF0(resultRecord, rank + 1);
        ((Rec *)resultRecord)->f48 += amount;
        if (flag) func_00430A20(raceRecord, RaceOrganization__getScore(state, 0));
        u8 rankByte = rank;
        if (rankByte < *bestRank) {
            func_00430A58(raceRecord, 2, rankByte);
            *bestRank = rankByte;
        }
        if (func_0057F238(name, D_0068D568) == 0) {
            func_0042F448(messageQueue, D_00622F4C + 4, 2, rankByte, 0xE, value);
        } else {
            func_0042F270(messageQueue, name, rankByte, 0xE, value);
        }
        screen->f4A4 = amount;
        func_00114390(screen, session);
    }
}
