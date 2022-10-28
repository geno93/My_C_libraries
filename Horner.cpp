#include<stdio.h>
#include<stdlib.h>
typedef double vettore [100];

main(){
vettore a,b;double z;int n;
printf("inserire il grado del polinomio n= ");scanf("%d",&n);
for(int i=n;i>=0;i--){
         printf("\ninserire il coefficente di grado %d del polinomio P: a[%d]= ",i,i);scanf("%lf",&a[i]);
                      }
printf("\n\ninserire il valore da inserire nel polinomio z= ");scanf("%lf",&z);
b[0]=a[n];
for(int k=1;k<=n;k++) b[k]=z*b[k-1]+a[n-k];
printf("il valore del polinomio calcolato in z e' P(z)=%lf\n\n",b[n]);
//system("PAUSE");
return 0;}
