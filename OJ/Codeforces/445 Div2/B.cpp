#include<cstdio>
#include<map>
using namespace std;
const int maxn = 1001010;
map<int, int> mmp;
int a[maxn];
int main(){
    int x, n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(int i = n; i > 0; i --){
        if(!mmp[a[i]])
            ans = a[i];
        mmp[a[i]] = 1;
    }
    printf("%d", ans);
    return 0;
}
