#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
int n,i;float Ma=0,Mg=1,Mq=0,Mh=0;
printf("inserisci la dimensione n= ");scanf("%d",&n);
int v[n];
for(i=0;i<n;i++){
                 printf("v[%d]= ",i);scanf("%d",&v[i]);
                 }
for(i=0;i<n;i++){
                 Ma+=v[i];
                 Mg*=v[i];
                 Mq+=v[i]*v[i];
                 Mh=1./v[i];
                 }
Ma=Ma/n;Mg=pow(Mg,1./n);Mq=sqrt(Mq/n);Mh=n/Mh;
printf("\nla media aritmetica e' %f",Ma);
printf("\nla media geometrica e' %f",Mg);
printf("\nla media quadratica e' %f",Mq);
printf("\nla media armonica e' %f\n",Mh);
system("PAUSE");
return(0);
}
