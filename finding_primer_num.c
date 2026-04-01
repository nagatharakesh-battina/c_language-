#include<stdio.h>
#include<math.h>
void prim(int a){
    int count=0;
    for(int i=2;i<sqrt(a);i++){
        if(a%i==0){
            count++;
        }
    }
    if(count==0){
        printf("it is a prime number");
    }else{
        printf("it is not a prime number");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    prim(n);
}
