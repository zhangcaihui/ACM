#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 101010;
int n, l, r, p;
double a[maxn], sum, ans, tem;
void putin(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%lf", &a[i]);
    scanf("%d%d", &l, &r);
    sum = 0, ans = 0;
    for(int i = l; i <= r; i ++)
        sum += a[i] / (1.0 - a[i]);
}

double cal(int x){
    return (l <= x && x <= r) ? sum - a[x]/(1.0-a[x]) : sum - (sum - 1) * a[x];
}

void proc(){
    for(int i = 1; i <= n; i ++){
        tem = cal(i);
        p = ans < tem ? i : p;
        ans = max(ans, tem);
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        putin();
        proc();
        printf("%d\n", p);
        printf("ans = %lf\n", ans);
    }
}
