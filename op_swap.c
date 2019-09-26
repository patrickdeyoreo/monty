#include "monty.h"

/**
 * op_swap - swap the top two elements on the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void op_swap(stack_t **sp, unsigned int lineno)
{
	stack_t *a = NULL;
	stack_t *b = NULL;

	if (!(*sp && *sp != (*sp)->next))
		failure("L%u: can't swap, stack too short\n", lineno);

	a = (*sp);
	b = (*sp)->prev;

	a->n ^= b->n;
	b->n ^= a->n;
	a->n ^= b->n;
}
