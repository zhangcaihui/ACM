#include<cstdio>
using namespace std;
typedef long long int LL;
long long int ans[100];
int main(){
    ans[0] = 1;
    for(int i = 1; i <= 60; i ++){
        ans[i] = ans[i-1] + (((LL)1)<<i);
        //printf("%lld\n", ans[i]);
    }
    long long int n, k;
    scanf("%lld%lld", &n, &k);
    if(k == 1){
        printf("%lld", n);
    }
    else{
        for(int i = 60; i ; i --){
            if((((LL)1) << i) & n){
                printf("%lld", ans[i]);
                return 0;
            }
        }
    }
}
