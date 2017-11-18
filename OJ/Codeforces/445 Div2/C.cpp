#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 1001010;
int n, x, p1[maxn], p2[maxn];
int main(){
    scanf("%d", &n);
    p1[0] = -1;
    for(int i = 1; i <= n; i ++){
        scanf("%d", &x);
        p1[i] = x;
        p1[p2[x]] = -1;
        p2[x] = i;
    }
    int ans = 0;
    for(int i = 0; i <= n; i ++)
        if(p1[i] == -1)
            ans ++;
    
    printf("%d", ans);
    return 0;
}
