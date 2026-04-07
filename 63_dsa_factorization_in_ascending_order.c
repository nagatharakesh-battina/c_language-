
#include <stdio.h>
#include<math.h>

int main()
{
    //printf("Hello World");
    int n1;
    
    
    scanf("%d",&n1);
    int arr[n1];
    int ind=0;
    int i=2;
    while(i<=n1){
        if(n1%i==0){
            arr[ind]=i;
            ind++;
            n1=n1/i;
        }else{
            i++;
        }
    }
    for(int i=0;i<ind;i++){
        printf("%d",arr[i]);
    }
    return 0;
}
