#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
struct node{
    char kin;
    int val;
}a[MAXN * 2];
int color(node tmp){
    return tmp.kin == 'W';
}
int n, rem[2][MAXN], cnt[2][MAXN];
char tem[3];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n*2; i ++){
        scanf("%s%d", tem, &a[i].val);
        a[i].kin = tem[0];
        rem[color(a[i])][a[i].val] = i;
    }
    for(int i = 1; i <= n*2; i ++){
        for(int j = i - 1; j > 0; j --){
            if(color(a[i]) != color(a[j])){
                if(a[i].val > a[j].val){
                    cnt[color(a[i])][a[i].val] ++;
                }
            }
        }
    }
    int ans = 0;
    for(int i = n; i > 0; i --){
        int col1 = rem[0][i] > rem[1][i] ? 0 : 1;
        int col2 = 1 - col1;
        int tmp1 = rem[col1][i];
        int tmp2 = rem[col2][i];
        while(cnt[col1][i] != i - 1){
            if(color(a[tmp1]) != color(a[tmp1+1]) && a[tmp1].val > a[tmp1+1].val){
                cnt[col1][i] ++;
            }
            rem[color(a[tmp1])][a[tmp1].val] ++;
            rem[color(a[tmp1+1])][a[tmp1+1].val] --;
            swap(a[tmp1], a[tmp1+1]);
            ans ++, tmp1 ++;
        }
        while(cnt[col2][i] != i - 1){
            if(color(a[tmp2]) != color(a[tmp2+1]) && a[tmp2].val > a[tmp2+1].val){
                cnt[col2][i] ++;
            }
            rem[color(a[tmp2])][a[tmp2].val] ++;
            rem[color(a[tmp2+1])][a[tmp2+1].val] --;
            swap(a[tmp2], a[tmp2+1]);
            ans ++, tmp2 ++;
        }
    }
    printf("%d", ans);
}
