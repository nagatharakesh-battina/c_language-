
#include <stdio.h>

int main()
{
    //printf("enter size and no to select\n");
    
    int t;
    scanf("%d",&t);
    int arr[t];
    int xo=0;
    for(int i=0;i<t;i++){
        scanf("%d",&arr[i]);
        xo=(xo)^(arr[i]);
    }
    printf("\n%d",xo);
    
   
    
    return 0;
}
