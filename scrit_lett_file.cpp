#include<stdio.h>
#include<stdlib.h>
#include<math.h>

main(){
       int n=3;
       double v[n],x[n];
       for(int i=0;i<n;i++) {printf("\nv[%d]= ",i);scanf("%lf",&v[i]);}
       FILE *fv,*fb;
       fv=fopen("vettori.dat","w+");
       for(int i=0;i<n;i++)
           fprintf(fv,"%lf  ",v[i]);
       fclose(fv);
       fb=fopen("vettori.dat","r+");
       for(int i=0;i<n;i++)
           fscanf(fb,"%lf",&x[i]);
       fclose(fb);
       printf("\n\n");
       for(int i=0;i<n;i++) printf("\nx[%d]=%lf",i,x[i]);
       printf("\n\n");
       system("PAUSE");
       return 0;
       }
