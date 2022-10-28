#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x){
return (x*x-2);}

double Df(double x){
return (2*x);}

int main(){
int a,b;double x0,x1,toll,err,max_iter,i;
//printf("inserire i valori dell'intervallo [a,b]");
//printf("\na= ");scanf("%d",&a);
//printf("b= ");scanf("%d",&b);
printf("\n\ninserire il # max di iterazioni: ");scanf("%lf",&max_iter);
printf("inserire la tolleranza: ");scanf("%lf",&toll);
printf("\n\ninserire il punto iniziale x0= ");scanf("%lf",&x0);
i=0;err=10;
while((i<max_iter)&&(err>(toll/5)))
  {i++;
   x1=x0-(f(x0)/Df(x0));
   err=fabs(x1-x0)+fabs(f(x1));
   printf("\nx%lf=%1.30lf \t f(x%lf)=%1.20lf",i,x1,i,f(x1));
   x0=x1;}
printf("\n\n");
//system("PAUSE");
return 0;
}




