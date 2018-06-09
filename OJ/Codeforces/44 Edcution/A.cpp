#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int n, a[MAXN];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n/2; i ++){
        scanf("%d", &a[i]);
    }
    int ans = 0;
    sort(a+1, a+1+n/2);
    for(int i = 1; i <= n/2; i ++){
        ans += abs(i*2 - a[i]);
    }
    if(!(n & 1)){
        int tem = 0, cnt = 0;
        for(int i = 1; i <= n; i += 2){
            tem += abs(a[++cnt] - i);
        }
        ans = min(ans, tem);
    }
    printf("%d", ans);
}
