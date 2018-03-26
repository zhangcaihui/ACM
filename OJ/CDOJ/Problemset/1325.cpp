#include<map>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 101010;
struct QUES{
    int t, l, r;
}que[MAXN];
map<int, int> mp;
int ql, qr;
int tree[MAXN*4], rem[MAXN*4];
int rans[MAXN*4];

void pushdown(int o, int l, int r){
    int lc = o*2, rc = o*2+1;
    if(tree[o]){
        tree[lc] = tree[rc] = 1;
    }
}

void update(int o, int l, int r){
    if(ql <= l && r <= qr){
        tree[o] = 1;
        rans[o] = rem[r] - rem[l];
        return ;
    }
    int m = (l + r) / 2;
    pushdown(o, l, r);
    if(ql <= m)
        update(o*2, l, m);
    if(m < qr)
        update(o*2, m+1, r);
    if(!tree[o])
        rans[o] = rans[o*2] + rans[o*2+1];
}

int query(int o, int l, int r){
    int ans = 0;
    if(ql <= l && r <= qr){
        if(tree[o])
            return rans[o] = rem[r] - rem[l];
        return rans[o];
    }
    if(l == r)
        return 0;
    int m = (l + r) / 2;
    pushdown(o, l, r);
    if(ql <= m)
        ans += query(o*2, l, m);
    if(m < qr)
        ans += query(o*2+1, m+1, r);
    return ans;
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= q; i ++){
        scanf("%d%d%d", &que[i].t, &que[i].l, &que[i].r);
        rem[i*3-2] = que[i].l;
        rem[i*3-1] = que[i].r;
        rem[i*3] = que[i].r + 1;
    }
    sort(rem+1, rem+1+3*q);
    int len = unique(rem+1, rem+1+3*q) - rem - 1;
    for(int i = 1; i <= len; i ++)
        mp[rem[i]] = i;
    
    for(int i = 1; i <= q; i ++){
        ql = mp[que[i].l], qr = mp[que[i].r];
        if(que[i].t & 1)
            update(1, 1, len);
        else
            printf("%d\n", que[i].r - que[i].l + 1 - query(1, 1, len));
    }
    return 0;
}

/*
 
 5 3
 1 1 2
 1 4 5
 2 2 4
 
 */


