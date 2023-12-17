#include "monty.h"


/**
 * add_to_stack - Adds a node to the stack.
 * @utily: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_to_stack(stack_t **utily, __attribute__((unused))unsigned int ln)
{
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

