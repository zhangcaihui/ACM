//C Bate
#include<stdio.h>
int n, l, r, maxn = 101010, pp;
int minpl, minpr, maxpl, maxpr;
double minl, minr, maxl, maxr;
double a[101010], sum, ans;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
            scanf("%lf", &a[i]);
        scanf("%d%d", &l, &r);
        minl = minr = 10; maxl = maxr = -10;
        minpl = maxpl = 1; minpr = maxpr = n;
        for(int i = 1; i < l; i ++){
            if(minl > a[i]){
                minl = a[i];
                minpl = i;
            }
            if(maxl < a[i]){
                maxl = a[i];
                maxpl = i;
            }
        }
        for(int i = n; i > r; i --){
            if(minr >= a[i]){
                minr = a[i];
                minpr = i;
            }
            if(maxr <= a[i]){
                maxr = a[i];
                maxpr = i;
            }
        }

        sum = 0;
        double minn, maxx;
        
        for(int i = l; i <= r; i ++)
            sum += a[i] / (1.0-a[i]);
        if(sum > 1.0){
            if(minl <= minr)
                pp = minpl;
            else
                pp = minpr;
            ans = sum - (sum - 1) * a[pp];
        }
        else if(sum < 1.0){
            if(maxl >= maxr)
                pp = maxpl;
            else
                pp = maxpr;
            ans = sum - (sum - 1) * a[pp];
        }
        else{
            ans = sum;
            if(l == 1)
                pp = r + 1;
            else
                pp = 1;
        }
            
        int temp;
        for(int i = l; i <= r; i ++){
            if(ans < (sum - a[i]/(1.0-a[i]))){
                pp = i;
                ans = sum - a[i]/(1.0-a[i]);
            }
            else if(ans == sum - a[i]/(1.0-a[i])){
                if(pp > i){
                    pp = i;
                }
            }
        }
        printf("%d\n", pp);
    }
    return 0;
}