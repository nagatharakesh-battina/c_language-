
#include <stdio.h>
#include<stdlib.h>
struct Node *head;
 int len=0;
struct Node {
	int data;
	struct Node *next;
	struct Node *pre;
};
void in_h(int data) {

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = head;
	newNode->pre = NULL;
	head = newNode;
}
void in(int data) {
	if(head==NULL) {
		in_h(data);
	} else {
		struct Node *temp=head;
		while(temp->next!=NULL) {
			temp=temp->next;
		}
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = data;
		newNode->next = NULL;
		newNode->pre =temp;
		temp->next = newNode;
	}
	len++;
}
void search(int n){
    struct Node *temp_tail;
    struct Node *temp=head;
    int sum=0;
    while(temp->next!=NULL) {
		
		temp=temp->next;
	}    
	temp_tail=temp;
	temp=head;
	while(temp!=temp_tail){
	    sum=temp_tail->data+temp->data;
	    if(sum==n){
	        printf("%d %d \n",temp_tail->data,temp->data);
	    }if(sum>n){
	        temp_tail=temp_tail->pre;
	    }else{
	        temp=temp->next;
	    }
	}
}


void display() {
	struct Node *temp=head;
	while(temp->next!=NULL) {
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}


int main()
{
	int n=1,m,p;
	while(n!=-1) {
		scanf("%d",&n);
		if(n!=-1){
		    in(n);
		}
	}
    int t;
    printf("enterthe target value\n");
    scanf("%d",&t);

    search(t);
	return 0;
}
