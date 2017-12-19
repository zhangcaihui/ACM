#include<cstring>
#include<cstdio>
using namespace std;
bool turn, ff;
char a[25][25], b[23333];
void cond(int& x, int& y, char vec){
    int xx = x, yy = y;
    if(vec == 'A')
        xx = x - 1;
    else if(vec == 'B')
        xx = x + 1;
    else if(vec == 'L')
        yy = y - 1;
    else if(vec == 'R')
        yy = y + 1;
    
    if(!xx || xx > 5){
        ff = true;
    }
    if(!yy || yy > 5){
        ff = true;
    }
    if(ff)
        return ;
    char tem = a[x][y];
    a[x][y] = a[xx][yy];
    a[xx][yy] = tem;
    x = xx, y = yy;
}
int main(){
    int cnt = 0;
    while(1){
        ff = false;
        int x, y;
        for(int i = 1; i <= 5; i ++){
            for(int j = 1; j <= 5; j ++){
                scanf("%c", &a[i][j]);
                if(a[i][j] == ' ')
                    x = i, y = j;
                else if(a[i][j] == 'Z'){
                    return 0;
                }
            }
            getchar();
        }
        if(cnt)
            printf("\n");
        int p = 0;
        do{
            scanf("%s", b+p);
            p = strlen(b);
        }while(b[strlen(b)-1] != '0');
        getchar();
        
        printf("Puzzle #%d:\n", ++cnt);
        for(int i = 0; b[i] != '0'; i ++){
            cond(x, y, b[i]);
        }
        if(ff)
            printf("This puzzle has no final configuration.\n");
        for(int i = 1; i <= 5 && !ff; i ++){
            for(int j = 1; j <= 5; j ++){
                printf("%c", a[i][j]);
                if(j < 5)
                    printf(" ");
            }
            printf("\n");
        }
    }
}