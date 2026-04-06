/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int* get_lbs(char *p){
    int *arr = (int*)malloc(sizeof(strlen(p)));
    for(int i=0;i<strlen(p);i++){
        arr[i]=0;
    }
    int len=0;
    for(int i=1;i<strlen(p);i++){
        if(p[len]==p[i]){
            len++;
            arr[i]=len;
        }else {
               // printf("%d %d\n",i, len);
            if(len!=0){
                i--;
                len=arr[len-1];
            }
        }
        
        
    }
    
    return arr;
}

int main()
{   
    char text[]="ababbababdabdbabdbbaabba";
    char pat[]="baabba";
    
    int *arr=get_lbs(pat);
    
    for(int i = 0; i < strlen(pat); i++)
        printf("%d ", arr[i]);
    
    int j = 0;
    for(int i = 0; i < strlen(text); i++){
        if(text[i] == pat[j])
            j++;
        else{
            if(j != 0){
                j = arr[j-1];
                i--;
            }
        }
        
        if(j == strlen(pat)){
            printf("found at: %d\n", i - j + 1);
           j=0;
        }
        
    }
    
    return 0;
}
