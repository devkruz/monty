#include "monty.h"

/**
 * free_stack - free the stack
 * @stack: the stack head
 *
 * Return: nothing
*/

void free_stack(stack_t **stack)
{
	stack_t *tmp;
	stack_t *head;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*stack = head;
}
