#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) printf("Overflow\n");
    else {
        if (front == -1) front = 0;
        q[++rear] = val;
        printf("Inserted %d\n", val);
    }
}

void dequeue() {
    if (front == -1 || front > rear) printf("Underflow\n");
    else printf("Deleted %d\n", q[front++]);
}

void display() {
    if (front == -1) printf("Empty\n");
    else {
        for (int i = front; i <= rear; i++) printf("%d ", q[i]);
        printf("\n");
    }
}

int main() {
    int ch, val;
    do {
        printf("\n1-Enqueue 2-Dequeue 3-Display 4-Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &val); enqueue(val); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4:exit(0);
            default:printf("wrong selection,try again !!");
        }
    } while (ch != 4);
    return 0;
}
