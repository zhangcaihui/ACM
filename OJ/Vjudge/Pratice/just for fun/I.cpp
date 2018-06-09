#include<cstdio>
using namespace std;
typedef long long int LL;
LL xx = 1;
LL rem[62];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= 60; i ++)
        rem[i] = rem[i-1] + (xx<<(i-1));
    while(n --){
        LL x, y, ans = 0;
        scanf("%lld%lld", &x, &y);
        for(int i = 60; i >= 0; i --){
            if((x & (xx<<i)) == (y & (xx<<i))){
                ans += (x & (xx << i));
                continue;
            }
            ans += rem[i+1]; 
            break;
        }
        printf("%lld\n", ans);
    }   
    return 0;
}
