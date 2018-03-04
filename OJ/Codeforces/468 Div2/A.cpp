#include<cstdio>
#include<cstdlib>
typedef long long int LL;
LL rem[1001010];
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    for(int i = 1; i <= 1010; i ++)
        rem[i] = rem[i-1] + i;
    int tem = abs(b-a) / 2;
    printf("%lld", rem[tem]+rem[abs(a-b) - tem]);
}