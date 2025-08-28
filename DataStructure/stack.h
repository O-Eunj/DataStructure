#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_STACK 5

typedef struct { 
	int data[MAX_STACK];
	int pos; 
} Stack;

void init_stack(Stack* s);
bool empty_stack(Stack* s);
bool full_stack(Stack* s);
void push_stack(Stack* s, int value);
bool pop_stack(Stack* s, int *value);

#endif
