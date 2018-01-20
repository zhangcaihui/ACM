#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<queue>
#include<cmath>
using namespace std;
struct node{
    double x, y, z;
    char name[100];
}a[100];
map<string, int> mp;
int n, m, q;
double dis[100][100];
char nam1[100], nam2[100];
void puin(){
    memset(dis, 0, sizeof(dis));
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%s%lf%lf%lf", a[i].name, &a[i].x, &a[i].y, &a[i].z);
        mp[a[i].name] = i;
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i ++){
        scanf("%s%s", nam1, nam2);
        dis[mp[nam1]][mp[nam2]] = -1;
    }
}
double sqa(double x){ return x*x;}
double cal(int xx, int yy){ return sqrt(sqa(a[xx].x-a[yy].x) + sqa(a[xx].y-a[yy].y) + sqa(a[xx].z-a[yy].z));}
void proc(){
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(dis[i][j] == -1)
            dis[i][j] = 0;
            else
            dis[i][j] = cal(i, j);
        }
    }
    
    for(int u = 1; u <= n; u ++)
    for(int x = 1; x <= n; x ++)
    for(int y = 1; y <= n; y ++){
        dis[x][y] = min(dis[x][y], dis[x][u] + dis[u][y]);
    }
    
    scanf("%d", &q);
    while(q--){
        scanf("%s%s", nam1, nam2);
        printf("The distance from %s to %s is %.0lf parsecs.\n", nam1, nam2, dis[mp[nam1]][mp[nam2]]);
    }
}

int main(){
    int T = 0;
    scanf("%d", &T);
    for(int cnt = 1; cnt <= T; cnt ++){
        printf("Case %d:\n", cnt);
        puin();
        proc();
    }
    return 0;
}
/*
 
 3
 4
 Earth 0 0 0
 Proxima 5 0 0
 Barnards 5 5 0
 Sirius 0 5 0
 2
 Earth Barnards
 Barnards Sirius
 6
 Earth Proxima
 Earth Barnards
 Earth Sirius
 Proxima Earth
 Barnards Earth
 Sirius Earth
 3
 z1 0 0 0
 z2 10 10 10
 z3 10 0 0
 1
 z1 z2
 3
 z2 z1
 z1 z2
 z1 z3
 2
 Mars 12345 98765 87654
 Jupiter 45678 65432 11111
 0
 1
 Mars Jupiter
 */


