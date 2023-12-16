#include "monty.h"
#include <stdio.h>

/**
 * parse - parses input
 * @file_name - file
 * @stack: stack
 * Return: some args
 */

extern int arg;

char *parse(FILE *f, stack_t *stack)
{
	int i = 0;
	instruction_t funs[] = {{"push", push}, {NULL, NULL}};
	char *line = NULL;
	unsigned int line_number = 0;
	char *command = NULL;
	size_t len = 0;
	ssize_t read;
		
	while ((read = getline(&line, &len, f)) != -1)
	{
		line_number++;
		command = strtok(line, " \t\n");
		if (command == NULL)
		{
			free(line);
			continue;
		}
		helper.arg = atoi(strtok(NULL, " \t\n"));
		while (funs[i].opcode != NULL)
		{
			if (strcmp(command, funs[i].opcode) == 0)
			{
				funs[i].f(&stack, line_number);
				break;
			}
			i++;
		}
		if (funs[i].opcode == NULL)
		{
			dprintf(2, "L%d: unknown instruction %s\n", line_number, command);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = NULL;
		i = 0;
	}
	free(line);
	exit(EXIT_SUCCESS);
}

/**
 * push - pushes value to stack
 * @stack: stack
 * @line_number: line_number
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!helper.arg)
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = helper.arg;
	new->next = (*stack);
	new->prev = NULL;
	(*stack) = new;
}
