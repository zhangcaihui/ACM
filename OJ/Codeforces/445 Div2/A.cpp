#include<cstdio>
int a[100], sum = 0;
bool f = false;
void dfs(int tem, int h, int p){
    if(h == 3){
        if(tem * 2 == sum)
            f = true;
        return ;
    }
    if(p == 7)
        return ;
    for(int i = p; i <= 6; i ++)
        dfs(tem+a[i], h+1, i+1);
}
int main(){
    for(int i = 1; i <= 6; i ++)
        scanf("%d", &a[i]), sum += a[i];
    dfs(0, 0, 1);
    if(f)
        printf("YES");
    else
        printf("NO");
}
