#include "monty.h"

/**
 * swap - swap the top two elements on the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void swap(stack_t **sp, unsigned int lineno)
{
	if (!(*sp && (*sp)->prev != (*sp)->next))
		failure("L%u: can't swap, stack too short\n", lineno);

	(*sp)->n ^= (*sp)->prev->n;
	(*sp)->prev->n ^= (*sp)->n;
	(*sp)->n ^= (*sp)->prev->n;
}
