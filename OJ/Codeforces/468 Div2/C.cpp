#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 101010;
int cnt[5];
int arr[MAXN];
int maxv = -MAXN, minv = MAXN, n;
int sumv, ans = MAXN;
int a, b, c, ff = 0;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &arr[i]);
        minv = min(minv, arr[i]);
        maxv = max(maxv, arr[i]);
    }

    for(int i = 1; i <= n; i ++){
        cnt[arr[i]-minv] ++;
        sumv += arr[i] - minv;
    }

    //printf("%d %d %d\n", cnt[0], cnt[1], cnt[2]);
    for(int i = 0; i <= 3; i ++)
        if(cnt[i])
            ff ++;

    if(ff == 1){
        printf("%d\n", n);
        for(int i = 1; i <= n; i ++)
            printf("%d ", minv);
        return 0;
    }
    else if(ff == 2){
        if(maxv - minv > 1){
            sumv -= n;
            ans = abs(sumv);
            printf("%d\n", ans);
            for(int i = 1; i <= ans; i ++){
                printf("%d ", sumv > 0 ? maxv : minv);
            }
            for(int i = 1; i <= n - ans; i ++)
                printf("%d ", minv + 1);
            return 0;
        }
        printf("%d\n", n);
        for(int i = 1; i <= n; i ++)
            printf("%d ", arr[i]);
        return 0;
    }
    else{
        sumv -= n;
        for(int i = 0; i <= n; i ++){
            int ta, tb, tc;
            ta = i;
            tc = sumv + ta;
            tb = n - ta - tc;
            if(tb < 0 || tc < 0)
                continue;
            if(ans > min(ta, cnt[0]) + min(tb, cnt[1]) + min(tc, cnt[2])){
                ans = min(ta, cnt[0]) + min(tb, cnt[1]) + min(tc, cnt[2]);
                a = ta, b = tb, c = tc;
            }
        }
        printf("%d\n", ans);
        for(int i = 1; i <= a; i ++)
            printf("%d ", minv);
        for(int i = 1; i <= b; i ++)
            printf("%d ", minv + 1);
        for(int i = 1; i <= c; i ++)
            printf("%d ", maxv);
    }
}