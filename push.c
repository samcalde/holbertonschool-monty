#include "monty.h"

stack_t *pushfunct(stack_t **stack, unsigned int content)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
		//malloc error
	if (content == NULL)
		//No argument error

	newnode->prev = NULL;
	newnode->n = content; 
	newnode->next = stack;

	(*stack)->prev = newnode;

	stack = newnode;

	return (stack);
}