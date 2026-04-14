char* convertToTitle(int columnNumber) {
    char* str=(char*)malloc(100*sizeof(char));
    char ch;
    int i=0,n;
    while(columnNumber>0){
        columnNumber--;
        str[i]='A'+columnNumber%26;
        columnNumber=columnNumber/26;
    i++;
    }
    str[i]='\0';
    int len =i;
    for(int n=0;n*2<len;n++){
        ch=str[n];
        str[n]=str[len-1-n];
        str[len-1-n]=ch;

    }
    return str;
}
