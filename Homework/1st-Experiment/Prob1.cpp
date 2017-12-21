#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 2333333;
int m, n, a[maxn], b[maxn], ans[maxn];
int main(){
    scanf("%d", &n);
    for(int i = n; i >= 0; i --)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i = m; i >= 0; i --)
        scanf("%d", &b[i]);
    for(int i = n; i >= 0; i --)
        for(int j = m; j >= 0; j --)
            ans[i+j] += a[i] * b[j];
    int i = n + m;
    while(!ans[i])
        i --;
    for( ; i >= 0; i --)
        printf("%d ", ans[i]);
    return 0;
}