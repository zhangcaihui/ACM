#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 101010;
int a[15], ans[MAXN];
int dfs(int h, int sum, int p){
    if(h == 0){
        if(sum == 0)
            return 1;
        else
            return 0;
    }
    for(int i = p; i > 0; i --){
        ans[h] = a[i];
        if(dfs( h-1, (sum+a[i]) % 3, i))
            return 1;
    }
    return 0;
}
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    sort(a+1, a+1+n);
    if(dfs(k, 0, n) && ans[k])
        for(int i = k; i ; i --)
            printf("%d", ans[i]);
    else
        printf("-1");
}
