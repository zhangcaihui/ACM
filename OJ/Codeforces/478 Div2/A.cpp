#include<bits/stdc++.h>
using namespace std;
char tem[1010]; 
int ch[1010][100];
int rem[1010], ans;
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%s", tem);
        for(int j = 0; tem[j]; j ++){
            ch[i][tem[j] - 'a'] = 1;
        }
    }
    
    for(int i = 1; i <= n; i ++){
        int flag = 0;
        for(int j = 1; j < i; j ++){
            int tmf = 1;
            for(int k = 0; k <= 26; k ++){
                if(ch[i][k] != ch[j][k]){
                    tmf = 0;
                }
            }
            flag = max(flag, tmf);
        }
        if(flag)
            continue;
        else{
            ++ ans;
        }
    }
    printf("%d", ans);
}
