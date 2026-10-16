struct Node { int state,value; char pad[4]; int n; char pad2[0x14]; int result; char pad3[0xc]; int mode; };
struct Obj { char pad[0x20]; Node *node; };
extern "C" void func_005ADF20(int);
extern "C" int func_00570E00(Obj *,int *);
extern "C" int func_00571B20(Node *,Node **,unsigned char *);
extern "C" int func_00570BE0(Obj *obj,int *out) {
    unsigned char flag;
    Node *found;
    int count;
    if(!obj || !out) return -0x200;
    Node *node=obj->node;
    func_005ADF20(0);
    switch(node->mode) {
    case 3:
    case 0: {
        flag=0;
        found=0;
        int r=func_00571B20(node,&found,&flag);
        if(r==0) {
            if(flag==1) {
                *out=found->result;
                return found->n;
            }
            *out=0;
            return 0;
        }
        return r;
    }
    default: {
        count=0;
        if(node->n) {
            int r=func_00570E00(obj,&count);
            if(r) return r;
            if(count==0) return r;
        }
        int r=node->state;
        if (r==0) {
            *out=node->value;
            return 0;
        }
        return r;
    }
    }
}
