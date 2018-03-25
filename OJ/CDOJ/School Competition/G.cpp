#include<map>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1010100;
map<int, int> mp;
int T, n, arr[20];
int rem[MAXN], m, tem[20];
long long int ans = 0;
int gcd(int x, int y){ return x == 0 ? y : gcd(y%x, x);}
long long int lcm(long long int x, long long int y){
    return x / gcd(x, y) * y;
}
void proc(){
    int cnt = 0;
    ans = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++){
        scanf("%d", &arr[i]);
        tem[i] = arr[i];
        if(mp[arr[i]] > 0){
            cnt ++;
            arr[i] = MAXN * 10; 
        }
       
        mp[tem[i]] ++;
    }
    for(int i = 1; i <= m; i ++){
        if(mp[tem[i]] & 1)
            continue;
        if(arr[i] < MAXN * 10)
            cnt ++;
        arr[i] = MAXN * 10;
    }
    for(int i = 1; i <= m; i ++)
        mp[tem[i]] = 0;
    sort(arr+1, arr+1+m);
    m -= cnt;
    
    for(int i = 1; i < (1<<m); i ++){
        long long int tmp = 1;
        for(int j = 0; j < m; j ++){
            if(i&(1<<j))
                tmp = lcm(tmp, arr[j+1]);
        }
        ans += (n / tmp) * rem[i];
    }
    printf("%lld\n", ans);
}

int main(){
    for(int i = 1; i < (1<<15); i ++){
        int cnt = 0;
        for(int j = 0; j <= 15; j ++){
            if(i & (1<<j))
                cnt ++;
        }
        if(cnt & 1)
            rem[i] = 1;
        else
            rem[i] = -1;
    }
    scanf("%d", &T);
    while(T--){
        proc();
    }
}

