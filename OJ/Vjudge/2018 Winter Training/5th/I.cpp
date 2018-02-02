#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
const int MAXN = 101010;
int n, m, arr[MAXN], tim[MAXN];
int minv[MAXN], maxv[MAXN];
deque<int> q;
void clear(){
    while(!q.empty())
        q.pop_back();
}

void puin(){
    int tmpax = 0, tmpin = 2016100100;
    for(int i = 1; i <= n; i ++){
        scanf("%d%d", &tim[i], &arr[i]);
        tmpin = min(tmpin, arr[i]);
        tmpax = max(tmpax, arr[i]);
        minv[i] = tmpin;
        maxv[i] = tmpax;
    }
    return ;
}

int check(int x, int y, int kin){
    if(kin)
        return x > y;
    return x < y;
}

int aver(int len, int kin){
    double sum = 0;
    int l, r, ans;
    l = 1;
    ans = 0;
    sum = arr[1];
    for(r = 2; r <= n; r ++){
        while(tim[r] - tim[l] > len){//
            sum -= arr[l];
            l ++;
        }
        if(r != l)
            ans += check(arr[r], sum / (r - l), kin);
        sum += arr[r];
    }
    return ans;
}

int calin(int len, int kin){
    int ans = 0;
    clear();
    q.push_back(1);
    for(int i = 2; i <= n; i ++){
        int x;
        while(!q.empty()){
            x = q.front();
            if(tim[i] - tim[x] <= len)
                break;
            q.pop_front();
        }
        if(q.empty())
            x = i;
        else
            x = q.front();
        ans += check(arr[i], arr[x], kin);
        while(!q.empty()){
            x = q.back();
            if(arr[i] > arr[x])
                break;
            q.pop_back();
        }
        q.push_back(i);
    }
    return ans;
}

int calax(int len, int kin){
    int ans = 0;
    clear();
    q.push_back(1);
    for(int i = 2; i <= n; i ++){
        int x;
        while(!q.empty()){
            x = q.front();
            if(tim[i] - tim[x] <= len)
                break;
            q.pop_front();
        }
        if(q.empty())
            x = i;
        else
            x = q.front();
        ans += check(arr[i], arr[x], kin);
        while(!q.empty()){
            x = q.back();
            if(arr[i] < arr[x])
                break;
            q.pop_back();
        }
        q.push_back(i);
    }
    return ans;
}

void proc(){
    scanf("%d", &m);
    char s1[10], s2[10];
    int len, kin;
    for(int i = 1; i <= m; i ++){
        scanf("%s%s%d", s1, s2, &len);
        if(s1[0] == 'g')
            kin = 1;
        else
            kin = 0;
        if(s2[1] == 'v')
            printf("%d\n", aver(len, kin));
        else if(s2[1] == 'i')
            printf("%d\n", calin(len, kin));
        else
            printf("%d\n", calax(len, kin));
    }
}

int main(){
    //freopen("test.in", "r", stdin);
    
    while(scanf("%d", &n) != EOF){
        puin();
        proc();
    }
    return 0;
}
/*
 
 10
 60 30
 120 28
 180 35
 240 34
 300 40
 360 31
 420 28
 480 2
 540 42
 600 30
 2
 gt avg 7200
 lt min 300
 
 */

