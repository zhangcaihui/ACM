#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL gcd(LL x, LL y) { return x == 0 ? y : gcd(y%x, x);}
int main(){
    int n, tim;
    LL x, y, d, tem;
    scanf("%d", &n);
    for( tim = 1; tim <= n; tim ++){
        scanf("%lld%lld%lld", &x, &y, &d);
        x = x % y;
        tem = gcd(x, y);
        x /= tem; y /= tem;
        tem = d;
        while((tem = gcd(y, tem)) != 1)
            y /= tem;
        if(y == 1)
            printf("Finite\n");
        else
            printf("Infinite\n");
    }
}
