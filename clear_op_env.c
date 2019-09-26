#include "monty.h"
#include "words.h"

/**
 * clear_op_env - clear stack operation environment
 */
void clear_op_env(void)
{
	free_words(&op_env.av);
	free_stack(&op_env.sp);
}
