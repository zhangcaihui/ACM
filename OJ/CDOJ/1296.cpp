#include<cstdio>
#include<cstring>
using namespace std;
int x, y;
int n, m, k;
int p[20], dp[1<<16];
int v[300][2], q[300][2], ot[300][2];
int find(int x){ return p[x] == -1 ? x : (p[x] == find(p[x]));}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i ++)
        scanf("%d%d", &v[i][0], &v[i][1]);
    for(int i = 1; i <= k; i ++)
        scanf("%d%d", &q[i][0], &q[i][1]);
    memset(p, -1, sizeof(p));
    for(int i = 1; i <= m; i ++){
        if((x = find(v[i][0]) == (y = find(v[i][1])))
           continue;
       p[x] = y;
    }
   for(int i = 1; i <= k; i ++)
       if((x = find(q[i][0])) != (y = find(q[i][1]))){
           printf("-1");
           return 0;
       }
   memset(dp, 127, sizeof(dp));
   for(int i = 0; i < n; i ++)
       dp[1<<i] = 0;
           for(int i = 1; i < (1<<n); i ++){
               
           }
}
