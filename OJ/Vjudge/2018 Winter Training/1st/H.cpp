#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int x, y, z;
int p1, p2, len;
int k1, k2, k3;
int s1, s2, s3;
int t1, t2, t3;
char ch[10010];
bool check(char x){
    if(x == '+' || x == '-' || x == '*')
        return true;
    return false;
}
int cal(int xx, int yy, char t){
    if(t == '+')
    return xx + yy;
    if(t == '-')
    return xx - yy;
    else
    return xx * yy;
}
void puin(){
    x = y = z = 0;
    scanf("%s", ch+1);
    k1 = k2 = k3 = 0;
    len = strlen(ch+1);
    for(p1 = 2; !check(ch[p1]); p1 ++);
    for(p2 = len; ch[p2] != '='; p2 --);
    s1 = 1, s2 = p1 + 1, s3 = p2 + 1;
    
    
    t1 = t2 = t3 = 1;
    if(ch[s1] == '-')
    t1 = -1, s1 ++;
    else if(ch[s1] == '+')
    s1 ++;
    if(ch[s2] == '-')
    t2 = -1, s2 ++;
    else if(ch[s2] == '+')
    s2 ++;
    if(ch[s3] == '-')
    t3 = -1, s3 ++;
    else if(ch[s3] == '+')
    s3 ++;
    
    
    int tem = 1;
    for(int i = p1 - 1; i >= s1; i --){
        if(ch[i] == '?')
        k1 += tem;
        else
        x += (ch[i] - '0') * tem;
        tem *= 10;
    }
    tem = 1;
    for(int i = p2 - 1; i >= s2; i --){
        if(ch[i] == '?')
        k2 += tem;
        else
        y += (ch[i] - '0') * tem;
        tem *= 10;
    }
    tem = 1;
    for(int i = len; i >= s3; i --){
        if(ch[i] == '?')
        k3 += tem;
        else
        z += (ch[i] - '0') * tem;
        tem *= 10;
    }
    
}
bool check2(){
    if(ch[s1] == '?' && p1 - s1 != 1)
    return true;
    if(ch[s2] == '?' && p2 - s2 != 1)
    return true;
    if(ch[s3] == '?' && len + 1 - s3 != 1)
    return true;
    
    if(t1 < 0 && ch[s1] == '?')
        return true;
    if(t2 < 0 && ch[s2] == '?')
        return true;
    if(t3 < 0 && ch[s3] == '?')
        return true;
        
    return false;
}

void proc(){
    int cc[10010] = {0};
    for(int i = 1; i <= len; i ++)
        cc[ch[i] - '0'] = 1;
    if(!check2() && !cc[0]){
        if(cal(t1*x, t2*y, ch[p1]) == z*t3){
            printf("0\n");
            return ;
        }
    }
    for(int i = 1; i <= 9; i ++){
        if(cc[i])
            continue;
        if(cal(t1*(x+i*k1), t2*(y+i*k2), ch[p1]) == t3*(z+k3*i)){
            printf("%d\n", i);
            return ;
        }
    }
    printf("-1\n");
    return ;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        puin();
        proc();
    }
    return 0;
}
/*
 5
 1+1=?
 123*45?=5?088
 -5?*-1=5?
 19--45=5?
 ??*??=302?
 */