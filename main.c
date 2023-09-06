#include "monty.h"

/**
* main - monty language interpreter
*
* Return: 0 when exiting
*/

int main(char **argv, int argc)
{
	stack_t **stack = NULL;
	ssize_t readBytes;
	char *file_content = malloc(1024), *lines[256], filepath;
	const char line_delimiter[] = "\n";
	int i = 1, fd;

	//Malloc failure
	if (argc == 2)
	{
		filepath = argv[1];
		fd = open(filepath, 1024);
		//Error to open
		readBytes = read(fd, file_content, 1024);
		//Error in read (close fd and return error)

		lines[0] = strtok(file_content, line_delimiter);
		if (lines[0] == NULL)
			free(file_content);
		else
		{
			checkinstruction(lines[0], stack, 1);
			for (i = 1; lines[i] != NULL; i++)
			{
				lines[i] = strtok(NULL, line_delimiter);
				if (lines[i] != NULL)
					checkinstruction(lines[i], stack, (i + 1));
			}
			free(instruction);
		}
	}
	else
		//ERROR USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE

	return (0);
}