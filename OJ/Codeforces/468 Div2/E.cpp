
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ASC(char x){ return x - 'a';}
double rem[28][5010][28], cnt[28];
char ch[5100];
double ans;
int main(){
    scanf("%s", ch+1);
    long int len = strlen(ch+1);
    for(int i = 1; ch[i]; i ++){
        cnt[ASC(ch[i])] ++;
        for(int j = 1; j < len; j ++){
            int posi = i + j;
            if(i+j>len)
                posi -= len;
            rem[ASC(ch[i])][j][ASC(ch[posi])] ++;
        }
    }
    for(int i = 0; i < 26; i ++){
        double tmp = 0;
        double a = cnt[i] / len;
        for(int j = 1; j < len; j ++){
            double tem = 0;
            for(int k = 0; k < 26; k ++){
                if(rem[i][j][k] != 1)
                    continue;
                tem += a / cnt[i];
            }
            tmp = max(tmp, tem);
        }
        ans += tmp;
    }
    printf("%.8f", ans);
}
