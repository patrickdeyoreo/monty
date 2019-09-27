#include "monty.h"

/**
 * op_pall - print each element on the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void op_pall(stack_t **sp, unsigned int lineno __attribute__((unused)))
{
	stack_t *p = NULL;

	if (*sp)
	{
		(*sp)->next->prev = NULL;

		for (p = *sp; p; p = p->prev)
			printf("%d\n", p->n);

		(*sp)->next->prev = *sp;
	}
}
