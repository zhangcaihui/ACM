#include<cstdio>
long long int x, y;
int main(){
    scanf("%lld%lld", &x, &y);
    long long int diff = y / x;
    int cnt = 0;
    while(diff){
        cnt ++;
        diff /= 2;
    }
    printf("%d", cnt);
    return 0;
}