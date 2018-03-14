void Tarjan(int x){
    low[x] = dfn[x] = ++ cnt;
    inst[x] = 1;
    st.push(x);
    int k = v[x].size();
    for(int i = 0; i < k; i ++){
        int p = v[x][i];
        if(!dfn[p]){
            Tarjan(p);
            low[x] = min(low[x], low[p]);
        }
        else if(inst[p])
            low[x] = min(low[x], dfn[p]);
    }
    if(dfn[x] == low[x]){
        inst[x] = 0;
        color[x] = ++ cnum;
        v2[cnum].push_back(x);
        while(st.top() != x){
            color[st.top()] = cnum;
            inst[st.top()] = 0;
            v2[cnum].push_back(st.top());
            st.pop();
        }
        st.pop();
    }
}       
