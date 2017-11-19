#include<cstdio>
const int mod = 1e9+7;
long long int qpow(long long int x,long long int n, long long int p){
    long long int ans = 1;
    while(n){
        if(n&1)
            ans = (ans * x) % p;
        x = (x * x) % p;
        n >>= 1;
    }
    return ans;
}
long long int n, m, ans;
int  ff, k, cnt;
int main(){
    scanf("%lld%lld%d", &n, &m, &k);
    if(n == 1 || m == 1){
        if(n*m & 1)
            ans = 1;
        else{
            if(k < 0)
                ans = 0;
            else
                ans = 1;
        }
    }
    else
        ans = qpow(qpow(2, (n-1), mod), (m-1), mod);
    printf("%lld", ans);
    return 0;
}