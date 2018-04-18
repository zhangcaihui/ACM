#include<cstdio>
int n, A, B, C, T;
int tmp, a[1010];
int main(){
    scanf("%d%d%d%d%d", &n, &A, &B, &C, &T);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &tmp);
        a[tmp] ++;
    }
    int ans = 0;
    if(C <= B){
        ans = n * A;
    }
    else{
        ans = n * A;
        for(int i = 1; i <= T; i ++){
            ans += a[i] * (T - i) * (C-B);
        }
    }
    printf("%d", ans);
    return 0;
}
