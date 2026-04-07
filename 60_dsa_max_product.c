
#include <stdio.h>

int main()
{
    //printf("Hello World");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int pre=1,suf=1;
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(i!=0){
            pre*=arr[i];
        }
        else{
            pre =1;
        }
        if(n-i-1!=0){
            suf*=arr[n-i-1];
        }
        else{
            suf =1;
        }
        if(max<pre){
            max=pre;
        }
        if(max<suf){
            max=suf;
        }
    }
    printf("%d",max);

    return 0;
}
