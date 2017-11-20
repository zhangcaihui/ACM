
#include<cstdio>
#include<algorithm>
using namespace std;
int note[20], ans, a[20], n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]), note[i] = 1;
    if(n < 3)
        ans = 0;
    else{
        sort(a+1, a+1+n);
        for(int i = 1; i <= n; i ++){
            int ff = 1;
            for(int j = i + 1; j <= n && ff; j ++){
                for(int k = j + 1; k <= n && ff; k ++){
                    if(!note[k] || !note[j] || !note[i])
                        continue;
                    if(a[i] + a[j] > a[k]){
                        ff = 0;
                        ans ++;
                        note[i] = note[j] = note[k] = 0;
                        break;
                    }
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
