#include "monty.h"

/**
 * op_sub - sub the top two elements on the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void op_sub(stack_t **sp, unsigned int lineno)
{
	int to_sub = 0;

	if (!(*sp && *sp != (*sp)->next))
		failure("L%u: can't sub, stack too short\n", lineno);

	to_sub = (*sp)->n;

	op_pop(sp, lineno);

	(*sp)->n -= to_sub;
}
