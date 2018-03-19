#include<cstdio>
using namespace std;
typedef long long int LL;
const int MAXN = 101010;
const int MOD = 663224321;
int n, T;
LL dp[MAXN];
int main(){
    dp[1] = 1;
    scanf("%d", &T);
    for(int i = 2; i < MAXN; i ++){
        dp[i] = (MOD + dp[i-1] * i - i + 2) % MOD;
    }
    for(int i = 1; i <= T; i ++){
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}
