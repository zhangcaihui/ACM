#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 101010 * 2;
struct prob{
    int over;
    int tim;
    int num;
    friend bool operator < (const prob &a, const prob &b){
        if(a.tim == b.tim)
            return a.over > b.over;
        return a.tim < b.tim;// test is ok;
    }
}arr[MAXN];

int T, n;

bool check(int k){
    int cnt = 0, tem = 0;
    for(int i = 1; i <= n; i ++){
        if(arr[i].over < k)
            continue;
        tem += arr[i].tim;
        if(tem > T)
            return false;
        cnt ++;
        if(cnt == k)
            return true;
        }
    return false;
}
int main(){
    scanf("%d%d", &n, &T);
    for(int i = 1; i <= n; i ++){
        scanf("%d%d", &arr[i].over, &arr[i].tim);
        arr[i].num = i;
    }

    sort(arr+1, arr+1+n);
    /*test is ok;
    for(int i = 1; i <= n; i ++){
        printf("%d %d %d\n", arr[i].num, arr[i].tim, arr[i].over);
    }
    */
    
    int l = 0, r = n;
    while(l < r){
        int m = (l + r + 1) >> 1;
        if(check(m))
            l = m;
        else
            r = m - 1;
        }
    printf("%d\n%d\n", l, l);
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(cnt >= l)
            return 0;
        if(arr[i].over < l)
            continue;
        cnt ++;
        printf("%d ", arr[i].num);
    }

    return 0;
}