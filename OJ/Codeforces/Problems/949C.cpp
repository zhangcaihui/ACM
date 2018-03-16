#include<stack>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 105050;
stack<int> st;
vector<int> v[MAXN], v2[MAXN];
int n, m, h, cnt, cnum, tim[MAXN];
int color[MAXN], fro[MAXN], siz[MAXN];
int low[MAXN], dfn[MAXN], inst[MAXN];
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
        }
        else if(inst[p])
            low[x] = min(low[x], dfn[p]);
    }
    if(dfn[x] == low[x]){
        inst[x] = 0;
        color[x] = ++ cnum;
        siz[cnum] ++;
        v2[cnum].push_back(x);
        while(st.top() != x){
            color[st.top()] = cnum;
            inst[st.top()] = 0;
            siz[cnum] ++;
            v2[cnum].push_back(st.top());
            st.pop();
        }
        st.pop();
    }
}
bool check(int x, int y){
    if(tim[y] - tim[x] == 1)
        return true;
    if(!tim[y] && tim[x] == h-1)
        return true;
    return false;
}

void puin(){
    scanf("%d%d%d", &n, &m, &h);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &tim[i]);
    for(int i = 1; i <= m; i ++){
        int x, y;
        scanf("%d%d", &x, &y);
        if(check(x, y))
            v[x].push_back(y);
        if(check(y, x))
            v[y].push_back(x);
    }
    for(int i = 1; i <= n; i ++)
        if(!dfn[i])
            Tarjan(i);
    for(int i = 1; i <= n; i ++){
        int k = v[i].size();
        for(int j = 0; j < k; j ++){
            if(color[i] == color[v[i][j]]) continue;
            fro[color[i]] ++;
        }
    }
}

int ap[MAXN];

void proc(){
    int ans = MAXN, tmp;
    for(int i = 1; i <= cnum; i ++){
        if(fro[i])
            continue;
        if(ans > siz[i])
            ans = siz[i], tmp = i;
        }
    int k = v2[tmp].size();
    printf("%d\n", k);
    for(int i = 0; i < k; i ++){
        printf("%d ", v2[tmp][i]);
    }
    return ;
}

int main(){
    puin();
    proc();
    return 0;
}