#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int value;
    struct node *next;
};

// Traverse and print the linked list
void printList(struct node *head) {
    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at the beginning
void insertAtHead(struct node **head, int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end
void insertAtEnd(struct node **head, int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at a specific position (0-based index)
void insertAtPosition(struct node **head, int position, int value) {
    if (position == 0) {
        insertAtHead(head, value);
        return;
    }

    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;

    struct node *temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteFromHead(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete from end
void deleteFromEnd(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Delete from a specific position (0-based)
void deleteFromPosition(struct node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 0) {
        deleteFromHead(head);
        return;
    }

    struct node *temp = *head;
    for (int i = 0; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    struct node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

// Main function to test
int main() {
    struct node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printList(head); // 10 -> 20 -> 30

    insertAtHead(&head, 5);
    printList(head); // 5 -> 10 -> 20 -> 30

    insertAtPosition(&head, 2, 15);
    printList(head); // 5 -> 10 -> 15 -> 20 -> 30

    deleteFromHead(&head);
    printList(head); // 10 -> 15 -> 20 -> 30

    deleteFromEnd(&head);
    printList(head); // 10 -> 15 -> 20

    deleteFromPosition(&head, 1);
    printList(head); // 10 -> 20

    return 0;
}

