/*
 * stack.h
 *
 *  Created on: 5 janv. 2013
 *      Author: Matthieu
 */

#ifndef STACK_H_
#define STACK_H_

struct Stack
{
	void* marker;
	void* cursor;

	long unsigned int size;
};

void *stack_malloc(struct Stack* stack, long unsigned int size);

void stack_reset(struct Stack* stack);

void stack_putMarker(struct Stack* stack);

void stack_freeToMarker(struct Stack* stack);

struct Stack *stack_new(long unsigned int size);

void stack_delete(struct Stack* stack);

#endif /* STACK_H_ */
