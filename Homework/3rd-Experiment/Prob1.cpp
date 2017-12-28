#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1001010;
long long int repr;
char ch[MAXN];
int note[MAXN];
char check(char x){
    if(x == ' ' || x == '(' || x == ')')
        return '\0';
    if(x == '|' || x == '&' || x == '~')
        return '\0';
    return x;
}
struct node{
    
}
void puin(){
    char tem;
    int p = 0;
    do{
        tem = getchar();
        if(tem == ' ')
            continue;
        ch[++p] = tem;
    }while(tem != '\n');
}

void build(int o, int l, int r){
    
}

void proc(){
    int ord = 0;
    for(int i = 1; ch[i]; i ++){
        if(ch[i] == '(')
            ord ++;
        else if(ch[i] == ')')
            ord --;
        else if(ch[i] == '|' || ch[i] == '&')
            note[
    }
    build(1, 1, strlen(ch+1));
}

void outp(){
    
}

int main(){
    puin();
    outp();
}
