#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int check(char x){ return (x == '+') || (x == '-') || (x == '*') || (x == '\\');}
char expe[233333];
int cal(int fro, int to){

}
int main(){
    int n;
    scanf("%d", &n);
    while(n){
        gets(expe);
        printf("%lld", cal(1, strlen(expe)));
    }
}
