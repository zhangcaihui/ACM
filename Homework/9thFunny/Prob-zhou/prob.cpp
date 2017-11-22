#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
const int maxn = 101010;
int n, l, r, p;
double a[maxn], sum, ans, tem;
void puin(){
    memset(a, '\0', sizeof(a));
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%lf", &a[i]);
    scanf("%d%d", &l, &r);
}

double cal(int x){
    return (l <= x && x <= r) ? (sum - a[x]/(1.0-a[x])) : (sum - (sum - 1) * a[x]);
}

void proc(){
    ans = tem = sum = p = 0;
    for(int i = l; i <= r; i ++)
        sum += a[i] / (1.0 - a[i]);
    for(int i = 1; i <= n; i ++){
        tem = cal(i);
        p = ans < tem ? i : p;
        ans = max(ans, tem);
    }
    printf("%d\n", p);
    if(p < l || p > r)
        printf("---------->YES\n");
    fclose(stdin);
    //fclose(stdout);
}

char file0[] = "./";
char file1[] = "in0", file2[] = ".in", filename1[100], filename2[100];
char file3[] = "ou0", file4[] = ".out";

void oppe(int filecnt){
    int p = 0;
    for(int i = 0; file0[i]; i ++)  filename1[p++] = file0[i];
    for(int i = 0; file1[i]; i ++) filename1[p++] = file1[i];
    filename1[p++] = '0' + filecnt;
    for(int i = 0; file2[i]; i ++) filename1[p++] = file2[i];
    freopen(filename1, "r", stdin);
    
    p = 0;
    for(int i = 0; file0[i]; i ++)  filename2[p++] = file0[i];
    for(int i = 0; file3[i]; i ++) filename2[p++] = file3[i];
    filename2[p++] = '0' + filecnt;
    for(int i = 0; file4[i]; i ++) filename2[p++] = file4[i];
    //freopen(filename2, "w", stdout);
}

int main(){
    for(int filecnt = 1; filecnt < 10; filecnt ++){
        oppe(filecnt);
        puin();
        proc();
    }
    return 0;
}
