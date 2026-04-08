#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);   // FIXED index
    }

    int max,sw=3;

    // First window sum
    for(int i = 0; i <n-sw+1; i++){
        max=arr[i];
        for(int j = i; j<sw+i; j++){
            if(arr[j]>max){
                max=arr[j];
            }
        }
        printf("%d ",max);
    }
    return 0;
}
