#include<cstdio>
using namespace std;
int n, a, b, ans;
bool check(){
    return a != b;
}
int main(){
    scanf("%d%d%d", &n, &a, &b);
    while(check()){
        ans ++;
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        n = (n + 1) / 2;
    }
    if(n == 1)
        printf("Final!");
    else
        printf("%d", ans);
}