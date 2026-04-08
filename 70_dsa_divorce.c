#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    int count=0;
    scanf("%d",&n);
    for(int i=1;i<n/2+1;i++){
        if(n%i==0){
            count++;
            // printf("%d",i);
        }

    }
    
    printf("%d",count);

    return 0;
}
