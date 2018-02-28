#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1001010;
int arr[MAXN], r1[MAXN], r2[MAXN];
int main(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &arr[i]);
    for(int i = 1; i <= n; i ++){
        r1[i] = r1[i-1];
        if(arr[i] == 1)
            r1[i] ++;
    }
    for(int i = n; i > 0; i --){
        r2[i] = r2[i+1];
        if(arr[i] == 2)
            r2[i] ++;
    }
    arr[n+1] = 3;
    for(int i = 1; i < n; i ++){
        if(arr[i] == 2 && arr[i+1] == 1){
            int t1 = 0, t2 = 0;
            for(int j = i; j; j --){
                t1 = max(t1, r1[j-1] + r2[j] - r2[i+1]);
            }
            for(int j = i + 1; j <= n; j ++){
                t2 = max(t2, r2[j+1] + r1[j] - r1[i-1]);
            }
            ans = max(ans, t1+t2);
        }
    }
    for(int i = 0; i <= n; i ++)
        ans = max(ans, r1[i] + r2[i+1]);
    printf("%d", ans);
}