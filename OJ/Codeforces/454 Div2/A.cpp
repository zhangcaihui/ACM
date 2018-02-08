#include<cstdio>
#include<algorithm>
using namespace std;
int ans[5], limi[5][2];
int main(){
    int v[6];
    for(int i = 1; i <= 4; i ++)
        scanf("%d", &v[i]);
    limi[1][0] = max(v[3], v[4]);
    limi[1][1] = min(2*v[3], 2*v[4]);
    limi[2][0] = max(limi[1][0]+1, v[2]);
    limi[2][0] = max(2*v[4]+1, limi[2][0]);
    limi[2][1] = 2*v[2];
    limi[3][0] = max(limi[2][0]+1, v[1]);
    limi[3][1] = 2*v[1];
    for(int i = 1; i <= 3; i ++){
        if(limi[i][0] > limi[i][1]){
            printf("-1");
            return 0;
        }
    }
    for(int i = 3; i ; i --)
        printf("%d\n", limi[i][0]);

}