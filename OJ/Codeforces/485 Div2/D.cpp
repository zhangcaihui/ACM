#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100111;
priority_queue<int, vector<int>, greater<int> > q[MAXN];
queue<int> tq;
vector<int> v[MAXN];
int n, tx, ty, rec[111];
int m, k, s, vis[MAXN];
int main(){

    scanf("%d%d%d%d", &n, &m, &k, &s);
    
    for(int i = 1; i <= n; i ++){
        scanf("%d", &tx);
        rec[tx] = 1;
        v[MAXN - tx].push_back(i);
    }
    
    for(int i = 1; i <= m; i ++){
        scanf("%d%d", &tx, &ty);
        v[tx].push_back(ty);
        v[ty].push_back(tx);
    }
    
    for(int i = 1; i <= k; i ++){
        if(!rec[i])
            continue;
        memset(vis, 0, sizeof(vis));
        tq.push(MAXN - i);
        vis[MAXN - i] = 1;
        while(!tq.empty()){
            int tmp = tq.front(); tq.pop();
            int siz = v[tmp].size();
            for(int j = 0; j < siz; j ++){
                if(vis[v[tmp][j]]) continue;
                tq.push(v[tmp][j]);
                vis[v[tmp][j]] = vis[tmp] + 1;
            }
        }
        for(int j = 1; j <= n; j ++){
            q[j].push(vis[j] - 2);
        }
    }
    for(int i = 1; i <= n; i ++){
        int ans = 0;
        for(int j = 1; j <= s; j ++){
            ans += q[i].top(); q[i].pop();
        }
        printf("%d ", ans);
    }
    return 0;
}
