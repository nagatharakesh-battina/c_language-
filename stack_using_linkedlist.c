#include <stdio.h>
#include<stdlib.h>
struct Node *head;
 int len=0;
struct Node {
	int data;
	struct Node *next;
};
void in_h(int data) {
    struct Node *temp=head;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = temp;
	head = newNode;
	len++;
}


void po(){
    struct Node *temp=head;
    head=temp->next;
	//printf("%d",temp->data);
		free(temp);
		
		len--;
    
}
void dis(){
    struct Node *temp=head;
	while(temp->next!=NULL) {
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
   
}
int main() {
    int n=1,val;
    
   while(n!=0){
       printf("\n0 to exit\n1 to push\n2 to pop\n3 to display\n");
       scanf("%d",&n);
       switch(n){
       case 1:
               
                   printf("enter the number \n");
                   scanf("%d",&val);
                   in_h(val);
                
            break;
            
        case 2:
            
                //scanf("%d",&val); 
                
                po();
                printf("the val is poped \n");
          
            break;
        case 3:
            dis();
            break;
       }
    
   }
   

    return 0;
}
