#include<stdio.h>
#include<stdlib.h>
typedef float matrice [10][10];
void leggi_matrice(matrice,int&);
void copia_matrice(matrice,matrice,int);//forse serve &
int leggi_intero(void);
char scelta_operazione(matrice,int,int,int);
void scambia_riga(matrice,int,int,int);
void scambia_colonna(matrice,int,int,int);
void stampa_matrice(matrice,int);
main()
{
int n,j,k,p;matrice A,B;char operazione;
leggi_matrice(A,n);
copia_matrice(A,B,n);
do j=leggi_intero();
while((j>=n)||(j<0));
do k=leggi_intero();
while((k<0)||(k>=n));
operazione=scelta_operazione(B,j,k,n);
printf("\nperazione %d\n",operazione);
printf("\nla matrice di partenza e':\n");
stampa_matrice(A,n);
printf("\nla matrice dopo l'operazione e':\n");
stampa_matrice(B,n);
printf("\n\n");
system("PAUSE");
return(0);
}
void leggi_matrice(matrice C,int&m){ //nel caso sostituire con A
     printf("dammi la dim del numero di righe e di colonne(<=10) n= ");scanf("%d",&m);
     for(int i=0;i<m;i++){
                 for(int y=0;y<m;y++){
                                  printf("A[%d][%d]= ",i,y);
                                  scanf("%f",&C[i][y]);
                                  }}
     return;}
     
void copia_matrice(matrice C,matrice B,int m){
     for(int i=0;i<m;i++){
          for(int y=0;y<m;y++)
                 B[i][y]=C[i][y];}
     return;}
     
int leggi_intero(){
    int p;
    printf("\ndammi un p (0<=p<n) p= ");scanf("%d",&p);
    return(p);}
    
char scelta_operazione(matrice C,int l,int d,int m){
     int p; char stringa;
     printf("\nscelta operazione: 1- scambia la riga j-ma con la k-ma\
                                             2- scambia la colonna j-ma con la k-ma\n");
     scanf("%d",&p);
     switch(p){
               case 1:scambia_riga(C,l,d,m);stringa=1;break;
               case 2:scambia_colonna(C,l,d,m);stringa=2;break;
               default:printf("ERRORE");stringa=scelta_operazione(C,l,d,m);break;}
     return (stringa);}
     
void scambia_riga(matrice C,int l,int d,int m){
     float app;
     for(int i=0;i<m;i++)
     {app=C[l][i];C[l][i]=C[d][i];C[d][i]=app;} 
     return;}
     
void scambia_colonna(matrice C,int l,int d,int m){
     float app;
     for(int i=0;i<m;i++)
     {app=C[i][l];C[i][l]=C[i][d];C[i][d]=app;} 
     return;}
     
void stampa_matrice(matrice C,int m){
     for(int i=0;i<m;i++)
      for(int y=0;y<m;y++) printf("A[%d][%d]=%1.0f\n",i,y,C[i][y]); 
      return;}    
