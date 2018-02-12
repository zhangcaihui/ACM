#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 202020;

struct node{
    double maxx[20], minn[20];
    int p1[20], p2[20];
}arr[maxn];
double a[maxn], sum;
int n, ans, m;

void RMQ_init(int len){
    for(int i = 0; i < len; i ++) arr[i].maxx[0] = arr[i].minn[0] = a[i], arr[i].p1[0] = arr[i].p2[0] = i;
    for(int j = 1; (1 << j) - 1 < len; j ++)
        for(int i = 0; i + (1 << j) - 1 < n; i ++){
            arr[i].p1[j] = arr[i].minn[j-1] <= arr[i+(1<<(j-1))].minn[j-1] ? arr[i].p1[j-1] : arr[i+(1<<(j-1))].p1[j-1];
            
            arr[i].minn[j] = min(arr[i].minn[j-1], arr[i+(1<<(j-1))].minn[j-1]);
            
            arr[i].p2[j] = arr[i].maxx[j-1] >= arr[i+(1<<(j-1))].maxx[j-1] ? arr[i].p2[j-1] : arr[i+(1<<(j-1))].p2[j-1];
            
            arr[i].maxx[j] = max(arr[i].maxx[j-1], arr[i+(1<<(j-1))].maxx[j-1]);
        }
}

int RMQ(int l, int r, int t){
    int k = 0;
    while((1<<(k+1)) <= r - l + 1) k++;
    if(!t)
        return arr[l].minn[k] <= arr[r-(1<<k)+1].minn[k] ? arr[l].p1[k] : arr[r-(1<<k)+1].p1[k];
    
    return arr[l].maxx[k] >= arr[r-(1<<k)+1].maxx[k] ? arr[l].p2[k] : arr[r-(1<<k)+1].p2[k];
}

void prep(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
        scanf("%lf", &a[i]);
    RMQ_init(n);
}
int l, r;
void situ(int t){
    int pp1, pp2;
    pp1 = pp2 = ans = maxn - 10;
    a[maxn-10] = t ? -10 : 10;
    if(l)
        pp1 = RMQ(0, l-1, t);
    if(r < n-1)
        pp2 = RMQ(r+1, n-1, t);
    
    if(!t)
        ans = a[pp1] <= a[pp2] ? pp1 : pp2;
    else
        ans = a[pp1] >= a[pp2] ? pp1 : pp2;
}

void proc(){
    scanf("%d", &m);
    for(int event = 1; event <= m; event++){
        sum = 0;
        scanf("%d%d", &l, &r);
        for(int i = l; i <= r; i ++)
            sum += a[i] / (1.0-a[i]);
        
        if(sum > 1.0)
            situ(0);
        else if(sum < 1.0)
            situ(1);
        else
            ans = l ? 0 : r+1;
        printf("%d\n", ans);
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        prep();
        proc();
    }
    return 0;
}

