#include<cstdio>
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", y-x+2);
    }
}