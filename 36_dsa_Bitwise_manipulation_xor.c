#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    int count=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        count=count^arr[i];
    }
    
    printf("%d",count);

    return 0;
}
