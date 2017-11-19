#include<cstdio>
long long int a[10], b[10];
long long int lcd = 1, tem;
int ex_gcd(long long int a, long long int b, int &x, int &y){
    int ret, tmp;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ret = ex_gcd(b, a % b, x, y);
    tmp = x;
    x = y;
    y = tmp - a / b * y;
    return ret;
}

const int n = 6;
int main(){
    int x, y;
    for(int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]), lcd *= a[i];
    for(int i = 1; i <= n; i ++)
        scanf("%lld", &b[i]), tem = tem > b[i] ? tem : b[i];
    long long int ans = 0;
    for(int i = 1; i <= n; i ++){
        ex_gcd(lcd/a[i], a[i], x, y);
        ans += (lcd/a[i]) * x * b[i];
    }
    if(ans < tem)
        ans += ((tem - ans)/lcd + 1)*lcd;
    ans -= ((ans - tem)/lcd)*lcd;
    printf("%lld\n", ans);
    return 0;
}
