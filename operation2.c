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
void op_add(stack_t **stack, unsigned int line_number, char *arg, FILE **file)
{
	int tmp, tmp_next;
	stack_t *sub;
	stack_t *head = *stack;
	(void)arg;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, ADD_ERROR, line_number);
		fclose(*file);
		*file = NULL;
		exit(EXIT_FAILURE);
	}
	tmp = head->n;
	tmp_next = head->next->n;
	sub = head->next;
	sub->n = tmp + tmp_next;
	free(head);
	head = sub;
}
