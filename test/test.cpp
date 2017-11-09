#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1001010;
int note[maxn][2], n, stardand_;
vector<int> v[maxn];
void dfs(int x){
    for(int i = 0; i < 2; i ++){
        if(note[v[x][i]][i])
            continue;
        note[v[x][i]][i] = 1;
        dfs(v[x][i]);
        printf("%d", i);
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
        stardand_ |= (1<<i);
    for(int i = 0; i <= stardand_; i ++){
        v[i].push_back((i<<1) & stardand_);
        v[i].push_back(((i<<1) & stardand_) + 1);
    }
    dfs(0);
}
