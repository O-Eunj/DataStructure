#include "stack.h"

void init_stack(Stack* s) {
	s->pos = -1;
}

bool empty_stack(Stack* s) {
	return (s->pos == -1);
}

bool full_stack(Stack* s) {
	return (s->pos == MAX_STACK - 1);
}

void push_stack(Stack* s, int value) {
	if (!full_stack(s)) s->data[++s->pos] = value;
}

bool pop_stack(Stack* s, int* value) {
	if (empty_stack(s)) return false;
	*value = s->data[s->pos--];
	return true;
}