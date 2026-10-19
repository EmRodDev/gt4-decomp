/* compiler: ee-gcc2.96-no-strict-aliasing */
struct mUpdateContextPS2Layout {
    char pad0[0x348];
    char unk348[0xEC];
};

extern "C" void *mUpdateContextPS2__virtual_60(mUpdateContextPS2Layout *arg0) {
    return arg0->unk348;
}
