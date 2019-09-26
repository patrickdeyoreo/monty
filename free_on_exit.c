#include "monty.h"
#include <stdio.h>

/**
 * free_on_exit - free memory upon exit
 * @status: exit status
 * @ref: pointer to a pointer to the target memory
 */
void free_on_exit(int status __attribute__((unused)), void *ref)
{
	if (ref && *((void **) ref))
		free(*((void **) ref));
}
