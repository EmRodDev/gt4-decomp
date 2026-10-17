/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block64 {
    int words[16];
};

struct Channel {
    Block64 params;
    char pad[0x114 - sizeof(Block64)];
};

struct Mixer {
    char pad[0x4C];
    Channel channels[1];
};

struct Command {
    int type;
    int pad;
    Block64 params;
};

extern "C" Command *func_005560C8(Mixer *mixer, int mode);

extern "C" void func_00555D10(Mixer *mixer, int index, int value, int type, int skipMode)
{
    int mode = 0;
    if (!skipMode)
        mode = index == 0 ? 1 : 2;
    Command *cmd = func_005560C8(mixer, mode);
    Channel *channel = &mixer->channels[index];
    channel->params.words[3] = value;
    cmd->params = channel->params;
    cmd->type = type;
}
