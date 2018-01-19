#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1001010;
struct node{
    char kin;
    int num;
}a[MAXN], tem;
int cnt, ans, cun;
char b[MAXN], rem;
void puin(){
    scanf("%s", b+1);
    for(int i = 1; b[i]; i ++){
        if(b[i] == rem)
            a[cnt].num ++;
        else{
            a[++cnt].kin = rem = b[i];
            a[cnt].num = 1;
        }
    }
    cun = cnt;
}
void proc(){
    while(cnt > 1){
        ans ++, cun = 0;
        for(int i = 2; i <= cnt; i ++){
            if(a[i].num)
                a[i].num --;
            if(a[i-1].num)
                a[i-1].num --;
        }
        
        for(int i = 1; i <= cnt; i ++){
            if(a[i].kin == a[cun].kin)
                a[cun].num += a[i].num, a[i].num = 0;
            if(a[i].num)
                a[++cun].num = a[i].num, a[cun].kin = a[i].kin;
        }
        cnt = cun;
        cun = 123 + cnt;
    }
    printf("%d", ans);
}
int main(){
    puin();
    proc();
}