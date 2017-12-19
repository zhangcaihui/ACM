#include<cstdio>
#include<cstring>
using namespace std;
int a[233] = {1};
void pre(){
    for(int i = 1; i*3 <= 100; i ++)
        a[i*3] = 1;
    for(int i = 0; i <= 100; i ++){
        if(!a[i])
            continue;
        for(int j = 1; !a[i+j*7]; j ++)
            a[i+j*7] = 1;
    }
}
int main(){
    pre();
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        int x;
        scanf("%d", &x);
        if(a[x])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
