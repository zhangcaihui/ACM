#include<cstdio>
const int maxn = 1000;
int n, m, x, y;
char ch[maxn], a[3], b[3];
int main(){
    scanf("%d%d%s", &n, &m, ch+1);
    for(int i = 1; i <= m; i ++){
        scanf("%d%d%s%s", &x, &y, a, b);
        for(int j = x; j <= y; j ++){
            if(ch[j] == a[0])
                ch[j] = b[0];
        }
    }
    printf("%s", ch+1);
    return 0;
}

