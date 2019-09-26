#include "monty.h"

/**
 * op_rotr - rotate downward (toward bottom of stack)
 * @sp: stack pointer
 * @lineno: line number
 */
void op_rotr(stack_t **sp, unsigned int lineno __attribute__((unused)))
{
	if (*sp)
		*sp = (*sp)->next;
}
