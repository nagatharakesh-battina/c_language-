#include<stdio.h>
int main(){
    int n;
    printf("enterthe size of arr\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int r,k;
    printf("1 to left    2 to right\n");
    scanf("%d",&r);
    printf("enter  no of steps\n");
    scanf("%d",&k);
    int arr_k[k];
    if(r==1){
        for(int i=0;i<k;i++){
            arr_k[i]=arr[i];
        }
        for(int i=0;i<n-k;i++){
            arr[i]=arr[i+k];
        }
        for(int i=n-k;i<n;i++){
            arr[i]=arr_k[i-(n-k)];
        }
    }
     else if(r==2){
        for(int i=0;i<k;i++){
            arr_k[i]=arr[n-k+i];
        }

        for(int i=n;i>=k;i--){
            arr[i]=arr[i-k];
        }

        for(int i=0;i<k;i++){
            arr[i]=arr_k[i];
        }
    }
    
    
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
