#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 201010;
const int MAXN = 201010;
int a[maxn], note[maxn], rem[maxn], tree[maxn];
int n, ans = 1, ql, qr;
int lowbit(int x){ return (x & -x);}
void build(int x)
{
    for(int i = x; i < MAXN; i += lowbit(i))
        rem[i] ++;
}

int sum(int x)
{
    int cnt = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        cnt += rem[i];
    return cnt;
}

void setting(int x, int o, int l, int r){
    if(ql <= l && r <= qr){
        tree[o] = x;
        return ;
    }
    int m = (l + r) / 2;
    if(ql <= m)
        setting(x, o<<1, l, m);
    if(m < qr)
        setting(x, (o<<1)+1, m+1, r);
}

int find_(int x, int o, int l, int r){
    if(tree[o])
        return tree[o];
    int m = (l + r) / 2;
    if(x <= m)
        return find_(x, o<<1, l, m);
    else
        return find_(x, (o<<1)+1, m+1, r);
}

int main(){
    scanf("%d", &n);
    qr = n;
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++){
        int k = sum(a[i]);
        if(k == i - 1 && k)
            note[a[i]] --;
        if(k == i-2 && k)
            note[find_(a[i], 1, 1, n)] ++;
        build(a[i]);
        ql = 1, qr = a[i];
        setting(a[i], 1, 1, n);
    }
    if(a[1] < a[2])
        note[a[1]] --;
    int cnt = -maxn;
    for(int i = 1; i <= n; i ++){
        if(cnt < note[i])
            cnt = note[i], ans = i;
    }
<<<<<<< HEAD
    /* 
=======
    /*
>>>>>>> 90197ef6c4654121ca44c7091191f31e1e751537
    for(int i = 1; i <= n; i ++)
        printf("%d ", note[a[i]]);
    puts(" ");
    */
    printf("%d", ans);
    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> 90197ef6c4654121ca44c7091191f31e1e751537
