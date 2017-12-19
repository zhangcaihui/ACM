#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int n;
    int x = 0, y = 0, tem, no;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d%d", &tem, &no);
        if(tem > 0)
            x ++;
        else if(tem < 0)
            y ++;
    }
    if(x < 2 || y < 2)
        printf("Yes");
    else
        printf("No");
    return 0;
}