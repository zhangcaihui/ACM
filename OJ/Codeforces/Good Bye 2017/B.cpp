#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10010;
int ans, n, m, len;
char mp[101][101], dir[6];
char note[MAXN];
int x1, y1, x2, y2;
int rem[6];
void exec(){ // up, down, left, right
    int xx = x1, yy = y1;
    for(int i = 0; note[i]; i ++){
        if(note[i] == dir[0])
            xx --;
        else if(note[i] == dir[1])
            xx ++;
        else if(note[i] == dir[2])
            yy --;
        else if(note[i] == dir[3])
            yy ++;
        if(mp[xx][yy] == 'E'){
            ans ++;
            return ;
        }
        else if(mp[xx][yy] == '#' || !mp[xx][yy])
            return ;
    }
}
void dfs(int x){
    if( x == 4 ){
        exec();
        return ;
    }
    for(int i = 0; i < 4; i ++){
        if(rem[i])
            continue;
        rem[i] = 1;
        dir[x] = i + '0';
        dfs(x+1);
        rem[i] = 0;
    }
}
void proc(){
    dfs(0);
    printf("%d", ans);
}
void puin(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
        scanf("%s", mp[i]+1);
    scanf("%s", note);
    len = strlen(note);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++){
            if(mp[i][j] == 'S')
                x1 = i, y1 = j;
            else if(mp[i][j] == 'E')
                x2 = i, y2 = j;
        }
}
int main(){
    puin();
    proc();
}
