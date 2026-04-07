
#include <stdio.h>
#include<regex.h>

int main()
{
    //printf("enter size and no to select\n");
    regex_t reg;
    char *pat="^([a-z]+|[a-z]+-[0-9]+)@gmail.com$";
    char *t;
    scanf("%s",t);
    int ret= regcomp(&reg, pat, REG_EXTENDED);
    if(!ret){
        printf("done\n");
        
    }else{
        printf("error\n");
        return 1;
    }
    ret =regexec(&reg,t,0,NULL,0);
    if(!ret){
        printf("found");
        
    }else if(ret==REG_NOMATCH){
        printf("NO MATCH");
    }else{
        printf("issue");
    }
    regfree(&reg);
   
    
    return 0;
}
