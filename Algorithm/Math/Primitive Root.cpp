
long long a[100005], len;
long long q_pow(long long a, long long b, long long c)
{
    long long ans=1;
    while(b)
    {
        if(b%2)
            ans=(ans*a)%c;
        a=(a*a)%c;
        b/=2;
    }
    return ans;
}

// test if g ^ ((p-1)/a) == 1 (mod p)
long long g_test(long long g, long long p)
{
    for(int i=0;i<len;i++)
        if(q_pow(g, (p-1)/a[i], p)==1)
            return 0;
    return 1;
}

long long primitive_root(long long p)
{
    // get the prime factor of p-1
    len=0;
    long long tmp=p-1;
    for(long long i=2;i<=tmp/i;i++)
    {
        if(tmp%i==0)
        {
            a[len++]=i;
            while(tmp%i==0)
                tmp/=i;
        }
    }
    if(tmp!=1)
        a[len++]=tmp;
    
    // find the primitive root
    long long g=1;
    while(g<p)
    {
        if(g_test(g,p))
            return g;
        g++;
    }
}
