#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
map<int, int> mp;
int cnt, rem[101010 * 2], n;
int x, tx, ty;
LL val, ans;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d%d", &tx, &ty);
        if(mp[tx])
            tx = mp[tx];
        else
            tx = mp[tx] = ++ cnt;
        rem[tx] = max(ty, rem[tx]);
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d%d", &tx, &ty);
        if(mp[tx])
            tx = mp[tx];
        else
            tx = mp[tx] = ++ cnt;
        rem[tx] = max(ty, rem[tx]);
    }
    for(int i = 1; i <= cnt; i ++)
        ans += rem[i];
        
    printf("%lld", ans);
}
