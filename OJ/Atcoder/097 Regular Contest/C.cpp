#include<bits/stdc++.h>
using namespace std;
stack<char> ans;
const int MAXN = 10010100;
int cnt, ch[MAXN][26], k;
char a[5050], rem[MAXN];
int st[30];
void dfs(int tmp){
    if(tmp)
        k --;
    if(k == 0 && tmp){
        ans.push(rem[tmp]);    
        return;
    }
    for(int i = 0; i < 26; i ++){
        if(!ch[tmp][i])
            continue;
        dfs(ch[tmp][i]);
        if(k == 0)
            break;
    }
    if(k == 0 && tmp){
        ans.push(rem[tmp]);    
        return;
    }
}

int main(){
    scanf("%s%d", a+1, &k);
    int tem = 0, sum = 0,len = strlen(a+1);
    char p;
    for(int i = len; i ; i --){
        st[a[i]-'a'] = i;
    } 
    for(int i = 0; i < 26; i ++){
        if(!st[i])
            continue;
        sum += len - st[i] + 1;
        for(int x = st[i]; x <= len; x ++){
            if(a[x] != 'a' + i)
                continue;
            int tmp = 0;
            for(int j = x; j <= len; j ++){
                if(ch[tmp][a[j] - 'a'])
                    tmp = ch[tmp][a[j]-'a'];
                else{
                    tmp = ch[tmp][a[j]-'a'] = ++ cnt;
                    rem[cnt] = a[j];
                }
            }
        }
        if(sum >= k)
            break;
    }
    dfs(0);
    //printf("%s\n", rem+1);
    while(!ans.empty()){
        printf("%c", ans.top()); 
        ans.pop();
    }
    
}
