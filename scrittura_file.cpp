#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double t)
 {return (sin(t)*cos(t));}
 
main () {
     double x,y,a=1,b=6;
     int n=200;
     double h=(b-a)/n;
     FILE *fp;
     fp=fopen("tabella.dat","a");
     for(int i=0;i<=n;i++) {
             x=a+i*h; y=f(x);
             fprintf(fp," %lf   %lf\n",x,y);}
     fclose(fp);
     system("PAUSE");
     return 0;
     }
