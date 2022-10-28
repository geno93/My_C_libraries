#include<stdio.h>
#include<stdlib.h>
int main()
{
int i,j,n,m;
printf("dammi la dim del numero di righe n= ");scanf("%d",&n);
printf("\ndammi la dim del numero di colonne m= ");scanf("%d",&m);
float A[n][m],B[m][n];
for(i=0;i<n;i++){
                 for(j=0;j<m;j++){
                                  printf("A[%d][%d]= ",i,j);
                                  scanf("%f",&A[i][j]);
                                  }}
printf("\nLa trasposta e' \n");
for(i=0;i<m;i++){
                 for(j=0;j<n;j++){
                                  printf("\nB[%d][%d]=%1.0f",i,j,A[j][i]);
                                  }
                  }
printf("\n\n");                 
system("PAUSE");
return(0);  
}
