#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
const double eps = 1e-7;
double xx;
int rem;
double bot;
double cei(double x, int y){
    return int(x*pow(10, y))/double(pow(10, y));
}

double flo(double x, int y){
    if(int(x*pow(10,y))/double(pow(10, y)) == x)
    return x;
    return int(x*pow(10, y)+1)/double(pow(10, y));
}

bool check(double x, double y){
    if(x-eps <= y && y <= x + eps)
        return true;
    return false;
}
int P;
void puin(){
    P = 0, rem = 0, xx = 0;
    char tem[20];
    scanf("%s", tem+1);
    int i;
    for(i = 1; tem[i]; i ++){
        if(tem[i] == '.')
            break;
        P = P * 10 + tem[i] - '0';
    }
    double temp = 0.1;
    for(; tem[i]; i ++){
        xx = xx + (tem[i] - '0')* temp;
        temp *= 0.1, rem ++;
    }
    return ;
}
void proc(){
    int ff = 1;
    int x = 0, y = 0;
    if(xx){
        bot = 1;
        while(ff){
            bot *= 2;
            int l = 1, r = bot;
            while(l != r && ff){
                int m = (l + r) >> 1;
                if(check(cei(m/bot, rem), xx) || check(flo(m/bot, rem) , xx))
                    x = m, y = bot, ff = 0;
                if(m/bot < xx)
                    l = m + 1;
                else 
                    r = m;
            }
        }
    }
    if(P ||(!P && xx == 0))
        printf("%d", P);
    if(xx){
        if(P)
            printf(" ");
        printf("%d/%d", x, y);
    }
    printf("\"\n");
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        puin();
        proc();
    }
}