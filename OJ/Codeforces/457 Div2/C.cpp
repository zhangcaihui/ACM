#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1001010;
int prime[MAXN],primesize,phi[MAXN];
bool isprime[MAXN];
void pre(){
    memset(isprime,1,sizeof(isprime));
     isprime[1]=false;
     for(int i=2;i<= MAXN;i++)
     {
        if(isprime[i])
            prime[++primesize]=i;
        for(int j=1;j <= primesize && i * prime[j] <= MAXN;j++)
        {
             isprime[i*prime[j]]=false;
            if(i%prime[j]==0)break;
         }
     }
}
struct ANSIS{
    int u, v, val;
}rem[MAXN];
int cnt, n, m, sum, ff = 1;
int main(){
    pre();
    scanf("%d%d", &n, &m);
    //sum += 2, ++ cnt;
    //rem[cnt].u = 1, rem[cnt].v = n, rem[cnt].val = 2;
    for(int i = 1; i < n-1; i ++){
        ++ cnt;
        rem[cnt].u = i;
        rem[cnt].v = n;
        rem[cnt].val = 2;
        sum += 2;
    }
    // debug is ok
    //printf("%d \n", sum);
    int ans = *upper_bound(prime+1, prime+primesize+1, sum);
    ++ cnt;
    rem[cnt].val = ans - sum;
    rem[cnt].u = n-1, rem[cnt].v = n;

    for(int i = n-1; i > 1; i --){
        for(int j = i-1; j >= 1; j --){
            if(cnt == m)
                break;
            ++cnt;
            rem[cnt].u = j;
            rem[cnt].v = i;
            rem[cnt].val = ans;
        }
    }
    printf("%d %d\n", 2, ans);
    for(int i = 1; i <= m; i ++){
        printf("%d %d %d\n", rem[i].u, rem[i].v, rem[i].val);
    }
    return 0;
}