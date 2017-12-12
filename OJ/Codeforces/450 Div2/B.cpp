#include<cstdio>
#include<cstring>
int mp[233333];
int main(){
    int x, y, rem, z;
    scanf("%d%d%d", &x, &y, &z);
    rem = x % y;
    int cnt = 0;
    while(1){
        cnt ++;
        rem *= 10;
        x = rem / y;
        rem %= y;
        if(x == z)
            break;
        if(mp[rem]){
            printf("-1");
            return 0;
        }
        mp[rem] = 1;
    }
    printf("%d", cnt);
}
