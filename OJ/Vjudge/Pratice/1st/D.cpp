#include<cstdio>
char ch[200];
bool check(int p){
    int p1 = 0, p2 = p;
    while(ch[p2])
        if(ch[p1++] != ch[p2++])
            return false;
    return true;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", ch);
        for(int i = 1; ch[i]; i ++)
            if(check(i)){
                printf("%d\n", i);
                if(T)
                    puts("");//putchar(' ');
                break;
            }
    }
    return 0;
}
