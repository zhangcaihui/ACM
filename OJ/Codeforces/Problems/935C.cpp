#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
double r, xx1, yy1, xx2, yy2;
double dis(double xx1, double yy1, double xx2, double yy2){
    return sqrt((xx1 - xx2)*(xx1 - xx2) + (yy1 - yy2)*(yy1-yy2));
}
double x, y, d;
int main(){
    scanf("%lf%lf%lf%lf%lf", &r, &xx1, &yy1, &xx2, &yy2);
    if((d = dis(xx1, yy1, xx2, yy2)) >= r){
        printf("%lf %lf %lf", xx1, yy1, r);
        return 0;
    }
    
    if(xx1 == xx2 && yy1 == yy2){
        printf("%.5f %.5f %.5f", xx1 + r / 2, yy1, r / 2);
        return 0;
    }
    
    x = ((xx1 - xx2) * (r / d) + xx1 + xx2) / 2 ;
    y = ((yy1 - yy2) * (r / d) + yy1 + yy2) / 2;
    double ans = (d + r) / 2;
    printf("%.8f %.8f %.8f", x, y, ans);
    return 0;
}
