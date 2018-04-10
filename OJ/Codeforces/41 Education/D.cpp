#include<bits/stdc++.h>
using namespace std;
const int MAXN = 101010;
struct Edge{
    int x, y;
    Edge(int xx = 0, int yy = 0) : x(xx), y(yy){}
    friend bool operator < (Edge a, Edge b){
        if(a.x == b.x)
        return a.y < b.y;
        return a.x < b.x;
    }
}arr[MAXN];
map<Edge, int> mp, mp2, mp3;
int gcd(int x, int y){    return x == 0 ? y : gcd(y%x, x);}
int n, rx, ry, note[MAXN];
int flag, ans, cnt;
bool check(int p, int q, int i){
    return (arr[p].y-arr[q].y)*(arr[i].x-arr[p].x) == (arr[p].x-arr[q].x)*(arr[i].y-arr[p].y);
}

Edge cal(int tx, int ty){
    int tem;
    if(!tx)
        tem = ty;
    else if(!ty)
        tem = tx;
    else 
        tem = gcd(tx, ty);
    tx /= tem, ty /= tem;
    if(tx < 0){
        tx *= -1;
        ty *= -1;
    }
    Edge prin;
    prin.x = tx, prin.y = ty;
    return prin;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d%d", &arr[i].x, &arr[i].y);
        if(i == 1)
            continue;
        Edge tedge = cal(arr[i].x-arr[1].x, arr[i].y-arr[1].y);
        if(mp[tedge] == 1)
            flag ++;
        else if(!mp[tedge])
            cnt ++;
        mp[tedge] ++;
    }
    if(n <= 4)
        ans = 1;
    else{
        if(!flag){
            int cnt3 = 0, cnt4 = 1;
            for(int i = 3; i <= n; i ++){
                if(!mp2[cal(arr[i].x-arr[2].x, arr[i].y-arr[2].y)])
                    cnt3 ++;
                mp2[cal(arr[i].x-arr[2].x, arr[i].y-arr[2].y)] ++;
            }
            mp3[cal(arr[2].x-arr[3].x, arr[2].y-arr[3].y)];
            for(int i = 4; i <= n; i ++){
                if(!mp3[cal(arr[i].x-arr[3].x, arr[i].y-arr[3].y)])
                    cnt4 ++;
                mp3[cal(arr[i].x-arr[3].x, arr[i].y-arr[3].y)] ++;
            }
            if(cnt3 <= 2 || cnt4 <= 2)
                ans = 1;
        }
        else if(flag == 1 && cnt <= 3){
            ans = 1;
        }
        else if(flag == 1){
            for(int i = 1; i < n; i ++)
                if(mp[arr[i]] > 1)
                    note[i] = 1;
                    
            int p, q;
            for(int p = 1; p < n; p ++)
                if(!note[p])
                    break;
            for(int q = p+1; q < n; q ++)
                if(!note[q])
                    break;
                    
            int rem = 1;
            for(int i = q+1; i < n; i ++)
                if(mp[arr[i]] == 1){
                    if(!check(p, q, i))
                        rem = 0;
                }
            if(rem)
                ans = 1;
        }
        else if(flag == 2 && cnt == 2){
            ans = 1;
        }
        else
            ans = 0;
    }
    
    printf("%s", ans ? "YES" : "NO");
}
/*

5
0 1
0 0
1 1
1 -1
2 2
*/
