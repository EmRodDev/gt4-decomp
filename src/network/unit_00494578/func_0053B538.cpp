char *func_0053B538(char **save, const char *delim) {
    char *start = *save;
    const char *d;
    if (start == 0)
        return 0;
    if (delim == 0)
        return start;
    while (**save) {
        for (d = delim; *d; d++) {
            if (**save == *d) {
                **save = 0;
                (*save)++;
                return start;
            }
        }
        (*save)++;
    }
    *save = 0;
    return start;
}
