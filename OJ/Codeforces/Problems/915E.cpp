#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 101010 * 3;
struct node{
    int l, r, len;
    int stu;
    node(bool s = true, int lc = 0, int rc = 0, int l = 0): stu(s), l(lc), r(rc), len(l){}
}tree[MAXN * 4], poin[MAXN];

struct question{
    int l, r;
    bool stu;
    question(int lc = 0, int rc = 0, bool s = true): l(lc), r(rc), stu(s){}
}que[MAXN];
int n, q, tem, lef;
int arr[MAXN], len;

void build(int o, int l, int r){
    if(l == r){
        tree[o] = poin[l];
        return ;
    }
    int m = (l + r) >> 1;
    build(o<<1, l, m);
    build(o*2+1, m+1, r);
    poin[o].l = poin[o*2].l;
    poin[o].r = poin[o*2+1].r;
    poin[o].len = poin[o].r - poin[o].l;
}

void puin(){
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= q; i ++){
        scanf("%d%d%d", &que[i].l, &que[i].r, &tem);
        que[i].stu = tem - 1;
        arr[i*2-1] = que[i].l - 1;
        arr[i*2] = que[i].r;
    }
    arr[q*2+1] = n;
    sort(arr+1, arr+1+2*q+1);
    int len = unique(arr, arr+1+2*q+1) - arr - 1;
    for(int i = 1; i <= len; i ++){
        poin[i].l = arr[i-1];
        poin[i].r = arr[i];
        poin[i].len = arr[i] - arr[i-1];
    }
    
    build(1, 1, len);
}

int ql, qr, stu;

void pushdown(int o, int l, int r){
    int lc = o*2, rc = o*2 + 1;
    if(tree[o].stu >= 0){
        tree[lc].stu = tree[rc].stu = tree[o].stu;
        tree[o].stu = -1;
    }
}

void maintain(int o, int l, int r){
    if(tree[o].stu != -1){
        tree[o].len = (tree[o].r - tree[o].l) * tree[o].stu;
        return ;
    }
    int lc = o*2, rc = o*2+1;
    tree[o].len = tree[lc].len + tree[rc].len;
    return ;
}

void deal(int o, int l, int r){
    if(ql <= tree[o].l && tree[o].r <= qr){
        tree[o].stu = stu;
        tree[o].len = (tree[o].r - tree[o].l) * tree[o].stu;
        return ;
    }
    pushdown(o, l, r);
    int m = (l + r) >> 1;
    int len = 0, lc = o*2, rc = o*2+1;
    if(tree[m].l < qr)
         deal(lc, l, m);
    else
        maintain(lc, l, m);
    if(ql <= tree[m].r)
        deal(rc, m+1, r);
    else
        maintain(rc, m+1, r);
    maintain(o, l, r);
}

void proc(){
    for(int i = 1; i <= q; i ++){
        ql = que[i].l - 1;
        qr = que[i].r;
        stu = que[i].stu - 1;
        deal(1, 1, len);
        printf("%d\n", tree[1].len);
    }
}

int main(){
    puin();
    proc();
    return 0;
}