#include<cstdio>
#include<queue>
using namespace std;
const int MAXN = 1001010;
typedef long long int LL;
struct node{
    int val, posi;
    node(int v = 0, int p = 0): val(v), posi(p){}
}arr[MAXN];
deque<node> q;
int n, val, c;
LL ans[MAXN], sum;
int main(){
    scanf("%d%d", &n, &c);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &val);
        arr[i].posi = i, arr[i].val = val;
        sum += arr[i].val;
    }
    for(int i = 1; i < c; i ++){
        node tem;
        while(!q.empty()){
            tem = q.back();
            if(arr[i].val <= tem.val)
                q.pop_back();
            else
                break;
        }
        q.push_back(arr[i]);
    }
    for(int i = c; i <= n; i ++){
        node tem;
        while(!q.empty()){
            tem = q.back();
            if(arr[i].val <= tem.val)
                q.pop_back();
            else if(i - q.front().posi >= c)
                q.pop_front();
            else
                break;
        }
        q.push_back(arr[i]);
        ans[i] = max(ans[i-1], ans[i-c] + q.front().val);
    }
    printf("%lld", sum - ans[n]);
    return 0;
}
