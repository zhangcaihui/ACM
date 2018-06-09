#include<bits/stdc++.h>
using namespace std;
int n, p;
struct node{
    int l, r, cnt;
    bool operator < (const node xx) const {
        return r == xx.r ? l < xx.l : r < xx.r;
    }
}a[1001010];
int main(){
    scanf("%d", &n, &m);
    for(int i = 1; i <= m; i ++){
        scanf("%d%d%d", &a[i].l, &a[i].r , &a[i].cnt);
    }
    sort(a+1, a+1+m);
    for(int i = 1; i <= n; i ++){
        while(i > a[p].r)
            p ++;
    }
}
