#include <stdio.h>
#include <string.h>

int  len(int n,int  *arr,int target){
    
    for(int i=target;i>1;i--){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=arr[j]/i;
        }
        if(sum>=target){
            return i;
        }else{
            sum=0;
        }
        
    }
}


int main() {
    int n,target;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&target);
    int no_of_pieces=len(n,arr,target);
    printf("%d",no_of_pieces);

    return 0;
}
