#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
const int maxn = 1001010;
stack<char> s;
char expe[maxn];
int ff = 1;
int main(){
    scanf("%s", expe+1);
    for(int i = 1; expe[i]; i ++){
        if(expe[i] == ']'){
            if(s.top() != '[')
                ff = 0;
            else
                s.pop();    
        }
        else if(expe[i] == ')'){
            if(s.top() != '(')
                ff = 0;
            else
                s.pop();    
        }
        else
            s.push(expe[i]);
    }
    if(s.size())        
        ff = 0;
    if(ff)
        printf("YES");
    else
        printf("NO");
}