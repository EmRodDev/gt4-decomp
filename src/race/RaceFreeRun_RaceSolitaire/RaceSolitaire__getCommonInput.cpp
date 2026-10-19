/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { char pad[0xe0]; int flag; bool isActive() const { return flag != 0; } };
struct RaceSolitaireLayout {
    char pad[0x6c];
    Data *data;
    char pad70[0xe48c - 0x70];
    char input_e48c[0x3C0];
    char ghost_input_e84c[0x3C0];
};
extern "C" void *RaceSolitaire__getCommonInput(RaceSolitaireLayout *self) {
    if (self->data->isActive()) return self->ghost_input_e84c;
    return self->input_e48c;
}
