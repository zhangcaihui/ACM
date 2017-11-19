#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1001010;
int dp[maxn], n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i*8 <= n; i ++)
        dp[i*8] = i;
    for(int i = n; i ; i --){
        if(!dp[i])
            continue;
        for(int j = 1; j*6+i <= n && !dp[i+j*6]; j ++){
            dp[i+6*j] = min(dp[i]+j, dp[i+j*6]);
        }
    }
    if(!dp[n])
        printf("No");
    else
        printf("Yes : %d\n", dp[n]);
    return 0;
}