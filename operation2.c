#include "./monty.h"
/**
 * op_add - adds the top two elements of the stack
 * @stack: the head of the stack
 * @line_number: the current file line
 * @arg: inputed argument
 * @file: the file pointer
 *
 * Return: nothing
*/
void op_add(stack_t **stack, unsigned int line_number,
char *arg, FILE **file, char **file_content)
{
	(void)arg;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, ADD_ERROR, line_number);
		free(*file_content);
		fclose(*file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
