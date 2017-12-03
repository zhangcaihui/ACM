#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n, len;
struct node{
    char name[110];
    bool operator < (const node& tem){
        return strcmp(name, tem.name) > 0 ? 0 : 1;
    }
}file[110];
char ans[110][110];
void puin(){
    len = 0;
    for(int i = 1; i <= n; i ++){
        scanf("%s", file[i].name);
        len = max(len , (int)strlen(file[i].name));
    }
}
void proc(){
    for(int i = 1; i <= 60; i ++)
        printf("-");
    puts("");
    memset(ans, '\0', sizeof(ans));
    sort(file+1, file+1+n);
    int p = 0, cnt = 0, width = 0;
    int col = 62 / (len + 2), row = (n + col - 1) / col;
    int sum = (len+2) * col - 2;
    for(int i = 1; i <= col; i ++){
        for(int j = 1; j <= row && cnt < n; j ++)
            strcpy(ans[j]+p, file[++cnt].name);
        p += len + 2;
    }
    for(int i = 1; i <= row; i ++){
        for(int j = 0; j < sum; j ++)
            if(ans[i][j] == '\0')
                ans[i][j] = ' ';
            }
    
    for(int i = 1; i <= row; i ++)
        printf("%s\n", ans[i]);
}
int main(){
    while(scanf("%d", &n) != EOF){
        puin();
        proc();
    }
}