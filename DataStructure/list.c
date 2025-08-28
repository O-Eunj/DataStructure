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

void insert(List* list, Node* target, int value) {
	if (list->size != 0) {
		Node* new = (Node*)malloc(sizeof(Node));
		new->data = value;
		if (target->next == NULL) {
			target->next = new;
			new->next = NULL;
			list->tail = new;
			++list->size;
		}
		else {
			new->next = target->next;
			target->next = new;
			++list->size;
		}
	}
}

void erase(List* list, Node* target) {
	if (list->size != 0) {
		if (list->head == target) {
			list->head = target->next;
			if (list->tail == target) {
				list->tail = NULL;
			}
			free(target);
			--list->size;
		}

		Node* cur = list->head;
		while (cur->next != NULL && cur->next != target) {
			cur = cur->next;
		}

		if (cur->next == target) {
			cur->next = target->next;
			if (list->tail == target)
				list->tail = cur;
			free(target);
			--list->size;
		}
	}
}

Node* find(List* list, int target) {
	Node* cur = list->head;
	while (cur != NULL) {
		if (cur->data == target) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
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