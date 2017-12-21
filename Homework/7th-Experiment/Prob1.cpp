#include<cstdio>
const int MAXN = 1001010;
//二维树状数组
int n, a[MAXN], rem[MAXN];
int lowbit(int x){ return (x & -x);}
void build(int x)
{
    for(int i = x; i < MAXN; i += lowbit(i))
        rem[i] ++;
}
int sum(int x)
{
    int cnt = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        cnt += rem[i];
    return cnt;
}

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++){
        ans += sum(a[i]+1);
        build(a[i]);
    }
    printf("%d", ans);
    return 0;
}
/*
 sample:
 3
 3 2 1
 */
