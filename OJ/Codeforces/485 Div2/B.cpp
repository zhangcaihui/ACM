#include<bits/stdc++.h>
using namespace std;
int comp(double x, double y){
    double tx = y * log(x);
    double ty = x * log(y);
    if(tx < ty)
        return 1;
    else if(tx == ty)
        return 0;
    else
        return -1;
}
int main(){
    double x, y;
    scanf("%lf%lf", &x, &y);
    int cal = comp(x, y);
    if(x == y){
        printf("=");
        return 0;
    }
    if(cal > 0)
        printf("<");
    else if(cal == 0)
        printf("=");
    else
        printf(">");
}
