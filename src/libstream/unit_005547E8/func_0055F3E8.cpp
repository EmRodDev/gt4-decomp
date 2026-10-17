typedef int s32;
struct NameValue {
    const char *name;
    s32 value;
};
extern "C" s32 func_0057F238(const char *left, const char *right);
extern "C" s32 func_0055F3E8(NameValue *entry, const char *name) {
    s32 value;
    if (func_0057F238(entry->name, name) != 0)
        value = 0;
    else
        value = entry->value;
    return value;
}
