#include<cstdio>
#include<algorithm>
using namespace std;
long long int sum = 0;
long long int a[202020], b[202020];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]), sum += a[i];
    
    for(int i = 1; i <= n; i ++)
        scanf("%lld", &b[i]);
    
    sort(b+1, b+1+n);
    
    if(sum <= b[1] + b[2])
        printf("YES");
    else
        printf("NO");
    
}

