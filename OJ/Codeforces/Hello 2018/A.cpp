#include<cstdio>
typedef long long int LL;
int main(){
    int n;
    LL m;
    scanf("%d%lld", &n, &m);
    if(n >= 60){
        n = 60;
    }
    LL x = 1;
    for(int i = 1; i <= n; i ++)
        x <<= 1;
    printf("%lld", m%x);
    return 0; 
}