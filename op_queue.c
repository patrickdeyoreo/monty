#include "monty.h"

/**
 * op_queue - set stack mode to first-in first-out
 * @sp: stack pointer
 * @lineno: line number
 */
void op_queue(stack_t **sp __attribute__((unused)),
	unsigned int lineno __attribute__((unused)))
{
	op_env.mode = FIFO;
}
