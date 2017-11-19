#include<cstdio>
const int maxn = 1000;
int n;
int a[maxn][maxn];
int main(){
    scanf("%d", &n);
    int x = n, y = (n+1) / 2;
    for(int i = 1; i <= n+1; i ++)
        a[i][n+1] = a[n+1][i] = -1;
    for(int i = 1; i <= n*n; i ++){
        a[x][y] = i;
        int xx = x, yy = y;
        x ++, y ++;
        while(a[x][y]){
            if(x == 0)
                x = n;
            if(x > n && y > n)
                x = n - 1, y = n;
            else if(x > n)
                x = 1;
            else if(y > n)
                y = 1;
            else if(a[x][y] > 0)
                x = xx - 1, y = yy;
            if(1 <= x && x <= n && 1 <= y && y <= n)
                xx = x, yy = y;
        }
    }
    for(int i = n; i ; i --){
        for(int j = 1; j <= n; j ++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}