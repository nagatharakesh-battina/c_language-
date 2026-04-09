#include <stdio.h>
#include <string.h>

void sort(int  *arr,int n){
    for(int i=0;i<n;i++){
        int min=arr[i],f=i;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                f=j;
            }
        }
        arr[f]=arr[i];
        arr[i]=min;
    }
    printf("sorting done\n");
}
int search(int left,int n,int t,int *arr){
    
    int mid = 0;
    // printf("%d\n", n);
   
        mid = (left+n)/2;
        if(t==arr[mid]){
            printf("found");
            return mid;
        }else if(t>arr[mid]){
            left=mid+1;
            search(left,n,t,arr);
            
        }else if(t<arr[mid]){
            n=mid-1;
            search(left,n,t,arr);
        }
            
        
    
}


int main() {
    int n,t;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&t);
    sort(arr,n);
    int k=search(0,n-1,t,arr);
    printf("\n%d",k);
    

    return 0;
}
