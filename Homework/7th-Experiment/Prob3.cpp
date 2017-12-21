#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1001010;
int n, a[MAXN];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    sort(a+1, a+1+n);
    int k, x;
    scanf("%d", &k);
    while(k--){
        scanf("%d", &x);
        //printf("%ld<---->%ld\n", lower_bound(a+1, a+1+n, x) - a, upper_bound(a+1, a+1+n, x) - a);
        long int xx = lower_bound(a+1, a+1+n, x) - a, yy = upper_bound(a+1, a+1+n, x) - a;
        if(xx == yy|| xx > n)
            printf("%ld\n", xx);
        else
            printf("%ld %ld\n", xx, yy-1);
    }
    
}
/*
 Sample #1:
 6
 1 2 2 3 3 5
 3
 2
 4
 6
*/
