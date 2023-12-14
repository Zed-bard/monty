#include "monty.h"

int main(int ac, char **av)
{
	stack_t *stack = NULL;
	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	parse(av[1], stack);
	fclose(file);
	return (0);
}
