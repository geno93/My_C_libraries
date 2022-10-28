#include<stdio.h>
#include<stdlib.h>
main()
{
int N,i,j,min;
double t;
do {printf("dammi un intero positivo N= ");scanf("%d",&N);}
while(N<0);
printf("\n\n");
double a[N];
for(i=0;i<N;i++)
   {printf("a[%d]= ",i);scanf("%lf",&a[i]);}
// ordinameto(selection sort)
for(i=0;i<N-1;i++) {
    min=i;
    for(j=i+1;j<N;j++)
        if(a[j]<a[min])
           min=j;
     t=a[min];a[min]=a[i];a[i]=t;
     }
printf("\n\nvettore riordinato\n");
for(i=0;i<N;i++)
    printf("a[%d]=%lf\t",i,a[i]); 
printf("\n\n");
system("PAUSE");
return(0);    
}
