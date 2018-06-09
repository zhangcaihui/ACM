#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010 * 2.5;
stack<int> s;
int cnt = 400, n;
int ch[MAXN][2], val[MAXN], sum[MAXN];
void add(int st, int x){
    int tmp = st;
    for(int i = 20; i >= 0; i --){
        if(ch[tmp][(x>>i)&1])
            tmp = ch[tmp][(x>>i)&1];
        else
            tmp = ch[tmp][(x>>i)&1] = ++cnt;
        val[tmp] = x & (1 << i);
        s.push(tmp);
    }
    int next = 0;
    while(!s.empty()){
        int temp = s.top(); s.pop();
        sum[temp] = min(sum[temp], sum[next]+val[temp]);
        next = temp;
    }
}
int query(int st, int x, int s){
    int tmp = st, ans = 0;
    for(int i = 20; i >= 0; i --){
        bool flag = true;
        int temp = ch[tmp][!((x>>i)&1)];
        if(temp){
            if(ans + sum[temp] <= s){
                flag = false;
                tmp = temp;
                ans += val[temp];
            }
        }
        if(flag){
            temp = ch[tmp][((x>>i)&1)];
            if(temp && ans + sum[temp] <= s){
                tmp = temp;
                ans += val[temp];
            }
            else
                return -1;
        }
    }
    return ans;
}
int main(){
    scanf("%d", &n);
    memset(sum, 127, sizeof(sum));
    memset(ch, 0, sizeof(ch));
    sum[0] = 0;
    for(int i = 1; i <= n; i ++){
        int t, x, k, s;
        scanf("%d%d", &t, &x);
        if(t & 1){
            for(int j = 1; j * j <= n; j ++){
                if(x % j)
                    continue;
                add(j, x);
                if(j*j < x)
                    add(x/j, x);
            }
        }
        else{
            scanf("%d%d", &k, &s);
            int prin = query(k, x, s-x);
            printf("%d\n", prin);
        }
    }
}
/*
38
1 32577
2 21718 10859 77437
2 21718 10859 78404
2 32577 32577 97054
2 21718 10859 65518
1 10295
1 13438
1 1040
2 20590 10295 10227
1 9869
1 30418
1 32630
1 15280
1 30326
2 3820 1910 37422
1 29021
1 29349
2 84838 6526 100000
1 28009
1 12122
1 25726
1 580
2 28009 28009 84961
1 23340
2 70020 23340 95597
2 30305 6061 7094
2 33616 3056 69436
1 28283
1 18606
1 5448
2 41180 10295 4222
1 8500
1 26892
1 20702
2 49032 2724 60741
2 4482 4482 39034
1 32577
20123
2 22827 3261 66484
*/
