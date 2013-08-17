/*
 * stack.c
 *
 *  Created on: 5 janv. 2013
 *      Author: Matthieu
 */

#include <stdio.h>
#include <stdlib.h>

#include "../headers/stack.h"

struct Stack *stack_new(long unsigned int size)
{
	struct Stack* stack = malloc(sizeof(struct Stack) + size);

	if ( stack != NULL)
	{
		stack->cursor = stack;
		stack->marker = stack;
		stack->size   = size;
	}

	return (stack);
}

void stack_delete(struct Stack* stack)
{
	if ( stack != NULL )
	{
		free(stack);
	}
}

void *stack_malloc(struct Stack* stack, long unsigned int size)
{
	void* ptr = NULL;

	if ( stack != NULL)
	{
		// next position of the cursor if the "allocation" is successful
		void* nextCursor = stack->cursor;
		nextCursor += size;

		// cursors limit position
		void* cursorMax = stack;
		cursorMax += stack->size;

		if ( size > 0 && nextCursor <= cursorMax )
		{
			ptr = stack->cursor;
			stack->cursor += size;

			//printf("Allocated %d bytes successfully, %d bytes left.\n", size, cursorMax-nextCursor);
		}
		else
		{
			//printf("%d bytes missing to allocate %d bytes.\n", size, nextCursor-cursorMax);
		}
	}

	return (ptr);
}

void stack_reset(struct Stack* stack)
{
	if ( stack != NULL)
	{
		stack->marker = stack;
		stack->cursor = stack;
	}
}

void stack_putMarker(struct Stack* stack)
{
	if ( stack != NULL )
	{
		stack->marker = stack->cursor;
		//printf("Marker positioned after %d bytes.\n", stack->marker- (void*)stack);
	}
}

void stack_freeToMarker(struct Stack* stack)
{
	if ( stack != NULL)
	{
		//printf("Freeing %d bytes.\n", stack->cursor-stack->marker);
		stack->cursor = stack->marker;
	}
}
