#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int LL;
LL n, x = 1;
int main(){
    scanf("%lld", &n);
    LL ans = 0, i = 1;
    n --;
    while(x <= n){
        if(x & n){
            ans += x * ((n>>i)+1);
        }
        else
            ans += x * (n >> i);
        i ++;
        x <<= 1;
    }
    printf("%lld", ans);
    return 0;
}
