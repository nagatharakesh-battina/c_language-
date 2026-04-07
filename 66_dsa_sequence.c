
#include <stdio.h>

int main()
{
    //printf("enter size and no to select\n");
    
    int t;
    scanf("%d",&t);
    int eve=1,odd=-1;
    for(int i=0;i<t;i++){
        if(i%2==0){
            printf("%d ",eve++);
        }else{
            printf("%d ",odd--);
        }
    }
    
   
    
    return 0;
}
