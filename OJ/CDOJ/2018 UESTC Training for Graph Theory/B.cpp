#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
typedef long long int LL;
struct Edge{
    int x, y;
    LL val;
    bool operator < (const Edge xx) const{
        return val < xx.val;
    }
}a[MAXN];
int n, m, f[MAXN];
int find(int x){ return f[x] ? (f[x] = find(f[x])) : x;} 
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++)
        scanf("%d%d%lld", &a[i].x, &a[i].y, &a[i].val);
    sort(a+1, a+1+m);
    for(int i = 1; i <= m;){
        int a1, b1;
        int k = i, cnt1 = 0, cnt2 = 0;
        while(a[k].val == a[i].val)
            k ++;
        for(int j = i; j < k; j ++){
            a1 = find(a[j].x); b1 = find(a[j].y);
            if(a1 != b1)
                cnt1 ++;
        }
        for(int j = i; j < k; j ++){
            a1 = find(a[j].x); b1 = find(a[j].y);
            if(a1 != b1)
                f[a1] = b1, cnt2 ++;
        }
        if(cnt1 != cnt2){
            printf("zin");
            return 0;
        }
        i = k;
    }
    printf("ogisosetsuna");
}   
