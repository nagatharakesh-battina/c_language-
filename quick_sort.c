/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int getp(int * arr, int starts,int end){
    int p=starts;
    int sw=p,temp;
    for(int i=starts+1;i<=end;i++){
        if(arr[p]>arr[i]){
            sw++;
            temp=arr[sw];
            arr[sw]=arr[i];
            arr[i]=temp;
        }
    }
    temp=arr[sw];
    arr[sw]=arr[p];
    arr[p]=temp;
    return sw;
}
void qs(int * arr,int starts,int end){
    if(starts>end) return;
    int p=getp(arr,starts,end);
    qs(arr,starts,p-1);
    qs(arr,p+1,end);
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    qs(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
