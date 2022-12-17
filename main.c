#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

global_t global_var = {NULL, NULL, NULL};

/**
* main - monty code interpreter
* @argc: argument count
* @argv: argument value
*
* Return: 0 on success
*/


int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	int line_number = 0;
	size_t file_content_count = 0;

	if (argc != 2)
	{
		fprintf(stderr, USAGE);
		exit(EXIT_FAILURE);
	}
	global_var.file = fopen(argv[1], "r");

	if (global_var.file == NULL)
	{
		fprintf(stderr, FILE_ERROR, argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&global_var.file_content,
	&file_content_count, global_var.file)) != -1)
	{
		line_number++;
		controller(line_number, &stack);
	}

	fclose(global_var.file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
