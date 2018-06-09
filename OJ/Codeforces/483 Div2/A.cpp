#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
    }
    sort(a+1, a+1+n);
    printf("%d", a[(n+1)/2]);
}
