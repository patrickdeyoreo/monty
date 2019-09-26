#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

#include "getln.h"
#include "words.h"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef void (*instruction_fn)(stack_t **, unsigned int);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	instruction_fn f;
} instruction_t;

/**
 * enum stack_mode_n - stack mode enumeration
 * @LIFO: operate as a stack
 * @FIFO: operate as a queue
 */
typedef enum stack_mode_n
{
	LIFO = 0,
	FIFO = 1
} stack_mode_t;

/**
 * struct op_env_s - operation environment
 * @argv: argument vector
 * @stack: top of stack
 * @line: line buffer
 * @linesz: line size
 * @mode: stack mode
 */
typedef struct op_env_s
{
	char **argv;
	stack_t *stack;
	char *line;
	size_t linesz;
	stack_mode_t mode;
} op_env_t;

extern op_env_t op_env;

instruction_fn get_instruction_fn(const char *opcode);

void op_add(stack_t **sp, unsigned int lineno);
void op_div(stack_t **sp, unsigned int lineno);
void op_mod(stack_t **sp, unsigned int lineno);
void op_mul(stack_t **sp, unsigned int lineno);
void op_nop(stack_t **sp, unsigned int lineno);
void op_pall(stack_t **sp, unsigned int lineno);
void op_pint(stack_t **sp, unsigned int lineno);
void op_pop(stack_t **sp, unsigned int lineno);
void op_push(stack_t **sp, unsigned int lineno);
void op_sub(stack_t **sp, unsigned int lineno);
void op_swap(stack_t **sp, unsigned int lineno);

void free_stack(stack_t **sp);

void clear_op_env(void);

void failure(const char *fmt, ...);

int isinteger(const char *str);

#endif /* MONTY_H */
