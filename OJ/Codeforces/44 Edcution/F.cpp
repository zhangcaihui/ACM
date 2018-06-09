#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int MAXN = 201010;
const LL mod1 = 1e9+7, mod2 = 1e9+9, mod3 = 1e9+21;

LL inv(LL x, LL mod){
    LL ans = 1;
    LL y = mod - 2;
    while(y){
        if(y & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
LL rem1[MAXN], rem2[MAXN];
LL hash1[26][MAXN], hash2[26][MAXN];

char ch[MAXN];
int n, k, ea, eb;
int a, b, len;
int tma[2][26], tmb[2][26];

void pre(){
    rem1[0] = rem2[0] = 1;
    LL x = inv(mod3, mod1); LL y = inv(mod3, mod2);
    for(int i = 1; i <= n; i ++){
        rem1[i] = rem1[i-1] * x % mod1;
        rem2[i] = rem2[i-1] * y % mod2;
    }
    LL tx = 1, ty = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < 26; j ++){
            hash1[i][j] = hash1[i-1][j]; hash2[i][j] = hash2[i-1][j];
            if(ch[i]-'a' == j){
                hash1[i][j] = (hash1[i][j] + tx) % mod1;
                hash2[i][j] = (hash2[i][j] + ty) % mod2;
            }
        }
        tx = tx * mod3 % mod1;
        ty = ty * mod3 % mod2;
    }
}

int main(){
    scanf("%d%d", &n, &k);
    scanf("%s", ch+1);
    pre();
    for(int i = 1; i <= k; i ++){
        scanf("%d%d%d", &a, &b, &len);
        ea = a + len - 1; eb = b + len - 1;
        for(int j = 0; j < 26; j ++){
            tma[0][j] = (hash1[ea][j] - hash1[a-1][j] + mod1) % mod1 * rem1[a-1] % mod1;
            tma[1][j] = (hash2[ea][j] - hash2[a-1][j] + mod2) % mod2 * rem2[a-1] % mod2;
            tmb[0][j] = (hash1[eb][j] - hash1[b-1][j] + mod1) % mod1 * rem1[b-1] % mod1;
            tmb[1][j] = (hash2[eb][j] - hash2[b-1][j] + mod2) % mod2 * rem2[b-1] % mod2;
            
        }
        sort(tma[0], tma[0]+26); sort(tmb[0], tmb[0]+26);
        sort(tma[1], tma[1]+26); sort(tmb[1], tmb[1]+26);
        bool tem = true;
        for(int j = 0; j < 26; j ++){
            if(tma[0][j] != tmb[0][j])// || tma[1][j] != tmb[1][j])
                tem = false;
        }
        printf("%s\n", tem ? "YES" : "NO");
    }   
}
