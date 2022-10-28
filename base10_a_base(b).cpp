#include<stdio.h>
#include<stdlib.h>
main()
{
int n,b,i,ind,v[10];
printf("numero in base 10 n= ");scanf("%d",&n);
printf("\nnuova base (2<=b<=9) b= ");scanf("%d",&b);
ind=0;
while(n>0)
      {v[ind]=n%b;n=n/b;ind++;}
printf("il numero in base b e' ");
for(i=ind-1;i>=0;i--)
    printf("%d",v[i]);
printf("\n\n");
system("PAUSE");
return(0);      
}
