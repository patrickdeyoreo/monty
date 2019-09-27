#include "monty.h"

/**
 * op_pop - remove the element at the top of the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void op_pop(stack_t **sp, unsigned int lineno)
{
	stack_t *top = NULL;

	if (!*sp)
		failure("L%u: can't pop an empty stack\n", lineno);

	if (*sp != (*sp)->prev)
	{
		top = (*sp)->prev;
		(*sp)->next->prev = top;
		top->next = (*sp)->next;
	}
	free(*sp);
	*sp = top;
}

