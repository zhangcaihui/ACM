#include<cstdio>
const int maxn = 1001010;
char ch[maxn];
double rem[230];
int main(){
    rem['C'] = 12.01, rem['H'] = 1.008;
    rem['O'] = 16.00, rem['N'] = 14.01;
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", ch);
        int p = 0;
        double ans = 0;
        while(ch[p]){
            int cnt = 1;
            double var = rem[ch[p++]];
            if('1' <= ch[p] && ch[p] <= '9')
                cnt = 0;
            while('1' <= ch[p] && ch[p] <= '9'){
                cnt = 10 * cnt + ch[p++] - '0';
            }
            ans += var * cnt;
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}
/*
4
C
C6H5OH
NH2CH2COOH
C12H22O11
*/
