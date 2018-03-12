#include<cstdio>
using namespace std;
int main(){
    long long int n, m;
    scanf("%lld%lld",&n, &m);
    if(n > m){
        n ^= m ^= n ^= m;
    }
    if(n == 1){
        if(m == 1){
            printf("1");
            return 0;
        }
        printf("%lld", m*n - 2);
        return 0;
    }
    printf("%lld", n*m - (n*2+2*m - 4));
}