#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
struct node{
    int x,y,val;
    friend bool operator < (node a, node b){
        return a.val > b.val;
    }
};
priority_queue<node> q;
int point[2000];
int Find_(int x){ return (point[x] == -1) ? x : (point[x] = Find_(point[x]));}
void merage(int x, int y){
    if((x = Find_(x)) == (y = Find_(y))) return ;
    point[x] = y;
}
int main()
{
    int n,t;
    scanf("%d",&n);
    memset(point, -1, sizeof(point));
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
        {
            scanf("%d",&t);
            node tem;
            tem.x = i-1, tem.y = j, tem.val = t;
            q.push(tem);
        }
    int cnt = 0,ans = 0;
    while(cnt != n)
    {
        node tem = q.top();q.pop();
        if(Find_(tem.x) == Find_(tem.y)) continue;
        merage(tem.x, tem.y);
        ans += tem.val;
        cnt++;
    }
    printf("%d",ans);
    return 0;
}
