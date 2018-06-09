#include<bits/stdc++.h>
using namespace std;
int a, b;
char ch[10100];
int main(){
    scanf("%s", ch);
    for(int i = 0; ch[i]; i ++){
        if(ch[i] == '-')
            a ++;
        else
            b ++;
    }
    if(!b)
        printf("YES");
    else if(a % b)
        printf("NO");
    else
        printf("YES");
}
