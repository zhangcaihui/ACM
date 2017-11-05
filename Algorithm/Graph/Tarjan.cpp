
 void Tarjan(int x){
     low[x] = dfn[x] = ++ cnt;
 int k = pp[x].size();
 for(int i = 0; i < k; i ++){
     int v = pp[x][i];
         if(!dfn[v])
             Tarjan(v);
         low[x] = min(low[x], low[v]);
     }
 }       
