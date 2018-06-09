#include<bits/stdc++.h>
using namespace std;
char ch[5][1010];
int ans = 10101;
int rem;
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    if(k == 3){
        for(int i = 0; i < 3; i ++){
            ch[2][i+n/2] = '#';
        }
    }
    else if(k == 1){
        ch[2][(n+1)/2] = '#';
    }
    else{
        if(k & 1){
            ch[2][3] = '#';
        }
        for(int i = 2; i-1 <= k/2; i ++){
            if(i == 3)
                continue;
            ch[2][i] = ch[3][i] = '#';
        }       
    }
    printf("YES\n");
    for(int i = 1; i <= 4; i ++){
        for(int j = 1; j <= n; j ++)
            printf("%c", ch[i][j] ? '#' : '.');
        puts("");
    }
    
}   
