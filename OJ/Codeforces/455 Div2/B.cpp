#include<cstdio>
int main(){
    int ans = 0, n;
    scanf("%d", &n);
    for(int i = n; i > 0; i -= 2){
        ans += i;
    }
    printf("%d", ans);
}
