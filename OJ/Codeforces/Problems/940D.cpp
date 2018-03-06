#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 1001010;
int n, arr[MAXN];
char str[MAXN];
int l, r;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &arr[i]);
    scanf("%s", str+1);
    r = 1000000000;
    l = -r;
    for(int i = 5; i <= n; i ++){
        if(str[i] != str[i-1]){
            for(int j = 0; j <= 4; j ++){
                if(str[i] == '0'){
                    r = min(r, arr[i-j] - 1);
                }
                else
                    l = max(l, arr[i-j] + 1);
            }
        }
    }
    printf("%d %d", l, r);
}
