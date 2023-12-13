# 0x19. C - Stacks, Queues - LIFO, FIFO

**project Info:** In this project, we created a simple interpreter for Monty ByteCodes. The interpreter reads a bytecode file and executes the bytecode commands.
## Requirements
- Allowed editors: vi, vim, emacs
- All files compiled on Ubuntu 20.04 LTS using gcc with options -Wall -Werror -Wextra -pedantic -std=c89
- All files should end with a new line
- README.md file at the root of the project folder is mandatory
- Code should use the Betty style, checked with betty-style.pl and betty-doc.pl
- Maximum of one global variable allowed
- No more than 5 functions per file
- C standard library is allowed
- Prototypes of all functions should be included in the header file "monty.h"
- Don't forget to push your header file
- All header files should be include guarded
- Tasks are expected to be done in the order shown in the project

**About:** In this project, a simple interpreter for Monty ByteCodes was created. The interpreter reads a bytecode file and executes the bytecode commands.

### The Monty language

Monty 0.98 is a scripting language compiled into Monty byte codes, similar to Python. It relies on a unique stack with specific instructions to manipulate it.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. There is not more than one instruction per line, and there can be any number of spaces before or after the opcode and its argument.

## Compilation & Output
- Compiled using: `gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
- Output must be printed on `stdout`
- Error messages must be printed on `stderr`

# Project Categories

### Mandatory:-
| **Task** | **Description** |
| --- | --- |
| **1.** *push, pall* | Implement the push and pall opcodes. |
| **2.** *pint* | Implement the pint opcode. |
| **3.** *pop* | Implement the pop opcode. |
| **4.** *swap* | Implement the swap opcode. |
| **5.** *add* | Implement the add opcode. |
| **6.** *nop* | Implement the nop opcode. |

### Advanced:-
| **Task** | **Description** |
| --- | --- |
| **7.** *sub* | Implement the sub opcode. |
| **8.** *div* | Implement the div opcode. |
| **9.** *mul* | Implement the mul opcode. |
| **10.** *mod* | Implement the mod opcode. |
| **11.** *comments* | Treat lines starting with # as comments. |
| **12.** *pchar* | Implement pchar opcode to print the char at the top of the stack, followed by a new line. |
| **13.** *pstr* | Implement pstr opcode to print the string starting at the top of the stack, followed by a new line. |
| **14.** *rotl* | Implement rotl opcode to rotate the stack to the top. |
| **15.** *rotr* | Implement rotr opcode to rotate the stack to the bottom. |
| **16.** *stack, queue* | Implement stack and queue opcodes to set the format of the data to stack (LIFO) or queue (FIFO). |
| **17.** *Brainf*ck* | Write a Brainf*ck script that prints School, followed by a new line. |
| **18.** *Add two digits* | Add two digits given by the user. |
| **19.** *Multiplication* | Multiply two digits given by the user. |
| **20.** *Multiplication level up* | Multiply two digits given by the user. |
# AUTHOURS
[zerihun Shiferaw](https://github.com/Zed-bard)
[Abenezer Endalew](https://github.com/abeni-al7)
