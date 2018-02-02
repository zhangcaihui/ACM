#include<cstdio>
#include<algorithm>
using namespace std;
int n;
char kin[10], tem[100];
int mp[100][100];
int rem[][3] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, p;
void puin(){
    scanf("%d%s", &n, kin);
    if(kin[0] == 'u')
        p = 0;
    else if(kin[0] == 'd')
        p = 1;
    else if(kin[0] == 'l')
        p = 2;
    else if(kin[0] == 'r')
        p = 3;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++)
            scanf("%d", &mp[i][j]);
    }
    for(int i = 0; i <= n + 1; i ++)
        mp[i][0] = mp[0][i] = mp[n+1][i] = mp[i][n+1] = 0;
}

bool check(int i, int j){ return ((i) && (i <= n)) && ((j) && (j <= n));}

void proc0(){
    for(int i = 1; i <= n; i ++){
        for(int j = n; j ; j --){
            if(mp[i][j]){
                int x = i - rem[p][0], y = j - rem[p][1];
                while(check(x, y)){
                    if(mp[x][y]){
                        if(mp[x][y] == mp[i][j]){
                            mp[i][j] += mp[x][y];
                            mp[x][y] = 0;
                        }
                        break;
                    }
                    x -= rem[p][0];
                    y -= rem[p][1];
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = n; j ; j --){
            if(!mp[i][j]){
                int x = i - rem[p][0], y = j - rem[p][1];
                while(check(x, y)){
                    if(mp[x][y]){
                        mp[i][j] = mp[x][y];
                        mp[x][y] = 0;
                        break;
                    }
                    x -= rem[p][0];
                    y -= rem[p][1];
                }
            }
        }
    }
    return ;
}

void proc1(){
    for(int i = n; i ; i --){
        for(int j = 1; j <= n; j ++){
            if(mp[i][j]){
                int x = i, y = j;
                while(check(x, y)){
                    x -= rem[p][0];
                    y -= rem[p][1];
                    if(mp[x][y]){
                        if(mp[x][y] == mp[i][j]){
                            mp[i][j] += mp[x][y];
                            mp[x][y] = 0;
                        }
                        break;
                    }
                }
            }
        }
    }
    for(int i = n; i ; i --){
        for(int j = 1; j <= n; j ++){
            if(!mp[i][j]){
                int x = i, y = j;
                while(check(x, y)){
                    x -= rem[p][0];
                    y -= rem[p][1];
                    if(mp[x][y]){
                        mp[i][j] = mp[x][y];
                        mp[x][y] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void proc2(){
    for(int j = 1; j <= n; j ++){
        for(int i = 1; i <= n; i ++){
            if(mp[i][j]){
                int x = i, y = j;
                while(check(x, y)){
                    x -= rem[p][0];
                    y -= rem[p][1];
                    if(mp[x][y]){
                        if(mp[x][y] == mp[i][j]){
                            mp[i][j] += mp[x][y];
                            mp[x][y] = 0;
                        }
                        break;
                    }
                }
            }
        }
    }
    for(int j = 1; j <= n; j ++){
        for(int i = 1; i <= n; i ++){
            if(!mp[i][j]){
                int x = i, y = j;
                while(check(x, y)){
                    x -= rem[p][0];
                    y -= rem[p][1];
                    if(mp[x][y]){
                        mp[i][j] = mp[x][y];
                        mp[x][y] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void proc3(){
    for(int j = n; j ; j --){
        for(int i = n; i ; i --){
            if(mp[i][j]){
                int x = i, y = j;
                while(check(x, y)){
                    x -= rem[p][0];
                    y -= rem[p][1];
                    if(mp[x][y]){
                        if(mp[x][y] == mp[i][j]){
                            mp[i][j] *= 2;
                            mp[x][y] = 0;
                        }
                        break;
                    }
                }
            }
        }
    }
    for(int j = n; j ; j --){
        for(int i = n; i ; i --){
            if(!mp[i][j]){
                int x = i, y = j;
                while(check(x, y)){
                    x -= rem[p][0];
                    y -= rem[p][1];
                    if(mp[x][y]){
                        mp[i][j] = mp[x][y];
                        mp[x][y] = 0;
                        break;
                    }
                }
            }
        }
    }
    
}


void proc(){
    if(p == 0)// u
        proc0();
    if(p == 1)// d
        proc1();
    if(p == 2)// l
        proc2();
    if(p == 3)// r
        proc3();
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            printf("%d", mp[i][j]);
            if(j != n)
                printf(" ");
        }
        printf("\n");
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        puin();
        proc();
    }
    return 0;
}

/*
 4
 4 left
 2 0 2 2
 2 4 2 4
 2 0 2 4
 2 4 4 2
 3 down
 2 2 2
 2 4 2
 2 2 2
 3 left
 2 2 2
 2 4 2
 2 2 2
 3 right
 2 2 2
 2 4 2
 2 2 2
 */
