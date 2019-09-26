#include "monty.h"

/**
 * op_mul - mul the top two elements on the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void op_mul(stack_t **sp, unsigned int lineno)
{
	int to_mul = 0;

	if (!(*sp && *sp != (*sp)->next))
		failure("L%u: can't mul, stack too short\n", lineno);

	to_mul = (*sp)->n;

	op_pop(sp, lineno);

	(*sp)->n *= to_mul;
}
