#include<bits/stdc++.h>
using namespace std;
int n, m;
char ch[1010][1010];
int cal(char x){
    if(x == '.') return 0;
    return x - '0';
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++){
        scanf("%s", ch[i]+1);
    }
    bool flag = true;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            int num;
            if(ch[i][j] == '*')
                continue;
            else
                num = cal(ch[i][j]);
            int tem = 0;
            for(int x = -1; x <= 1; x ++){
                for(int y = -1; y <= 1; y ++){
                    if(ch[i+x][j+y] == '*')
                        tem ++;
                }
            }
            if(tem != num)
                flag = false;
        }
    }
    if(flag)
        printf("YES");
    else
        printf("NO");
}
