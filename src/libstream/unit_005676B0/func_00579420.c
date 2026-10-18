struct MT;
extern void func_00579438(struct MT *m, unsigned int seed);

/* Seeds the Mersenne Twister state object; a thin tail-call wrapper. */
void func_00579420(struct MT *m, unsigned int seed)
{
    func_00579438(m, seed);
}
