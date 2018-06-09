#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
int a[MAXN], b[MAXN], n, m;
int ca, cb, v, q;
void proc(){
    int xx1, xx2, yy1, yy2;
    scanf("%d%d%d%d", &xx1, &yy1, &xx2, &yy2);
    int p1 = min(yy1, yy2), p2 = max(yy1, yy2);
    int d = abs(xx1 - xx2);
    int ans = MAXN * 1000;
    int tmp1 = lower_bound(a+1, a+1+ca, p1) - a - 1;
    if(xx1 == xx2)
        ans = min(ans, abs(p1 - p2));
    if(0 < tmp1 && tmp1 <= ca){
        ans = min(ans, d + abs(p1 - a[tmp1]) + abs(p2 - a[tmp1]));
    }
    int tmp2 = tmp1 + 1;
    if(0 < tmp2 && tmp2 <= ca){
        ans = min(ans, d + abs(p1 - a[tmp2]) + abs(p2 - a[tmp2]));
    }
    
    tmp1 = lower_bound(b+1, b+1+cb, p1) - b - 1;
    if(0 < tmp1 && tmp1 <= cb){
        ans = min(ans, (d+v-1)/v + abs(p1 - b[tmp1]) + abs(p2 - b[tmp1]));
    }
    tmp2 = tmp1 + 1;
    if(0 < tmp2 && tmp2 <= cb){
        ans = min(ans, (d+v-1)/v + abs(p1 - b[tmp2]) + abs(p2 - b[tmp2]));
    }
    printf("%d\n", ans);
}
int main(){
    scanf("%d%d%d%d%d", &n, &m, &ca, &cb, &v);
    for(int i = 1; i <= ca; i ++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= cb; i ++)
        scanf("%d", &b[i]);
    scanf("%d", &q);
    while(q--){
        proc();
    }
}
