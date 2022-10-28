#include<stdio.h>
#include<stdlib.h>
int main()
{
int i,n,k,a;
double bin=1;
printf("inserire il numero intero k= ");scanf("%d",&k);
do {
    printf("\ninserire un numero maggiore di %d n= ",k);
    scanf("%d",&n);}
while(k>n); 
if(k>=n-k) {
        for(i=1;i<=n-k;i++) bin=(float(k+i)/i)*bin;  
         }
else {
        for(i=1;i<=k;i++) bin=(float(n-k+i)/i)*bin;
     }
printf("\n\nil binomiale e' bin(%d,%d)=%lf\n",n,k,bin);
system("PAUSE");
return(0);
}
