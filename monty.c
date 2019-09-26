#include "monty.h"

op_env_t op_env = {0};

/**
 * main - entry point
 * @ac: argument count
 * @av: argument values
 *
 * Return: Upon success, return EXIT_SUCCESS.
 */
int main(int ac, char **av)
{
	instruction_fn fn = NULL;
	ssize_t n_read = 0;
	unsigned int lineno = 1;

	if (ac != 2)
		failure("USAGE: monty file\n");

	if (!freopen(av[1], "r", stdin))
		failure("Error: Can't open file %s\n", av[1]);

	atexit(clear_op_env);

	while ((n_read = fgetln(&op_env.line, &op_env.linesz, stdin)))
	{
		op_env.av = strtow(op_env.line);
		if (op_env.av && *op_env.av && **op_env.av != '#')
		{
			fn = get_instruction_fn(*op_env.av);
			if (!fn)
			{
				failure("L%u: unknown instruction %s\n",
					lineno, *op_env.av);
			}
			fn(&op_env.sp, lineno);
			free_words(&op_env.av);
		}
		++lineno;
	}
	if (n_read < 0)
		failure("Error: Can't read file %s\n", av[1]);

	exit(EXIT_SUCCESS);
}
