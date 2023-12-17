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

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - add the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - does nothing
 * @stack: stack
 * @line_number: line number
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
