#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libc.h"

void __funcs_on_exit();
void exit(int code)
{
	static int lock[2];

	/* If more than one thread calls exit, hang until _Exit ends it all */


	/* Only do atexit & stdio flush if they were actually used */
	__funcs_on_exit();
	//__fflush_on_exit(); // this is gone, replace with fflush()?

	/* Destructor s**t is kept separate from atexit to avoid bloat */
	if (libc.fini) libc.fini();
	if (libc.ldso_fini) libc.ldso_fini();

	_Exit(code);
	for(;;);
}

