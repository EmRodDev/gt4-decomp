/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" {
void *func_0057A320(void *container, void *key, int *found);

/* Lookup with default: returns the entry when found, else `fallback`. */
void *func_00613B28(void *container, void *key, void *fallback)
{
    int found = 0;
    void *entry = func_0057A320(container, key, &found);
    return found ? entry : fallback;
}
}
