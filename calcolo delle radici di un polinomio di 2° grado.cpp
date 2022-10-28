#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main ()
{
float a,b,c,delta,aa,x1,x2,x,alfa,beta,s;
printf("\n\n\n a=");scanf("%f",&a);
printf("\n b=");scanf("%f",&b);
printf("\n c="),scanf("%f",&c);
delta=b*b-4*a*c; aa=2*a;
if (delta>0) 
   {x1=(-b+sqrt(delta))/aa;x2=(-b-sqrt(delta))/aa;
   printf("\n\n x1=%f",x1);
   printf("\n x2=%f\n\n",x2);}
else if (delta==0)
   {x=-b/aa;
   printf("\n\n x=%f\n\n",x);}
else  {alfa=-b/aa;s=sqrt(-delta);beta=s/aa;
   printf("\n\n x3=%f+i%f",alfa,beta);
   printf("\n x4=%f-i%f\n\n",alfa,beta);}
system("PAUSE");return 0;   
}
