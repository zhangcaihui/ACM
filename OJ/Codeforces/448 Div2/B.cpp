#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 100101;
int n, x, k;
long long int a[maxn], cnt[maxn], rem[maxn];
long long int ans;
map<long long int, int> mp1, mp2;
int main(){
    scanf("%d%d%d", &n, &x, &k);
    for(int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]);
    sort(a+1, a+1+n);
    for(int i = 1; i <= n; i ++){
        cnt[i] = a[i] / x;
        if(a[i] % x == 0)
            rem[i] = 1, mp1[cnt[i]] ++;
        mp2[cnt[i]] ++;
    }
    rem[n+1] = 10000102200000;
    if(k == 0){
        int tem = 0;
        for(int i = 1; i <= n; i ++){
            if(cnt[i] != cnt[i-1]){
                tem = 0;
            }
            if(rem[i])
                continue;
            if(a[i] != a[i-1]){
                mp1[cnt[i]] += tem;
                tem = 1;
            }
            else
                tem ++;
            ans += mp2[cnt[i]] - mp1[cnt[i]];
        }
        printf("%lld", ans);
        return 0;
    }
    for(int i = 1; i <= n; i ++){
        int xx;
        if(rem[i])
            xx = k - 1;
        else
            xx = k;
        ans += mp2[cnt[i] + xx];
    }
    printf("%lld", ans);
    return 0;
}
