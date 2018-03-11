#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN = 1010100;
const int MAZN = 301010;
int ch[MAXN][3];
int n, cnt, cout[MAXN];
int arr[MAZN];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &arr[i]);
    }
    for(int i = 1; i <= n; i ++){
        int tem, p = 0;
        scanf("%d", &tem);
        for(int k = 29; k >= 0; k --){
            int tmp = (tem>>k) & 1;
            if(ch[p][tmp])
                p = ch[p][tmp];
            else
                p = ch[p][tmp] = ++ cnt;
            cout[p] ++;
        }
    }

    for(int i = 1; i <= n; i ++){
        int x = arr[i];
        int ans = 0, p = 0;
        for(int j = 29; j >= 0; j --){
            int tmp = (x>>j) & 1;
            if(ch[p][tmp] && cout[ch[p][tmp]]){
                p = ch[p][tmp];
            }
            else{
                p = ch[p][!tmp];
                ans += (1 << j);
            }
            cout[p] --;
        }
        printf("%d ", ans);
    }


}