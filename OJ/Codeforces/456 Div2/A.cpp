#include<cstdio>
using namespace std;
int main(){
    long long int x, y, z;
    long long int a, b;
    scanf("%lld%lld", &a, &b);
    scanf("%lld%lld%lld", &x, &y, &z);
    long long int t1 = 2 * x + y;
    long long int t2 = y + 3 * z;
    long long int ans1 = (t1 - a) < 0 ? 0 : t1 - a;
    long long int ans2 = (t2 - b) < 0 ? 0 : t2 - b;
    printf("%lld", ans1 + ans2);
}
