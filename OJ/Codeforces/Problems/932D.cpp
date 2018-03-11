#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1001010;
const int lg = 21;
typedef long long int LL;
int cnt, T;
LL p, q, last;
struct node{
    int pre[lg];
    LL val, sum[lg];
    void init(){
        memset(pre, -1, sizeof(pre));
        memset(sum, -1, sizeof(sum));
    }
}arr[MAXN];

void proc1(){
    p = p ^ last;
    q = q ^ last;
    printf("debug #1: %lld %lld\n", p, q);
    arr[++cnt].val = q;
    if(arr[p].val >= q)
        arr[cnt].pre[0] = p, arr[cnt].sum[0] = arr[p].val;
    else{
        for(int i = 0; i < lg; i ++){
            if(arr[arr[p].pre[i]].val >= q){
                p = arr[p].pre[i];
                break;
            }
        }
        arr[cnt].pre[0] = p;
        arr[cnt].pre[0] = arr[p].val;
    }
    for(int i = 1; i < lg; i ++){
        arr[cnt].pre[i] = arr[arr[cnt].pre[i-1]].pre[i-1];
        arr[cnt].sum[i] = arr[arr[cnt].pre[i-1]].sum[i-1] + arr[cnt].sum[i-1];
    }
}

void proc2(){
    p = p ^ last;
    LL x = q ^ last;
    printf("debug #2: %lld %lld\n", p, x);
    LL sumv = arr[p].val;
    int len = 0;
    if(sumv > x){
        last = 0;
        printf("0");
        return;
    }
    len = 1;
    

}

int main(){
    scanf("%d", &T);
    arr[++cnt].pre[0] = 0, arr[cnt].val = 0;
    while(T--){
        int t;
        scanf("%d%lld%lld", &t, &p, &q);
        if(t&1)
            proc1();
        else
            proc2();
    }
}