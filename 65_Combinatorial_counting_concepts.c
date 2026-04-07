#include <stdio.h>
#include<math.h>
long long int fac(long long int n, long long int k){
    if(n == k){
        return 1;
    } else {
        return n * fac(n - 1, k);
    }
}
long long int power(long long int base, long long int exp){
    long long int res = 1;
    for(int i = 0; i < exp; i++){
        res *= base;
    }
    return res;
}

void com(long long int n, long long int r){
    printf("Without repetition: %lld\n", fac(n, n - r));
    printf("with repetition: %lld\n",power(n,r));
}

int main()
{
    long long int t = 36, num;

    printf("Enter size of the password:\n");
    scanf("%lld", &num);

    if(num > t){
        printf("Invalid\n");
    } else {
        com(t, num);
    }

    return 0;
}
