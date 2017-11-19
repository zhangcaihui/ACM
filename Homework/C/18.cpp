#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1001010;
char ch[maxn], b[maxn];
int p, n;
int main(){
    scanf("%s%d%d", ch, &p, &n);
    int len = strlen(ch);
    for(int i = 1; i <= n; i ++){
        for(int j = 0; ch[j+p+1]; j ++)
            b[j] = ch[j+p+1];
        for(int j = 0; j <= p; j ++){
            b[j+len-1-p] = ch[j];
        }
        for(int j = 0; b[j] ; j ++)
            ch[j] = b[j];
        }
    printf("%s\n", ch);
}