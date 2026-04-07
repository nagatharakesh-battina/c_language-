
#include <stdio.h>
int fac(int n){
    if(n==0||n==1){
        return 1;
    }else{
        return n*fac(n-1);
    }
}
void com(int n,int r){
    printf("%d",fac(n)/(fac(r)*fac(n-r)));
}
int main()
{
    printf("enter size and no to select\n");
    
    int t,num;
    scanf("%d%d",&t,&num);
    int f;
    printf("no of people fixed in the group 0 if not\n");
    scanf("%d",&f);
    t=t-f;
    num=num-f;
    
    if(t<num){
        printf("invalid");
        
    }else{
        com(t,num);
    }
    
    return 0;
}
