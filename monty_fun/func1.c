#include "monty.h"
<<<<<<< HEAD
=======

/**
 * parse - parses input
 * @file_name - file
 * @stack: stack
 * Return: some args
 */

extern int arg;
>>>>>>> 24cba3a8edffb129e79ed19a2f4b6269ece84e2f


/**
 * add_to_stack - Adds a node to the stack.
 * @utily: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_to_stack(stack_t **utily, __attribute__((unused))unsigned int ln)
{
<<<<<<< HEAD
	stack_t *currentElement;

	if (utily == NULL || *utily == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *utily;
		return;
	}
	currentElement = head;
	head = *utily;
	head->next = currentElement;
	currentElement->prev = head;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
=======
	int i = 0;
	instruction_t funs[] = {{"push", push}, {NULL, NULL}};
	char *line = NULL;
	unsigned int line_number = 0;
	char *command = NULL, *argument = NULL;
	size_t len = 0;
	ssize_t read;

	FILE *f = fopen(file_name, "r");
	if (f == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
		
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
>>>>>>> 24cba3a8edffb129e79ed19a2f4b6269ece84e2f
{
	stack_t *currentElement;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	currentElement = *stack;
	while (currentElement != NULL)
	{
		printf("%d\n", currentElement->n);
		currentElement = currentElement->next;
	}
<<<<<<< HEAD
=======
	new->n = helper.arg;
	new->next = (*stack);
	new->prev = NULL;
	(*stack) = new;
>>>>>>> 24cba3a8edffb129e79ed19a2f4b6269ece84e2f
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *currentElement;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	currentElement = *stack;
	*stack = currentElement->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(currentElement);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}

