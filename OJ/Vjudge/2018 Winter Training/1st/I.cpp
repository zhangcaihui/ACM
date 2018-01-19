#include<cstdio>
#include<map>
#include<cstring>
#include<string>
using namespace std;
const int MAXN = 1001010;
map<string, int> mp;
int ord[MAXN], n;

void puin(){
    scanf("%d", &n);
    string st;
    char ch[1001];
    for(int i = 0; i < n; i ++){
        scanf("%s", ch);
        st = ch;
        mp[st] = i;
    }
    for(int i = 0; i < n; i ++){
        scanf("%s", ch);
        st = ch;
        ord[i] = mp[st];
    }
}

int d[MAXN][22];

void RMQ_init(int arr[], int len){
    for(int i = 0; i < len; i ++) d[i][0] = arr[i];
    for(int j = 1; (1 << j) - 1 < len; j ++)
        for(int i = 0; i + (1 << j) - 1 < n; i ++)
            d[i][j] = max(d[i][j-1], d[i+(1<<(j-1))][j-1]);
}

int RMQ(int l, int r){
    int k = 0;
    while((1<<(k+1)) <= r - l + 1) k++;
    return max(d[l][k], d[r-(1<<k)+1][k]);
}

int ans[MAXN];

void proc(){
    int cnt = 0, l = 0, r = 0;
    RMQ_init(ord, n);
    while(r < n){
        if(RMQ(l, r) == r){
            ans[++cnt] = r - l + 1;
            l = r = r + 1;
        }
        else
            r ++;
    }
    for(int i = 1; i <= cnt; i ++)
        printf("%d ", ans[i]);
    printf("\n");
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        puin();
        proc();
    }
    return 0;
}


/*
 
 
 3
 5
 A
 B
 C
 D
 E
 A
 C
 D
 B
 E
 3
 RED
 BLUE
 ORANGE
 RED
 BLUE
 ORANGE
 3
 MOE
 LARRY
 CURLY
 CURLY
 MOE
 LARRY
 
 */