#include<cstdio>
#include<cstring>
using namespace std;
char ch[101010];
int len;
int main(){
    scanf("%s", ch+1);
    long int k = strlen(ch+1);
    for(int i = 1; i <= k; i ++){
        if(len == 26)
            break;
        if(ch[i] - 'a' <= len){
            ch[i] = 'a' + len;
            len ++;
        }
    }
    if(len == 26){
        printf("%s", ch+1);   
    }
    else
        printf("-1");
}