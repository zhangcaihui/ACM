#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int MAXN = 2e5+7;
int n, tim, tmp, cnt[MAXN];
int f[MAXN], vis[MAXN], rem[MAXN];
struct node{
    int h, num;
    friend bool operator < (node xx, node yy){
        return xx.h < yy.h;
    }
}a[MAXN];
priority_queue<node> q;
queue<int> prin;
vector<int> v[MAXN];
void dfs(int x, int h){
    rem[x] = 1;
    int k = v[x].size();
    for(int i = 0; i < k; i ++){
        if(rem[v[x][i]])
            continue;
        dfs(v[x][i], h+1);
    }
    a[x].h = h;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &tmp);
        v[tmp].push_back(i);
        if(tmp)
            v[i].push_back(tmp), cnt[i] ++;
        cnt[tmp] ++;
        a[i].num = i;
    }
    if(!(n & 1)){
        printf("NO");
        return 0;
    }
    dfs(1, 1);
    for(int i = 1; i <= n; i ++){
        if(cnt[i] & 1)
            continue;
        q.push(a[i]);
    }
    while(!q.empty()){
        node tem = q.top(); q.pop();
        if((cnt[tem.num] & 1) || vis[tem.num])
            continue;
        vis[tem.num] = true;
        prin.push(tem.num);
        int k = v[tem.num].size();
        for(int i = 0; i < k; i ++){
            if(vis[v[tem.num][i]])
                continue;
            cnt[v[tem.num][i]] --;
            if(cnt[v[tem.num][i]] & 1)
                continue;
            q.push(a[v[tem.num][i]]);
        }
    }
    printf("YES\n");
    while(!prin.empty()){
        printf("%d\n", prin.front()); prin.pop();
    }
}
