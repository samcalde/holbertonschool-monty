#include "monty.h"

/**
* main - monty language interpreter
*
* Return: 0 when exiting
*/

int main(void)
{
	ssize_t line_len = 0;
	size_t arg_line_len = 0;
	stack_t **stack;
	char *instruction = NULL, *lines[32];
	const char line_delimiter[] = "\n";
	int i = 1;

	line_len = getline(&instruction, &arg_line_len, stdin);
	lines[0] = strtok(instruction, line_delimiter);
	if (lines[0] == NULL)
		free(instruction);
	else
	{
		for (i = 1; lines[i] != NULL; i++)
		{
			lines[i] = strtok(NULL, line_delimiter);
			if (lines[i] != NULL)
				stack = checkinstruction(lines[i], stack);
		}
		free(instruction);
	}

	return (0);
}