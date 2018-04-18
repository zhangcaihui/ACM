#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 202020;
queue<int> q1;
char ch[MAXN];
int arr0[MAXN], arr1[MAXN];
int rem[MAXN], p;
int pre[MAXN], suf[MAXN];
int main(){
    scanf("%s", ch+1);
    long int len = strlen(ch+1);
    for(int i = 1; i <= len; i ++){
        pre[i] = pre[i-1];
        if(ch[i] == '1'){
            pre[i] ++;
            q1.push(i);
        }
        else
            arr[++p] = i;
        if(i-pre[i] < pre[i]){
            printf("-1");
            return 0;
        }
    }
    for(int i = len; i > 0; i --){
        suf[i] = suf[i+1];
        if(ch[i] == '1'){
            suf[i] ++;
        }
        if(len+1-i-suf[i] < suf[i]){
            printf("-1");
            return 0;
        }
    }
    printf("%ld\n", len - 2*pre[len]);
    for(int i = 1; i <= len; i ++){
        if(rem[i])
            continue;
        if(!q1.empty()){
            printf("3 %d", i);
            int tem1 = q1.front(); q1.pop();
            int tmp = upper_bound(arr, arr+1+p, tem1) - arr;
            int tem2 = arr[tmp];
            printf(" %d %d\n", tem1, tem2);
            rem[tem1] = rem[tem2] = 1;
            arr[tmp] = tem1;
        }
        else
            printf("1 %d\n", i);
    }
}
