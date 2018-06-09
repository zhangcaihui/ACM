#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
map<int, string> mp2;
char ch[100];
int rem[100];
int main(){
    mp["purple"] = 1; mp2[1] = "Power";
    mp["green"] = 2; mp2[2] = "Time";
    mp["blue"] = 3; mp2[3] = "Space";
    mp["orange"] = 4; mp2[4] = "Soul";
    mp["red"] = 5; mp2[5] = "Reality";
    mp["yellow"] = 6; mp2[6] = "Mind";
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%s", ch);
        string tem = ch;
        rem[mp[tem]] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= 6; i ++){
        if(!rem[i]) cnt ++;
    }
    printf("%d\n", cnt);
    for(int i = 1; i <= 6; i ++){
        if(!rem[i])
            cout << mp2[i] << endl;
    }
}
