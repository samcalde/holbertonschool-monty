#include "monty.h"

void pallfunct(stack_td **stack, __attribute__((unused)) char *content, __attribute__((unused))int line_number)
{
	stack_td *currentnode = (*stack);

	while (currentnode->next != NULL)
	{
		printf("%d\n", currentnode->n);
		currentnode =  currentnode->next;
	}

	return;
}

void pintfunct(stack_td **stack, __attribute__((unused)) char *content, int line_number)
{
	if (stack != NULL)
		printf("%d\n", (*stack)->n);
	else
		printf("L%d: can't pint, stack empty\n", line_number);
	
	return;
}

void popfunct(stack_td **stack, __attribute__((unused)) char *content, int line_number)
{
	stack_td *currentnode = (*stack);

	if (stack != NULL)
	{
		free(currentnode);
		currentnode =  currentnode->next;
		(*stack) = currentnode;
	}
	else
		printf("L%d: can't pop an empty stack\n", line_number);

	return;
}

void swapfunct(stack_td **stack, __attribute__((unused)) char *content, int line_number)
{
	stack_td *secondnode = (*stack);

	if ((*stack)->next != NULL)
	{
		secondnode = secondnode->next;
		(*stack)->next = secondnode->next;
		(*stack)->prev = secondnode;
		secondnode->next = (*stack);
		secondnode->prev = NULL;
		(*stack) = secondnode;
	}
	else
		printf("L%d: can't swap, stack too short\n", line_number);
	
	return;
}

void addfunct(stack_td **stack, __attribute__((unused)) char *content, int line_number)
{
	stack_td *currentnode = (*stack);
	int temporal = 0;

	if ((*stack)->next != NULL)
	{
		temporal = currentnode->n;
		free(currentnode);
		currentnode = currentnode->next;
		currentnode->n = (currentnode->n) + temporal;
		(*stack) = currentnode;
	}
	else
		printf("L%d: can't add, stack too short\n", line_number);

	return;
}

void nopfunct(__attribute__((unused)) stack_td **stack, __attribute__((unused)) char *content, __attribute__((unused)) int line_number)
{
	return;
}

void freestack(stack_td **stack)
{
	stack_td *currentnode = (*stack);

	while (currentnode->next != NULL)
	{
		free(currentnode);
		currentnode =  currentnode->next;
	}

	return;
}
