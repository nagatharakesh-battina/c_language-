#include <stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int count=0;
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++){
        if(str[i]!=str[i+1]){
            printf("%c%d",str[i],count+1);
            count=0;
        }else{
            count++;
        }
    }

    return 0;
}
