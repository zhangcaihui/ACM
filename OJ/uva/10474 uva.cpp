#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100100;
int n, m, x;
int arr[maxn];
int main(){
    int T = 0;
    while(scanf("%d%d", &n, &m) && (n || m)){
        printf("CASE# %d:\n", ++T);
        for(int i = 1; i <= n; i ++) scanf("%d", &arr[i]);
        arr[n+1] = 2016100101;
        sort(arr+1, arr+1+n);
        for(int i = 1; i <= m; i ++){
            scanf("%d", &x);
            int p = lower_bound(arr+1, arr+1+n, x) - arr;
            if(p > n || arr[p] != x)
                printf("%d not found\n", x);
            else
                printf("%d found at %d\n", x, p);
        }
    }
}