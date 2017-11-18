#include<cstdio>
int a[1001010];
int main(){
    int l, n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    l = n + 1;
    for(int i = n; i > 0; i --){
        if(l > i)
            ans ++;
        l = i - a[i] < l ? i-a[i] : l;
    }
    printf("%d", ans);
    return 0;
}
