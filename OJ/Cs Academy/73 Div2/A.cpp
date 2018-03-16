#include<cstdio>
#include<algorithm>
using namespace std;
int rem[10101][4];
int main(){
    int n, arr[10010];
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &arr[i]);
        for(int j = 0; j < 3; j ++){
            rem[i][(arr[i]+j) %3] = j;
        }
    }
    int ans = 1001010;
    for(int i = 0; i < 3; i ++){
        int sum = 0;
        for(int j = 1; j <= n; j ++)
            sum += rem[j][i];
        ans = min(ans, sum);
    }
    printf("%d", ans);
}