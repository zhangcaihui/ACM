//KMP
/*
 f 数组为失配数组，P 数组为给定数组，T 数组为待匹配数组
 */

void find(char T[], char P[], int f[]){
    int n = strlen(T), m = strlen(P);
    getfail(P, f);
    int j = 0;
    for(int i = 0; i < n; i ++){
        while(j && P[j] != T[i]) j = f[j];
        if(P[j] == T[i]) j ++;
        if(j == m) printf("%d\n",i-m+1);
    }
}

void getfail(char P[], int f[]){
    int m = strlen(P);
    f[0] = 0; f[1] = 0;
    for(int i = 1; i < m; i ++){
        int j = f[i];
        while(j && P[i] != P[j]) j = f[j];
        f[i+1] = (P[i] == P[j]) ? j+1 : 0;
    }
}

