#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 510;
char ch[MAXN][MAXN];
int pre[MAXN][MAXN];
int suf[MAXN][MAXN];
int rem[MAXN][MAXN];
int n, m, k;
int dp[MAXN][MAXN];
int ans, p[MAXN];
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i ++){
        scanf("%s", ch[i] + 1);
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            pre[i][j] = pre[i][j-1];
            if(ch[i][j] == '1')
                pre[i][j] ++;
            }
        for(int j = m; j > 0; j --){
            suf[i][j] = suf[i][j+1];
            if(ch[i][j] == '1')
                suf[i][j] ++;
        }
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= m; j ++){
            for(int l = m+1; l > 0; l --){
                if(pre[i][j] + suf[i][l] > k || j >= l)
                    break;
                rem[i][pre[i][j]+suf[i][l]] = max(m+1-l+j, rem[i][pre[i][j]+suf[i][l]]);
            }
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j <= k; j ++){
            for(int l = 0; l+j <= k; l ++){
                dp[i+1][j+l] = max(dp[i+1][j+l], dp[i][j]+rem[i+1][l]);
            }
        }
    }

    int ans = n*m;
    for(int i = 0; i <= k; i ++){
        ans = min(ans, n*m - dp[n][i]);
    }
    printf("%d", ans);
}