/* compiler: ee-gcc2.96-nogcse */
typedef signed char s8;
typedef unsigned char u8;

/* Each node keeps up to three links to other nodes (-1 = free). */
struct Links { s8 link[3]; };
struct Graph { char pad[0x98]; struct Links *nodes; };

/* Links node `id` to lower-numbered nodes that still have a free slot; counts the new links. */
int func_00527E10(struct Graph *g, s8 id, u8 *count) {
    s8 *mine = g->nodes[id].link;
    int k;
    for (k = 0; k < 3; k++) {
        if (mine[k] == -1) {
            s8 t = 0;
            if (id > 0) {
                struct Links *n = g->nodes;
                do {
                    s8 *theirs = n->link;
                    int j, slot;
                    if (theirs != mine) {
                        slot = -1;
                        for (j = 0; j < 3; j++) {
                            if (theirs[j] == -1) {
                                if (slot == -1) slot = j;
                            } else if (theirs[j] == id) {
                                slot = -1;
                                break;
                            }
                        }
                        if (slot != -1) {
                            mine[k] = t;
                            theirs[slot] = id;
                            (*count)++;
                            break;
                        }
                    }
                    t++;
                    n++;
                } while (t < id);
            }
        }
    }
    return 0;
}
