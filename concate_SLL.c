#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node*next;
};

struct Node* createNode(int value){
    struct Node*newnode= (struct Node*)malloc(sizeof( struct Node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}


// Insert at end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {        // List empty
        *head = newNode;
        printf("Inserted %d at end.\n", value);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("Inserted %d at end.\n", value);
}

// Display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Concatenate two lists
void concatenate(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;   // if first list empty, result is second list
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *head2;   // link last node of list1 to head of list2
    *head2 = NULL;         // optional: clear second list
    printf("Lists concatenated successfully!\n");
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at end (List1)\n");
        printf("2. Insert at end (List2)\n");
        printf("3. Display List1\n");
        printf("4. Display List2\n");
        printf("5. Concatenate List2 into List1\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&head1, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&head2, value);
                break;

            case 3:
                display(head1);
                break;

            case 4:
                display(head2);
                break;

            case 5:
                concatenate(&head1, &head2);
                printf("\nConcated list(List1):");
                display(head1);
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
