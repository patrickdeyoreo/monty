#include "monty.h"

/**
 * op_pint - print the value at the top of the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void op_pint(stack_t **sp, unsigned int lineno)
{
	if (*sp)
		printf("%d\n", (*sp)->n);
	else
		failure("L%u: can't pint, stack empty\n", lineno);
}
