#include <stdio.h>
#include<string.h>
int main(){
    int count[26]={0};
    char str1[50];
    scanf("%s",str1);
    for(int i=0;i<strlen(str1);i++){
       
            count[str1[i]-'a']++;
        
    }
    for(int i=0;i<26;i++){
        if(count[i]!=0){
            printf("%c%d",'a'+i,count[i]);
        }

    }
    
}
