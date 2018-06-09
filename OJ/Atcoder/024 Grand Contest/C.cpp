#include<bits/stdc++.h>
using namespace std;
int n, a[1001010];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i ++){
        if(a[i] >= i || a[i] - a[i-1] > 1){
            printf("-1");
            return 0;
        }
    }
    long long int ans = 0;
    for(int i = n; i > 0; i --){
        ans += a[i];
        /*
        if(a[i] < maxv){
            printf("-1");
            return 0;
        }
        maxav = max(maxv, a[i]);
        */
        while(a[i-1] == a[i]-1){
            i --;
        }
    }
    printf("%lld", ans);
}
