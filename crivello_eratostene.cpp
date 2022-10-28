#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
int N;
do
{printf("dammi un numero positivo N= ");scanf("%d",&N);}
while(N<=0);
int v[N+1],cont=0,i,j;
for(i=1;i<=N;i++)v[i]=i;
for(i=2;i<=sqrt(N);i++)
    {if(v[i]!=0) {
                 printf("%d\t",i);cont++;
                 for(j=2*i;j<=N;j+=i) v[j]=0;}}
for(i=sqrt(N)+1;i<=N;i++)
    {if(v[i]!=0){printf("%d\t",i);cont++;}}
printf("\n\ni numeri primi inferiori a %d sono %d\n\n",N,cont);
system("PAUSE");
return(0);
}
