#include<bits/stdc++.h>
using namespace std;
int n;
long long int s[3030], c[3030];
long long int dp[3030][3];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%lld", &s[i]);
    for(int i = 1; i <= n; i ++) scanf("%lld", &c[i]);
    for(int i = 0; i <= 3; i ++){
        for(int j = 0; j <= n; j ++){
            dp[j][i] = 10000101022;
        }
    }
    
    for(int i = 1; i <= n; i ++) 
        dp[i][0] = c[i];
        
    for(int i = 1; i <= 2; i ++){
        for(int j = 1; j <= n; j ++){
            for(int k = 1; k < j; k ++){
                if(s[k] < s[j]){
                    dp[j][i] = min(dp[j][i], dp[k][i-1] + c[j]);
                }
            }
        }
    }
    long long int ans = dp[0][0];
    for(int i = 1; i <= n; i ++)
        ans = min(ans, dp[i][2]);
    printf("%lld", ans == dp[0][0] ? -1 : ans);
}
