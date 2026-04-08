#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at end (circular)
void in(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if(head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Display circular list
void display(struct Node *head) {
    if(head == NULL) return;

    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("\n");
}

// Delete a node safely
void del(struct Node *delNode) {
    if(head == NULL) return;

    struct Node *temp = head;

    // Only one node
    if(head == head->next && head == delNode) {
        free(head);
        head = NULL;
        return;
    }

    // If deleting head
    if(head == delNode) {
        while(temp->next != head)
            temp = temp->next;

        temp->next = head->next;
        struct Node *t = head;
        head = head->next;
        free(t);
        return;
    }

    // Delete other node
    while(temp->next != delNode)
        temp = temp->next;

    temp->next = delNode->next;
    free(delNode);
}

// Round Robin Scheduling
void round_robin(int quantum) {
    if(head == NULL) return;

    struct Node *temp = head;

    while(head != NULL) {
        display(head);

        struct Node *nextNode = temp->next; // save next before delete

        temp->data -= quantum;

        if(temp->data <= 0) {
            del(temp);
        }

        if(head == NULL) break;

        temp = nextNode;
    }

    printf("All processes completed\n");
}

int main() {
    int n;

    // Input until -1
    while(1) {
        scanf("%d", &n);
        if(n == -1) break;
        in(n);
    }

    printf("Round Robin Execution:\n");
    round_robin(4);   // quantum = 4

    return 0;
}
