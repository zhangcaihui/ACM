#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 1001010;
char ch[MAXN];
int cnt[MAXN], n, p, sum;
int main(){
    scanf("%s", ch+1);
    n = strlen(ch+1);
    int ans = MAXN;
    for(int i = 1; i <= n; i ++){
        if(ch[i] != ch[i-1])
        p ++;
        cnt[p] ++;
    }
    for(int i = 1; i <= p; i ++){
        sum += cnt[i];
        int tem = max(n-sum, sum);
        ans = min(ans, tem);
    }
    printf("%d", ans);
}

