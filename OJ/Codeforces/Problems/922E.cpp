#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int LL;
LL dp[1010][10101];
int n;
LL B, X, W, sum;
LL c[10010], cost[10010];
int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d%lld%lld%lld", &n, &W, &B, &X);
    dp[0][0] = W;
    for(int i = 1; i <= n; i ++)
        scanf("%lld", &c[i]);
    for(int i = 1; i <= n; i ++)
        scanf("%lld", &cost[i]);
    
    for(int i = 1; i <= n; i ++){
        sum += c[i];
        for(int j = 0; j <= sum; j ++){
            for(int k = 0; k <= c[i]; k ++){
                if(j - k < 0)
                    break;
                else if(dp[i-1][j-k] < 0)
                    continue;
                dp[i][j] = max(dp[i][j], min(dp[i-1][j-k] + X, W + B*(j-k)) - cost[i]*k);
            }
        }
    }
    int ans;
    for(int i = 0; i <= sum; i ++){
        if(dp[n][i+1] < 0){
            ans = i;
            break;
        }
    }
    printf("%d", ans);
}

