#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,min,max,i,indmin,indmax;
printf("inserisci la dimensione n= ");scanf("%d",&n);
int v[n];
for(i=0;i<n;i++){
                 printf("v[%d]= ",i);scanf("%d",&v[i]);
                 }
min=v[1];max=v[1];
for(i=0;i<n;i++){
                 if(v[i]<min){min=v[i];indmin=i;}
                 if(v[i]>max){max=v[i];indmax=i;}
                 }
printf("\nil minimo e' %d e l'indice e' %d",min,indmin);
printf("\nil massimo e' %d e l'indice e' %d\n",max,indmax);
system("PAUSE");
return(0);     
}
