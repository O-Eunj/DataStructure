#ifndef LIST_H
#define LIST_H

typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct list {
	Node* head;
	Node* tail;
	int size;
}List;

void initialize(List* list);
void add(List* list, int value);
void insert(List* list, Node* target, int value);
void erase(List* list, Node* target);
Node* find(List* list, int target);
void reverse(List* list);
void sort(List* list);
void clear(List* list);
void print_list(List* list);

#endif
