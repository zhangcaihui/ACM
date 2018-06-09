#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
char ch[MAXN];
int n, len, cnt;
int rema[MAXN], remb[MAXN];
int tr1(char x){ 
    if(x == 'W') return 1;
    else if(x == 'L') return -1;
    return 0;
}
char tr2(int x){
    if(x == 1) return 'W';
    else if(x == -1) return 'L';
    return 'D';
}
int kin(int x){
    if(x > 0) return 1;
    else if(!x) return 0;
    return -1;
}
int main(){
    int p = 0, k, tmp = 0;
    int a = 0, b = 0, len;
    scanf("%d%d%s", &len, &k, ch+1);
    int minv = 0, maxv = 0, tem = 0;
    while(p != len){
        tmp = p;
        if(ch[tmp+1] == '?'){
            while(ch[tmp+1] == '?'){
                tmp ++;
            }   
            ++ cnt;
            int xx = k, yy = -k;
            if(tmp != len)
                xx --, yy ++;
            rema[cnt] = min(xx, a + tmp - p);
            remb[cnt] = max(yy, b - tmp + p);
            p = tmp;
        }
        tem = 0;
        while(ch[tmp+1] != '?' && tmp != len){
            tem += tr1(ch[tmp+1]);
            tmp ++;
            if(tmp != len){
                rema[cnt] = min(rema[cnt], k-tem-1);
                remb[cnt] = max(remb[cnt], -k-tem+1);
            }
        }
        if(tmp == len){
            rema[cnt] = min(rema[cnt], k-tem);
            remb[cnt] = max(remb[cnt], -k-tem);
        }
        a = rema[cnt] + tem;
        b = remb[cnt] + tem;
        p = tmp;
    }
    int posi = 0, count = 0, ff, tar;
    tmp = 0;
    for(int i = 0; i <= cnt; i ++){
        if(rema[i] < remb[i]){
            printf("NO");
            return 0;
        }
    }
    if(a == k)
        ff = 1;
    else if(b == -k)
        ff = -1;
    else{
        printf("NO");
        return 0;
    }
    while(tmp != len){
        while(ch[tmp+1] != '?' && tmp != len){
            posi += tr1(ch[tmp+1]);
            tmp ++;
        }
        count ++;
        while(ch[tmp+1] == '?'){
            if(ff == 1)
                tar = rema[count];
            else
                tar = remb[count];
            int ord = kin(tar-posi);
            if(((posi + ord == k) || (posi+ord == -k)) && tmp+1 != len)
                ord = 0;
            posi += ord;
            ch[tmp+1] = tr2(ord);
            tmp ++;
        }
    }
    
    printf("%s", ch+1);
    /*
    20 5
    ?LLLLLWWWWW?????????
    */
    
}
