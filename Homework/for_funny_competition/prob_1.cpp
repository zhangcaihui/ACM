#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 101010;
int n, l, r, p, pp;
int minpl, minpr, maxpl, maxpr;
double minl, minr, maxl, maxr, minn;
double a[maxn], sum, ans, tans;
void prep(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%lf", &a[i]);
    scanf("%d%d", &l, &r);
    minl = minr = 10, maxl = maxr = -10;
    minpl = maxpl = 1, minpr = maxpr = n;
    for(int i = 1; i < l; i ++){
        minpl = minl <= a[i] ? minpl : i;
        minl = min(minl, a[i]);
        maxpl = maxl >= a[i] ? maxpl : i;
        maxl = max(maxl, a[i]);
    }
    for(int i = n; i > r; i --){
        minpr = minr < a[i] ? minpr : i;
        minr = min(minr, a[i]);
        maxpr = maxpr > a[i] ? maxpr : i;
        maxr = max(maxr, a[i]);
    }
}

void proc(){
    sum = 0;
    for(int i = l; i <= r; i ++)
        sum += a[i] / (1.0 - a[i]);
    if(sum > 1.0){
        p = minl <= minr ? minpl : minpr;
        ans = sum - (sum - 1) * a[p];
    }
    else if(sum < 1.0){
        p = maxl >= maxr ? maxpl : maxpr;
        ans = sum - (sum - 1) * a[p];
    }
    else
        ans = sum, p = l == 1 ? r + 1 : 1;
    tans = ans - 1;
    for(int i = l; i <= r; i ++)
        if(tans < (sum - a[i]/(1.0-a[i])))
            pp = i, tans = sum - a[i]/(1.0-a[i]);
    if(tans > ans)
        ans = tans, p = pp;
    else if(tans == ans && p > pp)
        p = pp; 
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        prep();
        proc();
        printf("%d\n", p);
    }
}