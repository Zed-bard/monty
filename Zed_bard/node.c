#include "monty.h"
/**
 * add_Node - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void add_Node(stack_t **head, int n)
{

	stack_t *current, *utility;

	utility = *head;
	current = malloc(sizeof(stack_t));
	if (current == NULL)
	{ printf("Error\n");
		exit(0); }
	if (utility)
		utility->prev = current;
	current->n = n;
	current->next = *head;
	current->prev = NULL;
	*head = current;
}

