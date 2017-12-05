#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long int len[230];
char aa[] = {" What are you doing at the end of the world? Are you busy? Will you save us?"};
char bb[][100] = {" What are you doing while sending \"",
                  " \"? Are you busy? Will you send \"", " \"?"};
int rem;
void pre(){
    len[0] = 75;
    int i = 0;
    long long int xx = 1e18*2 + 100;
    //printf("%lld\n", xx);
    while(len[i] <= xx){
        i ++;
        len[i] = 68 + 2 * len[i-1];
    }
    rem = i;
}

char find_(int n, long long int k){
    int p;
    if(n == 0){
        p = k;
        return aa[p];
    }
    if(k <= 34){
        p = k;
        return bb[0][p];
    }
    else if(k <= len[n-1] + 34)
        return find_(n-1, k - 34);
    else if(k <= len[n-1] + 34 + 32){
        p = k - 34 - len[n-1];
        return bb[1][p];
    }
    else if(k <= len[n-1] * 2 + 34 + 32)
        return find_(n-1, k-len[n-1]-34-32);
    else{
        p = k-(len[n-1] * 2 + 34 + 32);
        return bb[2][p];
    }
}

int main(){
    pre();
    int T = 0;
    scanf("%d", &T);
    while(T--){
        int n;
        long long int k;
        scanf("%d%lld", &n, &k);
        if(n > rem){
            if(k >= (n-k))
                k -= (n-k)*34, n = rem;
            else{
                int tem = k%75 ? k%75 : 75;
                printf("%c", aa[tem]);
            }
        }
        if(k <= len[n])
            printf("%c", find_(n, k));
        else
            printf(".");
    }
    return 0;
}
