// Note that fa[i][0] != i.
int LCA(int u,int v)  
{  
    if(dep[u]<dep[v])swap(u,v);  //我们默认u的深度一开始大于v，那么如果u的深度小就交换u和v  
    int delta=dep[u]-dep[v];    //计算深度差  
    for(int x=0;x<=max0;x++)    //此循环用于提到深度相同。  
        if((1<<x)&delta)  
            u=fa[u][x];  
    if(u==v)return u;  
    for(int x=max0;x>=0;x--)     //<strong>注意！此处循环必须是从大到小!</strong>因为我们应该越提越“精确”，  
        if(fa[u][x]!=fa[v][x])   //如果从小到大的话就有可能无法提到正确位置，自己可以多想一下  
        {  
            u=fa[u][x];  
            v=fa[v][x];  
        }  
    return fa[u][0];    //此时u、v的第一个父亲就是LCA。  
}