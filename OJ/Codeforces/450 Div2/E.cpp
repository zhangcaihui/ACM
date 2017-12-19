#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1001010;
int n, m, dp[maxn], rem[maxn];
char a[maxn];
int xa, xb, ya, yb, cnt[maxn];
int main(){
    scanf("%d%s%d", &n, a+1, &m);
    for(int i = 1; i <= n; i ++){
        cnt[i] = cnt[i-1];
        if(a[i] == '?')
            cnt[i] ++;
    }
    for(int i = 1; i < m; i ++){
        if(a[i] == '?')
            continue;
        if(i&1){
            if(a[i] == 'a')
                xa = i;
            else
                xb = i;
        }
        else{
            if(a[i] == 'a')
                ya = i;
            else
                yb = i;
        }
    }
    for(int i = m; i <= n; i ++){
        if(i&1){//odd
            if(a[i] == 'a')
                xa = i;
            else if(a[i] == 'b')
                xb = i;
        }
        else{//even
            if(a[i] == 'a')
                ya = i;
            else if(a[i] == 'b')
                yb = i;
        }
        if((i-m+1)&1){// start from odd;
            if(ya > (i-m) || xb > (i-m)){
                dp[i] = dp[i-1];
                rem[i] = rem[i-1];
                continue;
            }
            if(dp[i-m]+1 > dp[i-1])
                rem[i] = rem[i-m] + cnt[i] - cnt[i-m];
            else if(dp[i-m]+1 == dp[i-1])
                rem[i] = min(rem[i-m] + cnt[i] - cnt[i-m], rem[i-1]);
            else
                rem[i] = rem[i-1];
            dp[i] = max(dp[i-1], dp[i-m] + 1);
        }
        else{//start from even
            if(yb > (i-m) || xa > (i-m)){
                dp[i] = dp[i-1];
                rem[i] = rem[i-1];
                continue;
            }
            if(dp[i-m]+1 > dp[i-1])
                rem[i] = rem[i-m] + cnt[i] - cnt[i-m];
            else if(dp[i-m]+1 == dp[i-1])
                rem[i] = min(rem[i-m] + cnt[i] - cnt[i-m], rem[i-1]);
            else
                rem[i] = rem[i-1];
            dp[i] = max(dp[i-1], dp[i-m] + 1);
        }

    }
    printf("%d", rem[n]);
}