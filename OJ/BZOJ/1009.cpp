#include<bits/stdc++.h>
using namespace std;
int n, m, k;
struct Matrix{
    int siz;
    int arr[101][101];
    void init(){
        siz = m;
        memset(arr, 0, sizeof(arr));
    }
    void clea(){
        for(int i = 0; i <= m; i ++)
            arr[i][i] = 1;
    }
};
char ch[101];
int p[101][11], cnt[101];

Matrix cal(Matrix x, Matrix y){
    Matrix ans;
    ans.init();
    for(int i = 0; i <= m; i ++)
        for(int j = 0; j <= m; j ++)
            for(int q = 0; q <= m; q ++){
                ans.arr[i][j] += x.arr[i][q] * y.arr[q][j];
                ans.arr[i][j] %= k;
            }
    return ans;
}

Matrix qpow(Matrix x, int p){
    Matrix ans;
    ans.init(); 
    ans.clea();
    while(p){
        if(p & 1)
            ans = cal(ans, x);
        p >>= 1;
        x = cal(x, x);
    }
    return ans;
}

int main(){
    scanf("%d%d%d%s", &n, &m, &k, ch+1);
    p[0][ch[1]-'0'] = 1;
    cnt[0] = 1;
    for(int i = 1; i < m; i ++){
        cnt[i]++;
        p[i][ch[i+1]-'0'] = i+1;
        if(!p[i][ch[1]-'0'])
            cnt[i] ++;
        p[i][ch[1]-'0'] = max(1, p[i][ch[1]-'0']);
        for(int j = i-1; j ; j --){
            for(int k = 0; j - k; k ++){
                if(ch[i-k] != ch[j-k])
                    break;
                if(j-k == 1){
                    if(!p[i][ch[j+1]-'0'])
                        cnt[i] ++;
                    p[i][ch[j+1]-'0'] = max(p[i][ch[j+1]-'0'], j+1);
                }
            }
        }
    }
    Matrix rem;
    rem.init();
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < 10; j ++){
            rem.arr[p[i][j]][i] ++;
        }
    }
    Matrix ans = qpow(rem, n);
    int rec = 0;
    for(int i = 0; i < m; i ++)
        rec = (rec + ans.arr[i][0]) % k;
    printf("%d", rec);
}
