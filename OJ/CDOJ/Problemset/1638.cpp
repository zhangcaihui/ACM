#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 101010;
int n, m;
struct edge{
    int to_, clas, val;
    edge(int x, int y, int v):to_(x), clas(y), val(v){};
};
vector<edge> mp[maxn];
int ans1[maxn], ans2[maxn];
int cnt[maxn], ff, v;
queue<int> q;
void proc1(){
    memset(ans1, 128, sizeof(ans1));
    ans1[n+1] = 0;
    for(int i = 1; i <= n; i ++){
        mp[n+1].push_back(edge(i, -1, 0));
        mp[n+1].push_back(edge(i, 1, 0));
    }
    q.push(n+1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(cnt[u] > n || ans1[u] > 100){
            ff = 1;
            break;
        }
        int k = mp[u].size();
        for(int i = 0; i < k; i ++){
            if(mp[u][i].clas == 1)
                continue;
            v = mp[u][i].to_;
            if(ans1[v] < ans1[u] + mp[u][i].val)
                q.push(v), cnt[v] ++, ans1[v] = ans1[u] + mp[u][i].val;
        }
    }
    for(int i = 1; i <= n; i ++)
        if(ans1[i] > 100)
            ff = 1;
}

void proc2(){
    if(ff)
        return ;
    memset(ans2, 127, sizeof(ans2));
    memset(cnt, 0, sizeof(cnt));
    ans2[n+1] = 100;
    q.push(n+1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        int k = mp[u].size();
        for(int i = 0; i < k; i ++){
            if(mp[u][i].clas == -1)
                continue;
            v = mp[u][i].to_;
            if(ans2[v] > ans2[u] - mp[u][i].val)
                q.push(v), cnt[v] ++, ans2[v] = ans2[u] - mp[u][i].val;
        }
    }
}

int main(){
    int x, y, v;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++){
        scanf("%d%d%d", &x, &y, &v);
        mp[x].push_back(edge(y, 1, v));
        mp[y].push_back(edge(x, -1, v));
    }
    proc1();
    proc2();
    if(ff)
        printf("-1");
    else{
        for(int i = 1; i <= n; i ++)
            printf("%d %d\n", ans1[i], ans2[i]);
    }
    return 0;
}