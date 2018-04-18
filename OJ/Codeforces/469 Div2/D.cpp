
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long int LL;
LL n, N;
LL ans(LL p){
    return (p + 1) / 2;
}
LL find(LL p){
    if(p & 1){
        return p;
    }
    if(p == N - 1) {
        return N;
    }
    return find((p+1)/2 + n);
}

int main(){
    int T;
    LL p;
    scanf("%lld%d", &n, &T);
    N = 2*n - 1;
    while(T--){
        scanf("%lld", &p);
        if(p & 1){
            printf("%lld\n", ans(p));
            continue;
        }
        LL tem = p / 2;
        //debug :
        //printf("%lld", find(all+tem));
        printf("%lld\n", ans(find(n+tem)));
    }
}

