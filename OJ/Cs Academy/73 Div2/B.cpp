
LL Hash(int cur,int dep)
{
    if(!h[dep])
        h[dep] = rand() % mod;
    LL sum = h[dep];
    vis[cur]=1;
    int k = s[cur].size();
	for(int i=0;i<k;++i)
		if(!vis[s[cur][i]])
			sum=(sum+Hash(s[cur][i],dep+1) * h[dep]) % mod;
	return (sum*sum)%mod;
}