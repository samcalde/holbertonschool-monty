#include "monty.h"

/**
* main - monty language interpreter
*
* Return: 0 when exiting
*/

int main(int argc, char **argv)
{
	stack_td *stack = malloc(sizeof(stack_td));
	ssize_t readBytes;
	char *file_content = malloc(30000), *lines[4000], *filepath;
	const char line_delimiter[] = "\n";
	int i = 1, fd;
	
	if (file_content == NULL || stack == NULL)
		printf("Error: malloc failed\n");
	if (argc == 2)
	{
		filepath = argv[1];
		fd = open(filepath, O_RDONLY);
		if (fd < 0)
		{
			printf("Error: Can't open file %s\n", filepath);
		}
		readBytes = read(fd, file_content, 1024);
		if (readBytes < 0)
		{
			close(fd);
			return (0);
		}

		lines[0] = strtok(file_content, line_delimiter);
		if (lines[0] == NULL)
			free(file_content);
		else
		{
			for (i = 1; lines[i - 1] != NULL; i++)
			{
				lines[i] = strtok(NULL, line_delimiter);
			}
			checkinstruction(lines[0], (&stack), 1);
			for (i = 1; lines[i - 1] != NULL; i++)
			{
				checkinstruction(lines[i], (&stack), (i + 1));
			}
			free(file_content);
			close(fd);
		}
	} 
	if (argc != 2)
	{
		free(file_content);
		free(stack);
		//ERROR USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
	}
	return (0);
}
