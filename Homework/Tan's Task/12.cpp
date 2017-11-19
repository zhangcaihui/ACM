#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;
const int maxn = 1010;
int a[maxn][maxn], b[maxn*maxn];
int main(){
    srand(time(0));
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++){
            b[i*m-m+j] = a[i][j] = rand();
        }
    sort(b+1, b+1+n*m);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++)
            a[i][j] = b[i*m-m+j];
        }
    int x, i;
    while(scanf("%d", &x) != EOF){
        for(i = 1; a[i][n] < x; i ++);
        for(int j = 1; j <= m; j ++)
            if(a[i][j] == x){
                printf("Yes\n");
                break;
            }
        printf("No\n");
    }
    return 0;
}
