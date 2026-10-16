/* compiler: ee-gcc2.96-no-strict-aliasing */
struct ResultLine {
    char pad0[0xB4];
    int changed;
    char padB8[0xC0 - 0xB8];
};
struct ResultArcade {
    char pad0[0x68];
    ResultLine lines[6];
    char pad[0x4F0 - 0x68 - 6 * 0xC0];
    int player_rank;
};
extern "C" void ResultArcade__setPlayerRank(ResultArcade *self, int rank) {
    if (self->player_rank != rank) {
        self->lines[self->player_rank].changed = 1;
        self->player_rank = rank;
        self->lines[rank].changed = 1;
    }
}
