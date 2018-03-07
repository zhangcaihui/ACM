#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 101010;
int n, len, cnt[12];
char st[MAXN * 2], ans[MAXN*2];

bool dfs(int h, int minv){
    if(minv <= st[len/2+h] - '0'){
        int tmp, tmin = 10;
        for(int i = st[len/2+h]-'0'; i >= 0; i --){
            if(cnt[i]){
                cnt[i] --;
                tmp = i;
                ans[len/2+h] = tmp + '0';
                break;
            }
        }

        for(int i = minv; i <= 10; i ++){
            if(cnt[i]){
                tmin = i;
                break;
            }
        }
    }
}

void deal(){
    len = strlen(st + 1);
    for(int i = 1; i <= len; i ++)
        ans[i] = '\0';
    for(int i = 0; i < 10; i ++)
        cnt[i] = 0;
    if(len & 1){
        for(int i = 1; i <= len - 1; i ++)
            printf("9");
        puts("");
        return ;
    }
    if(st[1] == '1'){
        int ff = 0;
        for(int i = 2; i <= len; i ++){
            ff += st[i] - '0';
        }
        if(!ff){
            for(int i = 1; i <= len - 2; i ++){
                printf("9");
            }
            return ;
        }
    }
    for(int i = 1; i <= len / 2; i ++){
        ans[i] = st[i];
        cnt[st[i]-'0'] ++;
    }
    int minv = 0;
    for(int i = 0; i <= 9; i ++){
        if(cnt[i]){
            minv = i;
            break;
        }
    }
    if(!dfs(1, minv)){
        for(int i = len/2; i > 0; i --){
            if(st[i]>'0'){
                cnt[st[i]-'0'] --;
                st[i] --;
                cnt[st[i]-'0'] ++;
            }
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%s", st + 1);
        deal();
    }
}