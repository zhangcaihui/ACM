#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
int n, x, m;
queue<int> q;
vector<int> v[MAXN];
int ans[MAXN], vis[MAXN];
int main(){
    scanf("%d%d%d", &n, &x, &m);
    for(int i = 1; i <= m; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        v[b].push_back(a);
    }
    memset(ans, 127, sizeof(ans));
    vis[x] = 1;
    ans[x] = 1;
    q.push(x);
    while(!q.empty()){
        int xx = q.front(); q.pop();
        int k = v[xx].size();
        vis[xx] = 1;
        for(int i = 0; i < k; i ++){
            if(vis[v[xx][i]]) continue;
            q.push(v[xx][i]);
            vis[v[xx][i]] = 1;
            ans[v[xx][i]] = ans[xx] + 1;
        }
    }
    int prin = MAXN;
    for(int i = 1; i <= n; i ++){
        if(v[i].size() || !vis[i])
            continue;
        else
            prin = min(prin, ans[i]);
    }
    printf("%d", prin);
}
