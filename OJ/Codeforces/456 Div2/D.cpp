#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long int LL;
const int MAXN = 101010;
struct node{
    LL num;
    int x;
    node(int xx, int yy): num(xx), x(yy){}
    friend bool operator < (node aa, node bb){
        return aa.num < bb.num;
    }// test is OK
};
priority_queue<node> q;
int p[MAXN];
LL px[MAXN], py[MAXN];
int main(){
    long long int n, m;
    int r, k;
    scanf("%lld%lld%d%d", &n, &m, &r, &k);
    for(int i = 1; i <= m; i ++){
        px[i] = min((int)m-r+1, i) - max(1, (int)i-r+1) + 1;
    }

    for(int i = 1; i <= n; i ++){
        py[i] = min((int)n-r+1, i) - max(1, (int)i-r+1) + 1;
    }

    sort(py+1, py+1+n);
    for(int i = 1; i <= m; i ++){
        p[i] = n;
        q.push(node( py[n]*px[i], i));
    }

    /* debug is OK
    while(!q.empty()){
        printf("%lld \n", q.top().num);
        q.pop();
    }
    */
    long long int sum1 = 0;
    long long int sum2 = (n-r+1)*(m-r+1);
    while(k--){
        node tem = q.top(); q.pop();
        int u = tem.x;
        int v = --p[u];
        sum1 += tem.num;
        if(v)
            q.push(node(py[v]*px[u], u));
        }
        //
    // debug is OK
    //printf("%lld %lld\n", sum1, sum2);

    printf("%.10lf", (double)sum1 / (double)sum2);
    return 0;

}
