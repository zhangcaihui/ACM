#include<cstdio>
double ans = 1, arr[1001];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        double n, sum = 0;
        ans = 1;
        scanf("%lf", &n);
        for(int i = 1; i <= n; i ++){
            scanf("%lf", &arr[i]);
            sum += arr[i];
        }
        for(int i = 1; i <= n; i ++){
            ans *= arr[i] / sum;
            n -= arr[i];
        }
        printf("%.5f\n", ans);
    }
    return 0;
}
