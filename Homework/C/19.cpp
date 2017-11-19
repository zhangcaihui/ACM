#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1001010;
char a[maxn], b[maxn];
int main(){
    int ans = 0;
    scanf("%s", a+1);
    int len = strlen(a+1);
    for(int i = 0; i < len; i ++)
        b[len-i] = a[i+1];
    for(int i = 1; i <= len; i ++){
        int flag = 1;
        for(int j = 1; j+i-1 <= len; j ++){
            if(a[i+j-1] != b[j]){
                flag = 0;
                break;
            }
        }
        if(flag){
            ans = len - i + 1;
            break;
        }
    }
    printf("length = %d\n%s%s", 2*len-ans, a+1, b+1+ans);
}