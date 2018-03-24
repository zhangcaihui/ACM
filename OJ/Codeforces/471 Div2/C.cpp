#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int Q, pre[100], rem[100];
vector<int> v[100];
LL xx = 1, len[12], MAXV = (LL)1001010001010001010;
bool check(double a, LL p, LL lim){
    double ans = 1;
    while(p){
        if(p & 1)
            ans = ans * a;
        if(ans > lim)
            return false;
        p >>= 1;
        a *= a;
    }
    return true;
}

int main(){
    
    for(int i = 2; i < 61; i ++){
        for(int j = i/2; j > 1; j --){
            if(i % j)
                continue;
            v[i].push_back(j);
        }
    }
    
    for(int i = 59; i > 1; i --){
        LL l = 1, r = MAXV;
        while(l < r){
            LL m = (r - l + 1) / 2 + l;
            if(check(m, i, MAXV))
                l = m;
            else
                r = m - 1;
        }
        rem[i] = l;
    }
    
    scanf("%d", &Q);
    while(Q--){
        LL L, R, ans = 0;
        scanf("%lld%lld", &L, &R);
        LL up;
        for(up = 59; up; up --){
            if(R & (xx<<up))
                break;
        }
        for(int i = up; i >= 2; i --){
            LL tmax = rem[i];
            int k = v[i].size();
            LL l = 1, r = tmax;
            while(l < r){
                LL m = (r - l + 1) / 2 + l;
                if(check(m, i, R))
                    l = m;
                else
                    r = m - 1;
            }
            pre[i] += l - 1;
            l = 1, r = tmax;
            while(l < r){
                LL m = (r - l + 1) / 2 + l;
                if(check(m, i, L-1))
                    l = m;
                else
                    r = m - 1;
            }
            pre[i] -= l - 1;
            
            for(int j = 0; j < k; j ++){
                int y = v[i][j];
                pre[y] -= pre[i];    
            }
            
            ans += pre[i];
            pre[i] = 0;
        }
        if(L == 1)
            ans ++;
        printf("%lld\n", ans);
    }

}
