#include<bits/stdc++.h>
using namespace std;
double sum, a[101010], A, B;
int n;
int main(){
    scanf("%d%lf%lf", &n, &A, &B);
    for(int i = 1; i <= n; i ++){
        scanf("%lf", &a[i]);
        sum += a[i];
    }
    sort(a+2, a+1+n);
    int ans = 0;
    for(int i = n; i > 1; i --){
        if(a[1] / sum >= B / A){
            printf("%d", ans);
            return 0;
        }
        sum -= a[i];
        ans ++;
    }
    printf("%d", n-1);
    return 0;
}
