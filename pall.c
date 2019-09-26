#include "monty.h"
#include <stdio.h>


/**
 * pall - print each element on the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void pall(stack_t **sp, unsigned int lineno __attribute__((unused)))
{
	stack_t *p = NULL, *tmp = NULL;

	if (*sp)
	{
		switch (op_env.mode)
		{
		case LIFO:
			tmp = (*sp)->next->prev;
			(*sp)->next->prev = NULL;

			for (p = tmp; p; p = p->prev)
				printf("%d\n", p->n);

			(*sp)->next->prev = tmp;
			break;

		case FIFO:
			tmp = (*sp)->next;
			(*sp)->next = NULL;

			for (p = tmp; p; p = p->next)
				printf("%d\n", p->n);

			(*sp)->next = tmp;
			break;
		}

	}
}
