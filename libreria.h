#include<stdio.h>
#include<stdlib.h>
#define max 100					//la dimensione di tutti gli array creati a inizio funzioni
#define min 1.e-14				//la precisioni delle funzioni che ne fanno uso
#define nep 2.71828182845904523536028747	//nepero, utile per esponenziali logaritmi e radici ennesime
#define pi  3.14159265358979323846264338	//pigreco utile per coseno, seno e forse altro
typedef double vettore[max];
typedef double matrice[max][max];

/*in tutte le funzioni ordine variabili che vengono passate alla funzione, con il rispettivo nome accanto,
a parità di tipo messe in ordine alfabetico:
matrici, vettori, numeri qualsiasi, numeri usati come contatori...
infine nelle void che devono modificare vettori o matrici per ultimo il vettore o la matrice
su cui restituire il risultato
*/

void invio(int); 		 	                //stampa n invii
void leggip(vettore,char,int);		//legge un polinomio
int leggima(matrice,char,int);		        //legge una matrice chiedendo numero righe e colonne
void leggim(matrice,char,int,int); 	        //legge una matrice nxm
void leggimq(matrice,char,int);		        //legge matrice quadrata
void triangolsup(matrice,char,int,int);                                                   // DA VERIFICARE PER LE MATRICI QUADRATE
void stampam(matrice,char,int,int);         //stampa una matrice
void stampama(matrice,char,int,int);        //stampa a tabella una matrice
void stampamaq(matrice,char,int);	        //stampa a tabella una matrice quadrata
void leggiv(vettore,char,int);  	        //legge un vettore dimensione n
void stampav(vettore,char,int); 	        //stampa un vettore classico
void stampave(vettore,char,int);	        //stampa un vettore riga
int leggin(char);			                //legge un intero
void stampan(int,char);			            //stampa un numero intero
double leggilf(char);		    	        //legge un double
void stampalf(double,char);	    	        //stampa un double
double potenza(double,int);	    	        //eleva a potenze intere un double
double fatt(int);		        	        //calcola il fattoriale di un numero
double modlf(double);	    		        //fa il valore assoluto di un double
double normam(vettore, int);                //trova norma del massimo di un vett
double scalare(vettore,vettore,int);        //prodotto scalare tra 2 vettori
double rad(double);			                //radice quadrata di un numero algoritmo con metodo babilonese
double normae(vettore,int);		            //norma euclidea di un vettore
void LAq(matrice,vettore,int,vettore);	    //prodotto matrice quadrata per un vettore
double bil(vettore,matrice,vettore,int);    //forma bilineare vettore trasposto matrice vettore
void matr(matrice,matrice,int,matrice);	    //prodotto tra matrici quadrate
void combim(matrice,matrice,int,double,matrice);	//combinazione lineare di matrici quadrate
double numeri10(int,int);		            //trasforma ogni numero dalla base 10 a una base a scelta<10
double numerib(int,int,int);		        //trasforma ogni numero da una base a qualsiasi altra minore di 10
double binario(int);			            //trasforma da base 10 a sistema binario
void somma(vettore,vettore,vettore,int);    //somma array
double esp(double);			                //esponenziale qualsiasi preciso taylor e giochetti potenze di 2
double radn(double,int);		            //radice ennesima con qualsiasi indice intero
double logs(double);			            //logaritmo sfruttando i multipli di nep e giochetto radice
void stampall(double,char);		            //stampa col %.16lf per avere piu' cifre
double potenze(double,double);		        //potenza con indice qualsiasi anche fratto
int mcd(int,int);			                //trova il massimo comune divisore tra 2 numeri int naturalmente
int mcm(int,int);	                //trova il minimo comune multiplo sfruttando il massimo comune divisore
void azzerav(vettore,int);		            //azzera tutte le componenti del vettore
void azzeram(matrice,int,int);		        //azzera tutte le componenti della matrice
void scambiav(vettore,vettore,int);	        //scambia le componenti di due vettori
void combir(matrice,int,int,int,double);    //fa combinazioni lineari di righe
/*
 *il primo int e' per il numero di colonne,
 *gli altri due int sono per indicare le
 *due righe da combinare la prima viene
 *moltiplicata per il double scritto alla
 *fine e sommata alla seconda
 */

void scambiar(matrice,int,int,int);	        //come la precedente ma lei scambia le due righe indicate
void scambiac(matrice,int,int,int);	        //come la precedente ma lei scambia le due colonne indicate
void aggv(matrice,vettore,int,int);	        //sostituisce a colonna un vettore int come sopra
void scalav(vettore,int,double);	        //moltiplica ogni componente di v per il double
int pivot(matrice,int,int);		        //cerca l'indice della riga con pivot maggiore nella colonna
void clear();					//pulire il terminale
double resto(double,double);			//calcola il resto tra due double utile per funzioni periodiche
double sen(double);				//seno con taylor
double cos(double);				//coseno con taylor
void copiav(vettore,int,vettore);			//copia un vettore nell'altro
double horner(vettore,int,double);			//calcola il valore del polinomio in x0
void hornerd(vettore,int,double,vettore);	//calcola il polinomio quoziente di x-x0
double derivata(vettore,int,double);		//calcola il valore della derivata di un polinomio con horner
double derivata2(vettore,int,double);		//calcola derivata seconda di un polinomio con horner
void matrice1(matrice,int);			//trasforma la matrice in quella unità di ordine n
int diag(matrice,int,int);		            //diagonalizza matrici l'int e' utile per determinante
void diag1(matrice,int);			//per l'inversa prima parte
void diag2(matrice,int,int);			//per l'inversa seconda parte
void copiam(matrice,int,int,matrice);		//copia una matrice in una altra
double det(matrice,int);			//calcola il determinante usando diag
void trasposta(matrice,int,int,matrice);	//traspone una matrice qualsiasi e la salva in un'altra
void trasponiq(matrice,int);		//traspone una matrice quadrata e la salva in se stessa
/*void capovolgi(matrice,int);		//inverte l'ordine delle righe di una matrice da n in poi
void trasformamq(matrice,int);		//rende utilizzabile di nuovo diag su una matrice per ricavare l'inversa
*/
void affianca(matrice,int,matrice);	//affianca a una matrice quadrata un altra dello stesso ordine
void lambda(matrice,int);		//questa divide tutti gli elementi di ogni riga per i rispettivi pivot
int inversa(matrice,int,matrice);		//inverte una matrice quadrata
void calcola(matrice,vettore,int,vettore);	// calcola le soluzioni e le salva nell'ultimo vettore
void gauss(matrice,vettore,int,vettore); //risolve un sistema di equazioni,il risultato nell'ultimo vettore
double newton1(vettore,int);	 		//metodo di newton per 1 radice del polinomio
void newton(vettore,int,vettore);	//salva nel secondo vettore le n-1 radici del polinomio
double diagonaledominante(matrice A, int n);	//calcola lambda per jacobi 
void jacobi(matrice,vettore,int,vettore);	//jacobi vero e proprio	
//torniamo a piazzare un main nel mezzo
/*
main()
{vettore b; int n;vettore a;
n=leggin('n');
leggip(b,'b',n);
newton(b,n,a);
stampave(a,'a',n);
return 0;
}
*/
//stampa \n
void invio(int k)
{
    for(int i=0;i<k;i++){
        printf("\n");
    }
}

//legge un polinomio
void leggip(vettore a,char m, int k)
{
    for(int i=k;i>=0;i--){
        printf("inserisci il coefficiente di grado %d del polinomio %c",i,m);
		scanf("%lf",&a[i]);
		invio(1);
    }
}

//legge prima numero righe e numero colonne e poi legge attraverso l'altro la matrice
/*int leggima(matrice a,char m,int b)  //come si stampa(da non usare)
{
    int k,t;
    invio(1);
    printf("quante righe m e colonne n ha la matrice %c?",m);
    do{
        k=leggin('m');
    }while(k>max or k<=0);
    do{
        t=leggin('n');
    }while(k>max or k<=0);
    leggim(a,m,k,t);
    if(b==1){       //non capisco il perche
        return k;       leva il commento nel caso
    }else if(b==2){
        return t;
    }else{ 
        return 0;
    }
}*/

//leggi matrice   OK
void leggim(matrice a,char m, int k,int t)
{
    for(int i=0;i<k;i++){
        for(int j=0;j<t;j++){
            invio(1);
            printf("inserisci la componente  %c[%d][[%d] della matrice %c: ",m,i,j,m);
            scanf("%lf",&a[i][j]);
        }
    }
}

//leggi matrice quadrata    OK
void leggimq(matrice a,char m,int k)
{
    leggim(a,m,k,k);
}

//stampa matrice   OK
void stampam(matrice a,char m, int k,int t)
{
    for(int i=0;i<k;i++)
        for(int j=0;j<t;j++){
            invio(1);
            printf("la componente %c[%d][%d] della matrice %c e': %g",m,i,j,m,a[i][j]);
        }
    }

//stampa matrice a forma di matrice    OK(da usare)
void stampama(matrice a,char m,int k,int t)
{
    printf("\nle componenti della matrice %c sono:\n",m);
	for(int i=0;i<k;i++){
	    invio(1);
	    for(int j=0;j<t;j++){
            printf("%lg ",a[i][j]);
        }
	}
	invio(2);
}

//stampa matrice quadrata usando la funzione precedente    OK
void stampamaq(matrice a,char m,int k)
{
    stampama(a,m,k,k);
}

//leggi vettore   OK
void leggiv(vettore a,char m, int k)
{
    for(int i=0;i<k;i++){
        printf("inserisci la componente %c[%d] del vettore %c= ",m,i,m);
		scanf("%lf",&a[i]);
    }
}

//stampa vettore   OK
void stampav(vettore a,char m, int k)
{
    for(int i=0;i<k;i++){
        invio(1);
        printf("la componente %c[%d] del vettore %c e': ",m,i,m);
		printf("%lg ",a[i]);
    }
}

//stampa vettore riga    OK
void stampave(vettore a,char m, int k)
{
    invio(1);
    printf("\nle componenti del vettore %c sono:  ( ",m);
    for(int i=0;i<k;i++){
        printf("%lg ",a[i]);
    } 
    printf(" )\n");
}

//legge interi    OK
int leggin(char m)
{
    int a;
     invio(1);
     printf("inserisci il numero intero %c= ",m);
     scanf("%d",&a);
     return a;
}

//stampa numeri interi    OK
void stampan(int a,char m)
{
    invio(1);
    printf("%c vale: %d",m,a);
}

//legge double     OK
double leggilf(char m)
{
    double a;
    invio(1);
    printf("inserisci il numero %c= ",m);
    scanf("%lf",&a);
    return a;
}
//stampa numeri doppia precisione     OK
void stampalf(double a,char m)
{
    invio(1);
    printf("%c vale: %lg",m,a);
    invio(1);
}

//eleva a potenze negative o positive  OK
double potenza(double a,int b)
{
    double c;if(b==0) return 1;if(a==0) return 0;
    c=1.;
    if(b<0){
        a=1./a;
        b=-b;
    }else{
        ;
    }
	for(int i=0;i<b;i++){
	    c=a*c;
    }
        return c;
}

//fattoriale di numeri interi positivi   OK
double fatt(int a)
{
    double b=1,c=modlf(a);
    if(a==0 or a==1){
        return 1;
    }
    while(c>1){
        b=c*b;
        c--;
    }
    if(a>0){
        return b;
    }else{
        return -b;
    }
}

//calcola il modulo di variabili double    OK
double modlf(double a)
{
    if(a>=0){
        return a;
    }else{
        return -a;
    }
}

//norma del massimo   OK
double normam(vettore a,int k)
{
    int j=0;
    for(int i=1;i<k;i++){
        if(modlf(a[i])>modlf(a[j])){
            j=i;
        }
    }
    return modlf(a[j]);
}

//prodotto scalare   OK
double scalare(vettore a,vettore b, int k)
{
    double s=0;
    for(int i=0;i<k;i++){
        s=s+(b[i]*a[i]);
    }
    return s;
}

//radice quadrata di un numero   OK
double rad(double a)
{
    int i=0,k=1;
    if(a<0){
        k=0;
    }
    double c=modlf(a);
    a=c;
    do{
        c=(c+(double(a)/c))/2;
        i++;
    }while(modlf(c*c-a)>min and i<50);
    if(k){
        return c;
    }else{
        return -c;
    }
}

//norma euclidea     OK
double normae(vettore a, int k)
{
    return rad(scalare(a,a,k));
}

//matrice quadrata per vettore     OK
void LAq(matrice a, vettore b, int k, vettore c)
{
    for(int i=0;i<k;i++){
        c[i]=0;
        for(int j=0;j<k;j++){
            c[i]=c[i]+a[i][j]*b[j];
        }
    }
}

//forma bilineare, vettore trasposto per matrice per altro vettore        OK
double bil(vettore x,matrice a,vettore y, int k)
{vettore z;
    LAq(a,y,k,z);
    return scalare(x,z,k);
}

//matrice per matrice quadrate   OK
void matr(matrice a,matrice b,int k,matrice c)
{
    for(int n=0;n<k;n++){
        for(int i=0;i<k;i++){
            c[n][i]=0;
            for(int j=0;j<k;j++){
                c[n][i]=c[n][i]+a[n][j]*b[j][i];
            }
        }
    }
}

//combinazione lineare di matrici
void combim(matrice a,matrice b,int k,double m,matrice c)
{
	for(int i=0;i<k;i++) for(int j=0;j<k;j++) c[i][j]=a[i][j]+m*b[i][j];
}

//sistemi numerazione da base 10 all'altra
double numeri10(int a,int c)
{
    double d=0;
    int k=1,b;
    if(c==10){
        return a;
    }
    while(a){
        b=a%c;
        a=a/c;
        d=d+k*b;
        k=k*10;
    }
    return d;
}

//sistemi di numerazione da base qualsiasi a qualsiasi passando per base 10
double numerib(int a,int b,int c)
{
    double d=0;
    int k=1;
    int e;
    while(a){
        e=a%10;
        a=a/10;
        d=d+k*e;
        k=k*b;
    }
    return numeri10(d,c);
}

//trasforma numeri da base 10 a sistema binario
double binario(int a)
{
    return numeri10(a,2);
}

//somma array sotto forma di vettori
void somma(vettore a,vettore b,vettore c,int k)
{
    for(int i=0;i<k;i++){
        c[i]=a[i]+b[i];
    }
}

//calcolano l'esponenziale con taylor con un trucchetto grazie alle proprietà esponenziali e potenze di due
double esp(double a)
{
    double b,c,e,d;
    int f,k=1,j=2,i=0;
    int z=0; if(a<0) {z=1;a=1./a;}
    f=int(a)/1;a=a-f;
    b=potenza(nep,f);
    c=1;
    if(a==0){
        if(z) return 1./b; return b;
    }
    while(a>0.05){
        a=a/2;
        i++;
    }
    d=a;
    do{
        e=c;
        c=c+d/k;
        k=k*j;
        d=d*a;
        j++;
    } while(modlf(c-e)>min);
    a=potenza(c,int(potenza(2,i)));
    if(z) return 1./a*b;return a*b;
}

//radice ennesima non molto preciso
double radn(double a,int n)
{
    int c=1, j=0;
    double b;
    if(n%2==0){
        while(c<n){
            j++;
            c=potenza(2,j);
            if(n%c==0 and n/c==1)
            {
                for(int i=0;i<j;i++){
                    a=rad(a);
                }
            return a;
            }
        }
    }
    b=1./n;return potenze(a,b);
}

//logaritmo strano, ma preciso, stranamente preciso
double logs(double a)
{
    int j=0;
    int l=0;
    while(esp(l)<a){
        l++;
    }
    l--;
    a=a/potenza(nep,l);
    double c=10;
    double d=0;
    int k=1;
    if(a>1.5){
        a=1./a;
        k=0;
    }
    while(a<0.90){
        a=rad(a);
        j++;
    }
    for(int i=1;modlf(c-d)>min and i<max;i++){
        c=a;
        d=d-(potenza(1-a,i)/double(i));
    }
	if(k==0){
	    d=-d;
	}
    return l+d*potenza(2,j);
}

//stampa fino alla 16cifra i double
void stampall(double a,char m)
{
    invio(1);
    printf("%c vale:",m);
    printf("%16lf ",a);
    invio(1);
}

//potenze ad esponente qualsiasi
double potenze(double a,double b)
{
    int d=int (b)/1;
    if(b-d==0){
        return potenza(a,d);
    }
    double c;
    c=b*logs(a);
    return esp(c);
}

//Massimo comune divisore
int mcd(int a,int b)
{
    int r,c;
    if(a<b){
        c=a;
        a=b;
        b=c;
    }
    r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

//minimo comune multiplo
int mcm(int a,int b)
{
    int c,d;
    c=mcd(a,b);
    d=(a/c)*(b/c)*c;
    return d;
}

//azzera un intero vettore
void azzerav(vettore a,int k)
{
    for(int i=0;i<=k;i++){
        a[i]=0;
    }
}
//azzera  intera matrice
void azzeram(matrice a,int k,int m)
{
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            a[k][m]=0;
        }
    }
}
//inserisce in ogni componente del vettore a quelle di b e viceversa
void scambiav(vettore a,vettore b,int k)
{
    double c;
    for(int i=0;i<k;i++){
        c=a[i];
        a[i]=b[i];
        b[i]=c;
    }
}

//fa una combinazione lineare di righe moltiplica per uno scalare la riga con indice b e la somma a quella c
//dove k è il numero di colonne che ci interessa siano combinate
void combir(matrice a,int k,int b,int c,double m)
{
    for(int i=0;i<k;i++){
        a[c][i]=a[c][i]+m*a[b][i];
    }
}

//scambia due righe, k ci dice fino a quale colonna b e c sono gli indici delle righe da scambiare
void scambiar(matrice a,int k,int b,int c)
{
    double d;
    for(int i=0;i<k;i++){
        d=a[c][i];
        a[c][i]=a[b][i];
        a[b][i]=d;
    }
}
//scambia due colonne, k ci dice fino a quale riga e b e c sono gli indici delle colonne da scambiare
void scambiac(matrice a,int k,int b,int c)
{
    double d;
    for(int i=0;i<k;i++){
        d=a[i][c];
        a[i][c]=a[i][b];
        a[i][b]=d;
    }
}
//inserisce al posto della colonna c il vettore b fino alla riga k
void aggv(matrice a,vettore b,int k,int c)
{
    for(int i=0;i<k;i++)
        a[i][c]=b[i];
    }
//prodotto vettore per uno scalare
void scalav(vettore a,int k,double c)
{
    for(int i=0; i<k;i++){
        a[i]=c*a[i];
    }
}
//cerca pivot, gli si passa il numero di righe,l'indice della colonna in cui cercare e da quale riga in poi restituisce l'indice della riga con il valore maggiore
int pivot(matrice a,int k,int b)
{
    int j=b;
    for(int i=b;i<k;i++){
        if(modlf(a[b][j])<modlf(a[b][i])){
            j=i;
        }
    }
    return j;
}

//pulisce il terminale
void clear()
{system("clear");
}

//resto tra numeri double
double resto(double a,double b)
{double s=int(a)%1; s=a-s;s=s+int(a)%int(b); return s;}

//seno grazie a taylor
double sen(double a)
{
    double s;int k=0,c=1;a=double(a)/2;
    if(a<0) {a=-a;c=-c;}
    a=resto(a,360);
    if(a>180) {a=a-180;c=-c;}
    if(a>90) {a=a-180;c=-c;}
    s=0;a=double(a)/180*pi;
    
if(a>pi) {a=a-pi;c=-c;}
    if(a>1) {a=a-pi;c=-c;}
    
    do
    {s=s+potenza(-1,k)*potenza(a,2*k+1)/fatt(2*k+1);k++;
}
	while(1./fatt(2*k+1)>min); return c*s;

}

//coseno grazie a taylor
double cos(double a)
{double s;int k=0,c=1;a=double(a)/2;
    a=modlf(a);
    a=resto(a,360);
    if(a>180) {a=a-180;c=-c;}
    if(a>90) {a=a-180;c=-c;}
    s=0;a=double(a)/180*pi;
        do
    {s=s+potenza(-1,k)*potenza(a,2*k)/fatt(2*k);k++;}
    while(1./fatt(2*k)>min); return c*s;
}
//fa la copia esatta del polinomio o vettore da 0 a n compresi
void copiav(vettore a, int n, vettore b)
{for(int i=0;i<=n;i++) b[i]=a[i];
}
//calcola il valore di un polinomio in x0 usando horner
double horner(vettore a,int k,double b)
{double y=a[k];
	for (int i=k-1; i>=0; --i)
              y=b*y+a[i]; return y;}
//calcola il polinomio ottenuto dividendo per x-z il polinomio precedente
void hornerd(vettore a,int k,double z,vettore b)
{vettore c;int j;copiav(a,k,c);
	b[k-1]=c[k];
	for(int i=k-1;i>=0;i--) b[i-1]=z*b[i]+c[i]; 
}
//derivata di un polinomio
double derivata(vettore a,int n,double x)
{vettore b;copiav(a,n,b);
hornerd(b,n,x,b);return horner(b,n-1,x);
}
//derivata seconda di un polinomio
double derivata2(vettore a,int n,double x)
{vettore b;copiav(a,n,b);
hornerd(b,n,x,b);hornerd(b,n-1,x,b);return horner(b,n-2,x);
}
//trasforma una matrice nella matrice unità
void matrice1(matrice a,int k)
{azzeram(a,k,k);for(int i=0;i<k;i++) a[i][i]=1; 
}
//dovrebbe diagonalizzare una matrice di n righe e l colonne
int diag(matrice a,int n,int l)
{
    int z=1,r;double m;
    for(int k=0;k<n-1;k++)
{
	r=pivot(a,n,k);if(k!=r) {z=-z;scambiar(a,l,r,k);}
	for(int i=k+1;i<n;i++)
{
if(a[k][k]!=0) m=double(a[i][k])/a[k][k];else if(a[k][k]==0) m=0;
	for(int j=k;j<l;j++) a[i][j]=a[i][j]-m*a[k][j];
}
}return z;
}
//usa quella di sopra per inversa
void diag1(matrice a,int n)
{int i=diag(a,n,2*n);
}
//diagonalizza in alto per l'inversa
void diag2(matrice a,int n)
{double m;
for(int k=n-1;k>0;k--)
	for(int i=k-1;i>=0;i--)
	{m=a[i][k];
		for(int j=n;j<2*n;j++) a[i][j]=a[i][j]-m*a[k][j];}
}
//copia una matrice in un'altra
void copiam(matrice a,int n,int k,matrice b)
{for(int i=0;i<n;i++) for(int j=0;j<k;j++) b[i][j]=a[i][j];}
//determinante
double det(matrice a,int n)
{double c;matrice b;int z;copiam(a,n,n,b);
z=diag(b,n,n);c=1;c=c*z;
for(int i=0;i<n;i++) c=c*b[i][i]; return c;
}
//trasposta matrice qualsiasi usando copiam
void trasposta(matrice a,int n,int k,matrice b)
{matrice c;copiam(a,n,k,c);
for(int i=0;i<n;i++) for(int j=0;j<k;j++) b[i][j]=c[j][i];
}
//trasposta matrici quadrate
void trasponiq(matrice a,int n)
{trasposta(a,n,n,a);
}
/*
//capovolge la matrice accanto a quella quadrata di cui si sta facendo l'inversa
void capovolgi(matrice a,int n)
{matrice b; copiam(a,n,2*n,b);
for(int i=0;i<n;i++) for(int j=n;j<2*n;j++) a[i][j]=b[n-i][j];
}
//trasforma una matrice per rendere possibile la seconda parte di invertirla
void trasformamq(matrice a,int n)
{vettore b;for(int i=0;i<=n/2;i++) scambiar(a,n,i,n-i);for(int i=0;i<=n/2;i++) scambiac(a,n,i,n-i);
}*/
//affianca a una matrice quadrata un'altra matrice quadrata
void affianca(matrice a,int n,matrice b)
{vettore c;
for(int i=0;i<n;i++) {for(int j=0;j<n;j++) c[j]=b[i][j];
	aggv(a,c,n,n+i);}
}
//divide ogni termine della matrice su ogni riga per i rispettivi elementi della diagonale principale serve per l'inversa
void lambda(matrice a,int n)
{double m;
for(int i=0;i<n;i++){m=a[i][i];for(int j=0;j<2*n;j++) a[i][j]=double(a[i][j])/m;} 
}
//inverte una matrice quadrata invertibile usando diag e capovolgi e trasformamq
int inversa(matrice a,int n,matrice b)
{int i=0;if(modlf(det(a,n))<min) {printf("\nla matrice non e' invertibile\n");i=1;}
matrice1(b,n);affianca(b,n,b);
copiam(a,n,n,b);
diag1(b,n);lambda(b,n);diag2(b,n);
for(int j=0;j<n;j++)for(int k=0;k<n;k++) b[j][k]=b[j][k+n];
return i;
}
//calcola le soluzioni del sistema reso triangolare superiore
void calcola(matrice a,int n,vettore c)
{double s;
	c[n-1]=a[n-1][n]/a[n-1][n-1];
 for (int i=n-2;i>=0;i--)
		{s=0.0;
	  for (int j=i+1;j<n;j++)
	       s=s+a[i][j]*c[j];
               c[i]=double(a[i][n]-s)/a[i][i];}}   	                       	 
//gauss non modifica la matrice iniziale ma trova le soluzioni del sistema di equazioni
void gauss(matrice a,vettore b,int n,vettore c)
{int i;matrice d;
copiam(a,n,n,d);
aggv(d,b,n,n);i=diag(d,n,n+1);calcola(d,n,c);
}
//newton per trovare una radice di un polinomio
double newton1(vettore x,int n)
{int i=0,j=0;double b,c,d,e,f;vettore a;copiav(x,n,a);
c=horner(a,n,i);e=horner(a,n,-i);if(c==0) return 0;
do{i++;
b=horner(a,n,i);
d=horner(a,n,-i);
if(c*b<=0) j=1; 
if(d*e<=0) j=2;
	f=b;b=c;c=f;
	f=d;d=e;e=f;
if(i==max*max) {invio(5);printf("il polinomio di grado %d non ha radici reali ignora gli altri output",n);invio(5);return 0;}
}while(j==0);
if(j==1) {b=horner(a,n,i)*derivata2(a,n,i);if(b>0) c=i;else if(b<0) c=i-1;else if(b==0) return i;}
if(j==2) {b=horner(a,n,-i)*derivata2(a,n,-i);if(b>0) c=-i;else if(b<0) c=1-i;else if(b==0) return -i;}
d=c;
do {c=c-double(horner(a,n,c))/derivata(a,n,c);b=c;c=d;d=b;} while(modlf(horner(a,n,b))>min);return double(d+b)/2;
}
void newton(vettore a,int n,vettore b)
{double c;vettore d;copiav(a,n,d);int k=n;
do{c=newton1(d,n);hornerd(d,n,c,d);n--;b[n]=c; 
if(n<k-1)
	if(b[n+1]!=0)
		if(b[n]==0) 
			{for(int ii=n-1;ii>=0;ii--) b[ii]=0;return;}
}

while(n>0);
}
//calcola lambda per jacobi e restituisce 0 se non e' a diagonale dominante
double diagonaledominante(matrice A, int n)
{
       double sum, lambda = 0.0;
		

       for (int i = 0; i < n; ++i)
               {
                   sum = 0.0;
                   for (int j = 0; j < n; ++j)
					   if (i != j)
						   sum = sum + modlf(A[i][j]);
				   sum = sum / modlf(A[i][i]);
				   if (lambda < sum)
					   lambda = sum;
               }
		if (lambda<1)
	   return lambda;
		return 0;
}
//jacobi identico a gauss per entrate e uscite 
void jacobi(matrice A, vettore b,int n, vettore x)
{
	int k = 0;
	double rho, s;double lambda=diagonaledominante(A,n);
		if(lambda==0) {printf("\n\nla matrice non e'a  diagonale dominante\n\n");return;}
	bool have_rho = false;
	for (int i = 0; i < n; ++i)
		x[i] = 0.0;
	do {
		for (int i = 0; i < n; ++i)
		{
			s = 0.0;
			for (int j = 0; j < n; ++j)
				if (j != i)
					s = s + x[j] * A[i][j];
			x[i] = (b[i] - s) / A[i][i];
		}
		if (!have_rho)
		{
			rho = logs(min * (1 - lambda) / normae(x,n)) / logs(lambda);
			have_rho = true;
		}
	} while (++k <= rho);
}

void triangolsup(matrice b,char m,int k,int t) {
     for(int i=0;i<k;i++)
             for(int j=i;j<t;j++){
            invio(1);
            printf("inserisci la componente  %c[%d][[%d] della matrice %c: ",m,i,j,m);
            scanf("%lf",&b[i][j]);
        }
     for(int i=1;i<k;i++)
             for(int j=0;j<i;j++)
                   b[i][j]=0;
     return;
     }  

