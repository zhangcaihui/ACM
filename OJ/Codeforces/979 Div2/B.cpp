#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
typedef long long int LL;
char a[4][MAXN];
LL cnt[3][3300], ans[3];
char prin[4][10] = {"Kuro", "Shiro", "Katie"};
int main(){
    int n;
    scanf("%d%s%s%s", &n, a[0], a[1], a[2]);
    for(int i = 0; i < 3; i ++){
        int len = strlen(a[i]);
        for(int j = 0; j < len; j ++){
            cnt[i][a[i][j]] ++;
        }
    }
    int p = -1;
    for(int i = 0; i < 3; i ++){
        LL len = strlen(a[i]);
        LL tem = 0;
        for(int j = 1; j < 400; j ++)
            tem = max(tem, cnt[i][j]);
      
        LL rec = 0;
        if(tem == len && n == 1){
                rec = max((LL)1, len-1);
        }
        else{
            rec = min(len, n+tem);
        }
        ans[i] = rec;
    }
    int ff = 0;
    LL tem = -1;
    for(int i = 0; i < 3; i ++){
        tem = max(ans[i], tem);
    }
    for(int i = 0; i < 3; i ++)
        if(tem == ans[i]){
            ff ++;
            p = i;
        }
            
    if(ff > 1){
        printf("Draw");
        return 0;
    }   
    else{
        printf("%s", prin[p]);
    }
}
