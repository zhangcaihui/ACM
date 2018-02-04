#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int LL;
LL rem[100], dp[100];
LL dfs(int p, LL l){
    if(l <= 0)
        return 0;
    if(!p)
        return l * dp[p];
    int tmp = (1<<p);
    LL tem1 = (l+tmp-1) / tmp * dp[p];
    LL tem2 = l / tmp * dp[p];
    tem2 += dfs(p-1, l - (l/tmp) * tmp);
    return min(tem1, tem2);
}

int main(){
    int n, l;
    scanf("%d%d", &n, &l);
    for(int i = 0; i < n; i ++)
        scanf("%lld", &rem[i]);
    
    dp[0] = rem[0];
    for(int i = 1; i < n; i ++)
        dp[i] = min(dp[i-1]<<1, rem[i]);
    
    int tem = 1<<(n-1);
    LL ans = dp[n-1] * (l / tem);

    l -= (l / tem) * tem;
    ans += dfs(n-1, l);
    printf("%lld", ans);
}