#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int x, y;
const int mod = 1e9 + 7;
map<int, long long int> mp;
long long int qpow(int x, int y){
    long long int ans = 1, xx = x;
    while(y){
        if(y&1)
            ans = ans * xx % mod;
        xx = xx * xx % mod;
        y >>= 1;
    }
    return ans;
}
long long int cal(int xx){
    if(mp[xx])
        return mp[xx];
    long long int tem = 0;
    tem = qpow(2, xx-1);
    for(int i = 2; i*i <= xx; i ++){
        if(xx % i)
            continue;
        tem -= cal(xx/i);
        if(i*i != xx)
            tem -= cal(i);
        while(tem < 0)
            tem += mod;
    }
    return mp[xx] = tem - 1;
}
int main(){
    mp[1] = 1;
    scanf("%d%d", &x, &y);
    if(y % x == 0)
        printf("%lld", cal(y/x));
    else
        printf("0");
    return 0;
}