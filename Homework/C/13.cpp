#include<cstdio>
const int maxn = 100;
int a[] = {0, 12, 2, 8, 22, 16, 4, 10, 6, 14, 20}, b[maxn];
int main(){
    int sum = 0, cnt = 0, f, ave;
    for(int i = 1; a[i]; i ++) sum += a[i];
    while(1){
        sum = 0;
        for(int i = 1; i <= 10; i ++)
            sum += a[i];

        if(sum % 10 == 0)
            f = 1;
        else
            f = 0;

        ave = sum / 10;
        for(int i = 1; i <= 10; i ++){
            if(a[i] != ave)
                break;
            f ++;
        }
        if(f == 11)
            break;
        
        for(int i = 2; i <= 10; i ++)
            b[i] = (a[i-1] + a[i]) / 2;
        
        b[1] = (a[1] + a[10]) / 2;
        for(int i = 1; i <= 10; i ++){
            a[i] = b[i];
            if(a[i] & 1)
                a[i] ++;
        }    
        cnt ++;
    }
    printf("%d\n",cnt);
}