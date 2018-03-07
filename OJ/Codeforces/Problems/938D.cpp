#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 2* 101010;
typedef long long int LL;
struct edge{
    int u, v, stu;
    LL val;
};
LL arr[MAXN], val;
vector<edge> v[MAXN];
int n, m;
int x, y;

void puin(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++){
        scanf("%d%d%lld", &x, &y, &val);
        edge tem;
        tem.u = x, tem.v = y, tem.val = val;
        v[x].push_back(tem);
        tem.u = y, tem.v = x;
        v[y].push_back(tem);
    }

    for(int i = 1; i <= n; i ++)
        scanf("%lld", &arr[i]);
    for(int i = 1; i <= m; i ++){
        if(edge[i].val * 2 < )
    }
}

int main(){
    puin();
}