
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 201010;
typedef double LL;
int arr[MAXN];
struct node{
    LL a, b;
    node(){
        a = b = 0;
    }
    friend bool operator < (node x, node y){
        return x.b < y.b;
    }
}a1[MAXN], a2[MAXN];
LL ans = 0;
LL s1[MAXN], s2[MAXN];
LL p1[MAXN], p2[MAXN];
int cnt1, cnt2;
int main(){
    int n, T;
    scanf("%d%d", &n, &T);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &arr[i]);
    }
    for(int i = 1; i <= n; i ++){
        int tem;
        scanf("%d", &tem);
        if(tem < T){
            a1[++cnt1].a = arr[i];
            a1[cnt1].b = T - tem;
        }
        else if(tem > T){
            a2[++cnt2].a = arr[i];
            a2[cnt2].b = tem - T;
        }
        else
            ans += arr[i];
    }
    sort(a1+1, a1+1+cnt1);
    sort(a2+1, a2+1+cnt2);
    for(int i = 1; i <= cnt1; i ++){
        p1[i] = p1[i-1] + a1[i].a * a1[i].b;
        s1[i] = s1[i-1] + a1[i].a;
    }
    for(int i = 1; i <= cnt2; i ++){
        p2[i] = p2[i-1] + a2[i].a * a2[i].b;
        s2[i] = s2[i-1] + a2[i].a;
    }
    double prin;
    if(p1[cnt1] < p2[cnt2]){
        ans += s1[cnt1];
        for(int i = 0; i < cnt2; i ++){
            if(p2[i+1] >= p1[cnt1]){
                ans += s2[i];
                prin = ans + (double)(p1[cnt1] - p2[i]) / (double)(a2[i+1].b);
                break;
            }
        }
    }
    else if(p1[cnt1] > p2[cnt2]){
        ans += s2[cnt2];
        for(int i = 0; i < cnt1; i ++){
            if(p1[i+1] >= p2[cnt2]){
                ans += s1[i];
                prin = ans + (double)(p2[cnt2]-p1[i]) / (double)(a1[i+1].b);
                break;
            }
        }
    }
    else
        prin = ans + s1[cnt1] + s2[cnt2];
    printf("%.7lf", prin);
}
