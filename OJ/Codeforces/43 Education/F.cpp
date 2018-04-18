#include<stack>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 101;//010;
struct Edge{
    int u, v;
}a[MAXN];
stack<int> st;
vector<int> scp[MAXN];
vector<int> v[MAXN], v2[MAXN];
int n, m, cnum, rem[MAXN];
int inst[MAXN], dfn[MAXN], low[MAXN];
int cnt, color[MAXN], tim[MAXN];
void Tarjan(int x){
    low[x] = dfn[x] = ++ cnt;
    inst[x] = 1;
    st.push(x);
    int k = v[x].size();
    for(int i = 0; i < k; i ++){
        int p = v[x][i];
        if(!dfn[p]){
            Tarjan(p);
            low[x] = min(low[x], low[p]);
            if(x == 2)
                return ;
        }
        else if(inst[p]){
            low[x] = min(low[x], dfn[p]);
            if(x == 2)
                return ;
        }
    }
    if(dfn[x] == low[x]){
        inst[x] = 0;
        color[x] = ++ cnum;
        v2[cnum].push_back(x);
        while(st.top() != x){
            color[st.top()] = cnum;
            inst[st.top()] = 0;
            v2[cnum].push_back(st.top());
            st.pop();
        }
        st.pop();
    }
}
int dfn2[MAXN];
void dfs(int x){
    int k = v[x].size();
    dfn2[x] = 1;
    for(int i = 0; i < k; i ++){
        int p = v[x][i];
        if(dfn2[p])
            continue;
        rem[scp[x][i]] = 1;
        dfs(p);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++){
        int x, y;
        scanf("%d%d", &x, &y);
        a[i].u = x, a[i].v = y;
        v[x].push_back(y);
        v[y].push_back(x);
        scp[y].push_back(i);
        scp[x].push_back(i);
    }
    
    for(int i = 1; i <= n; i ++){
        if(dfn[i])
            continue;
        Tarjan(i);
        dfs(i);
    }
    
    for(int i = 1; i <= m; i ++){
        if(rem[i])
            continue;
        if(color[a[i].u] != color[a[i].v])
            continue;
        tim[color[a[i].u]] ++;
    }
    int ans = 0;
    for(int i = 1; i <= m; i ++){
        if(color[a[i].u] != color[a[i].v])
            continue;
        if(tim[color[a[i].u]] == 1)
            ans ++;
    }
    printf("%d\n", ans);
    for(int i = 1; i <= m; i ++){
        if(color[a[i].u] != color[a[i].v])
            continue;
        if(tim[color[a[i].u]] == 1)
            printf("%d ", i);
    }
}

