#include<stdio.h>
#include<stdlib.h>
typedef double vettore[100];
double f(double x){
      return(x*x-2);}

main(){
double a,b,h;vettore x,y;int n;
printf("inserire l'intervallo [a,b] nel quale plottare la funzione:\n");
printf("a= ");scanf("%lf",&a);printf("b= ");scanf("%lf",&b);
printf("\ninserire il valore per la suddivisione dell'intervallo: n= ");scanf("%d",&n);
h=(b-a)/n;
for(int i=0;i<=n;i++) {x[i]=a+i*h;y[i]=f(x[i]);}
FILE *f1,*f2;
f1=fopen("valorif.dat","w+");
for(int i=0;i<=n;i++) fprintf(f1," %lf\t%lf\n",x[i],y[i]);
fclose(f1);
f2=fopen("file.cmd","w+");
fprintf(f2,"plot \"valorif.dat\" w l");
fclose(f2);
system("gnuplot -persist file.cmd");
return 0;}
