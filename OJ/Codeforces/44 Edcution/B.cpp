#include<bits/stdc++.h>
using namespace std;
int n, m;
char ch[2018][2018];
int rem[2018];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++){
        scanf("%s", ch[i]+1);
    }   
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(ch[i][j] == '1')
                rem[j] ++;
        }
    }
    for(int i = 1; i <= n; i ++){
        bool flag = false;
        for(int j = 1; j <= m; j ++){
            if(rem[j] == 1 && ch[i][j] == '1'){
                flag = true;
            }    
        }
        if(!flag){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}
