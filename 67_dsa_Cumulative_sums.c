
#include <stdio.h>

int main()
{
    //printf("Hello World");
    int n;
    scanf("%d",&n);
    int arr[n];
    int pre_sum[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(i==0){pre_sum[0]=arr[0];
        }else{
            pre_sum[i]=pre_sum[i-1]+arr[i];
        }
    }
    
    for(int i=0;i<n;i++){
        printf("%d ",pre_sum[i]);
    }
    

    return 0;
}
