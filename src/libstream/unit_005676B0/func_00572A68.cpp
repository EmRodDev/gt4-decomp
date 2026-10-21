/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Node {
    u32 unk0;
    u32 unk4;
    char pad8[0x4];
    Node *next;
};

extern "C" void func_005769F0(Node *head);
extern "C" void func_00576A28(Node *head);

extern "C" s32 func_00572A68(char *arg0) {
    Node *head = (Node *)(arg0 + 0x4C);
    func_005769F0(head);
    s32 min = 0x10;
    char *cursor = arg0 + 0x48;
    s32 i = 0xF;
    do {
        Node *n = *(Node **)cursor;
        if (n != 0) {
            do {
                u32 len = n->unk4 - (u32)n;
                n = n->next;
                if (min < len)
                    min = (s32)len;
            } while (n != 0);
        }
        if (min != 0x10)
            break;
        i--;
        cursor -= 4;
    } while (i >= 0);
    func_00576A28(head);
    return min - 0x10;
}
