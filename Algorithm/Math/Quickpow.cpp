
int qpow(int x, int n, int p){
    int ans = 1;
    while(n){
        if(n&1)
            ans = (ans * x) % p;
        x = (x * x) % p;
        n >>= 1;
    }
    return ans;
}


