#include "monty.h"
#include <string.h>

/**
 * get_instruction_fn - get the function associated with an opcode
 * @opcode: the opcode to match
 *
 * Return: If opcode is NULL, return NULL. If match is found, return the
 * corresponding function. If match is not found, exit with EXIT_FAILURE.
 */
instruction_fn get_instruction_fn(const char *opcode)
{
	static instruction_t instructions[] = {
		{"add",  op_add},
		{"div",  op_div},
		{"mod",  op_mod},
		{"mul",  op_mul},
		{"nop",  op_nop},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop",  op_pop},
		{"push", op_push},
		{"sub",  op_sub},
		{"swap", op_swap},
		{0}
	};
	instruction_t *op = instructions;

	if (opcode)
	{
		while (op->opcode)
		{
			if (!strcmp(opcode, op->opcode))
				return (op->f);
			++op;
		}
	}
	return (NULL);
}
