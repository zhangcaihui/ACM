#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 501010;
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
    arr[++cnt].val = q;
    if(arr[p].val >= q)
        arr[cnt].pre[0] = p, arr[cnt].sum[0] = arr[p].val;
    else{
        for(int i = lg - 1; i >= 0; i --){
            if(arr[p].pre[i] == -1)
                continue;
            if(arr[arr[p].pre[i]].val < q)
                p = arr[p].pre[i];
            }
        arr[cnt].pre[0] = arr[p].pre[0];
        arr[cnt].sum[0] = arr[arr[p].pre[0]].val;
    }
    if(arr[cnt].pre[0] == -1)
        return ;
    for(int i = 1; i < lg; i ++){
        if(arr[arr[cnt].pre[i-1]].pre[i-1] == -1)
            break;
        arr[cnt].pre[i] = arr[arr[cnt].pre[i-1]].pre[i-1];
        arr[cnt].sum[i] = arr[arr[cnt].pre[i-1]].sum[i-1] + arr[cnt].sum[i-1];
    }
}

void proc2(){
    p = p ^ last;
    q = q ^ last;
    LL sumv = arr[p].val;
    if(sumv > q){
        last = 0;
        printf("0\n");
        return;
    }
    int len = 1;
    for(int i = lg - 1; i >= 0; i --){
        if(arr[p].pre[i] == -1)
            continue;
        if(sumv + arr[p].sum[i] <= q){
            sumv += arr[p].sum[i];
            len += (1 << i);
            p = arr[p].pre[i];
        }
    }
    last = len;
    printf("%d\n", len);
}

int main(){
    scanf("%d", &T);
    for(int i = 0; i < MAXN; i ++)
        arr[i].init();
    arr[++cnt].pre[0] = -1, arr[cnt].val = 0;
    while(T--){
        int t;
        scanf("%d%lld%lld", &t, &p, &q);
        if(t&1)
            proc1();
        else
            proc2();
    }
}