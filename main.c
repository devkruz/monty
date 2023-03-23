#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"


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
	char *file_content = NULL;
	size_t file_content_size = 0;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, USAGE);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, FILE_ERROR, argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&file_content,
	&file_content_size, file)) != -1)
	{
		line_number++;
		controller(line_number, &stack, &file_content, &file);
	}

	fclose(file);
	free(file_content);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
