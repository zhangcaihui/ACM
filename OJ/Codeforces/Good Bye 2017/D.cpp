#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
const long long int mod = 1e9+7;
long long int gcd(long long int x, long long int y){ return x == 0 ? y : gcd(y%x, x);}

struct Func{
    long long int x, y;
    Func(long long int xx = 0, long long int yy = 0):x(xx), y(yy){}
    bool check(){
        if(!this->x || !this->y)
        return false;
        return true;
    }
    Func operator + (const Func &sec){
        long long int temx = sec.y * this->x + sec.x * this->y;
        long long int temy = sec.y * this->y;
        if(!this->check())
        return sec;
        return Func(temx/gcd(temx, temy), temy/gcd(temx, temy));
    }
    Func operator * (const Func &sec){
        long long int temx = sec.x * this->x;
        long long int temy = sec.y * this->y;
        return Func(temx/gcd(temx, temy), temy/gcd(temx, temy));
    }
}dp[1001][1001];

long long int quick_inverse(long long int x,long long int p) {
    long long int ret = 1;
    long long int exponent = p - 2;
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
    dp[1][0] = Func(1, 1);
    for(int i = 1; i <= k; i ++)
    for(int j = 0; j < k; j ++){
        if(!dp[i][j].x || !dp[i][j].y || i + j >= k)
        break;
        dp[i+1][j] = dp[i+1][j] + dp[i][j] * Func(a, a+b);
        dp[i][j+i] = dp[i][j+i] + dp[i][j] * Func(b, a+b);
    }
    Func ans = Func(0, 0);
    long long int sum;
    long long int temx = (a+b*k), temy = b;
    
    for(int i = 1; i <= k; i ++){
        for(int j = 0; j < k; j ++){
            if(!dp[i][j].x || !dp[i][j].y || i+j < k)
            continue;
            sum = i + j;
            temx = a+b*sum, temy = b;
            Func tem = Func(temx/gcd(temx, temy), temy/gcd(temx, temy));
            ans = ans + dp[i][j] * tem;
        }
    }
    printf("%lld", ans.x * quick_inverse(ans.y, mod) % mod);
    return 0;
}



