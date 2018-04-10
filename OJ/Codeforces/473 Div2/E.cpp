#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int lowbit(int x){ return (x & -x);}
LL x = 1, ans ;
int main(){
    LL n;
    scanf("%lld", &n);
    n --;
    while(n){
        ans += x * (n >> 1) + x;
        x <<= 1 ;
        n >>= 1;
    }
    printf("%lld", ans);
}
