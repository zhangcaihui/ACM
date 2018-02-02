#include<cstdio>
#include<cstring>
using namespace std;
const int mod = 1e9+7;
int mp[129], cnt[15];
long long int pre[59];
int arr[100], lef[15];
char ch[1001];

long long int quick_inverse(long long int x, int p) {
    long long int ret = 1;
    int exponent = p - 2;
    for (int i = exponent; i; i >>= 1, x = x * x % p) {
        if (i & 1) {
            ret = ret * x % p;
        }
    }
    return ret;
}


void proc(){
    int len = 0;
    long long int ans = 0;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; ch[i]; i ++){
        if(!mp[ch[i]])
            continue;
        arr[len] = mp[ch[i]];
        cnt[mp[ch[i]]] ++;
        len ++;
    }
    
    for(int i = 1; i <= 13; i ++)
        lef[i] = 4 - cnt[i];
    
    for(int i = 0; i < len; i ++){
        
        int tem = 0;
        for(int j = 1; j <= 13; j ++)
            tem += lef[j];
        if(!tem){
            ans ++;
            break;
        }
        
        int px = arr[i];
        int sum = 0;
        long long int mul = 1;
        for(int j = 13; j >= px; j --){
            sum += lef[j];
            mul *= pre[lef[j]];
            mul %= mod;
        }
        for(int j = px - 1; j ; j --){
            if(!lef[j])
                continue;
            int tsum = sum;
            long long int tmul = mul;
            for(int k = px - 1; k ; k --){
                if(j == k){
                    tmul *= pre[lef[k] - 1];
                    tmul %= mod;
                    tsum += lef[k] - 1;
                }
                else{
                    tmul *= pre[lef[k]];
                    tmul += mod;
                    tmul %= mod;
                    tsum += lef[k];
                }
            }
            ans += pre[tsum] * quick_inverse(tmul, mod);
            ans += mod;
            ans %= mod;
        }
        if(!lef[px])
            break;
        lef[px] --;
    }
    printf("%lld\n", (ans + mod) % mod);
}

int main(){
    mp['A'] = 1, mp['2'] = 2, mp['3'] = 3;
    mp['4'] = 4, mp['5'] = 5, mp['6'] = 6;
    mp['7'] = 7, mp['8'] = 8, mp['9'] = 9;
    mp['0'] = 10,mp['J'] = 11, mp['Q'] = 12;
    mp['K'] = 13;
    pre[0] = 1;
    for(int i = 1; i <= 54; i ++){
        pre[i] = pre[i-1] * i;
        pre[i] %= mod;
    }
    while(scanf("%s", ch) != EOF){
        proc();
    }
}
//AA22334455667788991010JJQQKK
