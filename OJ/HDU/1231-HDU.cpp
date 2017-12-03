#include<cstdio>
int arr[100100], n;
int main(){
    while(scanf("%d", &n) && n){
        for(int i = 1; i <= n; i ++)
            scanf("%d", &arr[i]);
        int ans = -1234567, ans1, ans2;
        int sum = 0, p1 = 1, p2 = 0;
        for(int i = 1; i <= n; i ++){
            p2 = i;
            sum += arr[i];
            if(sum > ans)
                ans1 = p1, ans2 = p2, ans = sum;
            if(sum < 0)
                sum = 0, p1 = p2 = i + 1;
            }
        if(ans >= 0)
            printf("%d %d %d\n", ans, arr[ans1], arr[ans2]);
        else
            printf("0 %d %d\n", arr[1], arr[n]);
    }
    return 0;
}