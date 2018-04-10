#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int MAXN = 101010;
map<string, int> mp;
stack<int> s;
int f[MAXN];
LL cost[MAXN];
int n, m, k;
string st;
char ch[MAXN];
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i ++){
        scanf("%s", ch);
        st = ch;
        mp[st] = i;
    }
    memset(cost, 127, sizeof(cost));
    for(int i = 1; i <= n; i ++){
        scanf("%lld", &cost[i]);
    }
    
    for(int i = 1; i <= m; i ++){
        int tem, p;
        LL minv = cost[0];
        scanf("%d", &tem);
        for(int j = 1; j <= tem; j ++){
            scanf("%d", &p);
            s.push(p);
            minv = min(minv, cost[p]);
        }
        while(!s.empty()){
            int p = s.top(); s.pop();
            cost[p] = minv;
        }
    }
    LL ans = 0;
    for(int i = 1; i <= k; i ++){
        scanf("%s", ch);
        st = ch;
        ans += cost[mp[st]];
    }
    printf("%lld", ans);
}
