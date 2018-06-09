#include<bits/stdc++.h>
using namespace std;
char ch[100];
int main(){
    scanf("%s", ch+1);
    int ans = 0;
    long int len = strlen(ch+1);
    for(int l = 1; l < len; l ++){
        for(int r = l + 1; r <= len; r ++){
            bool flag = true;
            for(int x = 0; x <= r - l; x ++){
                if(ch[l+x] != ch[r-x])
                    flag = false;
            }
            if(!flag) ans = max(ans, r-l+1);
        }
    }
    printf("%d", ans == 1 ? 0 : ans);
}
