#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int MAXN = 2 * 101010;
struct node{
    LL x, y;
    node(LL xx, LL yy) : x(xx), y(yy) {}
    friend bool operator < (node pp, node qq){
        if(pp.x == qq.x)
            return pp.y < qq.y;
        return pp.x < qq.x;
    }
};
int n;
LL X, Y, laji, aa, b;
LL ans;
map<LL, LL> mp;
map<node, LL> mmp;
int main(){
    scanf("%d%lld%lld", &n, &aa, &b);
    Y = aa, X = 1;
    LL tx, ty;
    for(int i = 1; i <= n; i ++){
        scanf("%lld%lld%lld", &laji, &tx, &ty);
        
        LL tem = X * ty - Y * tx;
        ans += 2*mp[tem];
        mp[tem] ++;
        
        node tem2 = node(tx, ty);
        ans -= 2 * mmp[tem2];
        mmp[tem2] ++;
    }
    printf("%lld", ans);
}

