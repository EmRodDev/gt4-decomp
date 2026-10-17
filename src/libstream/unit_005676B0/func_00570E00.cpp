struct Node {
    int pad0;
    char pad4[0x8];
    int state;
    char pad10[0x20 - 0x10];
    Node *link;
};

struct Source {
    int error;
    char pad[0xC - 4];
    int mode;
};

struct Device {
    char pad0[0x20];
    Node *target;
    Source *source;
};

extern "C" {
int func_005ADF20(int);
int func_00570EC0(Node *node, Node *link, int size);

int func_00570E00(Device *dev, int *out)
{
    Source *source;
    Node *node;
    if (!dev || !out)
        return -0x200;
    source = dev->source;
    *out = 0;
    func_005ADF20(0);
    if (source->mode == 0) {
        *out = 1;
    } else if (source->mode == 3) {
        return source->error ? source->error : -0x1F5;
    }
    int v_mode = dev->source->mode;
    node = dev->target;
    if (v_mode != node->state) {
        node->state = dev->source->mode;
        if (func_00570EC0(node, node->link, 0x10))
            return -0x1F5;
    }
    return 0;
}
}
