#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
vector<int> v[MAXN];
int deg[MAXN], vis[MAXN];
int cnt, st = 1, n;
stack<int> ans;
void dfs(int x){
    vis[x] = 1;
    int k = v[x].size();
    for(int i = 0; i < k; i ++){
        if(vis[v[x][i]]) continue;
        dfs(v[x][i]);
    }
    if(x != st && k == 1)   ans.push(x);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i ++){
        int tx, ty;
        scanf("%d%d", &tx, &ty);
        v[tx].push_back(ty);
        v[ty].push_back(tx);
        deg[tx] ++, deg[ty] ++;
    }
    
    for(int i = 1; i <= n; i ++)
        if(deg[i] > 2) st = i, cnt ++;
    
    if(cnt > 1){
        printf("No");
    }
    else{
        dfs(st);
        printf("Yes\n%d\n", ans.size());
        while(!ans.empty()){
            printf("%d %d\n", st, ans.top()); ans.pop(); 
        }
    }
}
