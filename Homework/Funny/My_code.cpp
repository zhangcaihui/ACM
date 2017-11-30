
#include<cstdio>
#include<cstring>
const int maxn = 1001010;
char str[maxn], all[2333], ch[maxn];
int ff, len, T, mp[2333];
void puin(){
    scanf("%s", str+1);
    for(int i = 1; str[i]; i ++)
        if(str[i] == '*')
            ff = 1;
    scanf("%d", &T);
    len = strlen(str+1);
}
void proc(){
    scanf("%s", ch+1);
    int tem = strlen(ch+1), ans = 1;
    if(!ff){
        if(tem != len)
            ans = 0;
        for(int i = 1; i <= len && ans; i ++){
            if(str[i] == '?')
                continue;
            if(ch[i] != str[i])
                ans = 0;
        }
    }
    else{
        int p1 = 0, p2 = tem + 1;
        for(int i = 1; str[i] != '*' && ans; i ++){
            p1 = i;
            if(str[i] == '?')
                continue;
            if(ch[i] != str[i])
                ans = 0;
        }
        for(int i = len; str[i] != '*' && ans; i --){
            p2 = tem+i-len;
            if(str[i] == '?')
                continue;
            if(ch[tem+i-len] != str[i])
                ans = 0;
        }
        if(p1 >= p2)
            ans = 0;
    }
    if(ans)
        printf("YES\n");
    else
        printf("NO\n");
}

int main(){
    puin();
    while(T--)
        proc();
    return 0;
}

