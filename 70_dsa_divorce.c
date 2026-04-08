#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    int count=0,largest;
    scanf("%d",&n);
    for(int i=1;i<n/2+1;i++){
        if(n%i==0){
            count++;
            largest =i;
        }

    }
    
    printf("%d \n%d",count,largest);

    return 0;
}
