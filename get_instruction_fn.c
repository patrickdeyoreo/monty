#include "monty.h"
#include <stdio.h>
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
		{"pall", pall},
		{"push", push},
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
		failure("L%u: unknown instruction %s\n", op_env.lineno, opcode);
	}
	return (NULL);
}
