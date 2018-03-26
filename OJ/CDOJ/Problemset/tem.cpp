#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int LL;
int n, k;
const int mod = 772002 + 233;
LL qpow(LL x, int p){
    LL ans = 1;
    while(p){
        if(p&1)
            ans = ans * x % mod;
        x = x * x % mod; 
        p >>= 1;
    }
    return ans;
}
LL ans, rem = 1;
LL C[35][35];
int main(){
    scanf("%d%d", &n, &k);
    int ff = -1;
    C[k][0] = 1;
    for(int j = 1; j <= k; j ++){
        C[k][j] = C[k][j-1] * (k-j +1) / j;
    }
    
    for(int i = 1; i <= k; i ++)
        C[k][i] %= mod;
    
    
    for(int i = 0; i < k; i ++){
       ff *= -1;
       ans += mod + (ff * C[k][i] * qpow(k-i, n)) % mod;
       //printf("check : %lld\n", C[k][i] * qpow(k-i, n));
       ans %= mod;
    }
    printf("%lld", ans);
}
