#ifndef MONTY_HEADER
#define MONTY_HEADER

/* lOADING MAIN_LIBRARIES*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct monty_data_s - Represents Monty's data.
 * @arg: The argument for Monty's operation.
 * @file: The file being processed by Monty.
 * @content: The content of the file being processed.
 * @lifi: The lifo/fifo mode indicator.
 *
 * Description: This structure defines Monty's data, which includes various
 * elements required for processing Monty commands. It consists of the argument
 * for Monty's operation, the file being processed, the content of the file,
 * and the lifo/fifo mode indicator. It is used to store and manage the data
 * needed during Monty's execution.
 */
typedef struct monty_data_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  monty_data_t;

extern monty_data_t custom_data;

/**
 * struct monty_command_s - Represents a Monty command.
 * @opcode: The opcode of the command.
 * @f: Pointer to the function that executes the command.
 *
 * Description: This structure defines a Monty command, which consists of an
 * opcode (a string representing the command) and a function pointer to the
 * implementation of the command. It is used to associate an opcode with its
 * corresponding function for execution.
 */
typedef struct monty_command_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} monty_command_t;

/* Fuctions Prototype */

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
/* push */
void monty_push(stack_t **head, unsigned int number);
/* pall */
void monty_pall(stack_t **head, unsigned int number);
/* pint */
void monty_pint(stack_t **head, unsigned int number);
/*execute */
int exe(char *content, stack_t **head, unsigned int counter, FILE *file);
/*execute */
void free_stack(stack_t *head);
/*pop */
void monty_pop(stack_t **head, unsigned int counter);
/*swap */
void monty_swap(stack_t **head, unsigned int counter);
/*add */
void monty_add(stack_t **head, unsigned int counter);
/*nop */
void monty_nop(stack_t **head, unsigned int counter);
/*sub */
void monty_sub(stack_t **head, unsigned int counter);
/*execute */
void monty_div(stack_t **head, unsigned int counter);
/*mul */
void monty_mul(stack_t **head, unsigned int counter);
/*mod */
void monty_mod(stack_t **head, unsigned int counter);
/*execute */
void monty_pchar(stack_t **head, unsigned int counter);
/*pstr */
void monty_pstr(stack_t **head, unsigned int counter);
/*rotl */
void monty_rotl(stack_t **head, unsigned int counter);
/*execute */
void monty_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
/*rotr */
void add_Node(stack_t **head, int n);
/*addqueue */
void addqueue(stack_t **head, int n);
/*queue */
void monty_queue(stack_t **head, unsigned int counter);
/*stack */
void monty_stack(stack_t **head, unsigned int counter);

#endif /*MONTY_HEADER*/

