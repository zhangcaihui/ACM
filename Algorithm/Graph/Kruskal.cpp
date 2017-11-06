struct edge{
    int x, y, val;
    friend bool operator < (edge xx, edge yy){
        return xx.val < yy.val;
    }
}e[maxn];

int find(int x){ return f[x] == -1 ? x : (f[x] = find(f[x]));}

int Kruskal(){
   memset(f, -1, sizeof(f));:
    for(int i = 1; i <= m; i ++){
        int xx =find(e[i].x), yy = find(e[i].y);
        if(xx == yy)
            continue;
        f[xx] = yy;
    }
    for(int i = 2; i <= n; i ++)
        if(find(1) != find(i))   
           return -1;// can't connet
    return 1; // can connect
}
