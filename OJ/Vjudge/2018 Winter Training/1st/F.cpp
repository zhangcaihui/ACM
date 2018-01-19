#include<cstdio>
#include<cstring>
using namespace std;
long long int ans;
char ch[1000];
int ff;
long int len;
long long int dp[12][100];
void puin(){
    ff = 1;
    scanf("%s", ch+1);
    len = strlen(ch+1);
    for(int i = 1; i <= len; i ++){
        if(ch[i] < ch[i-1])
            ff = 0;
    }
}
void proc(){
    if(!ff){
        printf("-1\n");
        return ;
    }
    ans = 0;
    for(int i = 0; i < len - 1; i ++){
        for(int j = 1; j <= 9; j ++)
            ans += dp[j][i];
    }
    ans += dp[0][len] - dp[0][len-1];
    for(int i = 1; i <= len; i ++){
        for(int j = ch[i]-'0'+1; j <= 9; j ++){
            ans -= dp[j][len-i];
        }
    }
    if(ans < 0)
        ans = 0;
    printf("%lld\n", ans);
}

long long int dfs(int x, int y){
    if(!y)
        return dp[x][y] = 1;
    if(dp[x][y])
        return dp[x][y];
    long long int sum = 0;
    for(int i = x; i <= 9; i ++){
        sum += dfs(i, y-1);
    }
    return dp[x][y] = sum;
}

int main(){
    int T;
    dfs(0, 80);
    scanf("%d", &T);
    while(T--){
        puin();
        proc();
    }
    return 0;
}