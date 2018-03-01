#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1001010;
char st[MAXN];
char sett[233];
int rem[233], len;
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", st+1);
    for(int i = 1; i <= n; i ++){
        if(!rem[st[i]])
            sett[++len] = st[i];
        rem[st[i]] = 1;
    }
    sort(sett+1, sett+1+len);
    if(k > n){
        printf("%s", st+1);
        for(int i = 1; i <= k - n; i ++)
            printf("%c", sett[1]);
        return 0;
    }
    for(int i = k; i; i --)
        if(st[i] != sett[len]){
            for(int j = 1; j <= len; j ++){
                if(st[i] == sett[j]){
                    st[i] = sett[j+1];
                    break;
                }
            }
            
            for(int j = i + 1; j <= k; j ++)
                st[j] = sett[1];
            
                break;
        }
    for(int i = 1; i <= k; i ++)
        printf("%c", st[i]);
}
