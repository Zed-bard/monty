#include "monty.h"
#include <stdio.h>

char *parse(char *file_name, stack_t *stack)
{
	int i = 0;
	instruction_t funs[] = {{"push", push}, {NULL, NULL}};
	char *line = NULL;
	unsigned int line_number = 0;
	char command[4];
	size_t *n;

	FILE *f = fopen(file_name, "r");
	if (f == NULL)
	{
		
	while (getline(&line, n, file) != -1)
	{
		line_number++;
		command = strtok(line, " \t\n");
		argument = strtok(NULL, " \t\n");
		while (funs[i].opcode != NULL)
		{
			if (strcmp(command, funs[i].opcode) == 0)
			{
				funs[i].f(stack, line_number);
				free(line);
			}
			i++;
		}
		free(line);
		fclose();
		dprintf(2, "L%d: unknown instruction %s\n", line_number, command);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = get_arg();
	new->next = (*stack);
	new->prev = NULL;
	(*stack) = new;
}
