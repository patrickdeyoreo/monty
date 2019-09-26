#include "monty.h"

/**
 * op_add - add the top two elements on the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void op_add(stack_t **sp, unsigned int lineno)
{
	int to_add = 0;

	if (!(*sp && *sp != (*sp)->next))
		failure("L%u: can't add, stack too short\n", lineno);

	to_add = (*sp)->n;

	op_pop(sp, lineno);

	(*sp)->n += to_add;
}
