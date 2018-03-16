#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 101010;
LL arr[MAXN], sum;
int n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%lld", &arr[i]);
        sum += arr[i];
    }
    sort(arr+1, arr+1+n);
    LL ans = sum;
    ans = sum = sum - arr[1] * n;
    for(int i = 2; i <= n; i ++){
        sum -= (n-i+1)*(arr[i] - arr[i-1]);
        sum += (i-1) * (arr[i] - arr[i-1]);
        ans = min(ans, sum);
    }
    printf("%lld", ans);
}