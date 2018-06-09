#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
int n, vis[MAXN], p[MAXN];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &p[i]);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(vis[i])
            continue;
        int tmp = i;
        while(!vis[tmp]){
            vis[tmp] = 1;
            cnt ++;
            tmp = p[tmp];
        }
        cnt --;
    }
    //printf("%d\n", cnt);
    if(cnt % 2 == (3*n) % 2)
        printf("Petr");
    else 
        printf("Um_nik"); 
}
