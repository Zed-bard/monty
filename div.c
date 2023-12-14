#include "monty.h"
/**
 * monty_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void monty_div(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, utility;

	h = *head;
	while (h)
	{
		h = h->next;

		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't divide, stack too short\n", counter);
		fclose(bus.stackFile);
		free(bus.stackContent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by null\n", counter);
		fclose(bus.stackFile);
		free(bus.stackContent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	utility = h->next->n / h->n;
	h->next->n = utility;
	*head = h->next;
	free(h);
}

