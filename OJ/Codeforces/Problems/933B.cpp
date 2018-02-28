#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1001010;
typedef long long int LL;
LL q[MAXN], ans[MAXN];
LL n, p, k;
int main(){
    scanf("%lld%lld", &p, &k);
    if(p < k){
        printf("1\n%lld", p);
        return 0;
    }
    ans[0] = p;
    while(1){
        if((n ^ 1)&1){ // even
            q[n] = p / k;
            p = q[n];
        }
        else{
            if(p%k == 0)
                q[n] = p / k;
            else
                q[n] = (p / k) + 1;
            p = q[n];
        }
        if((n&1) && p < k){
            break;
        }
        n ++;
    }

    int ff = 1;
    for(int i = 0; i <= n; i ++){
        ff *= -1;
        ans[i] += ff * k * q[i];
        ans[i+1] += ff * q[i];
    }
    printf("%lld\n", n+2);
    for(int i = 0; i <= n+1; i ++)
        printf("%lld ", ans[i]);
}