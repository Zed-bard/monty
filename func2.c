#include "monty.h"

/**
 * pint - print the value at the top of the stack
 * @stack: stack
 * @line_number: line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the value at the top of the stack
 * @stack: stack
 * @line_number: line number
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	head = (*stack)->next;
	free(*stack);
	*stack = head;
}	
