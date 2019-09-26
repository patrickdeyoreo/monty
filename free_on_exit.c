#include "monty.h"
#include <stdio.h>

void free_on_exit(int status __attribute__((unused)), void *ref)
{
	if (ref && *((void **) ref))
		free(*((void **) ref));
}
