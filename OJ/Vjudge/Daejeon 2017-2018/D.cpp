#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef long long int LL;
LL n, x;
map<LL, int> mp;
LL cal(LL y){
    LL ans = 0;
    while(y){
        LL tmp = y % 10;
        ans += tmp * tmp;
        y /= 10;
    }
    return ans;
}
int main(){
    scanf("%lld", &n);
    x = n;
    if(x == 1){
        printf("HAPPY");
        return 0;
    }
    while(1){
        mp[x] = 1;
        x = cal(x);
        if(x == 1){
            printf("HAPPY");
            return 0;
        }
        if(mp[x]){
            printf("UNHAPPY");
            return 0;
        }
    }
}
