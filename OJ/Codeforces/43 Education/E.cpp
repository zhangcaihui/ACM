#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 202020;
typedef long long int LL;
LL a1[MAXN], a2[MAXN], a0[MAXN], ans;
int cnt1, cnt2, cnt0, tmp, n;
char ch[2];
LL cal(LL x){
    if(x > 0) return x;
    return 0;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d%s", &tmp, ch);
        if(ch[0] == 'P')
            a0[++cnt0] = tmp;
        else if(ch[0] == 'B')
            a1[++cnt1] = tmp;
        else
            a2[++cnt2] = tmp;
    }
    if(!cnt0){
        printf("%lld", a1[cnt1]-a1[1]+a2[cnt2]-a2[1]);
        return 0;
    }
    if(!cnt1 && !cnt2){
        printf("%lld", a0[cnt0]-a0[1]);
        return 0;
    }
    if(cnt0 == 1){
        if(cnt1) ans += max(a1[cnt1],a0[cnt0]) - min(a1[1], a0[1]);
        if(cnt2) ans += max(a2[cnt2],a0[cnt0]) - min(a2[1], a0[1]);
        printf("%lld", ans);
        return 0;
    }
    a0[0] = a1[0] = a2[0] = -1e10;
    a1[cnt1+1] = a2[cnt2+1] = 1e10;
    ans += cal(a0[1]-a1[1]) + cal(a0[1]-a2[1]);
    ans += cal(a1[cnt1] - a0[cnt0]) + cal(a2[cnt2]-a0[cnt0]);
    int p1, p2;
    p1 = p2 = 1;
    for(int i = 1; i < cnt0; i ++){
        LL tem, temx, temy;
        tem = temx = temy = 0;
        while(a1[p1] < a0[i])
            p1 ++;
        while(a2[p2] < a0[i])
            p2 ++;
        if(a1[p1] > a0[i+1])
            temx = a0[i+1] - a0[i];
        else{
            temx = a1[p1] - a0[i];
            while(a1[p1+1] < a0[i+1]){
                p1 ++;
                temx = max(temx, a1[p1] - a1[p1-1]);
            }
            temx = max(temx, a0[i+1]-a1[p1]);
        }
        if(a2[p2] > a0[i+1])
            temy = a0[i+1] - a0[i];
        else{
            temy = a2[p2] - a0[i];
            while(a2[p2+1] < a0[i+1]){
                p2 ++;
                temy = max(temy, a2[p2] - a2[p2-1]);
            }
            temy = max(temy, a0[i+1]-a2[p2]);
        }
        LL len = a0[i+1]-a0[i];
        ans += min(2*len, 3*len - temx-temy);
    }
    printf("%lld", ans);
}

