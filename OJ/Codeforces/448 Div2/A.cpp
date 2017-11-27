#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[2333], n, sum[2333], ans = 360;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 0; i < n; i ++){
        for(int j = i+1; j <= n; j ++){
            ans = min(ans, abs(360-2*(sum[j]- sum[i])));
        }
    }
    printf("%d", ans);
    return 0;
}
