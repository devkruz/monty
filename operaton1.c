#include "monty.h"

/**
 * op_pint - print the top stack
 * @stack: the head of the stack
 * @line_number: the current file line
 *
 * Return: nothing
*/


void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, PINT_ERROR, line_number);
		fclose(global_var.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * op_push - pushes the new element to the
 * end of the stack
 * @stack: the stack head
 * @line_number: the current file line bean read
 *
 * Return: nothing
*/


void op_push(stack_t **stack, unsigned int line_number)
{
	int op_arg;

	if (global_var.arg == NULL || strcmp(global_var.arg, "$") == 0)
	{
		/* if error occurs */
			/* close file */
			/* free stack */
		/*free_stack(stack);*/
		fclose(global_var.file);
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	op_arg = atoi(global_var.arg);
	add_node(op_arg, stack);
}

/**
 * op_pall - print all the element in a stack
 * @stack: the head of stack
 * @line_number: the current file line bean read
 *
 * Return: nothin
*/

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	(void)line_number;
	(void)stack;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
