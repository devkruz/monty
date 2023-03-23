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
		{"add", op_add},
		{NULL, NULL}
	};

	op = strtok(*file_content, " \t\n");

		if (op == NULL)
			return;

	arg = strtok(NULL, " \t\n");


	while (opcode_lib[index].opcode != NULL && op != NULL)
	{
		if ((strcmp(opcode_lib[index].opcode, op)) == 0)
		{
			opcode_lib[index].f(stack, line_number, arg, file, file_content);
			break;
		}
		index++;
	}

	if (opcode_lib[index].opcode == NULL && op != NULL)
	{
		printf("%s\n", op);
		fprintf(stderr, OP_UNKNOWN, line_number, op);
		fclose(*file);
		free(*file_content);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
