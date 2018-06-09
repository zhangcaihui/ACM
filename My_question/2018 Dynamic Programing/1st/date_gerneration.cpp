#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
string name(string a, int x, string b){
    return a + to_string(x) + b;
}

void proc(int i){
    srand(time(NULL)+i);
    int n = rand() % 100000;
    printf("%d %d", n, rand() % 10000);
    for(int i = 1; i <= n; i ++){
        printf("%d ", rand() % 10000);
    }
}

int main(){
    int n = 100;
    for(int i = 1; i <= n; i ++){
        string TM1 = name("./A", i, ".in");
        char nam1[100];
        strcpy(nam1, TM1.c_str()); 
        freopen(nam1, "w", stdout);
        proc(i);
        fclose(stdout);
    }
}


