void RMQ_init(int arr[], int len){
    for(int i = 0; i < len; i ++) d[i][0] = arr[i];
    for(int j = 1; (1 << j) - 1 < len; j ++)
        for(int i = 0; i + (1 << j) - 1 < n; i ++)
            d[i][j] = min(d[i][j-1], d[i+(1<<(j-1))][j-1]);
}

int RMQ(int l, int r){
    int k = 0;
    while((1<<(k+1)) <= r - l + 1) k++;
    return min(d[l][k], d[r-(1<<k)+1][k]);
}


