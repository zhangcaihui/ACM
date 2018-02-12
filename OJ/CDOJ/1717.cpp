#include<cstdio>
#include<map>
using namespace std;
pair<long long int, long long int> p;
map<pair<long long int, long long int>, int> mmp;
const long long int mod1 = 1e9+7, mod2 = 1e9+9;
long long int qpow(long long int x, long long int n, long long int p){
    long long int ans = 1;
    while(n){
        if(n&1)
            ans = (ans * x) % p;
        x = (x * x) % p;
        n >>= 1;
    }
    return ans;
}
int main(){
    int n, m, a, b, ans = 0;
    scanf("%d%d%d%d", &m, &n, &a, &b);
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            int x = a + j, y = b + i;
            long long int x1 = qpow(x, y, mod1);
            long long int x2 = qpow(x, y, mod2);
            p = make_pair(x1, x2);
            if(!mmp[p])
                ans ++;
            mmp[p] ++;
        }
    }
    printf("%d", ans);
    return 0;
}
