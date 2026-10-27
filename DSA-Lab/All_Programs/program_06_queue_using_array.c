#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

/* check if queue is full */
int isFull() {
    return rear == MAX - 1;
}

/* check if queue is empty */
int isEmpty() {
    return front == -1 || front > rear;
}

/* insert an element at the rear of the queue */
void enqueue(int val) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = val;
    printf("Enqueued %d\n", val);
}

/* remove an element from the front of the queue */
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued %d\n", queue[front]);
    front++;
}

/* view the front element without removing it */
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

/* print all elements of the queue */
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front -> rear): ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
