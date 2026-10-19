/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Data { int a, b, c, d; };
struct Owner { char pad[0x24]; void *ctx; };
struct Chunk { char *data; int len; };
struct Input { Chunk chunks[8]; u32 size; int count; };
extern "C" int func_00571210(Owner *, Input *, int, Data *, int, u32 *, int *);
extern "C" int func_00571480(Owner *o, short v, Data *data, int *flag, int *status) {
    Input in;
    short val = v;
    u32 result = 0;
    if (flag == 0) return 2;
    *flag = 0;
    if (data == 0) return 2;
    if (status == 0) return 2;
    if (o == 0) return 2;
    in.count = 0;
    in.size = 0;
    in.chunks[in.count].data = (char *)&val;
    in.chunks[in.count].len = 2;
    in.size += 2;
    in.count++;
    int ret = func_00571210(o, &in, 0, data, 0, &result, status);
    if (result == 2) *flag = 1;
    return ret;
}
