#include<cstdio>
const int maxn = 1010;
double dp[maxn][maxn][3];
int n, m, p[]={2,0,1};
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
        for(int j = 0; j <= m; j ++){
            for(int k = 0; k < 3; k ++){
                if(k == 0){
                    dp[i][j][0] += (i+0.0) / (i+j+0.0);
                    dp[i+1][j][2] += (i+1.0)/(i+j+1.0) * dp[i][j][0];
                }
                dp[i][j+1][p[k]] += (j+1.0)/(i+j+1.0) * dp[i][j][k];
            }
        }
    printf("%.9lf\n", dp[n][m][0]);
    return 0;
}

