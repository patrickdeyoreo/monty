#include "monty.h"

/**
 * op_div - div the top two elements on the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void op_div(stack_t **sp, unsigned int lineno)
{
	int to_div = 0;

	if (!(*sp && *sp != (*sp)->next))
		failure("L%u: can't div, stack too short\n", lineno);

	to_div = (*sp)->n;
	if (!to_div)
		failure("L%u: division by zero\n", lineno);

	op_pop(sp, lineno);

	(*sp)->n /= to_div;
}
