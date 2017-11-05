//AC自动机--多模式匹配算法
void find(char *T){
    int n = strlen(T);
    int j = 0;
    for(int i = 0; i < n; i ++){
        int c = dix(T[i]);
        while(j && !ch[j][c]) j = f[j];
        j = ch[j][c];
        if(val[j]) print(j);
        else if(last[j]) print(last[j]);
    }
}
//val[i]表示以i节点作为单词末尾是否存在

void print(int i, int j){
    if(j){
        printf("%d: %d\n",j,val[j]);
        print(last[j]);
    }
}
//递归打印以节点j结尾的所有字符串

int getFail(){
    queue<int> q;
    f[0] = 0;
    for(int c = 0; c < SIGMA_SIZE; c++){
        int u = ch[0][c];
        if(u){
            f[u] = 0;
            q.push(u);
            last[u] = 0;
        }
    }
    while(!q.empty(){
        int r = q.front(); q.pop();
        for(int c = 0; c < SIGMA_SIZE; c ++){
            int u = ch[r][u];
            if(!u) continue;
            q.push(u);
            int v = f[r];
            while(v && !ch[v][c]) v = f[v];
            f[u] = ch[v][c];
            last[u] = val[f[u]] ? f[u] : last[f[u]];
        }
    }
        }
        //构造基于Tries树的失配函数
