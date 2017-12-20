#include<cstdio>
#include<cstring>
using namespace std;
long long int a[233] = {0, 1}, b[233] = {1}, tmp[233];
int ca = 1, cb;
int main(){
    int n;
    scanf("%d", &n);
    if(!n)
        printf("0\n1\n0\n0\n");
    else{
        int ff = 1;
        for(int i = 2; i <= n; i ++){
            ff *= -1;
            
            for(int j = 0; j <= ca; j ++)
                tmp[j] = a[j];
            for(int j = 0; j <= ca; j ++)
                a[j+1] = tmp[j];
            for(int j = 0; j <= cb; j ++)
                a[j] += b[j];
            for(int j = 0; j <= ca; j ++)
                b[j] = ff*tmp[j];
            cb = ca;
            ca = ca + 1;
        }
        printf("%d\n", ca);
        for(int i = 0; i <= ca; i ++)
            printf("%lld ", a[i]);
        puts("");
        printf("%d\n", cb);
        for(int i = 0; i <= cb; i ++)
            printf("%lld ", b[i]);
    }
}
