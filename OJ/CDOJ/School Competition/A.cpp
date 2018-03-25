#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct str{
    string num;
    friend bool operator < (str x, str y){
        return x.num+y.num > y.num+x.num;
    }
}arr[10010];
char tem[1010];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%s", tem);
        arr[i].num = tem;
    }
    sort(arr+1, arr+1+n);
    
    for(int i = 1; i <= n; i ++){
        cout << arr[i].num;
    }
    return 0;
}
