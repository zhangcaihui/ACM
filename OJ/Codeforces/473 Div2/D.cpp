#include<bits/stdc++.h>
using namespace std;
const int MAXN = 101010*30;
int rem[MAXN], o, lef = 2;
int n, arr[MAXN];
vector<int> v[MAXN];
int prime[maxn],primesize,phi[maxn];
bool isprime[maxn];
int main(){
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
}

int main(){

    for(int i = 2; i < MAXN; i ++){
        v[i].push_back(i);
        for(int j = 2; j*j <= i; j ++){
            if(i % j == 0){
                v[i].push_back(j);
                if(j*j != i){
                    v[i].push_back(i/j);
                }
            }
        }
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &arr[i]);
    }
    
    for(int i = 1; i <= n; i ++){
        int flag = 0, p;
        if(o){
            for(int j = lef; j < MAXN; j ++){
                int siz = v[j].size();
                int turn = 0;
                for(int k = 0; k < siz; k ++){
                    if(rem[v[j][k]]){
                        turn = 1;
                        break;
                    }
                }
                if(!turn){
                    printf("%d ", j);
                    for(int k = 0; k < siz; k ++){
                        rem[v[j][k]] = 1;
                    }
                    lef = j;
                    break;
                }
            }
        }
        else{
            int siz = v[arr[i]].size();
            int turn = 0;
            for(int j = 0; j < siz; j ++){
                if(rem[v[arr[i]][j]]){
                    turn = 1;
                    o = 1;
                    break;
                }
            }
            if(turn){
                for(int j = arr[i] + 1; ; j ++){
                    
                    int tem = 0;
                    int siz = v[j].size();
                    for(int k = 0; k < siz; k ++){
                        if(rem[v[j][k]]){
                            tem = 1;
                            break;
                        }
                    }
                    if(!tem){
                        for(int k = 0; k < siz; k ++){
                            rem[v[j][k]] = 1;
                        }
                        printf("%d ", j);
                        break;
                    }
                }
            }
            else{
                printf("%d ", arr[i]);
                int siz = v[arr[i]].size();
                for(int k = 0; k < siz; k ++){
                    rem[v[arr[i]][k]] = 1;
                }
            }
        }
    }
    return 0;
}
