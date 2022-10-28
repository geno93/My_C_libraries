#include<stdio.h>
#include<stdlib.h>
int main()
{
int i,k=0,j,n;
printf("dammi la dim del numero di righe e di colonne n= ");scanf("%d",&n);
float A[n][n],a[n];
for(i=0;i<n;i++){
                 for(j=0;j<n;j++){
                                  printf("A[%d][%d]= ",i,j);
                                  scanf("%f",&A[i][j]);
                                  }}
for(i=0;i<n;i++){
                 a[i]=0;
                 for(j=0;j<i;j++) 
                       a[i]=a[i]+A[i][j];
                 for(j=i+1;j<n;j++)
                       a[i]=a[i]+A[i][j];}

for(i=0;i<n;i++)
      {printf("\na[%d]=%1.0f\n",i,a[i]);if(a[i]>=A[i][i]) k++;}
if(k==0) printf("\nla matrice e' diagonalmente dominante\n\n");
else printf("\nla matrice NON e' diagonalmente dominante\n\n");
system("PAUSE");
return(0);
}
