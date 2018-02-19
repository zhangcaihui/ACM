#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 101010;
char A[MAXN], B[MAXN];
int main(){
    scanf("%s", A+1);
    long int len = strlen(A+1);
    for(int i = 1; i <= len; i ++){
        printf("%c", A[i]);
    }
    for(int i = len; i > 0; i --){
        printf("%c", A[i]);
    }
    return 0;
}
