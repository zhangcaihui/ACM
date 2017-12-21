#include<cstdio>
char oper[][8] = {"STRIKE", "HEAL"};
int ans[2333333];
int h1, a1, c;
int h2, a2, cnt;
int check(int x){ return x > 0;}
int main(){
    scanf("%d%d%d",&h1, &a1, &c);
    scanf("%d%d",&h2, &a2);
    while(check(h2)){
        if(!check(h2 - a1))
            ans[++cnt] = 0, h2 -= a1;
        else if(!check(h1 - a2))
            ans[++cnt] = 1, h1 += c - a2;
        else
            ans[++cnt] = 0, h1 -= a2, h2 -= a1;
    }
    printf("%d\n", cnt);
    for(int i = 1; i <= cnt; i ++)
        printf("%s\n", oper[ans[i]]);
    return 0;
}
