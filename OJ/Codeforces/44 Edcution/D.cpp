#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL n, h;
const LL up = 2e9+10;
LL ans;


LL find_lower(LL start, LL end, LL x){
    if(start == end)
        return start;
    LL m = (end - start) / 2 + start;
    LL cal = m * (m+1) / 2;
    if(cal < x)
        return find_lower(m+1, end, x);
    else
        return find_lower(start, m, x);
}

LL find_upper(LL start, LL end, LL x){
    if(start == end)
        return start;
    LL m = (end - start) / 2 + start;
    LL cal = m * m - (h-1) * h / 2;
    if(cal <= x)
        return find_upper(m+1, end, x);
    else
        return find_upper(start, m, x);
}



int main(){
    scanf("%lld%lld", &n, &h);
    if(h >= up){    
        printf("%lld", find_lower(1, up, n));
        return 0;
    }
    if(h * (h+1) / 2 >= n){
        printf("%lld", find_lower(1, up, n));
        return 0;
    }
    LL tem = find_upper(1, up, n) - 1;
    ans = tem - h + tem;
    n -= (tem * tem - (h-1)*h/2);
    ans += (n + tem - 1) / tem;
    printf("%lld", ans);
}
