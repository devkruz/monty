#include "monty.h"

/**
 * free_stack - free the stack
 * @stack: the stack head
 *
 * Return: nothing
*/

void free_stack(stack_t **stack)
{
	stack_t *tmp, *head = *stack;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}

	*stack = head;
}
