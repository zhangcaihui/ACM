//扩展欧几里得算法
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    LL d;
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
//中国剩余定理 ,r[]存放余数 ,prime[]存放两两互质的数
LL Chinese_Remainder(LL r[],LL prime[],int len)
{
    LL i, d, x, y, m, n=1, sum=0;
    //计算所以除数的积n，也是所以除数的最小公倍数
    for(i=0;i<len;i++)
        n *= prime[i];
    //计算符合所以条件的数
    for(i=0;i<len;i++)
    {
        m = n/prime[i];//计算除去本身的所有除数的积m
        d = exgcd(prime[i],m,x,y);//计算w[i]*x+m*y=gcd(w[i],m)的一个解y
        //累加整数解y的同并不断对n取余，其利用公式:(a+b)%c=(a%c+b%c)%c
        sum = (sum + y*m*r[i]) % n;
    }
    return (n + sum % n)%n;//满足所以方程的最小解
}

