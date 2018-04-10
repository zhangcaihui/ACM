#include<bits/stdc++.h>
using namespace std;
int arr[1010], n, m;
int rem[1010], ans;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++){
        scanf("%d", &arr[i]);
        rem[arr[i]] ++;
        int ff = 1;
        for(int j = 1; j <= n; j ++)
            if(!rem[j]){
                ff = 0;
                break;
            }
        if(ff)
            ans ++;
        if(ff)
        for(int j = 1; j <= n; j ++){
            rem[j] --;
        }
    }
    printf("%d", ans);
}
