#include "monty.h"

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
