#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 101010;
const int mod = 1e9+7;
vector<int> vec[MAXN];
int mp[10] = {2, 3, 5, 7, 11, 13};
int n, sumv[MAXN*4][7], addv[MAXN*4][7];
int dfn1[MAXN], dfn2[MAXN], fdfn[MAXN];
int arr[MAXN][7];
int rem[7];

long long int qpow(int x, int y){
    long long int ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

void pre(int x){
    for(int i = 0; i < 6; i ++){
        rem[i] = 0;
        while(x % mp[i] == 0){
            x /= mp[i];
            rem[i] ++;
        }
    }
}

int cnt;
void dfs(int o){
    int k = vec[o].size();
    dfn1[o] = ++cnt;
    fdfn[cnt] = o;
    for(int i = 0; i < k; i ++){
        dfs(vec[o][i]);
    }
    dfn2[o] = cnt;
}

void build(int o, int l, int r){
    if(l == r){
        for(int i = 0; i < 6; i ++)
            addv[o][i] = arr[fdfn[l]][i];
        //sumv[o][i] = arr[fdfn[l]][i];
        return ;
    }
    int lcd = (o<<1), rcd = (o<<1) + 1, m = (l + r) / 2;
    build(lcd, l, m);
    build(rcd, m+1, r);
}

void puin(){
    scanf("%d", &n);
    for(int i = 1; i < n; i ++){
        int u, v;
        scanf("%d%d", &u, &v);
        vec[u+1].push_back(v+1);
    }
    for(int i = 1; i <= n; i ++){
        int x;
        scanf("%d", &x);
        pre(x);
        for(int j = 0; j < 6; j ++)
            arr[i][j] = rem[j];
    }
    dfs(1);
    build(1, 1, n);
}

void maintain(int o, int l, int r){
    int lcd = (o<<1), rcd = (o<<1) + 1;
    for(int i = 0; i < 6; i ++){
        sumv[o][i] = 0;
        if(r > l)
            sumv[o][i] = (sumv[lcd][i] + sumv[rcd][i]) % mod;
        sumv[o][i] += addv[o][i] * (r - l + 1);
        sumv[o][i] %= mod;
    }
}

void upd_mor(int o, int l, int r, int p){
    int lcd = (o << 1), rcd = (o << 1) + 1, m = (l + r) / 2;
    if(dfn1[p] <= l && r <= dfn2[p]){
        for(int i = 0; i < 6; i ++)
            addv[o][i] = (addv[o][i] + rem[i]) % mod;
        maintain(o, l, r);
        return ;
    }
    if(dfn1[p] <= m)
        upd_mor(lcd, l, m, p);
    if(m < dfn2[p])
        upd_mor(rcd, m+1, r, p);
    maintain(o, l, r);
}

void update(int p, int val){
    pre(val);
    upd_mor(1, 1, n, p);
}

int que_mor(int o, int l, int r, int add, int h, int p){
    if(dfn1[p] <= l && r <= dfn2[p]){
        return (sumv[o][h] + (add + addv[o][h]) * (r - l + 1)) % mod;
    }
    int lcd = (o << 1), rcd = (o << 1) + 1, m = (l + r) / 2;
    int sum = 0;
    if(dfn1[p] <= m)
        sum += que_mor(lcd, l, m, (add + addv[o][h]) % mod, h, p);
    if(m < dfn2[p])
        sum += que_mor(rcd, m+1, r, (add+addv[o][h]) % mod, h, p);
    return sum % mod;
}

void query(int p){
    long long int ans1 = 1, ans2 = 1;
    for(int i = 0; i < 6; i ++){
        int y = que_mor(1, 1, n, 0, i, p), x = mp[i];
        ans1 = (ans1 * qpow(x, y)) % mod;
        ans2 = (ans2 * (y + 1)) % mod;
        printf("%d %d\n", x, y);
    }
    printf("%lld %lld\n", ans1, ans2);
}

char var1[] = "RAND", var2[] = "SEED";
void proc(){
    int q;
    char vari[10];
    scanf("%d", &q);
    for(int i = 1; i <= q; i ++){
        scanf("%s", vari);
        if(strcmp(vari, var2) == 0){
            int x, y;
            scanf("%d%d", &x, &y);
            update(x+1, y);
        }
        else{
            int x;
            scanf("%d", &x);
            query(x+1);
        }
    }
}

int main(){
    puin();
    proc();
    return 0;
}

/*
 8
 0 1
 0 2
 1 3
 2 4
 2 5
 3 6
 3 7
 7 3 10 8 12 14 40 15
 3
 RAND 1
 SEED 1 1
 RAND 1
 */


