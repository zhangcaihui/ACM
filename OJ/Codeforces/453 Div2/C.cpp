#include<cstdio>
const int maxn = 1001010;
int cnt[maxn], p[maxn], ff;
int n, sum, note[maxn];
int rem[maxn];
void check(){
    for(int i = 1; i <= n; i ++)
        if(cnt[i] > 1 && cnt[i-1] > 1){
            ff = 1;
            note[i] = 1;
        }
}

void proc1(){
    int pp = 0;
    for(int i = 1; i <= sum; i ++){
        if(i == 1){
            printf("0 ");
            continue;
        }
        if(i-1 == rem[pp])
            pp ++;
        printf("%d ", rem[pp-1]);
    }
    puts("");
}
void proc2(){
    int pp = 0;
    for(int i = 1; i <= sum; i ++){
        if(i == 1){
            printf("0 ");
            continue;
        }
        if(i-1 == rem[pp]){
            pp ++;
            printf("%d ", rem[pp-1]);
        }
        else if(note[pp]){
            printf("%d ", rem[pp-1] - 1);
        }
        else
            printf("%d ", rem[pp-1]);
    }
 }
int main(){
    scanf("%d", &n);
    for(int i = 0; i <= n; i ++){
        scanf("%d", &cnt[i]);
        sum += cnt[i];
        rem[i] = sum;
    }
    check();//maybe cnt[0] > 1
    if(!ff){
        printf("perfect");
        return 0;
    }
    printf("ambiguous\n");
    proc1();
    proc2();
    return 0;
}
