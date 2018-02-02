#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int mod = 1e9+7;
int roo;
long long a[100005], len;
long long q_pow(long long a, long long b, long long c)
{
    long long ans=1;
    while(b)
    {
        if(b%2)
            ans=(ans*a)%c;
        a=(a*a)%c;
        b/=2;
    }
    return ans;
}

// test if g ^ ((p-1)/a) == 1 (mod p)
long long g_test(long long g, long long p)
{
    for(int i=0;i<len;i++)
        if(q_pow(g, (p-1)/a[i], p)==1)
            return 0;
    return 1;
}

long long primitive_root(long long p)
{
    // get the prime factor of p-1
    len=0;
    long long tmp=p-1;
    for(long long i=2;i<=tmp/i;i++)
    {
        if(tmp%i==0)
        {
            a[len++]=i;
            while(tmp%i==0)
                tmp/=i;
        }
    }
    if(tmp!=1)
        a[len++]=tmp;
    
    // find the primitive root
    long long g=1;
    while(g<p)
    {
        if(g_test(g,p))
            return g;
        g++;
    }
}
const int MAXN = 101010;
long long int addv[MAXN*4], mulv[MAXN*4];
int n, q;

void build1(int o, int l, int r, int p, int v){
    if(l == r){
        while(v/roo){
            mulv[o] ++;
            v /= roo;
        }
        addv[o] = v;
        return ;
    }
    int m = (l + r) >> 1;
    if(p <= m)
        build1(o<<1, l, m, p, v);
    else
        build1(o<<1+1, m+1, r, p, v);
}

void add_update(int o, int l, int r){
    
}

void mul_update(int o, int l, int r){
    
}

void puin(){
    memset(addv, 0, sizeof(addv));
    memset(mulv, 0, sizeof(mulv));
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++){
        int tem;
        scanf("%d", &tem);
        build1(1, 1, n, i, tem);
    }
}

void proc(){
    
}

int main(){
    int roo = primitive_root(mod);
    int T;
    scanf("%d", &T);
    while(T--){
        puin();
        proc();
    }
}
