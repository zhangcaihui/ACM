#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[1001010];
int a[3], cnt[3][100100];
int stu(char xx) {
    if(xx == '0')
        return 0;
    else if(xx == '1')
        return 1;
    return 2;
 }
int main(){
    scanf("%s", ch+1);
    ch[0] = 'x';
    int ans = 0;
    int cnt = 0, p = 0;
    for(int i = 1; ch[i-1] || !(i-1); i ++){
        if(ch[i] != ch[i-1]){
            if(p == 0)
                cnt[p][x] = max(cnt, cnt[p][x-1]);
            else
                cnt[p][x] = max(cnt, cnt[p]);
            cnt = 1;
            p = stu(ch[i]);
            a[p] ++;
        }
        else
            cnt ++;
    }
    if(a[1] + a[0] <= 2)
        printf("%d", max(cnt1, cnt2));
    else
        printf("%d", cnt1 + cnt2);
    //printf("\n%d %d\n", cnt1, cnt2);
    //printf("\n%d %d\n", a[0], a[1]);
}