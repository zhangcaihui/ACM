#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 101010;
struct Edge{
    int x, y, cost;
    Edge(){ x = y = cost = 0;}
    friend bool operator < (Edge a, Edge b){
        return a.cost < b.cost;
    }
}arr[MAXN*5];
int n, f[MAXN], s, t, ans = 1e9+7, m;
int find(int x){ return f[x] == -1 ? x : (f[x] = find(f[x]));}

int check(){
    for(int i = 1; i <= m; i ++){
        int x, y;
        x = find(arr[i].x), y = find(arr[i].y);
        if(x == y)
            continue;
        f[x] = y;
        if((x = find(s)) == (y = find(t))){
            ans = min(ans, arr[i].cost);
            return 1;
        }
    }
    return 0;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++)
        scanf("%d%d%d", &arr[i].x, &arr[i].y, &arr[i].cost);
    sort(arr+1, arr+1+m);
    scanf("%d%d", &s, &t);
    memset(f, -1, sizeof(f));
    if(!check())
        ans = -1;
    
    printf("%d", ans);
}
