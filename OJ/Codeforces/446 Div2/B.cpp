#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 1001010;
int rem[maxn*4], n, ql, qr, ans;

void build(int o, int l, int r){
    if(ql <= l && r <= qr){
        rem[o] ++;
        return ;
    }
    else{
        int m = (l + r) / 2;
        if(ql <= m)
            build(o<<1, l, m);
        if(m < qr)
            build((o<<1)+1, m+1, r);
    }
}

void cal(int o, int l, int r, int x){
    if(l == r){
        if(rem[o] == 0)
            ans ++;
        return ;
    }
    int m = (l + r) / 2;
    rem[o<<1] += rem[o];
    rem[(o<<1)+1] += rem[o];
    if(x <= m)
        cal(o<<1, l, m, x);
    if(m < x)
        cal((o<<1)+1, m+1, r, x);
}

void proc(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        int l;
        scanf("%d", &l);
        if(!l || i == 1)
            continue;
        ql = max(i-l, 1);
        qr = i - 1;
        build(1, 1, n);
    }
    for(int i = 1; i <= n; i ++)
        cal(1, 1, n, i);
    printf("%d", ans);
}

int main(){
    proc();
    return 0;
}
