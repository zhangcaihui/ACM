#include<cstdio>
#include<cstring>
using namespace std;
typedef long long int LL;
LL n, all;
LL find(LL p, LL pre){
    if(p & 1){
        return p;
    }
    if(p == n - 1 && n&1) {
        return n;
    }
    if(p == n-2 && (!p&1)){
        return n - 1;
    }
    return find(p+p-all, all);
}

int main(){
    int T;
    scanf("%d%lld", &T, &n);
    while(T--){
        scanf("%lld", &p);
        all = (n + 1) / 2;
        if(p & 1){
            printf("%lld\n", p);
            continue;
        }
        LL tem = p / 2;
        printf("%lld\n", find(all+tem+1, all));
    }
}
