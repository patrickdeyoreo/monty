#include "monty.h"

/**
 * op_pop - remove the element at the top of the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void op_pop(stack_t **sp, unsigned int lineno)
{
	stack_t *tmp = NULL;

	if (!*sp)
		failure("L%u: can't pop an empty stack\n", lineno);

	if (*sp != (*sp)->prev)
	{
		tmp = (*sp)->prev;
		(*sp)->next->prev = tmp;
		tmp->next = (*sp)->next;
	}
	free(*sp);
	*sp = tmp;
}

