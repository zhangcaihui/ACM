#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 101010;
LL sum[MAXN], T[MAXN], v[MAXN];
struct node{
    int cnt;
    LL val;
}arr[MAXN];
int n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &v[i]);
    }
    for(int i = 1; i <= n; i ++){
        scanf("%lld", &T[i]);
        sum[i] = sum[i-1] + T[i];
    }

    for(int i = 1; i <= n; i ++){
        int tmp = lower_bound(sum+1, sum+1+n, sum[i-1]+v[i]) - sum;
        LL tem = sum[tmp];
        arr[tmp].val += sum[i-1] + v[i] - sum[tmp - 1];
        arr[tmp].cnt ++;
    }
    LL num = 0;
    for(int i = 1; i <= n; i ++){
        num ++;
        num -= arr[i].cnt;
        printf("%lld ", num*T[i] + arr[i].val);
    }
    return 0;
}