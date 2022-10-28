#include<stdio.h>
#include<stdlib.h>
int main()
{
int i,k,y,j,n,p,s;float app;
printf("dammi la dim del numero di righe e di colonne n= ");scanf("%d",&n);
float A[n][n],B[n][n];
for(i=0;i<n;i++){
                 for(y=0;y<n;y++){
                                  printf("A[%d][%d]= ",i,y);
                                  scanf("%f",&A[i][y]);
                                  }}
for(i=0;i<n;i++){
                 for(y=0;y<n;y++)
                          B[i][y]=A[i][y];}
do{printf("\ndammi un j (0<=j<%d) j= ",n);scanf("%d",&j);}
while((j>=n)||(j<0));
do
 {printf("dammi un k(!=j) (0<=k<%d) k= ",n);scanf("%d",&k);}
while((k<0)||(k>=n));
printf("\nscelta operazione: 1- scambia la riga j-ma con la k-ma\
                                             2- scambia la colonna j-ma con la k-ma\n");
//do {
    scanf("%d",&p);
    switch(p){
              case 1: for(i=0;i<n;i++)
                           {app=B[j][i];B[j][i]=B[k][i];B[k][i]=app;}
                      break;
              case 2: for(i=0;i<n;i++)
                           {app=B[i][j];B[i][j]=B[i][k];B[i][k]=app;}
                      break;
              default:printf("ERRORE! Scegliere l'operazione giusta tra 1 e 2\n");
                      break;}
                      //}
//while((p!=1)||(p!=2));    
printf("\nla matrice di partenza e':\n");
for(i=0;i<n;i++)
      for(y=0;y<n;y++) printf("A[%d][%d]=%1.0f\n",i,y,A[i][y]);
printf("\nla matrice dopo l'operazione e':\n");
for(i=0;i<n;i++)
      for(y=0;y<n;y++) printf("B[%d][%d]=%1.0f\n",i,y,B[i][y]);
printf("\n\n");
system("PAUSE");
return(0);
} 
