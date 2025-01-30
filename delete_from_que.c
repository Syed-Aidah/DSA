#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d.\n", value);
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX;
        queue->arr[queue->rear] = value;
        printf("Enqueued %d to the queue.\n", value);
    }
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return -1;
    } else {
        int dequeuedValue = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX;
        }
        printf("Dequeued %d from the queue.\n", dequeuedValue);
        return dequeuedValue;
    }
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue->arr[queue->rear]);
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    int numElements, value;

    printf("Enter the number of elements to enqueue (max %d): ", MAX);
    scanf("%d", &numElements);

    if (numElements > MAX) {
        printf("Cannot enqueue more than %d elements.\n");
        return 0;
    }

    for (int i = 1; i <= numElements; i++) {
        printf("Enter value for element %d: ", i);
        scanf("%d", &value);
        enqueue(&queue, value);
    }

    display(&queue);

    char choice;
    do {
        printf("Do you want to dequeue an element from the queue? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            dequeue(&queue);
            display(&queue);
        } else if (choice != 'n' && choice != 'N') {
            printf("Invalid input! Please enter 'y' or 'n'.\n");
        }

    } while (choice != 'n' && choice != 'N');

    return 0;
}
