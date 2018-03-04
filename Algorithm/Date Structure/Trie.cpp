#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN = 1010;
const int MASN = 30;
struct Trie{
    int ch[MAXN][MASN];
    int cnt;
    
    Trie(){
        memset(ch, 0, sizeof(ch));
    }
    
    void creat(char *str){
        int len = strlen(str);
        int u = 0;
        for(int i = 0; i < len; i ++){
            int v = str[i];
            if(!ch[u][v])
                u = ch[u][v] = ++cnt;
            else
                u = ch[u][v];
        }
    }
    
    int find(char *str){
        int len = strlen(str);
        int u = 0;
        for(int i = 0; i < len; i ++){
            int v = str[i];
            if(!ch[u][v])
                return 0;
            else
                u = ch[u][v];
        }
        return 1;
    }
};
