#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 101010;
int mind[MAXN][20], maxd[MAXN][20];
int arr[MAXN], len[MAXN];
long long int minv, maxv;
void RMQ_init(int arr[], int len){
    for(int i = 0; i < len; i ++) maxd[i][0] = mind[i][0] = arr[i];
    for(int j = 1; (1 << j) - 1 < len; j ++)
        for(int i = 0; i + (1 << j) - 1 < len; i ++)
            maxd[i][j] = max(maxd[i][j-1], maxd[i+(1<<(j-1))][j-1]), mind[i][j] = min(mind[i][j-1], mind[i+(1<<(j-1))][j-1]);
}

void RMQ(int l, int r){
    int k = 0;
    while((1<<(k+1)) <= r - l + 1) k++;
    minv = min(mind[l][k], mind[r-(1<<k)+1][k]);
    maxv = max(maxd[l][k], maxd[r-(1<<k)+1][k]);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &arr[i]);
    }
    
    for(int i = 0; i < n; i ++){
        scanf("%d", &len[i]);
    }
    RMQ_init(arr, n);
    for(int i = 0; i < n; i ++){
        RMQ(i-len[i]+1, i);
        printf("%lld\n", minv * maxv);
    }
    return 0;
}
