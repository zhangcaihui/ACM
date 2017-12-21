#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn = 2333333;
struct node{
    int num;
    int jum;
    node *next;
}*a[maxn];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    /*  debug   */
    for(int i = 0; i <= n; i ++)
        a[i] = (node *)malloc(sizeof(node));
    for(int i = 0; i < n; i ++)
        a[i]->next = a[i+1];
    a[n]->next = a[1];
    /*  debug   */
    
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]->jum), a[i]->num = i;
    int cnt = n;
    node *p = a[0];
    while(cnt){
        int k = m % cnt;
        for(int i = 1; i < k; i ++){
            p = p->next;
        }
        node * tem = p->next;
        p->next = tem->next;
        m = tem->jum;
        printf("%d ", tem->num);
        cnt --;
    }
}
/*
7 20
3 1 7 2 4 8 4
*/