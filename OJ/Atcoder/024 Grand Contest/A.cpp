#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL a, b, c, k;
int main(){
    scanf("%lld%lld%lld%lld", &a, &b, &c, &k);
    if(k & 1){
        LL ta, tb, tc;
        ta = b + c;
        tb = c + a;
        tc = a + b;
        a = ta;
        b = tb;
        c = tc;
    }
    printf("%lld", a - b);

}
