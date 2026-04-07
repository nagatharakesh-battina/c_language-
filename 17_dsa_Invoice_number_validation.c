
#include <stdio.h>
#include<regex.h>

int main()
{
    //printf("enter size and no to select\n");
    regex_t reg;
    char *pat="^INV-[1-2][0-9][0-9][0-9](0[0-9]||1[0-2])-[0-9][0-9][0-9][0-9][0-9][0-9]$";
    char *input;
    scanf("%s",input);
    int ret= regcomp(&reg, pat, REG_EXTENDED);
    if(!ret){
        printf("done\n");
        
    }else{
        printf("error\n");
        return 1;
    }
    ret =regexec(&reg,input,0,NULL,0);
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
