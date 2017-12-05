#include<cstdio>
int main(){
    int T, n;
    scanf("%d", &T);
    while(T--){
        int ans[123] = {0};
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            int tem = i;
            while(tem){
                ans[tem % 10] ++;
                tem /= 10;
            }
        }
        for(int i = 0; i <= 9; i ++){
            if(i)
                printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}
