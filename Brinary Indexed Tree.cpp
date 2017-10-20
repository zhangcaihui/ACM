//二维树状数组

int lowbit(int x){ return (x & -x);}
void build(int t, int x, int y, int d)
{
    for(int i = x; i < MAXN; i += lowbit(i))
        for(int j = y; j < MAXN; j += lowbit(j))
            rem[t][i][j] += d;
}
int sum(int t, int x, int y)
{
    int cnt = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        for(int j = y; j > 0; j -= lowbit(j))
            cnt += rem[t][i][j];
    return cnt;
}
