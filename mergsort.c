/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

int* merg(int *left, int l1, int *right, int l2){
    int *arr = (int*)malloc((l1+l2)*sizeof(int));
    int i = 0, j = 0, k = 0;
    while(i < l1 && j < l2){
        if(left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    
    while(i < l1)
        arr[k++] = left[i++];
    while(j < l2)
        arr[k++] = right[j++];
    
    // for(int i = 0; i < l1 + l2; i++)
    //     printf("%d ", arr[i]);
        
    // printf("\n");
    return arr;
}

int *mergesort(int *arr,int l,int r){
    
    if(l==r){
        int *a=(int*)malloc(sizeof(int));
        a[0]=arr[l];
        return a;
    }
    int mid = (l + r)/2;
    int *left=mergesort(arr, l, mid);
    int *right=mergesort(arr, mid+1, r);
    return merg(left, mid-l+1, right, r-mid);
}


int main()
{
    int n,temp;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    // for(int i=0;i<n;i++){
    //     int min=i;
    //     for(int j=i+1;j<n;j++){
    //         if(arr[j]<arr[min]){
    //             min=j;
                
    //         }
            
    //     }
    //     temp=arr[i];
    //     arr[i]=arr[min];
    //     arr[min]=temp;
        
    
    // }
    // 

    int *sorted = mergesort(arr, 0, n - 1);
    for(int i=0;i<n;i++){
        printf("%d ", sorted[i]);
    }
    
    return 0;
}
