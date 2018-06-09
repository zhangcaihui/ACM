#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
int n, d, sum[MAXN] , k;
int a[MAXN], p[MAXN];
int main(){
    scanf("%d%d%d", &n, &k, &d);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    sort(a+1, a+1+n);
    for(int i = 1; i <= n; i ++)
        p[i] = upper_bound(a+1, a+1+n, a[i]+d) - a;
    sum[n+1] = 1;
    for(int i = n; i > 0; i --){
        sum[i] = sum[i+1];
        if(p[i] < i+k) continue;
        if(sum[i+k] - sum[p[i]+1] > 0)
            sum[i] ++;
    }
    if(sum[1] > sum[2])
        printf("YES");
    else
        printf("NO");
}
