#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int LL;
LL Inverse_element(LL a, int mod){
    LL ans = 1;
    int x = mod - 2;
    while(x){
        if(x&1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        x >>= 1;
    }
    return ans;
}

LL exgcd(LL a,LL b,LL &x,LL &y)
{
    LL d;
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

LL Chinese_Remainder(LL r[],LL prime[],int len)
{
    LL i, d, x, y, m, n=1, sum=0;
    for(i=0;i<len;i++)
        n *= prime[i];
    for(i=0;i<len;i++)
    {
        m = n/prime[i];
        d = exgcd(prime[i],m,x,y);
        sum = (sum + y*m*r[i]) % n;
    }
    return (n + sum % n)%n;
}

const int MAXN = 1001010;
int a, b, mod;
LL rem[MAXN], x, ans, p;
LL r[3], prim[3];
int main(){
    scanf("%d%d%lld%lld", &a, &b, &p, &x);
    rem[0] = 1, mod = p;
    for(int i = 1; i <= p; i ++)
        rem[i] = rem[i-1] * a % mod;
    LL tem = 1;
    for(int i = 1; i < p; i ++){
        LL tem = Inverse_element(rem[i], mod);
        LL tmp = (tem * b) % mod;
        prim[0] = p, r[0] = tmp;
        prim[1] = p-1, r[1] = i;
        LL xx = Chinese_Remainder(r, prim, 2);
        xx %= (p-1)*p;
        if(x < xx)
            continue;
        ans = ans + 1 + (x - xx) / ((p-1) * p);
    }
    printf("%lld", ans);
}
