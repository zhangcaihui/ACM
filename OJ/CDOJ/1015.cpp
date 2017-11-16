#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1001010;
double a[maxn], minl[maxn], minr[maxn];
int b[maxn], n, c[maxn];

void init(){
    memset(minl, 127, sizeof(minl));
    memset(minr, 127, sizeof(minr));
}

void prep(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%lf", &a[i]);
    }
    int p = 1;
    for(int i = 1; i <= n; i ++){
        if(minl[i-1] > a[i])
            p = i;
        minl[i] = min(minl[i-1], a[i]);
        b[i] = p;
    }
    p = n;
    for(int i = n; i > 0; i --){
        if(minr[i+1] > a[i])
            p = i;
        minr[i] = min(minr[i+1], a[i]);
        c[i] = i;
    }
}

void proc(){
    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; i ++){
        int l, r, ans = -1;
        double rem = 10;
        scanf("%d%d", &l, &r);
        if(l){
            rem = minl[l-1];
            ans = b[l-1];
        }
        if(r < n-1){
            if(minr[r+1] < rem){
                rem = c[r+1];
                ans = b[r+1];
            }
        }
        printf("%d\n", ans);
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        
        //printf("%f", minl[2]);

        prep();
        proc();
    }
}