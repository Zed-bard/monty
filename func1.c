#include "monty.h"

/**
 * free_stack - frees stack
 * @stack: stack
 */

void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		(*stack) = temp;
	}
}

/**
 * is_int - checks for an integer
 * @str: string to check
 * Return: 0 or 1
 */

int is_int(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
/**
 * parse - parses input
 * @file_name - file
 * @stack: stack
 */

void parse(FILE *f, stack_t **stack)
{
	int i = 0;
	instruction_t funs[] = {{"push", push}, {"pall", pall}, {"pop", pop},
				{"pint", pint}, {"swap", swap}, {NULL, NULL}};
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
			continue;
		helper.arg = strtok(NULL, " \t\n");
		while (funs[i].opcode != NULL)
		{
			if (strcmp(command, funs[i].opcode) == 0)
			{
				funs[i].f(&(*stack), line_number);
				break;
			}
			i++;
		}
		if (funs[i].opcode == NULL)
		{
			dprintf(2, "L%d: unknown instruction %s\n", line_number, command);
			free(*stack);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = NULL;
		i = 0;
	}
	free(line);
}

/**
 * push - pushes value to stack
 * @stack: stack
 * @line_number: line_number
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	if (!is_int(helper.arg))
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(helper.arg);
	new->next = (*stack);
	new->prev = NULL;
	(*stack) = new;
}

/**
 * pall - prints all values on the stack
 * @stack: stack
 * @line_number: line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}
