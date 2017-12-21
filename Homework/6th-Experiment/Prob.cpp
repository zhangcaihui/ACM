#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN = 1001010;
struct node{
    int val, note, num, pre;
    node() : val(MAXN), note(0){}
    friend bool operator < (node xx, node yy){
        return xx.val > yy.val;
    }
}a[MAXN];
struct edge{
    int to, val;
    edge(int x, int y): to(x), val(y) {};
};
vector<edge> v[MAXN];
priority_queue<node> q;
int n, m, x, y, z, ans[MAXN];
void Dijkstra(){
    a[1].val = 0, a[1].note = 1, a[1].pre = 1;
    q.push(a[1]);
    while(!q.empty()){
        node tem = q.top(); q.pop();
        a[tem.num].note = 1;
        int k = v[tem.num].size();
        for(int i = 0; i < k; i ++){
            if(a[v[tem.num][i].to].val <= a[tem.num].val + v[tem.num][i].val)
                continue;
            a[v[tem.num][i].to].val = a[tem.num].val + v[tem.num][i].val;
            q.push(a[v[tem.num][i].to]);
            a[v[tem.num][i].to].pre = tem.num;
        }
    }
}

void print(){
    int cnt = 0, p;
    for(int i = 2; i <= n; i ++){
        p = i;
        while(a[p].pre != p){
            ans[++cnt] = p;
            p = a[p].pre;
        }
        ans[++cnt] = 1;
        printf("%d : ", a[i].val);
        while(cnt){
            printf("%d", ans[cnt]);
            if(cnt != 1)
                printf("->");
            cnt --;
        }
        puts("");
    }
}

void puin(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++){
        scanf("%d%d%d", &x, &y, &z);
        v[x].push_back(edge(y, z));
        v[y].push_back(edge(x, z));
    }
    for(int i = 1; i <= n; i ++)
        a[i].num = i;
}
int main(){
    puin();
    Dijkstra();
    print();
}
/*
 
 11 22
 1 2 2
 1 3 8
 1 4 1
 2 3 6
 3 4 7
 2 5 1
 3 5 5
 3 6 1
 3 7 2
 4 7 9
 5 6 3
 6 7 4
 5 8 2
 5 9 9
 6 9 6
 7 9 3
 7 10 1
 8 9 7
 9 10 1
 8 11 9
 9 11 2
 10 11 4
 */


