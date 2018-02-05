#include<cstdio>
using namespace std;

bool check(int x, int y){
    if(x % 10 == 7 || x / 10 == 7)
        return false;
    if(y % 10 == 7 || y / 10 == 7)
        return false;
    return true;
}

int main(){
    int x, a, b;
    scanf("%d%d%d", &x, &a, &b);
    int cnt = 0;
    while(check(a, b)){
        cnt ++;
        b -= x;
        if(b < 0){
            b += 60;
            a --;
        }
        if(a < 0){
            a += 24;
        }
    }

    printf("%d", cnt);
}