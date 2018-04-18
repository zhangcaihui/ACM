#include<cstdio>
using namespace std;
typedef long long int LL;
const int mod = 1e9+9;
const int MAXN = 1e5+10;
long long int n, a, b, k;
LL qpow(LL x, LL y){
    LL ans = 1;
    while(y){
        if(y & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
LL rem, tmp;
char ch[MAXN];
int kind(char x){
    if(x == '+')
        return 1;
    return -1;
}
int main(){
    scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
    scanf("%s", ch+1);
    tmp = qpow(a, n);
    LL tem = qpow(a, mod-2) * b % mod;
    for(int i = 1; i <= k; i ++){
        rem = (rem + kind(ch[i]) * tmp + mod) % mod;
        tmp = tmp * tem % mod;
    }
    
    LL xx = qpow(tem, k);
    LL sum = 0, ans = 0;
    if(xx == 1)
        sum = (n+1) / k;
    else if((1+n) / k)
            sum = 1 * (qpow(xx, (1+n)/k) - 1) % mod * qpow(xx-1, mod-2) % mod;
    ans = sum * rem % mod;
    int y = (int)((1+n) % k);
    tem = qpow(a, n);
    for(int i = 1; i <= y; i ++){
        ans = (ans + kind(ch[i]) * tmp + mod) % mod;
        tmp = tmp * tem % mod;
    }
    printf("%lld", ans);
}
