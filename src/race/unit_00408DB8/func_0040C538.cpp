/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Builds a singly linked list of nodes, sorted in descending key order, from the elements of the list at source->(+0x60)->(+0x14) (the
 * element objects are over 0x3460 bytes large and carry an integer key at +0x3460, so they are probably cars; inferred from the size).
 * Node i lives at ranking + 0x500 + 16 * i and stores the element, its key (+4) and the key plus 00447598(adjustSource, i) (+8). With
 * useAdjusted nonzero the list is ordered by the adjusted key, otherwise by the plain key; equal keys keep arrival order. The head
 * goes to +0x560. Used for ordering drivers, which is a guess from the shape and the unit; what the key measures is purpose unknown. */
typedef int s32;
struct E { char pad[0x10]; E *next; };
struct E2 { char pad[0x3460]; s32 sortKey; };
struct N { N *next; s32 k4; s32 k8; void *element; };
struct L { char pad[0x14]; E *first; };
struct A1 { char pad[0x60]; L *l; char pad2[0xC]; void *adjustSource; };
struct A0 { char pad[0x500]; N nodes[1]; };
extern "C" int func_00447598(void *, s32);

struct Q { char pad[0x560]; N *head; };

extern "C" void func_0040C538(Q *ranking, A1 *source, s32 useAdjusted) {
    s32 i = 0;
    ranking->head = 0;
    E *element = source->l->first;
    void *adjustSource = source->adjustSource;
    if (element) {
        N *node = (N *)((char *)ranking + 0x500);
        do {
            s32 baseKey = ((E2 *)element)->sortKey;
            s32 adjustment = func_00447598(adjustSource, i);
            node->k4 = baseKey;
            s32 adjustedKey = baseKey + adjustment;
            node->element = element;
            node->k8 = adjustedKey;
            node->next = 0;
            s32 sortKey = useAdjusted ? adjustedKey : baseKey;
            N *prev = 0;
            N *head = ranking->head;
            N *cur = head;
            while (cur) {
                s32 curKey = useAdjusted ? cur->k8 : cur->k4;
                if (curKey < sortKey) break;
                prev = cur;
                cur = cur->next;
            }
            if (prev) {
                prev->next = node;
                node->next = cur;
            } else {
                node->next = head;
                ranking->head = node;
            }
            element = element->next;
            node++;
            i++;
        } while (element);
    }
}
