#include <stdio.h>
#define size 5

int items[size];
int front=-1,rear=-1;

int isFull() {
    if((front == rear+1 )|| (front == 0 && rear == size-1)) return 1;
    return 0;
}

int isEmpty(){
    if(front== -1)return 1;
    return 0;
}

void enqueue(int element){
    if (isFull())
      printf("\nQueue is Full!!\n");
    else{
      if(front == -1)front=0;
      rear=(rear+1)%size;
      items[rear]=element;
      printf("\nInserted-->%d ",element);
    }
}

int dequeue(){
    int element;
    if(isEmpty()){
        printf("\nQueue is Empty!!\n");
        return(-1);
    }else{
            element=items[front];
            if(front==rear){
            front=-1;
            rear=-1;
     }else{
        front=(front+1)%size;
     }
     printf("\nDeleted element-->%d \n",element);
     return(element);
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("\nEmpty Queue\n");
    } else {
        printf("\n--- Circular Queue State (Capacity: %d, Max Items: %d) ---", size, size - 1);
        printf("\nFront-->%d ", front);
        printf("\nItems--> ");

        for (i = front; i != rear; i = (i + 1) % size)
            printf("%d ", items[i]);


        printf("%d ", items[i]);

        printf("\nRear->%d\n", rear);
        printf("----------------------------------------------------------\n");
    }
}
int main() {
    int ch, val;
    do {
        printf("\n operations\n 1-Enqueue 2-Dequeue 3-Display 4-Exit: ");
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("enter the Value: "); scanf("%d", &val); enqueue(val); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4:exit(0);
            default:printf("wrong selection,try again !!");
        }
    } while (ch != 4);

}

