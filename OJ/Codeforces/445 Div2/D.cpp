#include<cstdio>
const int maxn = 1001010;
int n, ff, note[maxn];
char p1[maxn], p2[maxn], ch[maxn];
void puin(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%s", ch);
        note[ch[0]] ++;
        for(int j = 0; ch[j+1]; j ++){
            note[ch[j+1]] ++;

            if(p1[ch[j]] && p1[ch[j]] != ch[j+1])
                ff = 1;
            if(p2[ch[j+1]] && p2[ch[j+1]] != ch[j])
                ff = 1;

            if(p1[ch[j+1]] == ch[j])
                ff = 1;

            if(ch[j] == ch[j+1])
                ff = 1;

            p1[ch[j]] = ch[j+1];
            p2[ch[j+1]] = ch[j];
        }
    }
}

void proc(){
    char p;
    int cnt = 0;

    if(ff){
        printf("NO");
        return ;
    } 
    for(int i = 'a'; i <= 'z'; i ++){
        p = (char) i;
        p = p1[p];
        while(p){
            p = p1[p];
            if(p == (char)i){
                ff = 1;
                break;
            }
        }
    }
    if(ff){
        printf("NO");
        return ;
    } 

    for(int i = 'a'; i <= 'z'; i ++){
        if(p2[i] || !note[i])
            continue;
        p = (char)i;
        while(p){
            printf("%c", p);
            p = p1[p];
        }
    }
}

int main(){
    puin();
    proc();
    return 0;
}
