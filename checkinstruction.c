#include "monty.h"

/**
* checkinstruction - monty language interpreter
*
* Return: 0 when exiting
*/

stack_t *checkinstruction(char *line, stack_t **stack, int line_number)
{
	char *command[32];
	const char token_delimiter[] = " \t";
	int i = 1;

	command[0] = strtok(line, token_delimiter);

	if (command[0] == NULL)
		return (stack);
	else
		command[1] = strtok(NULL, token_delimiter);

	i = 0;
	while (cases[i].opcode != NULL)
	{
		if (strcmp(cases[i].opcode, command[0]) == 0)
		{
			cases[i].f(stack, atoi(command[1]));
			break;
		}
		i++;
	}
	//Handle unknown command

	return (stack);
}