#include "monty.h"

int main(int ac, char **av)
{
	FILE *f;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(av[1], "r");
	if (f == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	parse(av[1], stack);
	fclose(f);
	return (0);
}
