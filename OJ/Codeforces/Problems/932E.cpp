#include<cstdio>
using namespace std;
typedef long long int  LL;
const int MAXN = 5010;
const int mod = 1e9+7;
LL dp[MAXN][MAXN]; // i represent ith', j represent j x^j.
LL rev(LL x, int p){
    LL ans = 1;
    while(p){
        if(p&1)
            ans = ans * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return ans;
}
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    dp[1][1] = n;
    for(int i = 2; i <= k; i ++){
        for(int j = 1; j <= k; j ++){
            dp[i][j] = (dp[i-1][j] * j + dp[i-1][j-1] * (n-j+1)) % mod;
        }
    }
    LL ans = 0;
    LL rem = rev(2, n);
    LL tem = rev(2, mod - 2);
    /* test :
    printf("%lld %lld\n", rem, tem);

    for(int i = 1; i <= k; i ++){
        for(int j = 1; j <= k; j ++)
            printf("%lld ", dp[i][j]);
        printf("\n");
    }
    */

    for(int i = 1; i <= k; i ++){
        rem = rem * tem % mod;
        ans += rem * dp[k][i];
        ans %= mod;
    }
    printf("%lld\n", ans);
}