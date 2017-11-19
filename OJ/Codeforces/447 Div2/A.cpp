#include<cstdio>
char ch[1100];
int main(){
    int ans = 0;
    scanf("%s", ch);
    for(int i = 0; ch[i]; i ++){
        if(ch[i] != 'Q')
            continue;
        for(int j = i + 1; ch[j]; j ++){
            if(ch[j] != 'A')
                continue;
            for(int k = j + 1; ch[k]; k ++)
                if(ch[k] == 'Q')
                    ans ++;
        }
    }
    printf("%d", ans);
    return 0;
}