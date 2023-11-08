#include <stdio.h>
#define MAX 5
int front = -1, rear = -1;
int queue[MAX];

void nqueue(int a) {
    if ((front == 0 && rear == MAX - 1)||(rear + 1 == front)) {
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
        printf("Enter '3' to display queue elements\n");
        printf("Enter '4' for Exiting\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the number to be inserted inside the Queue: ");
                scanf("%d", &a);
                nqueue(a);
                display();
                break;
            case 2:
                dqueue();
                display();
                break;
            
            case 3:
                display();
                break;
            case 4:
                printf("EXITING THE MENU...");
                break;
            default:
                printf("Invalid");
                break;
        }
    } while (ch != 4);
}
