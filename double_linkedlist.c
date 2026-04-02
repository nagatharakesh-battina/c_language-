
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
void find(int data){
    struct Node *temp=head;
	while(temp->next!=NULL) {
		if(temp->data=data){
		    		printf("%d",temp->data);
		    		break;
		}
		temp=temp->next;
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
void in_m(int data,int n) {
	if(n==0){
	    in(data);
	}else if(n>len){
	    printf("position not found");
	}else if(n==len-1){
	    
	    in(data);
	}else{
	int i=0;
    struct Node *temp=head;
	while(i<n-1) {
		//printf("%d",temp->data);
		temp=temp->next;
		i++;
	}
	struct Node *temp2=temp->next;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = temp2;
	newNode->pre=temp;
	temp->next = newNode;
	len++;
	}
}
void del(int data, int n){
    if(head==NULL){
        printf("list is empty");
    }else if(n==0){
            struct Node *temp=head;
            head=temp->next;
            free(temp);
        }
        else if(n<len-1){
    
    	
        struct Node *temp=head;
    	while(--n!=0) {
		temp=temp->next;
    	}
    	
		struct Node *temp2=temp->next;
		temp->next=temp2->next;
		temp2->pre=temp;
		free(temp2);
		
		len--;
	
    }else if(n==len-1){
        struct Node *temp=head;
        while(temp->next->next!=NULL) {
			temp=temp->next;
		}
		struct Node *temp2=temp->next;
		free(temp2->next);
		temp->next=NULL;
		len--;
    }
}
int main()
{
	int n=1,m,p;
	while(n!=-1) {

		printf("0 to display\n-1 to exits\n-2 to insert at head\n-3 to add at end\n-4 to insert in the middle\n-5 to delete \n-6 to find\n");
		scanf("%d",&n);
		
		if(n==0) {
		  //  printf("entera number to add linkerd list\n");
		  //  scanf("%d",&m);
			display();
		} else if(n==-2) {
		    printf("entera number to add linkerd list\n");
		    scanf("%d",&m);
			in_h(m);
		} else if(n==-3 ) {
		    printf("entera number to add linkerd list\n");
		    scanf("%d",&m);
			in(m);
		} else if(n==-4 ) {
		    printf("entera number to add linkerd list\n");
		    scanf("%d",&m);
			printf("enter the position \n");
			scanf("%d",&p);
			in_m(m,p);
		}else if(n==-5){
		    printf("enter the position the length is %d  \n",len);
			scanf("%d",&p);
		    del(m,p);
		}else if(n==-6){
		    printf("entera number to add linkerd list\n");
		    scanf("%d",&m);
		    find(m);
		}
		

	}



	return 0;
}
