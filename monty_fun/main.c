#include "monty.h"

int main(int ac, char **av)
{
	stack_t *stack = NULL;
	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(av[1], "r");
	if (file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	parse(file, stack);
	fclose(file);
	return (0);
}
