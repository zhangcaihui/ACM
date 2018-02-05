#include<cstdio>
#include<queue>
#include<map>
#include<stack>
using namespace std;
typedef long long int LL;
priority_queue<int> q;
map<int, int> mp;
stack<int> tem;
int n;
void deal(int cnt){
    while(!q.empty()){
        int u = q.top();q.pop();
        tem.push(u);
    }
    while(cnt < n){
        int u = tem.top(); tem.pop();
        tem.push(u-1); tem.push(u-1);
        cnt  ++;
    }
    while(!tem.empty()){
        int u = tem.top(); tem.pop();
        q.push(u);
    }
}

int main(){
    LL x, tem=1;
    int cnt=0;
    scanf("%lld%d", &x, &n);
    for(int i = 0; i <= 61; i ++){
        if(x & (tem << i)){
            q.push(i);
            cnt ++;
            mp[i] ++;
            // debug:
            //printf("%d\n", i);
        }
    }
    if(cnt > n){
        // test:
        //printf("%d", cnt);
        printf("No");
        return 0;
    }
    while(cnt < n){
        LL u = q.top(); 
        if(mp[u] > n - cnt){
            deal(cnt);
            break;
        }
        q.pop();
        mp[u] --;
        mp[u-1] += 2;
        q.push(u-1); q.push(u-1);
        cnt ++;
    }
    printf("Yes\n");
    while(!q.empty()){
        LL u = q.top(); q.pop();
        printf("%lld ", u);
    }
    return 0;
}