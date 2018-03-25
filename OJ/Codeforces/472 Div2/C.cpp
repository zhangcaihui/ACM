#include<bits/stdc++.h>
using namespace std;
int rem1[100], rem2[100];
char ch[101][101];
struct node{
    int x, y;
    node(int a = 0, int b = 0){
        x = a, y = b;
    }    
};
vector<node> v[100][190];
queue<node> q;
int vis[101][101];
int temx[101], temy[101];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
        scanf("%s", ch[i]+1);
     
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){
            if(ch[j][i] != '#'){
                for(int p = 1; j + p <= m; p ++)
                    if(ch[i][j+p] == '#'){
                        v[i][j].push_back(node(i, j+p));
                        v[i][j+p].push_back(node(i, j));
                    }
            }            
        }
    }
    
    
    int ff = 1;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++){
           if(vis[i][j])
            continue;
           q.push(node(i, j));            
           while(!q.empty()){
                node tmp = q.front(); q.pop();
                int x = tmp.x, y = tmp.y;
                int k = v[x][y].size();
                for(int c = 0; c < k; c++){
                    node p = v[x][y][c];
                    int tx = p.x, ty = p.y;
                    if(vis[tx][ty])
                        continue;
                }
       }   
       
   }
            
    if(ff)
        printf("Yes");
    else
        printf("No");    
    
}
