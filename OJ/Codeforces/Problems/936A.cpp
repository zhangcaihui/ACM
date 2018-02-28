#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int LL;
LL k, d, t;
int main(){
    scanf("%lld%lld%lld", &k, &d, &t);
    LL t1 = k % d;
    LL t2 = d - t1;
    if(t1 == 0)
        t2 = 0;
    LL t3 = k - t2;
    LL cal = k * 2 + t2;
    LL sum = t * 2;
    LL tim = (sum / cal) * (k + t2);
    sum %=  cal;
    long double ans;
    if(2*k >= sum){
        cout << (long double)tim + ((long double)sum / 2);
    }
    else
        cout << (long double) tim + (k + sum - 2*k);
}