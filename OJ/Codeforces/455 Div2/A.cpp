#include<cstdio>
#include<algorithm>
#include<cstring>
char ch[2][22], ans[30];
int main(){
    scanf("%s%s", ch[0], ch[1]);
    int i;
    for(i = 1; ch[0][i] && ch[0][i] < ch[1][0]; i ++)
        ans[i] = ch[0][i];
    ans[0] = ch[0][0];
    ans[i] = ch[1][0];
    printf("%s", ans);
    return 0;
}
