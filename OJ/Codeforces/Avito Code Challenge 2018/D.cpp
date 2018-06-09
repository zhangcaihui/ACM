#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const LL xx = 1;
int dp[100][100], n, k;
LL ans, tem, a[100], sum;
struct node{
    int x, y;
    node(int tx = 0, int ty = 0): x(tx), y(ty) {}
};
queue<node> q;
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++){
        scanf("%lld", &a[i]);
    }
    for(int p = 60; p >= 0; p --){
        tem = ans + (xx << (LL)p);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        q.push(node(0, 0));
        while(!q.empty()){
            node tmp = q.front(); q.pop();
            sum = 0;
            for(int tp = tmp.x + 1; tp <= n; tp ++){
                sum += a[tp];
                if((sum & tem) == tem){
                    if(dp[tp][tmp.y+1]) continue;
                    dp[tp][tmp.y+1] = 1;
                    q.push(node(tp, tmp.y+1));
                }
            }
        }
        if(dp[n][k])
            ans = max(ans, tem);
        //printf("%lld - %lld\n", ans, tem);
    }
    printf("%lld\n", ans);
}
