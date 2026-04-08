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

// Proper display for circular list
void display() {
    if(head == NULL) return;

    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("\n");
}

// Floyd’s Cycle Detection
void cycle() {
    struct Node *slow = head;
    struct Node *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            printf("Cycle Found\n");
            return;
        }
    }

    printf("No Cycle Found\n");
}

int main() {
    int n;

    while(1) {
        scanf("%d", &n);
        if(n == -1) break;
        in(n);
    }

    display();
    cycle();

    return 0;
}
