#include<bits/stdc++.h>
using namespace std;
long long int n;
int main(){
    scanf("%lld", &n);
    if(n == 0){
        printf("0");
        return 0;
    }
    n ++;
    long long int ans = 0, cnt = 0;
    if(n & 1)
        ans = n;
    else
        ans = n / 2; 
    printf("%lld", ans);
}
