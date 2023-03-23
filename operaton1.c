#include "monty.h"

/**
 * op_swap -swaps the top two elements of the stack
 * @stack: the head of the stack
 * @line_number: the current file line
 * @arg: inputed argument
 * @file: the file pointer
 *
 * Return: nothing
*/

void op_swap(stack_t **stack, unsigned int line_number, char *arg, FILE **file)
{
	int tmp;
	int tmp_next;
	(void)arg;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, SWAP_ERROR, line_number);
		fclose(*file);
		*file = NULL;
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	tmp_next = (*stack)->next->n;
	(*stack)->n = tmp_next;
	(*stack)->next->n = tmp;

}
/**
 * op_pop - removes the top element of the stack
 * @stack: the head of the stack
 * @line_number: the file current line
 * @arg: inputed argument
 * @file: the file pointer
 *
 * Return: nothing
*/

void op_pop(stack_t **stack, unsigned int line_number, char *arg, FILE **file)
{
	stack_t *tmp;
	stack_t *head = *stack;
	(void)arg;

	if (*stack == NULL)
	{
		fprintf(stderr, POP_ERROR, line_number);
		fclose(*file);
		*file = NULL;
		exit(EXIT_FAILURE);
	}
	tmp = head->next;
	free(head);
	(*stack) = tmp;
	if (tmp != NULL)
		tmp->prev = NULL;
}

/**
 * op_pint - print the top stack
 * @stack: the head of the stack
 * @line_number: the current file line
 * @arg: inputed argument
 * @file: the file pointer
 *
 * Return: nothing
*/


void op_pint(stack_t **stack, unsigned int line_number, char *arg, FILE **file)
{
	(void)arg;

	if (*stack == NULL)
	{
		fprintf(stderr, PINT_ERROR, line_number);
		fclose(*file);
		*file = NULL;
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * op_push - pushes the new element to the
 * end of the stack
 * @stack: the stack head
 * @line_number: the current file line bean read
 * @arg: inputed argument
 * @file: the file pointer
 *
 * Return: nothing
*/


void op_push(stack_t **stack, unsigned int line_number, char *arg, FILE **file)
{
	int op_arg = atoi(arg);

	if (arg == NULL || (op_arg == 0 && (strncmp(arg, "0", 1) != 0)))
	{
		free_stack(stack);
		fclose(*file);
		*file = NULL;
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	add_node(op_arg, stack);
}

/**
 * op_pall - print all the element in a stack
 * @stack: the head of stack
 * @line_number: the current file line bean read
 * @arg: inputed argument
 * @file: the file pointer
 * Return: nothing
*/

void op_pall(stack_t **stack, unsigned int line_number, char *arg, FILE **file)
{
	stack_t *head = *stack;
	(void)line_number;
	(void)stack;
	(void)arg;
	(void)file;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
