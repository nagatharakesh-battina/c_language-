int lengthOfLastWord(char* s) {
    int count=0;
    
    int size=strlen(s),num;

    for(int i=size-1;i>=0;i--){
        num=s[i];
        if((num>=65 &&num<91) ||(num>=97 &&num<123)){
                //if(count!=0){
                    count++;
                    
        }else if(count!=0){
                        break;
                    }
    }

    return count;
}
