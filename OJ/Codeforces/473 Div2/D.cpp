#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include <cstring>
using namespace std;
const int maxn = 1001010*3;
const int MAXN = 101010;
vector<int> v[MAXN];
int prime[maxn],primesize,phi[maxn];
bool isprime[maxn];
void pre(){
    memset(isprime,1,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<= maxn;i++)
    {
        if(isprime[i])prime[++primesize]=i;
        for(int j=1;j <= primesize && i * prime[j] <= maxn;j++)
        {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)break;
        }
    }
    
    for(int i = 2; i < MAXN; i ++){
        for(int j = 1; prime[j] <= i; j ++){
            if(i % prime[j])
                continue;
            v[i].push_back(prime[j]);
        }
    }
}
int n, flag, lef = 1;
bool rem[maxn];
int main(){
    pre();
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        int tem;
        scanf("%d", &tem);
        if(flag){//flag means have changed.
            while(rem[prime[lef]])
                lef ++;
            printf("%d ", prime[lef]);
            rem[prime[lef]] = 1;
        }
        else{
            int siz = v[tem].size();
            bool tmp = false;
            for(int j = 0; j < siz; j ++){
                if(rem[v[tem][j]]){
                    tmp = true;
                    break;
                }
            }
            if(!tmp){
                for(int j = 0; j < siz; j ++)
                    rem[v[tem][j]] = true;
                printf("%d ", tem);
            }
            else{
                flag = true;
                for(int j = tem + 1; ; j ++){
                    tmp = false;
                    siz = v[j].size();
                    for(int k = 0; k < siz; k ++){
                        if(rem[v[j][k]]){
                            tmp = true;
                            break;
                        }
                    }
                    if(!tmp){
                        printf("%d ", j);
                        for(int k = 0; k < siz; k ++)
                            rem[v[j][k]] = true;
                        break;
                    }
                }
            }
        }
    }
}
