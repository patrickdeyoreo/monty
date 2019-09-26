#include "monty.h"
#include <stdio.h>
#include <string.h>

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
		failure("L%u: unknown instruction %s\n", op_env.ln, opcode);
	}
	return (NULL);
}
