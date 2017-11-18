#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 2300;
int gcd(int x, int y){ return x == 0 ? y : gcd(y%x, x);}
int a[maxn], l[maxn], rem, jud;
int main(){
    int n, cnt = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
        if(a[i] == 1)
            cnt ++;
    }
    
    jud = a[1];
    for(int i = 1; i <= n; i ++)
        jud = gcd(a[i], jud);
    
    for(int i = 1; i <= n; i ++){
        rem = a[i];
        for(int j = i; j <= n; j ++){
            rem = gcd(rem, a[j]);
            if(rem == 1){
                l[i] = j - i;
                break;
            }
        }
        if(rem != 1)
            l[i] = maxn;
    }
    
    rem = maxn;
    for(int i = 1; i <= n; i ++)
        rem = min(rem, l[i]);
    
    if(jud != 1){
        printf("-1");
        return 0;
    }
    
    if(cnt){
        printf("%d", n-cnt);
    }
    else{
        //for(int i = 1; i <= n; i ++){
        //    printf("l == %d\n", l[i]);
        //}
        //printf("%d\n", rem);
        printf("%d", n-1+rem);
    }
}
