#include<cstdio>
using namespace std;
typedef long long int LL;
const LL mod = 1e9+7;
const int MAXN = 101010;
int s1[MAXN], s2[MAXN];

LL qpow(LL y){
    int p = mod - 2;
    LL ans = 1;
    while(p){
        if(p&1){
            ans = (ans*y) % mod;
        }
        y = (y * y) % mod;
        p >>= 1;
    }
    return ans % mod;
}

int main(){
    LL n, m;
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &s1[i]);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &s2[i]);
    
    LL rem = 1;
    LL ans = 0;
    
    LL pre = 0, r = qpow(m);
    for(int i = 1; i < m; i ++){
        pre = (pre + ((m - i) * r) % mod) % mod;
    }// 不知道怎么错的。。。。
    
    LL ppre;
    if(r & 1)
        pre = (mod*2 + 1 - r) / 2;
    else
        pre = (mod + 1 - r) / 2;
    //printf("%lld %lld\n", pre, ppre);
    for(int i = 1; i <= n; i ++){
        if(s1[i] == 0 && s2[i] == 0){
            ans += (rem * pre) % mod;
        }
        
        else if(!s1[i]){
            ans += ((rem * (m - s2[i])) % mod * r) % mod;
        }
        else if(!s2[i])
            ans += ((rem * (s1[i] - 1)) % mod * r) % mod;
        else if(s1[i] != s2[i]){
            if(s1[i] > s2[i])
                ans += rem;
            break;
        }
        else{
            ans %= mod;
            continue;
        }
         
        ans %= mod;
        rem = (rem * r) % mod;
    }
    //printf("%lld\n", (15 * r) % mod);
    ans %= mod;
    printf("%lld", ans);
}

