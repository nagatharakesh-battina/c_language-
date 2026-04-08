#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert into circular linked list
void in(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if(head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node *temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
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

// Split circular linked list
void split() {
    struct Node *slow = head;
    struct Node *fast = head;

    // Find middle using slow & fast
    while(fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // For even nodes
    if(fast->next->next == head) {
        fast = fast->next;
    }

    struct Node *head1 = head;
    struct Node *head2 = slow->next;

    // Make first half circular
    slow->next = head1;

    // Make second half circular
    fast->next = head2;

    printf("First half:\n");
    display(head1);

    printf("Second half:\n");
    display(head2);
}

int main() {
    int n;

    while(1) {
        scanf("%d", &n);
        if(n == -1) break;
        in(n);
    }

    printf("Original List:\n");
    display(head);

    printf("After Split:\n");
    split();

    return 0;
}
