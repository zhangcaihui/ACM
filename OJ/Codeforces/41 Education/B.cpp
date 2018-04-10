#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
typedef long long int LL;
int n, k;
int t[MAXN], a[MAXN];
LL ans, prin;
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
    }
    
    for(int i = 1; i <= n; i ++){
        scanf("%d", &t[i]);
        if(t[i])
            ans += a[i];
    }
    
    for(int i = 1; i <= k; i ++){
        if(!t[i])
            ans += a[i];
    }
    prin = ans;
    
    for(int r = k+1; r <= n; r ++){
        if(!t[r-k])
            ans -= a[r-k];
        if(!t[r])
            ans += a[r];
        prin = max(prin, ans);
    }
    printf("%lld", prin);
}
