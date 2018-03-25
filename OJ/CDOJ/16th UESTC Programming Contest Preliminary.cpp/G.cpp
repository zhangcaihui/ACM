#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010; 
char ch[MAXN];
int cnt[100], rem[100], sum;
int main(){
    scanf("%s", ch+1);
    for(int i = 0; i < 26; i ++){
        scanf("%d", &rem[i]);
        sum += rem[i];
    }
    ch[0] = 'z' + 1;
    int len = strlen(ch+1);
    for(int i = 1; i < sum; i ++){
        cnt[ch[i] - 'a'] ++;
    }
    
    for(int i = sum; i <= len; i ++){
        cnt[ch[i]-'a'] ++;
        cnt[ch[i-sum]-'a'] --;
        int ff = 1;
        for(int i = 0; i < 26; i ++){
            if(cnt[i] != rem[i]){
                ff = 0;
                break;
            }
        }
        if(ff){
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}

