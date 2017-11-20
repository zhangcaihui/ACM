#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
int a[4], x, ff;
struct node{
    int aa[4];
    friend bool operator < (node xp, node yp){
        for(int i = 0; i < 3; i ++){
            if(xp.aa[i] == yp.aa[i])
                continue;
            else
                return xp.aa[i] < yp.aa[i];
        }
        return 0;
    }
};
map<node, int> mp;
queue<node> q;
void proc(){
    for(int i = 0; i < 3; i ++)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    
    node tem;
    tem.aa[0] = a[0];
    tem.aa[2] = tem.aa[1] = 0;
    q.push(tem);
    mp[tem] = 1;
    
    
    while(!q.empty() && !ff){
        node uu = q.front(); q.pop();
        int tim = mp[uu];
        
        /* debug  
        for(int i = 0; i < 3; i ++){
            printf("%d ", uu.aa[i]);
        }
        printf("--->%d\n", tim - 1);
         */
        
        
        for(int i = 0; i < 3; i ++)
            if(uu.aa[i] == x)
                ff = tim;
        
        for(int i = 0; i < 3; i ++){
            tem = uu;
            tem.aa[i] = a[i];
            if(mp[tem])
                continue;
            mp[tem] = tim + 1;
            q.push(tem);
        }
        
        for(int i = 0; i < 3; i ++){
            tem = uu;
            tem.aa[i] = 0;
            if(mp[tem])
                continue;
            mp[tem] = tim + 1;
            q.push(tem);
        }
        int xx, yy;
        for(int i = 0; i < 3; i ++)
            for(int j = 0; j < 3; j ++){
                if(i == j)
                    continue;
                tem = uu;
                xx = tem.aa[i], yy = tem.aa[j];
                tem.aa[j] = a[j] < (xx + yy) ? a[j] : xx + yy;
                tem.aa[i] = a[j] < (xx + yy) ? xx + yy - a[j] : 0;
                if(mp[tem])
                    continue;
                mp[tem] = tim + 1;
                q.push(tem);
            }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        mp.clear();
        while(!q.empty()){
            q.pop();
        }
        ff = 0;
        proc();
        if(ff)
            printf("%d\n", ff - 1);
        else
            printf("NO\n");
    }
    
}

