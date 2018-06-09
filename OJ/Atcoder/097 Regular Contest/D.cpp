#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
int a[MAXN], f[MAXN];
int find(int x){
    return f[x] == 0 ? x : (f[x] = find(f[x]));
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
    }
    int x, y;
    for(int i = 1; i <= m; i ++){
        scanf("%d%d", &x, &y);
        int xx, yy;
        if((xx = find(x)) == (yy = find(y)))
            continue;
        f[xx] = yy;
    }  
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(find(i) == find(a[i]))
            ans ++;
    }
    printf("%d", ans);
    
}
