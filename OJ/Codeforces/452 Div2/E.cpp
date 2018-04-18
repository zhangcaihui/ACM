#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 201010;
struct node{
    int posi, siz, tai;
    friend bool operator < (node x, node y){
        if(x.siz == y.siz)
            return x.posi > y.posi;
        return x.siz < y.siz;
    }
}gat[MAXN];
int n, f[MAXN], note[MAXN];
int  p[MAXN], rp[MAXN], a[MAXN];
int find(int x){ return f[x] == -1 ? x : (f[x] = find(f[x]));}
priority_queue<node> q;

void pre(){
    memset(f, -1, sizeof(f));
    for(int i = 1; i < MAXN; i ++){
        p[i] = i-1;
        gat[i].tai = gat[i].posi = i;
        rp[i] = i + 1;
    }
}

int main(){
    pre();
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    a[n+1] = 1e9+7;
    for(int i = 1; i <= n; i ++){
        if(a[i] == a[p[i]]){
            f[i] = p[i];
            int x = find(i);
            gat[x].siz ++;
            gat[x].tai = i;
            note[i] = 1;
        }
        else
            gat[i].siz ++;
    }
    for(int i = 1; i <= n; i ++)
        if(!note[i]){
            q.push(gat[i]);
        }
    
    
    int ans = 0;
    while(!q.empty()){
        node tmp = q.top(); q.pop();
        if(note[tmp.posi])
            continue;
        ans ++;
        note[tmp.posi] = 1;
        int x = p[tmp.posi], y = rp[tmp.tai];
        x = find(x);
        rp[gat[x].tai] = y;
        p[y] = x;
        if(a[x] == a[y]){
            gat[x].tai = gat[y].tai;
            f[y] = x;
            gat[x].siz += gat[y].siz;
            note[y] = 1;
            q.push(gat[x]);
        }
    }
    printf("%d", ans);
    return 0;
}



