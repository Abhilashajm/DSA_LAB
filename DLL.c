#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct Node {
    int data;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *head = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}

// Insert at beginning
void insertBegin(int data) {
    struct Node *newNode = createNode(data);
    if (head != NULL) {
        newNode->rptr = head;
        head->lptr = newNode;
    }
    head = newNode;
    printf("inserted %d at beginning:",data);
}

// Insert at end
void insertEnd(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->rptr != NULL)
        temp = temp->rptr;

    temp->rptr = newNode;
    newNode->lptr = temp;
    printf("inserted %d at end:",data);
}

// Delete from beginning
void deleteBegin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->rptr;
    if (head != NULL)
        head->lptr = NULL;
    printf("deleted %d at beginning:",temp->data);
    free(temp);

}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    if (temp->rptr == NULL) {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->rptr != NULL)
        temp = temp->rptr;

    temp->lptr->rptr = NULL;
    printf("deleted %d at end:",temp->data);
    free(temp);

}

// Display list
void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->rptr;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, data;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete at beginning\n");
        printf("4. Delete at end\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insertBegin(data);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                insertEnd( data);
                break;

            case 3:
                deleteBegin(&head);
                break;

            case 4:
                deleteEnd(&head);
                break;

            case 5:
                display(head);
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
