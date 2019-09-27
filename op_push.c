#include "monty.h"

/**
 * op_push - push an element onto the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void op_push(stack_t **sp, unsigned int lineno)
{
	stack_t *new = NULL;
	char *nstr = NULL;
	int n = strtol(op_env.argv[1], &nstr, 10);

	if (!nstr || *nstr || nstr == op_env.argv[1])
		failure("L%u: usage: push integer\n", lineno);

	new = malloc(sizeof(*new));
	if (!new)
		failure("Error: malloc failed\n");

	new->n = n;
	if (*sp)
	{
		new->prev = (*sp);
		new->next = (*sp)->next;
		new->next->prev = new;
		(*sp)->next = new;
		if (op_env.mode == LIFO)
			(*sp) = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
		(*sp) = new;
	}
}
