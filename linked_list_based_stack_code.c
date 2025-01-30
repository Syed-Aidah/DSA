#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initStack(struct Stack* stack) {
    stack->top = NULL;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    } else {
        struct Node* temp = stack->top;
        int poppedValue = temp->data;
        stack->top = stack->top->next;
        free(temp);
        printf("Popped %d from the stack.\n", poppedValue);
        return poppedValue;
    }
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);

    int numElements, value;

    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &numElements);

    for (int i = 1; i <= numElements; i++) {
        printf("Enter value for element %d: ", i);
        scanf("%d", &value);
        push(&stack, value);
    }

    display(&stack);

    char choice;
    do {
        printf("Do you want to pop an element from the stack? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            pop(&stack);
            display(&stack);
        } else if (choice != 'n' && choice != 'N') {
            printf("Invalid input! Please enter 'y' or 'n'.\n");
        }

    } while (choice != 'n' && choice != 'N');

    return 0;
}
