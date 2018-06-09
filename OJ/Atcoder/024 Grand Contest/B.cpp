#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
int p[MAXN], a[MAXN], n;
int dp[MAXN];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
        dp[i] = 1; p[a[i]] = i;
    }
    for(int i = 2; i <= n; i ++){
        if(p[i] > p[i-1])
            dp[i] = dp[i-1] + 1;
    }
    
    int ans = MAXN;
    for(int i = 1; i <= n; i ++){
        ans = min(ans, n - dp[i]);
    }
    printf("%d", ans);
}
