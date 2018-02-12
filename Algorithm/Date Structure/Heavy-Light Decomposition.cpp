/*
Note: the meaning of the variate
siz[x]: 以x为跟的子树的节点个数
top[x]: x所在重链的顶端
son[x]: x的重儿子
dep[x]: x的节点深度
fat[x]: x的父亲节点
ran[x]: 树中x节点与其父节点的连边在剖分后在线段树中的编号
*/

#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 101010;

int siz[MAXN], fat[MAXN], dep[MAXN], son[MAXN];
int top[MAXN], son[MAXN], cnt;

struct Edge {
    int from, to, weight, num, ran;
    Edge(int f, int t, int w, int n): from(f), to(t), weight(w), num(n) {}
};

vector<Edge> v[MAXN];
int n, fr, to, c;
int note[MAXN];

void dfs1(int u){//calculate the value of siz/fat/dep/son
    note[to] = 1;
    int k = v[u].size();
    int tem = 0, sum = 0;
    for(int i = 0; i < k; i ++){
        int to = v[u][i].to;
        if(note[to])
            continue;
        fat[to] = u;
        dep[to] = dep[u] + 1;
        dfs(to);
        if(siz[to] > tem)
            son[u] = to;
        siz[u] += siz[to];
    }
    siz[u] ++;
}

void dfs2(int u){//calculate the value of top/ran
    if(!top[u])
        top[u] = u;
    if(son[u])
        top[son[u]] = top[u];
    
}

void clear(){
    cnt = 0;
    for(int i = 1; i <= n; i ++)
        v[i].clear();
    memset(siz, 0, sizeof(siz));
    memset(fat, 0, sizeof(fat));
    memset(dep, 0, sizeof(dep));
    memset(fat, 0, sizeof(fat));
    memset(son, 0, sizeof(son));
    memset(top, 0, sizeof(top));
    memset(note, 0, sizeof(note));
}

void puin(){
    scanf("%d", &n);
    clear();
    for(int i = 1; i < n; i ++){
        scanf("%d%d%d", &fr, &to, &c);
        v[fr].push_back(Edge(fr, to, c, i));
        v[to].push_back(Edge(to, fr, c, i));
    }
    dfs1(1);
    dfs2(1);
}

void proc(){
    
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        puin();
        proc();
    }
}

