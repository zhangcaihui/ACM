#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1001010;
char ch[MAXN];
int mp[2032];
int main(){
    scanf("%s", ch);
    int ans = 0;
    mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = 1;
    for(int i = 0; ch[i]; i ++)
    {
        if('0' <= ch[i] && ch[i] <= '9'){
            if((ch[i] - '0') & 1)
                ans ++;
        }
        else
            if(mp[ch[i]])
                ans ++;
    }
    printf("%d", ans);
}
