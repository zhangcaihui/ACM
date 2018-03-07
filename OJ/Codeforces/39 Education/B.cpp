#include<cstdio>
long long int a, b;
int check(){
    if(!a || !b)
        return 0;
    if(2*a > b && 2*b > a)
        return 0;
    if(a >= 2*b)
        return 1;
    if(b >= 2*a)
        return 2;
    return 0;
}
int main(){
    scanf("%lld%lld", &a, &b);
    int tem;
    while(tem = check()){
        if(tem == 1){
            long long int k = a / b;
            if(k&1)
                k -= 1;
            a -= k*b;
        }
        else{

            long long int k = b / a;
            if(k&1)
                k -= 1;
            b -= k*a;
        }

    }
    printf("%lld %lld", a, b);
}