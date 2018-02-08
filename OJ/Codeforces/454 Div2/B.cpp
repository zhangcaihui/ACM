#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char mp[5][5][10][10];
int main(){
    int x, y;
    for(int k = 1; k <= 3; k ++)
        for(int i = 1; i <= 3; i ++){
            for(int j = 1; j <= 3; j ++){
                scanf("%s", mp[k][j][i]+1);
            }
        }
    
    scanf("%d%d", &x, &y);
    int xx = x % 3, yy = y % 3;
    xx = (xx == 0) ? 3 : xx;
    yy = (yy == 0) ? 3 : yy;
    int ff = 0;
    for(int i = 1; i <= 3; i ++)
        for(int j = 1; j <= 3; j ++){
            if(mp[xx][yy][i][j] != 111 && mp[xx][yy][i][j] != 120)
                ff = 1;
            }
    if(ff){
        for(int i = 1; i <= 3; i ++)
            for(int j = 1; j <= 3; j ++){
                if(mp[xx][yy][i][j] != 111 && mp[xx][yy][i][j] != 120)
                    mp[xx][yy][i][j] = 33;
                }
            }
    else{

        for(int xx = 1; xx <= 3; xx ++){
            for(int yy = 1; yy <= 3; yy ++){
                for(int i = 1; i <= 3; i ++)
                    for(int j = 1; j <= 3; j ++){
                        if(mp[xx][yy][i][j] != 111 && mp[xx][yy][i][j] != 120)
                            mp[xx][yy][i][j] = 33;
                    }
                }
            }
        }

    for(int k = 1; k <= 3; k ++){
        for(int i = 1; i <= 3; i ++){
            for(int j = 1; j <= 3; j ++){
                printf("%s", mp[k][j][i]+1);
                if(j != 3)
                    printf(" ");
                }
            puts("");
        }
        puts("");
    }
    
    return 0;
}