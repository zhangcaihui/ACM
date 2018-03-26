#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 101010;
LL maxv[MAXN*4];
int ql, qr, p, x;
int n, q;
void add(int o, int l, int r){
    if(l == r){
        maxv[o] += x;
        return ;
    }
    int m = (l + r) / 2;
    if(p <= m)
        add(o<<1, l, m);
    else
        add(o*2+1, m+1, r);
    maxv[o] = max(maxv[o*2], maxv[o*2+1]);
}

LL query(int o, int l, int r){
    LL ans = 0;
    if(ql <= l && r <= qr)
        return maxv[o];
    int m = (l + r) / 2;
    if(ql <= m)
        ans = query(o*2, l, m);
    if(m < qr)
        ans = max(ans, query(o*2+1, m+1, r));
    return ans;
}

int main(){
    int t;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= q; i ++){
        scanf("%d", &t);
        if(t & 1){
            scanf("%d%d", &p, &x);
            add(1, 1, n);
        }
        else{
            scanf("%d%d", &ql, &qr);
            LL ans = query(1, 1, n);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
