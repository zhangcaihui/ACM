#include<bits/stdc++.h>
using namespace std;
double ans = 1, arr[1001];
double dp[1010];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        memset(dp, 0, sizeof(dp));
        double n, sum = 0;
        ans = 0;
        scanf("%lf", &n);
        for(int i = 1; i <= n; i ++){
            scanf("%lf", &arr[i]);   
            sum += arr[i];
        }
        dp[0] = 1;
        for(int i = 2; i <= n; i ++)
            for(int j = 1; j < i; j ++){
                dp[j] += dp[j-1] * arr[i] / (sum - j + 1);
            }
       
        int ff = -1;
        for(int i = 0; i <= n; i ++){
            ff *= -1;
            ans = ans + ff * dp[i];
        }
        printf("%.5f\n", ans);
    }
    return 0;
}
