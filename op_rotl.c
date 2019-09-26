#include "monty.h"

/**
 * op_rotl - rotate upward (toward top of stack)
 * @sp: stack pointer
 * @lineno: line number
 */
void op_rotl(stack_t **sp, unsigned int lineno __attribute__((unused)))
{
	if (*sp)
		*sp = (*sp)->prev;
}
