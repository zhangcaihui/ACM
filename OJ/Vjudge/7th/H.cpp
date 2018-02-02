
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

struct node{
    int x, y, len;
    char kin;
    node(int xx, int yy, char c, int l): x(xx), y(yy), kin(c), len(l){}
};

vector<node> v[25][25];

int dir[][3] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct temp{
    int x, y, len;
    temp(int xx, int yy, int l): x(xx), y(yy), len(l){}
};
queue<temp> q;

struct nod2{
    int x, y, dix;
    nod2(int a, int b, int c): x(a), y(b), dix(c) {}
};
queue<nod2> qq;

char ch[25][25], pace[210][110];
int n, m, quer, note[25][25];
bool check(int x, int y){ return (x) && (x <= n) && (y) && (y <= m);}
void puin(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
        scanf("%s", ch[i] + 1);
    scanf("%d", &quer);
    memset(pace, '\0', sizeof(pace));
    for(int i = 1; i <= quer; i ++)
        scanf("%s", pace[i] + 1);
    
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            v[i][j].clear();
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(ch[i][j] == '.' || ch[i][j] == '#')
                continue;
            memset(note, 0, sizeof(note));
            q.push(temp(i, j, 0));
            note[i][j] = 1;
            v[i][j].push_back(node(i, j, ch[i][j], 0));
            while(!q.empty()){
                temp tmp = q.front(); q.pop();
                for(int k = 0; k < 4; k ++){
                    int xx = tmp.x + dir[k][0], yy = tmp.y + dir[k][1];
                    if(check(xx, yy) && !note[xx][yy]){
                        if(ch[xx][yy] == '.' || ch[xx][yy] == '@'){
                            q.push(temp(xx, yy, tmp.len + 1));
                            note[xx][yy] = 1;
                        }
                        else if(ch[xx][yy] == '#')
                            continue;
                        else{
                            v[i][j].push_back(node(xx, yy, ch[xx][yy], tmp.len+1));
                            note[xx][yy] = 1;
                        }
                    }
                }
            }
        }
    }
}

const int MAXN = 100101022;
int note2[101][25][25], ccc;
int ans[25][25], temn[25][25];
int dis[25][25];
int px, py;
void proc(){
    memset(ans, 127, sizeof(ans));
    memset(dis, 127, sizeof(dis));
    ccc = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            if(ch[i][j] == '@'){
                px = i;
                py = j;
            }
    memset(temn, 0, sizeof(temn));
    q.push(temp(px, py, 0));
    temn[px][py] = 1;
    while(!q.empty()){
        temp u = q.front(); q.pop();
        dis[u.x][u.y] = u.len;
        for(int k = 0; k < 4; k ++){
            int xx = u.x + dir[k][0], yy = u.y + dir[k][1];
            if(!check(xx, yy) || ch[xx][yy] == '#' || temn[xx][yy])
                continue;
            temn[xx][yy] = 1;
            q.push(temp(xx, yy, u.len + 1));
        }
    }
    
    for(int i = 1; i <= quer; i ++){
        int cnt = strlen(pace[i] + 1);
        //pace[i][++cnt] = '\0';
        for(int x = 1; x <= n; x ++)
            for(int y = 1; y <= m; y ++){
                
                
                memset(note2, 127, sizeof(note2));
                note2[0][x][y] = 0;
                qq.push(nod2(x, y, 1));
                while(!qq.empty()){
                    nod2 u = qq.front(); qq.pop();
                    int k = v[u.x][u.y].size();
                    if(u.dix > cnt){
                        ans[x][y] = min(ans[x][y], note2[cnt][u.x][u.y]);
                    }
                    for(int j = 0; j < k; j ++){
                        int xx = v[u.x][u.y][j].x, yy = v[u.x][u.y][j].y;
                        if(ch[xx][yy] == pace[i][u.dix]){
                            if(note2[u.dix][xx][yy] < MAXN){
                                note2[u.dix][xx][yy] = min(note2[u.dix][xx][yy], note2[u.dix-1][u.x][u.y] + v[u.x][u.y][j].len);
                                continue;
                            }
                            note2[u.dix][xx][yy] = min(note2[u.dix][xx][yy], note2[u.dix-1][u.x][u.y] + v[u.x][u.y][j].len);
                            qq.push(nod2(xx, yy, u.dix+1));
                        }
                    }
                }
            }
    }
    int ans2 = MAXN;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            ans2 = min(ans[i][j] + dis[i][j], ans2);
    printf("%d\n", ans2);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        puin();
        proc();
    }
}

/*
 
 3
 5 5
 A.DB#
 @#.##
 .#..C
 .#...
 .....
 3
 AB
 AC
 BC
 5 5
 A.DB#
 @#.##
 .#..C
 .#...
 .....
 2
 AADBBBDCC
 AC
 
 5 5
 ADBBC
 @#D##
 .#..C
 .#...
 .....
 1
 DBBC
 
 5 5
 ADBBC
 @#D##
 .#..C
 .#...
 .....
 1
 DADBBC
 */
