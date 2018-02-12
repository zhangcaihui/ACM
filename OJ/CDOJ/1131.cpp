#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 110;
int dp[maxn][maxn], n, a[maxn], b[maxn][maxn];
void puin(){
    memset(dp, 127, sizeof(dp));
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
}

void proc(){
    for(int i = 1; i <= n; i ++){
        int sum = 0;
        for(int j = 0; j + i <= n; j ++){
            sum += a[j+i];
            b[i][j] = sum % 100;
        }
    }
    for(int i = 1; i <= n; i ++)
        dp[i][0] = 0;
    
    for(int j = 1; j < n; j ++){
        for(int i = 1; i+j <= n; i ++){
            for(int k = 0; k < j; k ++){
                dp[i][j] = min(dp[i][j], (dp[i][k] + dp[i+k+1][j-k-1] + b[i][k] * b[i+k+1][j-k-1]));
            }
        }
    }
    printf("%d\n", dp[1][n-1]);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        puin();
        proc();
    }
}
