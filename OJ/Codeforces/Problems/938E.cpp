#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 1001010;
const LL mod = 1e9+7;
LL arr[MAXN], nums[MAXN];
map<int, int> mp;
LL pre[MAXN];
LL Interve(LL x){
    int y = mod - 2;
    LL ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans % mod;
}
LL ans, sumv;
int n, len, rem[MAXN];
int main(){
    scanf("%d", &n);
    pre[0] = 1;
    for(int i = 1; i <= n; i ++){
        pre[i] = (pre[i-1] * i) % mod;
    }
    for(int i = 1; i <= n; i ++)
        scanf("%lld", &arr[i]);
    
    sort(arr+1, arr+1+n);
    for(int i = 1; i <= n; i ++){
        if(!mp[arr[i]])
            rem[++len] = arr[i];
        mp[arr[i]] = len;
        nums[len] ++;
    }
    
    sumv = nums[len];
    for(int i = len - 1; i > 0; i --){
        ans += ((rem[i] * pre[n]) % mod * ((pre[sumv + nums[i]] - (pre[sumv - 1 + nums[i]] * sumv) % mod + mod) % mod)) % mod * Interve(pre[sumv + nums[i]]);
        ans %= mod;
        sumv += nums[i];
    }
    
    printf("%lld", ans);
    return 0;
}
