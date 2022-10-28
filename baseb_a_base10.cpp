#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
int m,b,i;float v[10],n=0;
printf("base (2<=b<=9) b= ");scanf("%d",&b);
printf("\ndammi il numero di cifre m(<=10)= ");scanf("%d",&m);
printf("dammi le componenti(<%d) del numero di %d cifre\n",b,m);
for(i=0;i<m;i++)
  {scanf("%f",&v[i]);n=n+v[i]*(pow(b,m-i-1));}
printf("\n\nil numero trasformato e' %f \n\n",n);
system("PAUSE");
return(0);      
}
