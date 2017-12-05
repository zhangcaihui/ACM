#include<cstdio>
int T;
char ch[233];
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%s", ch);
        int cnt = 0, ans = 0;
        for(int i = 0; ch[i]; i ++){
            if(ch[i] == 'O')
                ans += (++cnt);
            else
                cnt = 0;
        }
        printf("%d\n", ans);
    }
}
