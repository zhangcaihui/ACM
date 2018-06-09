#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
typedef long long int LL;
vector<int> v[MAXN];
LL cnt[MAXN];
int n, xx, yy;
int vis[MAXN], note[MAXN];
void dfs(int x){
    vis[x] = 1;
    int k = v[x].size();
    for(int i = 0; i < k; i ++){
        if(vis[v[x][i]])
            continue;
        dfs(v[x][i]);
        cnt[x] += cnt[v[x][i]];
        note[x] = max(note[x], note[v[x][i]]);
    }
    cnt[x] ++;
}
int main(){
    scanf("%d%d%d", &n, &xx, &yy);
    note[yy] = 1;
    for(int i = 1; i < n; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(xx);
    LL tx = cnt[xx], ty = cnt[yy];
    int k = v[xx].size();
    for(int i = 0; i < k; i ++){
        if(note[v[xx][i]]){
            tx -= cnt[v[xx][i]];
            break;
        }
    }
    LL tem = (LL) n * (LL) (n-1);
    LL ans = tem - tx * ty;
    printf("%lld", ans);
}
