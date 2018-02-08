#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
const int MAXN = 101010;
struct line{
    char kin[2];
    string std;
    int len;
}arr[MAXN];
int mp[257], que[257];
int n, siz;
char tem[MAXN], rem;
int ans, ff;

void deal1(int x){
    char tmp[257] = {'\0'};
    for(int i = 0; i < arr[x].len; i ++)
        tmp[arr[x].std[i]] = 1;
    for(int i = 'a'; i <= 'z'; i ++)
        if(tmp[i])
            que[i] = 0;
    ff = 1;
}

void deal2(int x){
    char tmp[257] = {'\0'};
    for(int i = 0; i < arr[x].len; i ++)
        tmp[arr[x].std[i]] = 1;
    
    for(int i = 'a'; i <= 'z'; i ++)
        if(!tmp[i] && que[i])
            que[i] = 0;
    ff = 0;
    if(tmp[rem])
        ff = 1;
    if(ff && siz == 1)
        ans ++;
}

void deal3(int x){
    char tmp[257] = {'\0'};
    for(int i = 0; i < arr[x].len; i ++)
        tmp[arr[x].std[i]] = 1;
    
    ff = 0;
    if(tmp[rem])
        ff = 1;
    if(!ff && siz == 1)
        ans ++;
    else if(ff){
        memset(que, 0, sizeof(que));
        que[rem] = 1;
        siz = 1;
    }
}
    
void check(){
    int cnt = 0;
    for(int i = 'a'; i <= 'z'; i ++){
        if(que[i])
            cnt ++;
        }
    siz = cnt;
}


int main(){
    memset(que, -1, sizeof(que));
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%s%s", arr[i].kin, tem);
        arr[i].std = tem;
        arr[i].len = strlen(tem);
    }

    /* test is ok;
    for(int i = 0; i < arr[1].len; i ++)
        printf("%c", arr[1].std[i]);
    */
    rem = arr[n].std[0];

    for(int i = 1; i < n; i ++){
        if(arr[i].kin[0] == '.')
            deal1(i);
        else if(arr[i].kin[0] == '!')
            deal2(i);
        else
            deal3(i);
        
        //printf("%d\n", ans);
        check();
    }
    printf("%d", ans);
}