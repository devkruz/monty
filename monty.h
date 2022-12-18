#ifndef MONTY_H
#define MONTY_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct global_s - global varibale struct
 * @file: file pointer
 * @file_content: file content per line
 * @arg: operation argumentd
*/

typedef struct global_s
{
	FILE *file;
	char *arg;
	char *file_content;
} global_t;

extern global_t global_var;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* controller.c */
void controller(int, stack_t**);
/* operation1.c */
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
/* addnode.c */
void add_node(int arg, stack_t**);
/* free_stack.c */
void free_stack(stack_t **stack);

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define OP_UNKNOWN "L%d: unknown instruction %s\n"
#define MALLOC_FAILED "Error: malloc failed\n"
#define PINT_ERROR "L%d: can't pint, stack empty\n"
#define POP_ERROR "L%d: can't pop an empty stack\n"
#define SWAP_ERROR "L%d: can't swap, stack too short\n"
#endif
