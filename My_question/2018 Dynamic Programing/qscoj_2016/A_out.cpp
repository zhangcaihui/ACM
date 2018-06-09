#include<bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;
long long int gcd(long long int x, long long int y){ return x == 0 ? y : gcd(y%x, x);}
long long int dp[1001][1001];
long long int quick_inverse(long long int x,long long int p) {
    long long int ret = 1;
    long long int exponent = p - 2;
    for (int i = exponent; i; i >>= 1, x = x * x % p) {
        if (i & 1) {
            ret = ret * x % p;
        }
    }
    return ret;
}

long long int init(long long int x, long long int y){
    return x * quick_inverse(y, mod) % mod;
}

void proc(){
    memset(dp, 0, sizeof(dp));
    int k;
    long long int a, b;
    scanf("%d%lld%lld", &k, &a, &b);
    dp[1][0] = 1;
    for(int i = 1; i <= k; i ++)
        for(int j = 0; j < k; j ++){
            if(i + j >= k)
                break;
            dp[i+1][j] = (dp[i+1][j] + dp[i][j] * init(a, a+b)) % mod;
            dp[i][j+i] = (dp[i][j+i] + dp[i][j] * init(b, a+b)) % mod;
        }
    long long int ans = 0;
    long long int sum;
    long long int temx = (a+b*k), temy = b;
    
    for(int i = 1; i <= k; i ++){
        for(int j = 0; j < k; j ++){
            if(i+j < k)
                continue;
            sum = i + j;
            temx = a+b*sum, temy = b;
            long long int tem = init(temx, temy);
            ans += tem*dp[i][j];
            ans %= mod;
        }
    }
    printf("%lld", ans);
}

string name(string a, int x, string b){
    return a + to_string(x) + b;
}


int main(){
    int n = 100;
    for(int i = 1; i <= n; i ++){
        string name1 = name("./A", i, ".in");
        char name2[100];
        strcpy(name2, name1.c_str());
        freopen(name2, "r", stdin);
        
        name1 = name("./A", i, ".out");
        strcpy(name2, name1.c_str());
        freopen(name2, "w", stdout);
        proc();
        fclose(stdout);
        fclose(stdin);
    }
    return 0;
}

