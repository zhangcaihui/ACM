#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 101010;
int dp[MAXN][11][3][2], arr[11];
int main(){
    int n, len;
    scanf("%d%d", &n, &len);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &arr[i]);
    sort(arr+1, arr+1+n);
    dp[0][0][0][0] = 1;
    for(int i = 0; i < len; i ++){
        for(int j = 0; j <= n; j ++){
            for(int k = 0; k < 3; k ++){
                if(!dp[i][j][k][0])
                    continue;
                for(int l = 1; l <= n; l ++){
                    int x = (arr[l] + k) % 3;
                    int y = j;
                    dp[i+1][l][x][0] = j;
                    dp[i+1][l][x][1] = k;
                }
            }
        }
    }
    int s = 0, t = 0;
    for(int i = 1; i <= n; i ++){
        if(dp[len][i][0][0])
            s = i, t = 0;
    }
    if(s){
        for(int i = len; i > 0; i --){
            printf("%d", arr[s]);
            int tems = dp[i][s][t][0];
            int temt = dp[i][s][t][1];
            s = tems, t = temt;
        }
    }
    else{
        printf("-1");
    }
    return 0;
}
