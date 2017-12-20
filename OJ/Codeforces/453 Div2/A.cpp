#include<cstdio>
int a[233], b[233];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
        scanf("%d%d", &a[i], &b[i]);
    int left = 0;
    for(int i = 1; i <= n; i ++){
        if(left < a[i])
            continue;
        left = left > b[i] ? left : b[i];
    }
    if(left >= m)
        printf("YES");
    else
        printf("NO");
}
