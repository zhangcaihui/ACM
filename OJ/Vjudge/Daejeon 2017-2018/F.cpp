#include<cstdio>
using namespace std;
int ax, ay;
int rem[][2] = {{1, 1}, {1, 2}, {2, 2}, {2, 1}};
void dfs(int h, int num){
    if(h == 1){
        ax = rem[num][0];
        ay = rem[num][1];
        return ;
    }
    int k, tmp;
    k = (num-1)/(1<<(h-1));
    tmp -= k * (1<<(h-1));
    k ++;
    dfs(h-1, tmp);
    int siz = 1 << (h-1);
    if(k == 1){
        ax = siz - ax;
        ay = siz - ay;
    }
    else if(k == 2){
        ay += siz;
    }
    else if(k == 3){
        ax += siz;
        ay += siz;
    }
    else{
        int tem = ax;
        ax = ay;
        ay = tem;
        //ax ^= ay ^= ax ^= ay;
        ax += siz;
    }
}
int pp[15];
int main(){
    int num, h;
    pp[0] = 1;
    for(int i = 1; i < 17; i ++)
        pp[i] = pp[i-1] * 2;
    scanf("%d%d", &h, &num);
    for(int i = 1; i <= 16; i ++){
        if(h == pp[i]){
            h = i;
            break;
        }
    }
    dfs(h, num);
    printf("%d %d", ax, ay);
}
