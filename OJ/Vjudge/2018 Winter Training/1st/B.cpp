#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1001010;
int n, a[MAXN];
int tem, ans, cnt;
void puin(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
    }
    sort(a+1, a+1+n);
}
void proc(){
    int k = 0;
    tem = ans = cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(tem == a[i])
            k ++;
        if(tem != a[i])
            k = 1, tem = a[i];
        if(k > cnt)
            cnt = k, ans = a[i];
    }
    printf("%d\n", ans);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        puin();
        proc();
    }
}
/*
3
3
42
42
19
4
7
99
99
7
5
11
12
13
14
15

*/