/*  Euler's totient function    */

//Get the number of the numbers smaller than n and prime to n
int GetPhi(int n)  
{  
    int m = sqrt(n+0.5);  
    int ans = n;  
    for(int i=2; i<=m; ++i) if(n%i == 0)  
    {  
        ans = ans/i * (i-1);  
        while(n%i == 0) n /= i;  
    }  
    if(n > 1) ans = ans/n * (n-1);  
    return ans;  
}  

//Get all the value of Euler's totient function from 1 ~ n
void PhiTable(int n)  
{  
    for(int i=2; i<=n; ++i)  
        phi[i] = 0;  
    phi[1] = 1;  
    for(int i=2; i<=n; ++i) 
        if((!phi[i]))  
            for(int j=i; j<=n; j+=i)  
            {  
                if(!phi[j]) phi[j] = j;  
                phi[j] = phi[j]/i * (i-1);  
            }  
}  
        

//Get the sum of prefixes of the value of Euler's totient function from 1 ~ n
void SumPhiTable(int n)  
{  
    f[1] = 1;  
    for(int i=2; i<n; ++i)  
    {  
        if(!f[i])  
        {  
            for(int j=i; j<n; j+=i)  
            {  
                if(!f[j]) f[j] = j;  
                f[j] = f[j]/i * (i-1);  
            }  
        }  
        f[i] += f[i-1];  
    }  
}  