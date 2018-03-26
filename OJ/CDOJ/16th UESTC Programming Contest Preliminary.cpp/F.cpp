#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const LL mod1 = 1e9+7;
const LL mod2 = 1e9+9;
const LL r2 = 4116649;
const LL r3 = 2273235113;
LL qpow(LL x, int p, LL mod){
    LL ans = 1;
    while(p){
        if(p & 1)
            ans = ans * x % mod;
        x = (x * x) % mod;
        p >>= 1;
    }
    return ans;
}
int n, m;
map<int, int> mp;
char ch[1010][1010];
LL tem1[1010][1010];
LL rem1[1010][1010];
LL pow2[1010], pow3[1010];
LL rpow2[1010], rpow3[1010];
int cnt[1010][1010];

LL cal(int x1, int y1, int x2, int y2){
    LL ans = rem1[x2+1][y2+1];
    ans = (ans + mod1 - rem1[x1][y2+1]) % mod1;
    ans = (ans + mod1 - rem1[x2+1][y1]) % mod1;
    ans = (ans + rem1[x1][y1]) % mod1;
    ans = ans * rpow2[y1] % mod1;// ans * qpow(pow2[y1], mod1-2, mod1) % mod1;
    ans = ans * rpow3[x1] % mod1;//ans * qpow(pow3[x1], mod1-2, mod1) % mod1;
    return ans;
}



int num(int x1, int y1, int x2, int y2){
    return cnt[x2+1][y2+1] - cnt[x2+1][y1] - cnt[x1][y2+1] + cnt[x1][y1];
}

void proc(){
    
    int x1, y1, x2, y2;
    int a1, b1, a2, b2;
    scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &a1, &b1, &a2, &b2);
    LL val1 = cal(x1, y1, x2, y2);
    LL val2 = cal(a1, b1, a2, b2);
    
    if(val1 == val2){
        printf("Perfect\n");
        return ;
    }
    else if(mp.count((val2-val1+mod1) %mod1)||mp.count((val1-val2+mod1) %mod1)){    
        if(abs(num(x1, y1, x2, y2)- num(a1, b1, a2, b2)) == 1){
    		printf("One difference\n");
            return ;
        }
    }
    printf("Wrong\n");
    
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
        scanf("%s", ch[i] + 1);
    LL rec = 1;
    pow2[0] = pow3[0] = 1;
    for(int i = 0; i <= 1000; i ++){
        pow2[i+1] = pow2[i] * r2 % mod1;
        pow3[i+1] = pow3[i] * r3 % mod1;
        LL tmp = rec;
        for(int j = 0; j <= 1000; j ++){
            mp[tmp] = tmp;
            tmp = tmp * r2 % mod1;
        }
        rec = rec * r3 % mod1;
    }
    
    LL rec2 = qpow(pow2[1001], mod1-2, mod1);
    LL rec3 = qpow(pow3[1000], mod1-2, mod1);
    rpow2[1001] = rec2, rpow3[1001] = rec3;
    for(int i = 1000; i >= 0; i --){
        rpow2[i] = r2 * rpow2[i+1] % mod1;
        rpow3[i] = r3 * rpow3[i+1] % mod1;
    }
    
    for(int i = 1; i <= n; i ++){
        int tem = 0;
        for(int j = 1; j <= m; j ++){
            if(ch[i][j] == '1')
                tem ++;
            cnt[i][j] = cnt[i-1][j] + tem;
        }
    }
        
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            tem1[i][j] = (tem1[i][j-1] + (ch[i][j] - '0') * pow2[j-1]) % mod1;
        }
    }
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
           rem1[i][j] = (rem1[i-1][j] + tem1[i][j] * pow3[i-1]) % mod1;
        }
    }
    
    int T;
    scanf("%d", &T);
    while(T--){
        proc();
    }
}
