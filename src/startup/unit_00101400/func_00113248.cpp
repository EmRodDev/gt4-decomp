/* Provisional layouts: the roles of the two adjustments and option bytes are
 * unknown. Offsets follow the loads/stores shared by this settings update. */
struct Settings {
    char unknown0[0x12A];
    unsigned char mode;
    char unknown12B[0x160 - 0x12B];
    unsigned char option_a, option_b, adjustment_a, adjustment_b;
    unsigned char unknown164, dirty;
};
struct Owner {
    char unknown0[0x20];
    Settings settings;
    char unknown186[0x3448 - 0x186];
    int enabled;
};
struct Bridge { char unknown0[8]; Owner **owner; };
struct Subject { char unknown0[0x60]; Bridge *bridge; };
struct Context { char unknown0[0x6C]; Subject *subject; };
struct Configuration {
    char unknown0[0x3AC];
    unsigned char adjustment_a; char unknown3AD[3];
    unsigned char adjustment_b; char unknown3B1[3];
    unsigned char mode; char unknown3B5[3];
    unsigned char option_a; char unknown3B9[3];
    unsigned char option_b; char unknown3BD[3];
    int enabled, pair_selector;
    char unknown3C8[0x488 - 0x3C8];
    int pending;
};
extern "C" void func_00110B90(int, int *, int *);
extern "C" void func_003C0D78(Subject *, int, int);
extern "C" void func_003C0D98(Subject *, int, int);
extern "C" int func_00443240(Settings *);
extern "C" void func_00113248(Configuration *configuration, Context *context)
{
    int first, second;
    Subject *subject = context->subject;
    Owner *owner = *subject->bridge->owner;
    owner->enabled = configuration->enabled != 0;
    Settings *settings;
    func_00110B90(configuration->pair_selector, &first, &second);
    func_003C0D78(subject, first, 0);
    func_003C0D98(subject, second, 0);
    if (configuration->pending) {
        settings = &owner->settings;
        settings->adjustment_b = configuration->adjustment_b + 100;
        settings->adjustment_a = configuration->adjustment_a + 100;
        settings->option_a = configuration->option_a;
        settings->option_b = configuration->option_b;
        unsigned char mode = configuration->mode;
        if (mode) {
            settings->mode = mode;
            func_00443240(settings);
        }
        settings->dirty = 1;
        configuration->pending = 0;
    }
}
