#include "monty.h"

/**
 * controller - call the appropate operation
 * for the stack
 * @line_number: current file line bean read
 * @stack: the head of the
 *
 * Return: nothing
*/

void controller(int line_number, stack_t **stack)
{
	char *op;
	int index;

	instruction_t opcode_lib[] = {
		{"pall", op_pall},
		{"push", op_push},
		{"pint", op_pint},
		{NULL, NULL}
	};

	index = 0;

	op = strtok(global_var.file_content, " \t\n");
		if (op && op[0] == '#')
			return;
	global_var.arg = strtok(NULL, "\t\n");

	while (opcode_lib[index].opcode != NULL && op)
	{
		if ((strcmp(opcode_lib[index].opcode, op)) == 0)
		{
			opcode_lib[index].f(stack, line_number);
			break;
		}
		index++;
	}
	if (opcode_lib[index].opcode == NULL && op)
	{
		fprintf(stderr, OP_UNKNOWN, line_number, op);
		fclose(global_var.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
