for(k=0;k<n;k++){
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(A[i][j]>(A[i][k]+A[k][j])){
                A[i][j]=A[i][k]+A[k][j];
                path[i][j]=k;
            }
}

