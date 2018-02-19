#include<cstdio>
const int MAXN = 1001010;
int rem[MAXN], pres[MAXN][11];

int cal(int x){
    if(x < 10)
        return x;
    int tmp = 1;
    while(x){
        int tem = x % 10;
        x /= 10;
        tmp *= tem;
    }
    return cal(tmp);
}

void pre(){
    for(int i = 1; i < MAXN; i ++){
        rem[i] = cal(i);
    }
    
    for(int i = 1; i < MAXN; i ++){
        for(int j = 1; j < 10; j ++){
            pres[i][j] = pres[i-1][j];
        }
        pres[i][rem[i]] ++;
    }
}

void proc(){
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    printf("%d\n", pres[r][k] - pres[l-1][k]);
}

int main(){
    pre();
    int Q;
    scanf("%d", &Q);
    while(Q--){
        proc();
    }
}
