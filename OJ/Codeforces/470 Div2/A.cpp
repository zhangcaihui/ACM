#include<cstdio>
char ch[510][510];
int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++){
        scanf("%s", ch[i] + 1);
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(ch[i][j] != 'S')
                continue;
            for(int k = 0; k < 4; k ++){
                if(ch[i+d[k][0]][j+d[k][1]] == 'W'){
                    printf("No");
                    return 0;
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++)
            if(ch[i][j] == '.'){
                ch[i][j] = 'D';
            }
        }
        printf("Yes\n");
    for(int i = 1; i <= n; i ++){
        if(i != 1)
            printf("\n");
        printf("%s", ch[i]+1);
    }
}