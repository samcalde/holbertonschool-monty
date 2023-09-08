#include "monty.h"

void pushfunct(stack_td **stack, char *content, int line_number)
{
	stack_td *newnode = malloc(sizeof(stack_td));
	int num = 0;

	if (content == NULL)
	{
		printf("L%d: usage: push integer", line_number);
	}
	if (newnode == NULL)
		printf("Error: malloc failed\n");

	num = atoi(content);

	newnode->prev = NULL;
	newnode->n = num; 
	newnode->next = (*stack);

	(*stack)->prev = newnode;

	(*stack) = newnode;
	return;
}
