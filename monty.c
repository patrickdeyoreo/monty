#include "monty.h"

op_env_t op_env = {NULL, NULL, NULL, 0, LIFO};

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument values
 *
 * Return: Upon success, return EXIT_SUCCESS.
 */
int main(int argc, char **argv)
{
	instruction_fn fn = NULL;
	ssize_t len = 0;
	unsigned int lineno = 1;

	atexit(free_op_env);

	if (argc != 2)
		failure("USAGE: monty file\n");

	if (!freopen(argv[1], "r", stdin))
		failure("Error: Can't open file %s\n", argv[1]);

	while ((len = fgetln(&op_env.line, &op_env.linesz, stdin)) > 0)
	{
		op_env.argv = strtow(op_env.line);
		if (op_env.argv && *op_env.argv && **op_env.argv != '#')
		{
			fn = get_instruction_fn(*op_env.argv);
			if (fn)
				fn(&op_env.stack, lineno);
			else
				failure("L%u: unknown instruction %s\n",
					lineno, *op_env.argv);
		}
		free_words(&op_env.argv);
		++lineno;
	}

	if (len < 0)
		failure("Error: Can't read file %s\n", argv[1]);

	exit(EXIT_SUCCESS);
}
