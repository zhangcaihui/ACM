#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
const int MAXN = 1001010;
int n, cnt = 1;
double ans[MAXN], arr[MAXN], r;
int main(){
    scanf("%d%lf", &n, &r);
    for(int i = 1; i <= n; i ++)
        scanf("%lf", &arr[i]);
    ans[1] = r;
    for(int i = 2; i <= n; i ++){
        int ff = 0;
        for(int j = 1; j < i; j ++){
            if(fabs(arr[j] - arr[i]) > 2*r)
                continue;
            double x = fabs(arr[j] - arr[i]);
            ans[i] =max(ans[i], sqrt(4*r*r - x * x) + ans[j]);
            ff = 1;
        }
        if(!ff)
            break;
        cnt ++;
    }
    for(int i = 1; i <= cnt; i ++)
        printf("%.8lf ", ans[i]);
    return 0;
}
