#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
string name(string a, int x, string b){
    return a + to_string(x) + b;
}

void proc(int i){
    srand(time(0) + i);
    printf("%d %d %d", rand()%1000, rand()%MAXN, rand()%MAXN);
}

int main(){
    int n = 100;
    for(int i = 1; i <= n; i ++){
        string name1 = name("./A", i, ".in");
        char name2[100];
        strcpy(name2, name1.c_str());
        freopen(name2, "w", stdout);
        proc(i);
        fclose(stdout);
    }
}

