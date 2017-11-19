#include<cstdio>
using namespace std;
const int maxn = 1001010;
char ch[maxn];
int cnt;
int main(){
    scanf("%s", ch);
    for(int i = 0; ch[i+2]; i ++){
        int sum = 0;
        for(int j = 0; j < 3; j ++){
            if(ch[i+j] == 'A')
                sum += 1;
            if(ch[i+j] == 'B')
                sum += 3;
            if(ch[i+j] == 'C')
                sum += 9;
        }
        if(sum == 13)
            cnt ++;     
        }
    if(cnt)
        printf("Yes : %d\n", cnt);
    else
        printf("No\n");
    return 0;
}