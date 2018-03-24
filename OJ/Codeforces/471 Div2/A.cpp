#include<bits/stdc++.h>
using namespace std;
int h, m, H, D, N;
double C;
int main(){
    scanf("%d%d", &h, &m);
    scanf("%d%d%lf%d", &H, &D, &C, &N);
    double ans = 0;
    if(h >= 20){
        ans = (H + N - 1) / N * C * 0.8;
    }
    else{
        ans = (H + N - 1) / N * C;
        int d = (20 - h - 1) * 60 + (60 - m);
        ans = min(ans, (H + N - 1 + d * D) / N * C * 0.8);
    }
    printf("%.5lf", ans);
}
