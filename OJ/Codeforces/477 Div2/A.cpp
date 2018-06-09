#include<bits/stdc++.h>
using namespace std;
struct node{
     int x, y;
}a[1010];
int n, diff;
int cal(int i){
    return (a[i+1].x - a[i].x) * 60 + (a[i+1].y - a[i].y);
}

void prin(int i){
    printf("%d %d", a[i].x + (a[i].y+diff+1)/60, (a[i].y+diff+1)%60);
    return ;
}

int main(){
    scanf("%d%d", &n, &diff);
    for(int i = 1; i <= n; i ++){
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    if(a[1].x*60 + a[1].y >= diff + 1){
        printf("%d %d", 0, 0);
        return 0;
    }
    for(int i = 1; i < n; i ++){
        if(cal(i) >= 2*diff + 2){
            prin(i);
            return 0;        
        }
    }
    prin(n);
    return 0;
}
