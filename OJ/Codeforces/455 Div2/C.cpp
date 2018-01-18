#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const long long int mod = 1e9 + 7;
char ch[233333];
int cnt, n;
long long int sum[5010][5010];
void puin(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        getchar();
        scanf("%c", &ch[i]);
    }
}
void proc(){
    int cnt = 1;
    sum[0][1] = 1;
    for(int i = 1; i <= n; i ++){
        if(ch[i] == 'f')
        cnt ++;
        for(int j = 1; j <= cnt; j ++){
            if(ch[i] == 'f'){
                if(ch[i-1] == 'f')
                sum[i][j] = sum[i-1][j-1];
                else if(j != 1){
                    sum[i][j] = sum[i][j-1] + sum[i-1][cnt-1] - sum[i-1][j-2];
                }
            }
            else{
                if(ch[i-1] == 'f')
                sum[i][j] = sum[i-1][j];
                else{
                    sum[i][j] = sum[i][j-1] + sum[i-1][cnt] - sum[i-1][j-1];
                }
            }
            sum[i][j] =(sum[i][j] + mod) % mod;
        }
    }
    printf("%lld", sum[n][cnt]);
}
int main(){
    puin();
    proc();
    return 0;
}

