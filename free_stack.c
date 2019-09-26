#include "monty.h"

/**
 * free_stack - free and nullify a stack
 * @sp: pointer to a stack pointer
 */
void free_stack(stack_t **sp)
{
	stack_t *last = NULL;

	if (sp && *sp)
	{
		(*sp)->prev->next = NULL;

		while ((last = *sp))
		{
			*sp = last->next;
			free(last);
		}
	}

}
