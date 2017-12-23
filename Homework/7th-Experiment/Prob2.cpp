#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1001010;
int n, a[MAXN], k;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
    }
    sort(a+1, a+1+n);
    scanf("%d", &k);
    printf("%d", a[n-k+1]);
    return 0;
}
