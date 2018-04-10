#include<cstdio>
using namespace std;
const int MAXN = 101010;
typedef long long int LL;
int n, k;
int q[MAXN], p[MAXN];
long long int ans;
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++){
        p[i] = n / i;
        q[i] = n % i;
    }
 
    if(k == 0){
        printf("%lld", (LL)n * (LL)n);
        return 0;
    }
 
    for(int i = 1; i <= n; i ++){
        if(i <= k)
            continue;
        ans += (LL)(i - k) *  p[i];
        ans += q[i] >= k ? q[i] - k + 1 : 0;
    }
    printf("%lld", ans);
 
}

