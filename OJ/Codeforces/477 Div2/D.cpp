#include<bits/stdc++.h>
using namespace std;
double s1, s2;
struct node{
    int num;
    int x;
    friend bool operator < (node xx, node yy){
        return xx.x < yy.x;
    }
}a[1001010];
int n;
const int MAXN = 1001010;
int rem1[MAXN], rem2[MAXN];

int main(){
    scanf("%d%lf%lf", &n, &s1, &s2);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i].x);
        a[i].num = i;
    }
    
    sort(a+1, a+1+n);
    int p1 = n, p2 = n;
    while(p1 > 0){
        if(a[p1].x * (n - p1 + 1) >= s1)
            break;
        p1 --;
    }
    p2 = p1 - 1;
    while(p2 > 0){
        if(a[p2].x * (p1 - p2) >= s2)
            break;
        p2 --;
    }
    
    if(p1 > 0 && p2 > 0){
        printf("Yes\n");
        printf("%d %d\n", n - p1 + 1, p1 - p2);
        for(int i = p1; i <= n; i ++){
            printf("%d ", a[i].num);
        }
        puts("");
        for(int i = p2; i < p1; i ++){
            printf("%d ", a[i].num);
        }
        return 0;
    }
    
    p2 = n;
    
    while(p2 > 0){
        if(a[p2].x * (n - p2 + 1) >= s2)
            break;
        p2 --;
    }
    p1 = p2 - 1;
    while(p1 > 0){
        if(a[p1].x * (p2 - p1) >= s1)
            break;
        p1 --;
    }
    
    if(p1 > 0 && p2 > 0){
        printf("Yes\n");
        printf("%d %d\n", p2 - p1, n - p2 + 1);
        for(int i = p1; i < p2; i ++){
            printf("%d ", a[i].num);
        }
        puts("");
        for(int i = p2; i <= n; i ++){
            printf("%d ", a[i].num);
        }
        return 0;
    }
    printf("No");
}
