#include<bits/stdc++.h>
using namespace std;
long long int a[100], b[100];
int cal(int x, int y){
    int ans = 0;
    if(x == y)
        return 14;
    while(x != y){
        x ++;
        if(x > 14)
            x -= 14;
        ans ++;
    }
    return ans;
}
long long int ans;

int main(){
    for(int i = 1; i <= 14; i ++){
       scanf("%lld", &a[i]);
    }
    for(int i = 1; i <= 14; i ++){
        if(!a[i])
            continue;
       for(int j = 1; j <= 14; j ++){
            int d = cal(i, j);
            long long int x;
            if(i == j){
                x = 0;
            }
            else
                x = a[j];
            if(d <= ((a[i]-1) % 14) + 1){
                 b[j] = (a[i]+13)/14 + x;
            }
            else
                b[j] = a[i] / 14 + x;
       }
       long long int tem = 0;
       for(int j = 1; j <= 14; j ++){
            if(b[j] & 1)
                continue;
            tem += b[j];
       }
       ans = max(ans, tem);
    }
    printf("%lld", ans);
}
