#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
char ch[MAXN];
int cnt[30], sum, ff;
int main(){
    scanf("%s", ch);
    for(int i = 0; ch[i]; i ++){
        if(!cnt[ch[i]-'a'])
            sum ++;
        cnt[ch[i] - 'a'] ++;
    }
    if(sum > 4 || sum == 1){
        ff = 0;
    }
    else if(sum == 4)
        ff = 1;
    else if(sum == 3){
        for(int i = 0; i < 26; i ++)
            if(cnt[i] > 1){
                ff = 1;
                break;
            }
    }
    else{
        int tem = 0;
        for(int i = 0; i < 26; i ++)
            if(cnt[i] > 1)
                tem ++;
        if(tem > 1){
            ff = 1;
        }
    }
    if(ff)
        printf("Yes");
    else
        printf("No");
}
