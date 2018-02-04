#include<cstdio>
const int MAXN = 1001010;
int p1[MAXN], p2[MAXN], cnt[MAXN];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i ++){
        int p;
        scanf("%d", &p);
        p1[i] = p;
        p2[p] = 1;
    }
    for(int i = 2; i <= n; i ++){
        if(p2[i])
            continue;
        cnt[p1[i]] ++;
    }
    for(int i = 1; i <= n; i ++){
        if(!p2[i])
            continue;
        if(cnt[i] < 3){
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}