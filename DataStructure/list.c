#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initialize(List* list) {
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

}

void add(List* list, int value) {
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = value;
	new->next = NULL;

	if (list->size == 0) {
		list->head = new;
	}
	else {
		list->tail->next = new;
	}
	list->tail = new;
	++list->size;
}

void insert(List* list, int index, int value) {
	if (list->size != 0) {
		Node* new = (Node*)malloc(sizeof(Node));
		new->data = value;
		Node* pre = NULL;
		Node* cur = list->head;
		for (int i = 0; i < index; i++) {
			pre = cur;
			cur = cur->next;
		}
		new->next = cur->next;
		cur->next = new;
		if (new->next == NULL) list->tail = new;
		++list->size;
	}
}

void erase(List* list, int index) {
	if (list->size != 0) {
		Node* pre = NULL;
		Node* cur = list->head;
		for (int i = 0; i < index; i++) {
			pre = cur;
			cur = cur->next;
		}
		if (pre == NULL) {
			list->head = cur->next;
		}
		else {
			pre->next = cur->next;
		}
		if (cur == list->tail) list->tail = pre;
		free(cur);
		--list->size;
	}
}

Node* find(List* list, int target) {
	Node* cur = list->head;
	int index = 0;
	int found = 0;
	while (cur != NULL) {
		if (cur->data == target) {
			printf("index %d ", index);
			found = 1;
		}
		cur = cur->next;
		index++;
	}
	if (!found) {
		printf("Target node not found\n");
	}
	printf("\n");
}

void reverse(List* list) {
	if (list->size > 1) {
		Node* pre = NULL;
		Node* cur = list->head;
		Node* next = NULL;
		list->tail = list->head;

		while (cur != NULL) {
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		list->head = pre;
	}

}

void sort(List* list) {
	if (list->size > 1) {
		for (Node* i = list->head; i != NULL; i = i->next) {
			for (Node* j = i->next; j != NULL; j = j->next) {
				if (i->data > j->data) {
					int temp = i->data;
					i->data = j->data;
					j->data = temp;
				}
			}
		}

	}
}

void clear(List* list) {
	Node* cur = list->head;
	while (cur) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
	list->head = list->tail = NULL;
	list->size = 0;
}

void print_list(List* list) {
	for (Node* p = list->head; p != NULL; p = p->next)
		printf("[%d] ", p->data);

}