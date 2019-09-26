#include "monty.h"

op_env_t op_env = {NULL, NULL, 1, LIFO};

/**
 * main - entry point
 * @ac: argument count
 * @av: argument values
 *
 * Return: Upon success, return EXIT_SUCCESS.
 */
int main(int ac, char **av)
{
	char *lnbuf = NULL;
	size_t lnbufsz = 0;
	ssize_t n_read = 0;

	if (ac != 2)
		failure("USAGE: %s file\n", __FILE__);

	if (!freopen(av[1], "r", stdin))
		failure("Error: Can't open file %s\n", av[1]);

	atexit(clear_op_env);
	on_exit(free_on_exit, &lnbuf);

	while ((n_read = fgetln(&lnbuf, &lnbufsz, stdin)))
	{
		op_env.av = strtow(lnbuf);
		if (op_env.av && *op_env.av)
		{
			get_instruction_fn(*op_env.av)(&op_env.sp, op_env.ln);
			free_words(&op_env.av);
		}
		++op_env.ln;
	}
	if (n_read < 0)
		failure("Error: Can't read file %s\n", av[1]);

	return (EXIT_SUCCESS);
}
