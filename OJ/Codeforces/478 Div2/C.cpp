#include<bits/stdc++.h>
using namespace std;
const int MAXN = 101010 * 2;
typedef long long int LL;
int n, m;
long long int a[MAXN], b[MAXN], rem;
LL suma[MAXN];
int main(){
    memset(suma, 127, sizeof(suma));
    suma[0] = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++){
        scanf("%lld", &a[i]);
        suma[i] = suma[i-1] + a[i];
    }
    for(int i = 1; i <= m; i ++){
        scanf("%lld", &b[i]);
        if(rem + b[i] >= suma[n]){
            rem = 0;
            printf("%d\n", n);
            continue;
        }
        int tmp = upper_bound(suma+1, suma+1+n, rem + b[i]) - suma ;
        printf("%d\n", n - tmp + 1);
        rem = rem + b[i];
    }
    return 0;
}
