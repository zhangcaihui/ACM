#include<bits/stdc++.h>
using namespace std;
int dp[5050][5050], a[5050];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++)
        dp[i][i] = a[i];
    
    int rem = 1, tem = 0, len = 2;
    for(int d = 1; d <= n; d ++){
        for(int l = 1; l <= n ; l ++){
            if( l+d <= n && l+rem+tem <= n) 
                dp[l][l+d] = dp[l][l+tem] ^ dp[l+rem][l+rem+tem];
        }
        tem ++; 
        if(d+1 == len){
            rem *= 2;
            len *= 2;
            tem = 0;
        }
    }
    
    for(int d = 0; d <= n; d ++){
        for(int l = 1; l + d <= n ; l ++){
            dp[l-1][l+d] = max(dp[l][l+d], dp[l-1][l+d]);
            dp[l][l+d+1] = max(dp[l][l+d], dp[l][l+d+1]);
        }
    }
    
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i ++){
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", dp[x][y]);
    }
}
/*
1
1 1 
1 0 1 
1 1 1 1 
1 0 0 0 1 
1 1 0 0 1 1 
1 0 1 0 1 0 1 
1 1 1 1 1 1 1 1 
1 0 0 0 0 0 0 0 1 
1 1 0 0 0 0 0 0 1 1 
1 0 1 0 0 0 0 0 1 0 1 
1 1 1 1 0 0 0 0 1 1 1 1 
1 0 0 0 1 0 0 0 1 0 0 0 1 
1 1 0 0 1 1 0 0 1 1 0 0 1 1 
1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 
1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 
1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 
1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 
1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 
1 1 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 1 
1 0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 1 0 1 0 1 0 1 
1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 
1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 
1 1 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 1 
1 0 1 0 0 0 0 0 1 0 1 0 0 0 0 0 1 0 1 0 0 0 0 0 1 0 1 
1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1 
1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 
1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 

*/