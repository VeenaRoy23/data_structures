#include <stdio.h>
#define MAX 5
int front = -1, rear = -1;
int queue[MAX];

void nqueue(int a) {
    if ((front == 0 && rear == MAX - 1)  (rear + 1 == front)) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = a;
        printf("%d is Enqueued\n", a);
    } else if (front != 0 && rear == MAX - 1) {
        rear = 0;
        queue[rear] = a;
        printf("%d is Enqueued\n", a);
    } else {
        rear++;
        queue[rear] = a;
        printf("%d is Enqueued\n", a);
    }
}

void dqueue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else if (front == rear) {
        printf("Dequeuing %d\n", queue[front]);
        front = rear = -1;
    } else if (front == MAX - 1) {
        printf("Dequeuing %d\n", queue[front]);
        front = 0;
    } else {
        printf("Dequeuing %d\n", queue[front]);
        front++;
    }
}

void insertFront(int a) {
    if ((front == 0 && rear == MAX - 1)  (rear + 1 == front)) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[front] = a;
        printf("%d is Enqueued at the front\n", a);
    } else if (front == 0) {
        front = MAX - 1;
        queue[front] = a;
        printf("%d is Enqueued at the front\n", a);
    } else {
        front--;
        queue[front] = a;
        printf("%d is Enqueued at the front\n", a);
    }
}

void deleteRear() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else if (front == rear) {
        printf("Dequeuing %d\n", queue[rear]);
        front = rear = -1;
    } else if (rear == 0) {
        printf("Dequeuing %d\n", queue[rear]);
        rear = MAX - 1;
    } else {
        printf("Dequeuing %d\n", queue[rear]);
        rear--;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        if (front <= rear) {
            while (i <= rear) {
                printf("%d ", queue[i]);
                i++;
            }
        } else {
            while (i < MAX) {
                printf("%d ", queue[i]);
                i++;
            }
            i = 0;
            while (i <= rear) {
                printf("%d ", queue[i]);
                i++;
            }
        }
        printf("\n");
    }
}

int main() {
    int a, ch;
    do {
        printf("\nMenu\n");
        printf("Enter '1' for nqueue (enqueue at rear)\n");
        printf("Enter '2' for dqueue (dequeue from front)\n");
        printf("Enter '3' for insertFront (enqueue at front)\n");
        printf("Enter '4' for deleteRear (dequeue from rear)\n");
        printf("Enter '5' to display queue elements\n");
        printf("Enter '6' for Exiting\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the number to be inserted inside the Queue: ");
                scanf("%d", &a);
                nqueue(a);
                break;
            case 2:
                dqueue();
                break;
            case 3:
                printf("Enter the number to be inserted at the front: ");
                scanf("%d", &a);
                insertFront(a);
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("EXITING THE MENU...");
                break;
            default:
                printf("Invalid");
                break;
        }
    } while (ch != 6);
}
