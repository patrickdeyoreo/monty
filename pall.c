#include "monty.h"
#include <stdio.h>

void pall(stack_t **sp, unsigned int ln __attribute__((unused)))
{
	stack_t *ptr = NULL, *tmp = NULL;

	if (*sp)
	{
		switch (op_env.mode)
		{
		case LIFO:
			tmp = (*sp)->next->prev;
			(*sp)->next->prev = NULL;

			for (ptr = tmp; ptr; ptr = ptr->prev)
				fprintf(stdout, "%d\n", ptr->n);

			(*sp)->next->prev = tmp;
			break;

		case FIFO:
			tmp = (*sp)->next;
			(*sp)->next = NULL;

			for (ptr = tmp; ptr; ptr = ptr->next)
				fprintf(stdout, "%d\n", ptr->n);

			(*sp)->next = tmp;
			break;
		}

	}
}
