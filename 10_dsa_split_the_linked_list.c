

#include <stdio.h>
#include<stdlib.h>
struct Node *head;
 int len=0;
struct Node {
	int data;
	struct Node *next;
};

void in(int data) {
	if(head==NULL) {
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    	newNode->data = data;
    	newNode->next = newNode;
    	head = newNode;
	} else {
		struct Node *temp=head;
		while(temp->next!=head) {
			temp=temp->next;
		}
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = data;
		newNode->next = head;
		temp->next = newNode;
	}
	len++;
}
void display(struct Node * head) {
	struct Node *temp=head;
	printf("\n");
	while(temp!=NULL) {
		printf("%d ",temp->data);
		temp=temp->next;
	}
// 	printf("%d\n",temp->data);
}


void split(){
    // printf("Split method\n");
    struct Node* slow=head;
    struct Node *fast=head->next;
    while(fast->next!=head && fast->next->next!=head ){
        slow=slow->next;
        fast=fast->next->next;
        
    }if(fast->next->next==head){
        fast->next->next=NULL;
    }if(fast->next==head){
        fast->next=NULL;
    }
    fast=slow->next;
    slow->next=NULL;
    // printf("calling first time");
    display(head);
    display(fast);
    // printf("end");
}

int main()
{
	int n=1;
	while(n!=-1) {
	    scanf("%d",&n);
		if(n != -1) 
		    in(n);

	}
	printf("\nInsertion completed");
	split();



	return 0;
}
