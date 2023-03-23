#include "monty.h"

/**
 * add_node - add a new node to the beginnng
 * of a stack
 * @arg: the new node element
 * @stack: the head of the stack
 *
 * Return: nothing
*/

void add_node(int arg, stack_t **stack)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, MALLOC_FAILED);
		exit(EXIT_FAILURE);
	}

	new_node->prev = NULL;
	new_node->n = arg;
	new_node->next = (*stack);

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
