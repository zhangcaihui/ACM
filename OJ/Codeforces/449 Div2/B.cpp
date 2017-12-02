#include<cstdio>
int main(){
    int x;
    long long int mod;
    scanf("%d%lld", &x, &mod);
    long long int sum = 0;
    for(int i = 1; i <= x; i ++){
        long long int tem = i;
        int ff = 0;
        int xx = i;
        while(xx){
            tem *= 10;
            ff = 1;
            tem += xx % 10;
            xx /= 10;
        }
        //printf("test %d : %lld\n", i,tem);
        tem %= mod;
        sum += tem;
        sum %= mod;
    }
    printf("%lld\n", sum);
}


