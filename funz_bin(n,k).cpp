#include<stdio.h>
#include<stdlib.h>
int leggi_intero(void);
int leggi_base(void);
double bin(int,int);
void stampa(double);

main(){
int k,n;double bino;
k=leggi_intero();
do n=leggi_base();
while(n<k);
printf("\n");
bino=bin(n,k);
stampa(bino);
system("PAUSE");
return(0);
}

int leggi_intero(void){
    int a;printf("inserire un intero positivo k= ");scanf("%d",&a);
    if(a<0){printf("\nERRORE!!");
            a=leggi_intero();}
    printf("\n");
    return a;}
    
int leggi_base(void){int k;
    int b;printf("inserire un numero maggore di %d: n= ",k);scanf("%d",&b);
    return b;}
    
double bin(int c,int d){
    double bin=1;int i;
    if(d>=c-d) {
        for(i=1;i<=c-d;i++) bin=(double(d+i)/i)*bin;  
         }
else {
        for(i=1;i<=d;i++) bin=(double(c-d+i)/i)*bin;
     }
return(bin);}

void stampa(double x){
     printf("il binomiale e' %lf\n\n",x);return ;}


    
    

