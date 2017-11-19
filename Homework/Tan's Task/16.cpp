#include<cstdio>
#include<cstring>
#include<vector>
const int maxn = 10010;
char ch[maxn];
int note[maxn];
int main(){
    scanf("%s", ch);
    for(int i = 0; ch[i]; i ++){
        note[ch[i]] ++;
    }
    for(int i = 0; i < maxn; i ++){
        if(note[i])
            printf("%c : %d \n", (char)i, note[i]);
        }
    return 0;
}
