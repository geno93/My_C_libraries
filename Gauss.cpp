#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#define _CRT_SECURE_NO_WARNINGS

typedef double matrice[10][10];
typedef double vettore[10];

void leggi_mat(matrice , int&);
void leggi_vet(vettore , int);
void stampa_trmat(matrice, int);
void stampa_vett(vettore, int);
void rimonta(matrice, vettore, vettore, int);
double riduci(matrice, vettore, int); //il double e' per il determinante
double residuo(matrice, vettore, vettore, vettore, int);

int main() {
	int n; matrice A, M; vettore v, b, x, res; double error, det;
	leggi_mat(A, n);
	printf("\n\n");
	leggi_vet(b, n);
	for (int i = 0; i < n; i++) {
		v[i] = b[i];
		for (int j = 0; i < n; i++) M[i][j] = A[i][j];
	}
	det = riduci(A, b, n);
	if (det == 0) {
		printf("\n\n"); system("PAUSE");
		return 0;
	}
	printf("\n\ndet=%lf", det);
	stampa_trmat(A, n);
	printf("\n\n");
	stampa_vett(b, n);
	rimonta(A, b, x, n);
	printf("le soluzioni del sistema Ax=b sono:");
	stampa_vett(x, n);
	error = residuo(M, v, x, res, n);
	printf("\n\nnorma del residuo\n");
	stampa_vett(res, n);
	printf("\n\n");
	system("PAUSE");
	return 0;
}

void leggi_mat(matrice A, int &m){
	printf("dammi la dim del numero di righe e di colonne(<=10) n= "); scanf("%d", &m);
	for (int i = 0; i < m; i++){
		for (int y = 0; y < m; y++){
			printf("A[%d][%d]= ", i, y);
			scanf("%lf", &A[i][y]);
		}
	}
	return;
}

void leggi_vet(vettore x, int m){
	for (int i = 0; i < m; i++){ printf("b[%d]= ", i); scanf("%lf", &x[i]); }
	return;
}
	
void stampa_trmat(matrice A, int m){
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) printf("%lf\t", A[i][j]);
		printf("\n");
	}
	return;
}

void stampa_vett(vettore x, int m){
	for (int i = 0; i < m; i++) printf("x[%d]=%lf ",i,x[i]);
}

void rimonta(matrice A, vettore b, vettore c, int m){
	double s;
	c[m - 1] = b[m - 1] / A[m - 1][m - 1];
	for (int i = m - 2; i >= 0; i--){
		s = 0;
		for (int j = i + 1; j < m; j++) s += A[i][j] * c[j];
		c[i] = (b[i] - s) / A[i][i];
	}
	return;
}

double riduci(matrice A, vettore b, int m){
	double M, aux,s,det=1; int cont = 0,ind;
	for (int k = 0; k < m - 1; k++){
		M = fabs(A[k][k]); ind = k;
		for (int i = k + 1; i< m; i++) 
		if (fabs(A[i][k])>M){ M = A[i][k]; ind = i; }
		if (M == 0){ printf("ERRORE! La matrice e' singolare"); return 0; }
		if (ind>k){ cont++;
		for (int j = k; j < m; j++){ aux = A[k][j]; A[k][j] = A[ind][j]; A[ind][j] = A[k][j]; }
		aux = b[k]; b[k] = b[ind]; b[ind] = aux;
		}
		for (int i = k + 1; i < m; i++) { s = A[i][k] / A[k][k];
		for (int j = k + 1; j < m; j++) {
			A[i][j] = A[i][j] - s*A[k][j]; printf("\n\n");
		}
		b[i] = b[i] - s*b[k];
		}
	}
	for (int k = 0; k < m; k++) det = det*A[k][k];
	if (det == 0) printf("La matrice e' singolare\n\n");
	if (cont % 2 != 0) return(-det);
	else return(det);
}

double residuo(matrice A, vettore b, vettore x, vettore r, int m){
	double max;
	for (int i = 0; i < m; i++){
		r[i] = 0;
		for (int j = 0; j < m; j++)
			r[i] = r[i] + A[i][j] * x[j];
		r[i] = r[i] - b[i];
	}
	max = fabs(r[0]);
	for (int i = 0; i < m;i++) 
	if (fabs(r[i]) >= max) max = fabs(r[i]);
	return max;
}

