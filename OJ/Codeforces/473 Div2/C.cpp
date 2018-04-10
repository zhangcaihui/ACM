#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    if(n < 6)
        printf("-1\n");
    else{
        printf("1 2\n2 3\n2 4\n");
        for(int i = 5; i <= n; i ++)
            printf("%d %d\n", 1, i);
    }
    for(int i = 1; i < n; i ++)
        printf("%d %d\n", i, i+1);
}
