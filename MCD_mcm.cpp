#include<stdio.h>
#include<stdlib.h>
main()
{
int a,b,mcm,MCD,r,appo;
printf("inserisci il numero a= ");scanf("%d",&a);
printf("inserisci il numero b= ");scanf("%d",&b);
printf("\n\n");
if(a>b){appo=a;a=b;b=appo;}
mcm=a*b;
do {
    r=b%a;
    if(r!=0){b=a;a=r;}
    else MCD=a;
    }
while(r>0);
mcm=mcm/MCD;
printf("MCD(b,a)=%d e mcm(b,a)=%d\n\n",MCD,mcm);
system("PAUSE");
return(0);      
}
