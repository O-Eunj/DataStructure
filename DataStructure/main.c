#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "list.h"

void stack_menu(Stack* stack) {
    int num, temp;
    while (1) {
        printf("1.Add\n");
        printf("2.Pop\n");
        printf("3.Print\n");
        printf("4.Clear\n");
        printf("0.Back\n");
        printf("Enter your choice\n");
        scanf("%d", &num);

        if (num == 0) return;

        switch (num) {
        case 1:
            if (full_stack(stack)) {
                printf("Stack is full\n");
            }
            else {
                printf("Enter a number: ");
                scanf("%d", &temp);
                push_stack(stack, temp);
            }
            break;

        case 2:
            if (empty_stack(stack)) {
                printf("Stack is empty\n");
            }
            else {
                pop_stack(stack, &temp);
                printf("Popped: %d\n", temp);
            }
            break;

        case 3:
            if (empty_stack(stack)) {
                printf("Stack is empty\n");
            }
            else {
                printf("Stack:");
                for (int i = stack->pos; i >= 0; i--) {
                    printf("%d ", stack->data[i]);
                }
            }
            printf("\n");
            break;

        case 4:
            init_stack(stack);
            printf("Clear Stack\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    }
}

void queue_menu(Queue* queue) {
    int num, temp;
    while (1) {
        printf("1.Add\n");
        printf("2.Pop\n");
        printf("3.Print\n");
        printf("4.Clear\n");
        printf("0.Back\n");
        printf("Enter your choice\n");
        scanf("%d", &num);

        if (num == 0) return;

        switch (num) {
        case 1:
            if (full_queue(queue)) {
                printf("Queue is full\n");
            }
            else {
                printf("Enter a number: ");
                scanf("%d", &temp);
                push_queue(queue, temp);
            }
            break;

        case 2:
            if (empty_queue(queue)) {
                printf("Queue is empty\n");
            }
            else {
                pop_queue(queue, &temp);
                printf("Popped: %d\n", temp);
            }
            break;

        case 3:
            if (empty_queue(queue)) {
                printf("Queue is empty\n");
            }
            else {
                int i = queue->head;
                printf("Queue:");
                for (int cnt = 0; cnt < queue->size; cnt++) {
                    printf("%d ", queue->data[i]);
                    i = (i + 1) % MAX_QUEUE;
                }
            }
            printf("\n");
            break;

        case 4:
            init_queue(queue);
            printf("Clear Queue\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    }
}
void list_menu(List* list) {
    int num, target, value;
    while (1) {
        printf("1.Add\n");
        printf("2.Insert\n");
        printf("3.Erase\n");
        printf("4.Reverse\n");
        printf("5.Sort\n");
        printf("6.Clear\n");
        printf("0.Back\n");
        printf("Enter your choice\n");
        scanf("%d", &num);

        if (num == 0) return;

        switch (num) {
        case 1:
            printf("Add: ");
            scanf("%d", &value);
            add(list, value);
            print_list(list);
            printf("\n");
            break;

        case 2:
            if (list->size == 0) {
                printf("Insert: ");
                scanf("%d", &value);
                add(list, value);
                print_list(list);
                printf("\n");
            }
            else {
                printf("Insert (target value): ");
                scanf("%d", &target);
                printf("Next value to target: ");
                scanf("%d", &value);
                Node* targetnode = find(list, target);
                if (targetnode == NULL) {
                    printf("Target node not found!\n");
                    print_list(list);
                    printf("\n");
                }
                else {
                    insert(list, targetnode, value);
                    print_list(list);
                    printf("\n");
                }
            }
            break;

        case 3:
            if (list->size == 0) {
                printf("Empty");
                printf("\n");
            }
            else {
                printf("Erase target: ");
                scanf("%d", &target);
                Node* targetnode = find(list, target);
                if (targetnode == NULL) {
                    printf("Target node not found!\n");
                    print_list(list);
                    printf("\n");
                }
                else {
                    erase(list, targetnode);
                    print_list(list);
                    printf("\n");
                }
            }
            break;

        case 4:
            if (list->size == 0) {
                printf("Empty");
                printf("\n");
            }
            else if (list->size == 1) {
                print_list(list);
                printf("\n");
            }
            else {
                reverse(list);
                print_list(list);
                printf("\n");
            }
            break;

        case 5:
            if (list->size == 0) {
                printf("Empty");
                printf("\n");
            }
            else if (list->size == 1) {
                print_list(list);
                printf("\n");
            }
            else {
                sort(list);
                print_list(list);
                printf("\n");
            }
            break;

        case 6:
            clear(list);
            printf("Clear\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    }
}

int main(void) {

    Stack stack;
    Queue queue;
    List list;

    init_stack(&stack);
    init_queue(&queue);
    initialize(&list);

    int num, temp, target, value;

    while (1) {
        printf("MENU\n");
        printf("1.Stack\n");
        printf("2.Queue\n");
        printf("3.List\n");
        printf("4.Quit\n");
        printf("Enter your choice\n");
        scanf("%d", &num);

        switch (num) {
            case 1 :
                stack_menu(&stack);
                break;

            case 2 :
                queue_menu(&queue);
                break;

            case 3 :
                list_menu(&list);
                break;

            case 4 :
                printf("Exiting program\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;

}
/*int main(void) {
    Stack stack;
    Queue queue;

    init_stack(&stack);
    init_queue(&queue);

    int num, temp;

    while (1) {
        printf("MENU\n");
        printf("1.Add to Stack\n");
        printf("2.Add to Queue\n");
        printf("3.Pop Stack\n");
        printf("4.Pop Queue\n");
        printf("5.Print Stack\n");
        printf("6.Print Queue\n");
        printf("7.Clear Stack\n");
        printf("8.Clear Queue\n");
        printf("9.Quit\n");
        printf("Enter your choice\n");
        scanf("%d", &num);

        switch (num) {
        case 1:
            if (full_stack(&stack)) {
                printf("Stack is full\n");
            }
            else {
                printf("Enter a number: ");
                scanf("%d", &temp);
                push_stack(&stack, temp);
            }
            break;

        case 2:
            if (full_queue(&queue)) {
                printf("Queue is full\n");
            }
            else {
                printf("Enter a number: ");
                scanf("%d", &temp);
                push_queue(&queue, temp);
            }
            break;

        case 3:
            if (empty_stack(&stack)) {
                printf("Stack is empty\n");
            }
            else {
                pop_stack(&stack, &temp);
                printf("Popped: %d\n", temp);
            }
            break;

        case 4:
            if (empty_queue(&queue)) {
                printf("Queue is empty\n");
            }
            else {
                pop_queue(&queue, &temp);
                printf("Popped: %d\n", temp);
            }
            break;

        case 5:
            if (empty_stack(&stack)) {
                printf("Stack is empty\n");
            }
            else {
                printf("Stack:");
                for (int i = stack.pos; i >= 0; i--) {
                    printf("%d ", stack.data[i]);
                }
            }
            printf("\n");
            break;

        case 6:
            if (empty_queue(&queue)) {
                printf("Queue is empty\n");
            }
            else {
                int i = queue.head;
                printf("Queue:");
                for (int cnt = 0; cnt < queue.size; cnt++) {
                    printf("%d ", queue.data[i]);
                    i = (i + 1) % MAX_QUEUE;
                }
            }
            printf("\n");
            break;

        case 7:
            init_stack(&stack);
            printf("Clear Stack\n");
            break;

        case 8:
            init_queue(&queue);
            printf("Clear Queue\n");
            break;

        case 9:
            printf("Exiting program\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}*/