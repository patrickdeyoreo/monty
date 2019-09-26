#include "monty.h"

/**
 * push - push an element onto the stack
 * @sp: stack pointer
 * @lineno: line number
 */
void push(stack_t **sp, unsigned int lineno)
{
	stack_t *new = NULL;

	if (!(op_env.av[1] && isinteger(op_env.av[1])))
		failure("L%u: usage: push integer\n", lineno);

	new = malloc(sizeof(stack_t));
	if (!new)
		failure("Error: malloc failed\n");

	new->n = atoi(op_env.av[1]);
	if (*sp)
	{
		new->prev = (*sp);
		new->next = (*sp)->next;
		(*sp)->next->prev = new;
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
