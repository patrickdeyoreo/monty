#include "monty.h"

/**
 * op_mod - mod the top two elements on the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void op_mod(stack_t **sp, unsigned int lineno)
{
	int to_mod = 0;

	if (!(*sp && *sp != (*sp)->next))
		failure("L%u: can't mod, stack too short\n", lineno);

	to_mod = (*sp)->n;
	if (!to_mod)
		failure("L%u: division by zero\n", lineno);

	op_pop(sp, lineno);

	(*sp)->n %= to_mod;
}
