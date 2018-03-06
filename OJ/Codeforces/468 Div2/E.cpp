<<<<<<< HEAD
=======

>>>>>>> c09e62f8537447e660b424d0b22337af1e8d45e7
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ASC(char x){ return x - 'a';}
<<<<<<< HEAD
int rem[28][5100][28], cnt[28];
char ch[5100];
double ans = 1;
=======
double rem[28][5010][28], cnt[28];
char ch[5100];
double ans;
>>>>>>> c09e62f8537447e660b424d0b22337af1e8d45e7
int main(){
    scanf("%s", ch+1);
    long int len = strlen(ch+1);
    for(int i = 1; ch[i]; i ++){
<<<<<<< HEAD
        cnt[ASC(i)] ++;
        for(int j = 1; j < len; j ++){
            int posi = i + j;
            if(i+j>len){
                posi -= len;
            }
            rem[ASC(ch[i])][j][ASC(ch[posi])] ++;
        }
    }
    for(int i = 0; i < 'z' - 'a'; i ++){
        int tem = 5100;
        double tmp = 1;
        for(int j = 1; j < len; j ++){
            int posi = i + j;
            if(posi > len)
                posi -= len;
            double cal = 0;
            for(int k = 0; k < 'z' - 'a'; k ++){
                int rec = rem[ASC(ch[i])][j][k];
                if(!rec)
                    continue;
                cal += (double)(rec - 1) / (rec);
            }
            tmp = min(tmp, cal);
        }
        ans -= tmp;
    }
    printf("%.8f", ans);
}
=======
        cnt[ASC(ch[i])] ++;
        for(int j = 1; j < len; j ++){
            int posi = i + j;
            if(i+j>len)
                posi -= len;
            rem[ASC(ch[i])][j][ASC(ch[posi])] ++;
        }
    }
    for(int i = 0; i < 26; i ++){
        double tmp = 0;
        double a = cnt[i] / len;
        for(int j = 1; j < len; j ++){
            double tem = 0;
            for(int k = 0; k < 26; k ++){
                if(rem[i][j][k] != 1)
                    continue;
                tem += a / cnt[i];
            }
            tmp = max(tmp, tem);
        }
        ans += tmp;
    }
    printf("%.8f", ans);
}
>>>>>>> c09e62f8537447e660b424d0b22337af1e8d45e7
