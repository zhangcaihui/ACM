#include<cstdio>
using namespace std;
typedef long long int LL;
const int MAXN = 1010100;
const LL MOD = 1e9+7;
LL dp[MAXN], rem = 2;
int main(){
    dp[1] = dp[2] = 1;
    for(int i = 3; i < MAXN; i ++){
        rem = rem * 2 % MOD;
        dp[i] =  (dp[i-1] * (rem - 1) + MOD) % MOD;
    }
    int T = 0;
    scanf("%d", &T);
    //for(int i = 1; i <= 100; i ++)
    //    printf("%lld\n", dp[i]);
    while(T--){
        int n;
        scanf("%d", &n); 
        printf("%lld\n", dp[n]);
    }
}
