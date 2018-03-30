//离散函数
int three_devide(int l,int r) //找凸点  
{  
    while(l < r-1)  
    {  
        int mid  = (l+r)/2;  
        int mmid = (mid+r)/2;  
        if( f(mid) > f(mmid) )  
            r = mmid;  
        else  
            l = mid;  
    }  
    return f(l) > f(r) ? l : r;  
}  

//连续函数
double three_devide(double low,double up)  
{  
    double m1,m2;  
    while(up-low>=eps)  
    {  
        m1=low+(up-low)/3;  
        m2=up-(up-low)/3;  
        if(f(m1)<=f(m2))  
            low=m1;  
        else  
            up=m2;  
    }  
    return (m1+m2)/2;  
}  
