#include<cstdio>
int n, note[30], ord[30];
int cnt;
void all(int x){
    if(x == n){
        for(int i = 1; i <= n; i ++)
            printf("%d ", ord[i]);
        puts("");
        cnt ++;
    }
    for(int i = 1; i <= n; i ++){
        if(note[i])
            continue;
        note[i] = 1;
        ord[x+1] = i;
        all(x+1);
        note[i] = 0;
    }
}

int main(){
    scanf("%d", &n);
    all(0);
    printf("%d\n", cnt);
    return 0;
}
