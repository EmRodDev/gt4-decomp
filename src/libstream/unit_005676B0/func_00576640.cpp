/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next; int thread; };
struct Obj { Node *head; int f4; int f8; int fc; Node *active; int f14; int owner; int priority; int count; int threshold; };
extern "C" int func_005ADB30(int,int);
extern "C" int func_005ADB90();
extern "C" int func_005ADBD0(int);
extern "C" int func_005B72A8();
extern "C" int func_00576640(Obj *o,int change) {
    Node *list = 0;
    int priority = -1;
    int id = func_005ADB90();
    int error = 0;
    int enabled = func_005B72A8();
    int count = o->count;
    if(count == 0) {
        error = 1;
    } else if(id != o->owner) {
        error = 1;
    } else {
        count--;
        o->count = count;
        if(count == 0) {
            list = o->active;
            o->owner = -1;
            o->active = 0;
            o->f14 = 0;
            if(list == 0) {
                list = o->head;
                o->f4 = 0;
                o->head = 0;
            }
        }
        if(change && o->threshold == count) {
            priority = o->priority;
            o->threshold = -1;
            o->priority = -1;
        }
    }
    if(enabled) asm volatile("ei");
    if(error) return 0;
    int found = 0;
    if(list) {
        int old = func_005ADB30(id,1);
        Node *next;
        do {
            int thread = list->thread;
            next = list->next;
            list = next;
            if(thread != id) func_005ADBD0(thread);
            else found = 1;
        } while(next);
        priority = (~priority == 0) ? old : priority;
    }
    if(priority != -1) func_005ADB30(id,priority);
    return found;
}
