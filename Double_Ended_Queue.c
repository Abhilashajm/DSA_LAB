#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int deque[SIZE];
int front = -1, rear = -1;

void insert_right();
void insert_left();
void delete_right();
void delete_left();
void display();

int main() {
    int choice;
    do {
        printf("\n--- DEQUE MENU ---");
        printf("\n1. Insert at right");
        printf("\n2. Insert at left");
        printf("\n3. Delete from right");
        printf("\n4. Delete from left");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_right(); break;
            case 2: insert_left(); break;
            case 3: delete_right(); break;
            case 4: delete_left(); break;
            case 5: display(); break;
            case 6: printf("\nExited...\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

int isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
    return (front == -1);
}

void insert_right() {
    int val;
    if (isFull()) {
        printf("\nOVERFLOW\n");
        return;
    }
    printf("Enter value to insert at right: ");
    scanf("%d", &val);

    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1)
        rear = 0;
    else
        rear++;

    deque[rear] = val;
}

void insert_left() {
    int val;
    if (isFull()) {
        printf("\nOVERFLOW\n");
        return;
    }
    printf("Enter value to insert at left: ");
    scanf("%d", &val);

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0)
        front = SIZE - 1;
    else
        front--;

    deque[front] = val;
}

void delete_left() {
    if (isEmpty()) {
        printf("\nUNDERFLOW\n");
        return;
    }
    printf("\nDeleted element from left: %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else if (front == SIZE - 1)
        front = 0;
    else
        front++;
}

void delete_right() {
    if (isEmpty()) {
        printf("\nUNDERFLOW\n");
        return;
    }
    printf("\nDeleted element from right: %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = SIZE - 1;
    else
        rear--;
}

void display() {
    if (isEmpty()) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nDeque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
