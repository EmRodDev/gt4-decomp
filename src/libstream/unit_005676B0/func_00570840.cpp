typedef unsigned int u32;
struct Data { int a, b, c, d; };
struct Owner;
struct Chunk { char *data; int len; };
struct Input { Chunk chunks[8]; u32 size; int count; };
extern "C" int func_00571210(Owner *owner, Input *in, int arg2, Data *data, int arg4, u32 *out, int *status);
extern "C" int func_00570840(void *a, void *b, Owner *owner, char *data, int len, int *flags, Data *d, int arg4, int z) {
    Input in;
    u32 out = 0;
    int status = -0x1F5;
    if (a == 0 || z < -1 || b == 0) return -0x1F5;
    if (len == 0) return 0;
    in.count = 0; in.size = 0; in.chunks[in.count].data = data; in.chunks[in.count].len = len; in.size += len; in.count++;
    if (func_00571210(owner, &in, *flags, d, arg4, &out, &status) == 0) return out;
    return status == 0 ? -0x1F5 : status;
}
