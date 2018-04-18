#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 101010;
struct node{
    int val, pi;
    friend bool operator < (node xx, node yy){
        return xx.val < yy.val;
    }
}a[MAXN];
vector<int> v[MAXN];
int n, m;
int ans[MAXN], cnt[MAXN];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++){
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].val ++, a[y].val ++;
        v[x].push_back(y);
        v[y].push_back(x);
        cnt[x] ++, cnt[y] ++;
    }
    for(int i = 0; i < n; i ++)
        a[i].pi = i;
    sort(a, a+n);
    int prin = 0;
    for(int i = 0; i < n; i ++){
        int k = v[a[i].pi].size();
        for(int j = 0; j < k; j ++){
            if(cnt[v[a[i].pi][j]] <= a[i].val)
                continue;
            ans[v[a[i].pi][j]] = max(ans[v[a[i].pi][j]], ans[a[i].pi]+1);
            prin = max(prin, ans[v[a[i].pi][j]]);
        }
    }
    printf("%d" , prin+1);
}
/*
 6 9
 0 1
 0 4
 1 2
 1 3
 1 4
 1 5
 2 5
 3 4
 4 5
 */
