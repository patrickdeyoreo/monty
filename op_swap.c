#include "monty.h"

/**
 * op_swap - swap the top two elements on the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void op_swap(stack_t **sp, unsigned int lineno)
{
	stack_t *p = *sp;

	if (!(p && p != p->next))
		failure("L%u: can't swap, stack too short\n", lineno);

	p->n ^= p->prev->n;
	p->prev->n ^= p->n;
	p->n ^= p->prev->n;
}
