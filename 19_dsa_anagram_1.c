#include <stdio.h>
#include<string.h>
int main(){
    int count[26]={0},f=0;
    char str1[50],str2[50];
    scanf("%s%s",str1,str2);
    for(int i=0;i<strlen(str1);i++){
        //if(i<strlen(str1)){
            count[str1[i]-'a']++;
        count[str2[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(count[i]!=0){
            f=1;
        }
    }
    if(f==0){
        printf("anagram");
        
    }else{
        printf("not an anagram");
    }
}
