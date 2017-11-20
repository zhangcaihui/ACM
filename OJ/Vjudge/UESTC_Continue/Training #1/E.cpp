#include<cstdio>
long long int a[1001][1001], sub[1001], sum;
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++)
            scanf("%lld", &a[i][j]), sum += a[i][j], sub[i] += a[i][j];
    }
    long long int rem = sum / (n - 1);
    for(int i = 1; i <= n; i ++)
        a[i][i] = rem - sub[i];

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++)
            printf("%lld ", a[i][j]);
        printf("\n");
    }
}
