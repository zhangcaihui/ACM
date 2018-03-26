#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 10100;
int n, m;
int f[maxn];
struct edge{
    int x, y, val;
    friend bool operator < (edge xx, edge yy){
        return xx.val < yy.val;
    }
}e[maxn];


void putin(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++)
        scanf("%d%d%d", &e[i].x , &e[i].y, &e[i].val);
    sort(e+1, e+1+m);
}

int find(int x){ return f[x] == -1 ? x : (f[x] = find(f[x]));}

int Kruskal(int u){
    for(int i = u; i <= m; i ++){
        int xx =find(e[i].x), yy = find(e[i].y);
        if(xx == yy)
            continue;
        f[xx] = yy;
        if(find(1) == find(n))
            return e[i].val - e[u].val;
    }
    return -1;
}

void proc(){
    int tem = 0, ans = 100101022;
    for(int i = 1; i <= m; i ++){
        memset(f, -1, sizeof(f));
        if((tem = Kruskal(i)) == -1)
            break;
        ans = min(ans, tem);
    }
    ans = (n == 1) ? 0 : ans;
    printf("%d\n", ans);
}

int main(){
    putin();
    proc();
    return 0;
}
