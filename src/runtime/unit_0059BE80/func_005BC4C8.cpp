/* compiler: ee-gcc2.96-no-strict-aliasing */
/* crtbegin-style __do_global_ctors: register the EH frame table, run the constructor list in
 * reverse (the list may be -1 terminated by count, else NULL terminated), then register the
 * destructor runner with atexit. */
typedef void (*func_ptr)(void);

extern "C" {
extern char D_006D3E00[];
extern char D_0088D7B0[];
extern func_ptr D_00616F24[];
void func_005BEC48(void *, void *);
int func_005A2ED0(void (*)(void));
void func_005BC438(void);

int func_005BC4C8(void)
{
	func_005BEC48(D_006D3E00, D_0088D7B0);
	{
		unsigned long nptrs = (unsigned long) D_00616F24[0];
		int i;
		if (nptrs == (unsigned long) -1)
			for (nptrs = 0; D_00616F24[nptrs + 1] != 0; nptrs++);
		for (i = nptrs; i != 0; i--)
			D_00616F24[i] ();
	}
	return func_005A2ED0(func_005BC438);
}
}
