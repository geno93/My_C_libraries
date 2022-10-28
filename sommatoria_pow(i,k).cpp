#include <stdio.h>
#include <stdlib.h>
main()
{
int k,n,i,p=1,somma=1,q;
printf("dammi un numero intero k=");scanf("%d",&k);
printf("\ndammi un numero intero n=");scanf("%d",&n);
for(i=2;i<=n;i++)
{{for(q=1;q<=k;q++)
     p=p*i;}somma=somma+p;p=1;}
printf("la somma e' s=%d\n\n",somma);
system("PAUSE");
return(0);          
}
