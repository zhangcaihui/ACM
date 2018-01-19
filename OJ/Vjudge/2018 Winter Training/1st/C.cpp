#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1001;
const double INF = 100101022;
double w[MAXN], c[MAXN], v[MAXN];
int n;
void puin(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%lf%lf", &w[i], &c[i]);
    }
}
int ans, p[MAXN];
void proc(){
    ans = 0;
    for(int i = 1; i <= n; i ++){
        p[i] = 1;
        for(int j = 1; j < i; j ++){
            if(w[i] > w[j] && c[i] < c[j])
                p[i] = max(p[i], p[j] + 1);
        }
        ans = max(p[i], ans);
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
2
1.0 1.0
1.5 0.0
3
1.0 1.0
1.0 1.0
1.0 1.0
6
1.5 9.0
2.0 2.0
2.5 6.0
3.0 5.0
4.0 2.0
10.0 5.5
*/