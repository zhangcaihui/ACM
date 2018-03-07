#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN  = 10100;
int rem[MAXN*3];
int arr[1001];
int sumv, sum;
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &arr[i]);
        if(arr[i] > 0)
            sumv += arr[i];
        else
            sum += arr[i];
    }

    printf("%d", sumv - sum);
}