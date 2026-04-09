char* longestCommonPrefix(char** strs, int strsSize) {
    int n=0,j=0,f=0;
    char *str = (char*)malloc(200);
    if (strsSize == 0 || strs[0][0] == '\0'){
        
        return "";
    }else
    while(1){
        int i=0;
        str[j]=strs[i][j];
        
        while(strsSize>i){
            if (strs[i][j] == '\0' || strs[i][j] != str[j]){
                f=1;
                break;
            }
            i++;
        }
        if(f==0){
            j++;
        }else{
            str[j]='\0';
            break;
        }
        
    }
    if(j==0){
        return "";
    }
    // printf("\"%s\"",str);
    return str;
    
}
