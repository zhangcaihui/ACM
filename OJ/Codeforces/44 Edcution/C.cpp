#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int MAXN = 1001010;
int n, m, cnt;
LL a[MAXN], l;

bool check(){
    int tmp = upper_bound(a+1, a+1+n*m, a[1] + l) - a;
    cnt = tmp - 1;
    if(tmp <= n)
        return true;
    return false;
}

int main(){
    scanf("%d%d%lld", &n, &m, &l);
    for(int i = 1; i <= n*m; i ++){
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+1+n*m);
    if(check()){
        printf("0");
        return 0;
    }
    LL ans = 0;
    int tem = cnt - n;
    for(int i = 1; i <= cnt; i ++){
        ans += a[i];
        for(int j = 1; tem && j < m; j ++) 
            tem --, i ++; 
    }
    printf("%lld", ans);
}
