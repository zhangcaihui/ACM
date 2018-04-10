#include<bits/stdc++.h>
using namespace std;
char ch[5][110][110];
int n;
int ans, dp[5][2];
int rem[5][2];
int main(){
    scanf("%d", &n);
    memset(dp, 127, sizeof(dp));
    for(int i = 1; i <= 4; i ++){
        for(int j = 1; j <= n; j ++)
            scanf("%s", ch[i][j] + 1);
        //gets();
    }
    /*
    for(int i = 1; i <= 4; i ++){
        puts("");
        for(int j = 1; j <= n; j ++)
            printf("%s\n", ch[i][j]+1);
           
    }
    */
    
    for(int i = 1; i <= 4; i ++){
        int cnt = 0;
        for(int j = 1; j <= n; j ++)
            for(int k = 1; k <= n; k ++){
                if((j+k) & 1){
                   if(ch[i][j][k] != '1'){
                        cnt ++;
                   }
                }
                else
                    if(ch[i][j][k] != '0')
                        cnt ++;
            }
        rem[i][1] = cnt;
        cnt = 0;
        
        for(int j = 1; j <= n; j ++)
            for(int k = 1; k <= n; k ++){
                if((j+k) & 1){
                   if(ch[i][j][k] != '0'){
                        cnt ++;
                   }
                }
                else
                    if(ch[i][j][k] != '1')
                        cnt ++;
            }
        rem[i][0] = cnt;
    }
    
    int sum = 0, ans = 101010;
    for(int i = 1; i <= 4; i ++)
        sum += rem[i][0];
    for(int i = 1; i <= 3; i ++){
        for(int j = i+1; j <= 4; j ++){
            ans = min(ans, sum - rem[i][0] - rem[j][0] + rem[i][1] + rem[j][1]);
        }
    }
    printf("%d", ans);
    
}
