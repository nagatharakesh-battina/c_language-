#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node *head=NULL;
 int len=0;
struct Node {
	char data;
	struct Node *next;
};
void po(){
    struct Node *temp=head;
    head=temp->next;
	//printf("%d",temp->data);
		free(temp);
		
		len--;
    
}
void in_h(char data) {
    if(data=='}'&& head!=NULL){
        if(head->data=='{'){
            po();
        }
    }else if(data==')' && head!=NULL){
        if(head->data=='('){
            po();
        }
    }else if(data==']'&& head!=NULL){
        if(head->data=='['){
            po();
        }
    }else{
    struct Node *temp=head;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = temp;
	head = newNode;
	len++;
    }
}




int main() {
    
    
   
    char str[100];
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++){
        in_h(str[i]);
    }
    
    if(head==NULL){
        printf("balanced");
    }else{
         printf("not balanced");

    }
   
   

    return 0;
}
