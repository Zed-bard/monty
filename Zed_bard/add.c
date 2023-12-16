#include "monty.h"
/**
 * monty_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void monty_add(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't append, stack too short\n", counter);
		fclose(bus.stackFile);
		free(bus.stackContent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	utility = h->n + h->next->n;
	h->next->n = utility;
	*head = h->next;
	free(h);
}

