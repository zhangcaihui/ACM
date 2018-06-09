#include<bits/stdc++.h>
using namespace std;
int a[1010];
int rem[10100], s[10100], cnt;
int main(){
    int T, n, x, m;
    scanf("%d", &T);
    while(T--){
        memset(s, 0, sizeof(s));
        memset(rem, 0, sizeof(rem));
        cnt = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i ++){
            int tem = 0, len = 0;
            for(int j = i; j <= n; j ++){
                len ++;
                tem ^= a[j];
                rem[tem] = max(rem[tem], len);
            }
        }
        for(int i = 0; i <= 1024; i ++){
            if(rem[i])
                s[++cnt] = i;
        }
        s[cnt + 1] = 10101009;
        scanf("%d", &m);
        for(int i = 1; i <= m; i ++){
            scanf("%d", &x);
            int p = lower_bound(s+1, s+1+cnt, x) - s;
            int diff = s[p] - x;
            if(diff > x - s[p-1] && rem[s[p-1]]){
                printf("%d\n", rem[s[p-1]]);
            }
            else if((diff == x - s[p-1]) && rem[s[p-1]]){
                printf("%d\n", max(rem[s[p-1]], rem[s[p]]));
            
            }
            else{
                printf("%d\n", rem[s[p]]);   
            }
        }
        puts("");
    }
}
