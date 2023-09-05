#include "monty.h"

/**
* checkinstruction - monty language interpreter
*
* Return: 0 when exiting
*/

stack_t *checkinstruction(char *line, stack_t *stack)
{
	char *tokens[32];
	const char token_delimiter[] = " \t";
	int i = 1;

	tokens[0] = strtok(line, token_delimiter);
	
	if (tokens[0] == NULL)
		return (stack);
	else
		tokens[1] = strtok(NULL, token_delimiter);

	i = 0;
	while (cases[i].opcode != NULL)
	{
		if (strcmp(cases[i].opcode, tokens[0]) == 0)
			cases[i].f(stack, atoi(tokens[1]));
	}

	return (stack);
}