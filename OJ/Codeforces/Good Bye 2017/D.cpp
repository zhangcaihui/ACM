#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
const int mod = 1e9+7;
long long int gcd(long long int x, long long int y){ return x == 0 ? y : gcd(y%x, x);}

struct Func{
    long long int x, y;
    Func(long long int xx = 0, long long int yy = 0){ x = xx, y = yy;}
    Func operator += (const Func &sec){
        long long int temx = sec.y * x + sec.x * y;
        long long int temy = sec.y * y;
        return Func(temx/gcd(temx, temy), temy/gcd(temx, temy));
    }
    Func operator * (const Func &sec){
        long long int temx = sec.x * x;
        long long int temy = sec.y * y;
        return Func(temx/gcd(temx, temy), temy/gcd(temx, temy));
    }
}dp[1001][1001];

long long int quick_inverse(long long int x,long long int p) {
    long long int ret = 1;
    int exponent = p - 2;
    for (int i = exponent; i; i >>= 1, x = x * x % p) {
        if (i & 1) {
            ret = ret * x % p;
        }
    }
    return ret;
}

int main(){
    int k;
    long long int a, b;
    scanf("%d%lld%lld", &k, &a, &b);
    dp[0][0] = Func(1, 1);
    for(int i = 0; i <= k; i ++)
        for(int j = 0; j < k; j ++){
            if(!dp[i][j].x || i + j >= k)
                continue;
            dp[i+1][j] += dp[i][j] * Func(a, a+b);
            dp[i][j+i] += dp[i][j] * Func(b, a+b);
        }
    Func ans = Func(0, 0);
    Func tem = Func(a+k*b/gcd(a+k*b, b), b/gcd(a+k*b, b));
    for(int i = 1; i <= k; i ++){
        for(int j = 0; j < k; j ++){
            if(i+j < k)
                continue;
            ans += dp[i][j] * tem;
        }
    }
    printf("%lld", ans.x * quick_inverse(ans.y, mod));
    return 0;
}


