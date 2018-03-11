#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1001010;
int prime[MAXN],primesize,phi[MAXN];
bool isprime[MAXN];
int rmax[MAXN], rmin[MAXN];
int main(){
     memset(isprime,1,sizeof(isprime));
     isprime[1]=false;
     for(int i=2;i<= MAXN;i++)
     {
        if(isprime[i])prime[++primesize]=i;
        for(int j=1;j <= primesize && i * prime[j] <= MAXN;j++)
        {
             isprime[i*prime[j]]=false;
            if(i%prime[j]==0)break;
         }
    }
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i ++){
        for(int j = 2; j*i <= n; j ++){
            if(isprime[i]){
                rmax[i*j] = i;
            }
            if(!rmin[i*j])
                rmax[i*j] = rmin[i*j] = i;
        }
    }

    int p = rmax[n], ans = MAXN, pp;
    // test:
    //printf("%d \n", p);
    //printf("%d\n", rmax[10]);
    for(int i = n; i > n - p; i --){
        if(isprime[i])
            continue;
        if(ans > i - rmax[i] + 1)
            pp = i;
        ans = min(ans, i - rmax[i] + 1);
    }    

    //printf("%d\n", pp);
    printf("%d",ans);
}