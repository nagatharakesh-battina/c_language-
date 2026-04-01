#include <stdio.h>

int arr[5], top = -1;

void push(int val) {
    if (top != 4) {
        arr[++top] = val;
    }
    
}
void po(){
    if (top != 1) {
        printf("%d",arr[top--]);
    }
    
}
void dis(){
    while(top!=-1){
        printf("%d  ",arr[top--]);
    }
    printf("\nstack is empty");
}
int main() {
    int n=1,val;
    
   while(n!=0){
       printf("\n0 to exit\n1 to push\n2 to get\n3 to display\n");
       scanf("%d",&n);
       switch(n){
       case 1:
               if(top!=4){
                   printf("enter the number \n");
                   scanf("%d",&val);
                   push(val);
                } else {
                    printf("Stack is full\n");
                }
            break;
            
        case 2:
            if(top!=-1){
                //scanf("%d",&val); 
                printf("the val is \n");
                po();
            }else{
                printf("stack is empty ");
            }
            break;
        case 3:
            dis();
            break;
       }
    
   }
   

    return 0;
}
