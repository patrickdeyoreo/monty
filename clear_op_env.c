#include "monty.h"

/**
 * clear_op_env - clear stack operation environment
 */
void clear_op_env(void)
{
	free_words(&op_env.argv);
	free_stack(&op_env.stack);
	free(op_env.line);
	op_env.line = NULL;
	op_env.linesz = 0;
}
