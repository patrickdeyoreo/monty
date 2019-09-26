#include "monty.h"

/**
 * op_stack - set stack mode to last-in first-out (default)
 * @sp: stack pointer
 * @lineno: line number
 */
void op_stack(stack_t **sp __attribute__((unused)),
	unsigned int lineno __attribute__((unused)))
{
	op_env.mode = LIFO;
}

