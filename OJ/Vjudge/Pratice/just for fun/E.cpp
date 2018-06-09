#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int MAXN = 10100;
const LL mod = 1e9+7;
LL ans, ans1, ans2, ans0;
int rem[3][MAXN], n;
char ch[MAXN];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        memset(rem, 0, sizeof(rem));
        scanf("%s", ch + 1);
        int len = strlen(ch+1);
        if(ch[1] == '2' || ch[1] == '3' || ch[1] == '1'){
            rem[1][1] = 1;
            rem[2][1] = 2;
            rem[1][len+1] = rem[2][len+1] = 0;
            for(int i = 1; i < len; i ++){
                rem[1][i+1] = ch[i] - '0' - rem[1][i] - rem[1][i-1];
                if(rem[1][i+1] < 0)
                    rem[1][len+1] = 1;
            }
            if((ch[len] - '0') != (rem[1][len-1] + rem[1][len]))
                rem[1][len+1] = 1;
            
            for(int i = 1; i < len; i ++){
                rem[2][i+1] = ch[i] - '0' - rem[2][i] - rem[2][i-1];
                if(rem[2][i+1] < 0)
                    rem[2][len+1] = 1;
            }
            if((ch[len] - '0') != (rem[2][len-1] + rem[2][len]))
                rem[2][len+1] = 1;
            ans = 0, ans1 = 1, ans2 = 1, ans0 = 1;
            if(!rem[1][len+1]){
                for(int i = 1; i <= len; i ++){
                    if(rem[1][i] == 1)
                        ans1 = ans1 * 2 % mod;
                } 
            }
            else ans1 = 0;
            if(!rem[2][len+1]){
                for(int i = 1; i <= len; i ++){
                    if(rem[2][i] == 1)
                        ans2 = ans2 * 2 % mod;
                } 
            }
            else ans2 = 0;
            rem[0][1] = 0;
            rem[0][len+1] = 0;
            
            for(int i = 1; i < len; i ++){
                rem[0][i+1] = ch[i] - '0' - rem[0][i] - rem[0][i-1];
                if(rem[0][i+1] < 0)
                    rem[0][len+1] = 1;
            }
            if((ch[len] - '0') != (rem[0][len-1] + rem[0][len]))
                rem[0][len+1] = 1;
                
            if(!rem[0][len+1]){
                for(int i = 1; i <= len; i ++){
                    if(rem[0][i] == 1)
                        ans0 = ans0 * 2 % mod;
                } 
            }
            else ans0 = 0;
            ans = (ans1 + ans2 + ans0) % mod;
            printf("%lld %lld %lld\n", ans0, ans1, ans2);
        }
        else if (ch[1] == '0'){
            rem[0][1] = 0;
            rem[0][len+1] = 0;
            
            for(int i = 1; i < len; i ++){
                rem[0][i+1] = ch[i] - '0' - rem[0][i] - rem[0][i-1];
                if(rem[0][i+1] < 0)
                    rem[0][len+1] = 1;
            }
            if((ch[len] - '0') != (rem[0][len-1] + rem[0][len]))
                rem[0][len+1] = 1;
            ans = 1;
            if(!rem[0][len+1]){
                for(int i = 1; i <= len; i ++){
                    if(rem[0][i] == 1)
                        ans = ans * 2 % mod;
                } 
            }
            else ans = 0;
       }
       else if (ch[1] == '4'){
            rem[2][1] = 2;
            rem[2][len+1] = 0;
            
            for(int i = 1; i < len; i ++){
                rem[2][i+1] = ch[i] - '0' - rem[2][i] - rem[2][i-1];
                if(rem[2][i+1] < 0)
                    rem[2][len+1] = 1;
            }
            if((ch[len] - '0') != (rem[2][len-1] + rem[2][len]))
                rem[2][len+1] = 1;
            ans = 1;
            if(!rem[2][len+1]){
                for(int i = 1; i <= len; i ++){
                    if(rem[2][i] == 1)
                        ans = ans * 2 % mod;
                } 
            }
            else ans = 0;
        }
        printf("%lld\n", ans);
    }
}
