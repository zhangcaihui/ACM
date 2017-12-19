#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, check = 999999999, cnt = 9;
int a[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
int cal(long long int x){
    if((x+1)/2 > n && (x&1))
        return 0;
    if(x/2 >= n && !(x&1))
        return 0;
    // may be wrong : two number need to be different.s
    return min(n-x/2, (x-1)/2);
}
int main(){
    long long int ans = 0;
    scanf("%d", &n);
    while(cal(check) == 0 && check){
        check /= 10;
        cnt --;
    }
    for(int i = 0; i < 9; i ++){
        a[cnt] = i;
        long long int tem = 0;
        for(int j = cnt; j >= 0; j --){
            tem = tem * 10 + a[j];
        }
        /*  debug
        printf("check : %lld\n", tem);
                     */
        ans += cal(tem);
    }
    if(!cnt)
        ans = (n-1) * n / 2;
    printf("%lld", ans);
    
    /*  debug
    printf("\n%d\n", cnt);
    
     */
    return 0;
}
