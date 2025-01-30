#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        stack->arr[++(stack->top)] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    } else {
        int poppedValue = stack->arr[stack->top--];
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
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);

    int numElements, value;

    printf("Enter the number of elements to push onto the stack (max %d): ", MAX);
    scanf("%d", &numElements);

    if (numElements > MAX) {
        printf("Cannot push more than %d elements.\n", MAX);
        return 0;
    }

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
