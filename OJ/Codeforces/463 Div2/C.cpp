#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1001010;
int ans[MAXN];
int gcd(int x, int y){ return x == 0 ? y : gcd(y%x, x);}


int main(){
    int n, a, b;
    int x = -1, y = -1;
    scanf("%d%d%d", &n, &a, &b);
    if(a > b){
        int tem = a;
        a = b;
        b = tem;
    }
    for(int i = n/a; i >= 0; i --){
        if((n - i*a) % b == 0){
            x = i;
            y = (n - i*a) / b;
            break;
        }
    }
    if(x < 0 && y < 0){
        printf("-1");
        return 0;
    }
    int st = 1;
    for(int i = 0; i < x; i ++){
        ans[st] = st + a - 1;
        for(int j = 1; j < a; j ++){
            ans[st + j] = st + j - 1;
        }
        st += a;
    }
    for(int i = 0; i < y; i ++){
        ans[st] = st + b - 1;
        for(int j = 1; j < b; j ++){
            ans[st + j] = st + j - 1;
        }
        st += b;
    }
    //printf("%d %d\n", x, y);
    for(int i = 1; i <= n; i ++)
        printf("%d ", ans[i]);
}
