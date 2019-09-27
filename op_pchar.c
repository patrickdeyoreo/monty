#include "monty.h"

/**
 * op_pchar - print the character at the top of the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void op_pchar(stack_t **sp, unsigned int lineno)
{
	if (*sp)
	{
		if ((*sp)->n > 0 && (*sp)->n < 128)
			printf("%c\n", (*sp)->n);
		else
			failure("L%u: can't pchar, value out of range\n", lineno);
	}
	else
		failure("L%u: can't pchar, stack empty\n", lineno);


}
