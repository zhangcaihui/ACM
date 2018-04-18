#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1001010;
struct node{
    int poin[2], vis;
    int stu, posi, cnt, p;
    friend bool operator < (node xx, node yy){
        if(xx.cnt == yy.cnt)
            return xx.posi > yy.posi;
        return xx.cnt > yy.cnt;
    }
}a[MAXN];
int n, ans;
bool check(int x){
    if(0 < x && x <= n) return true;
    return false;
}
priority_queue<node> q;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        a[i].poin[0] = i-1;
        a[i].poin[1] = i+1;
        a[i].posi = i;
        scanf("%d", &a[i].stu);
        a[i].p = a[i].poin[a[i].stu];
        a[a[i].poin[a[i].stu]].cnt ++;
    }
    for(int i = 1; i <= n; i ++)
        q.push(a[i]);
    while(!q.empty()){
        node tmp = q.top(); q.pop();
        int posi = tmp.posi;
        if(a[posi].vis)
            continue;
        a[posi].vis = 1;
        ans += a[posi].cnt;
        a[a[posi].p].cnt --;
        a[a[posi].poin[0]].poin[1] = a[posi].poin[1];
        a[a[posi].poin[1]].poin[0] = a[posi].poin[0];
        if(a[a[posi].poin[0]].p == posi){
            a[a[posi].poin[1]].cnt ++;
            a[a[posi].poin[0]].p = a[posi].poin[1];
            int x = a[posi].poin[1];
            if(check(x))
                q.push(a[x]);
        }
        if(a[a[posi].poin[1]].p == posi){
            a[a[posi].poin[0]].cnt ++;
            a[a[posi].poin[1]].p = a[posi].poin[0];
            int x = a[posi].poin[0];
            if(check(x))
                q.push(a[x]);
        }
    }
    printf("%d", ans);
}
