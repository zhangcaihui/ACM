/*
 void Tarjan(int x){
     low[x] = dfn[x] = ++ cnt;
 int k = pp[x].size();
 for(int i = 0; i < k; i ++){
     int v = pp[x][i];
         if(!dfn[v])
             Tarjan(v);
         low[x] = min(low[x], low[v]);
     }
 }
*/



#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10010;
vector<int> pp[maxn];

int low[maxn], dfn[maxn], cnt;

void Tarjan(int x){
    low[x] = dfn[x] = ++ cnt;
    int k = pp[x].size();
    for(int i = 0; i < k; i ++){
        int v = pp[x][i];
        if(!dfn[v]){
            Tarjan(v);
        }
        low[x] = min(low[x], low[v]);
    }
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) && n){
        int x, y, ff = 1;
        for(int i = 1; i <= m; i ++){
            scanf("%d%d", &x, &y);
            pp[x].push_back(y);
        }
        
        Tarjan(1);
        
        for(int i = 1; i <= n; i ++)
            if(low[i] != 1)
                ff = 0;
        
        if(ff)
            printf("Yes\n");
        else
            printf("No\n");
        
        
        for(int i = 1; i <= n; i ++)
            pp[i].clear();
        memset(low, 0, sizeof(low));
        memset(dfn, 0, sizeof(dfn));
        cnt = 0;
    }
}

