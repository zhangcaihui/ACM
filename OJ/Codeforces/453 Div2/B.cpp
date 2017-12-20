#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 1001010;
vector<int> v[maxn];
int note[maxn];
int cal(int col, int p){
    int ans = 0, k = v[p].size();
    if(col != note[p])
        ans ++;
    for(int i = 0; i < k; i ++){
        ans += cal(note[p], v[p][i]);
    }
    return ans;
}
int main(){
    int n, x;
    scanf("%d", &n);
    for(int i = 2; i <= n; i ++){
        scanf("%d", &x);
        v[x].push_back(i);
    }
    for(int i = 1; i <= n; i ++)
        scanf("%d", &note[i]);
    printf("%d", cal(0, 1));
}
