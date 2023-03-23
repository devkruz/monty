#include "monty.h"

/**
 * controller - call the appropate operation
 * for the stack
 * @line_number: current file line bean read
 * @stack: the head of the
 * @file_content: the file content
 * @file: file pointer
 *
 * Return: nothing
*/

void controller(int line_number, stack_t **stack,
char **file_content, FILE **file)
{
	char *op, *arg;
	int index = 0;

	instruction_t opcode_lib[] = {
		{"pall", op_pall},
		{"push", op_push},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{NULL, NULL}
	};

	op = strtok((*file_content), " \t\n");
		if (!op)
			return;
	printf("content:%s, op: %s", *file_content, op);
	arg = strtok(NULL, " \t\n");
	free(*file_content);
	*file_content = NULL;

	while (opcode_lib[index].opcode != NULL && op != NULL)
	{
		if ((strcmp(opcode_lib[index].opcode, op)) == 0)
		{
			opcode_lib[index].f(stack, line_number, arg, file);
			break;
		}
		index++;
	}
	if (opcode_lib[index].opcode == NULL && op)
	{
		fprintf(stderr, OP_UNKNOWN, line_number, op);
		fclose(*file);
		*file = NULL;
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
