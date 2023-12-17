#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
<<<<<<< HEAD
	fileRead(argv[1]);
	free_nodes();
=======
	FILE *f = fopen(av[1], "r");
	if (f == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	parse(av[1], stack);
	fclose(f);
>>>>>>> 24cba3a8edffb129e79ed19a2f4b6269ece84e2f
	return (0);
}

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *currentElement;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		currentElement = head;
		head = head->next;
		free(currentElement);
	}
}


/**
 * add_to_queue - Adds a node to the queue.
 * @utily: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **utily, __attribute__((unused))unsigned int ln)
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
	while (currentElement->next != NULL)
		currentElement = currentElement->next;

	currentElement->next = *utily;
	(*utily)->prev = currentElement;

}

