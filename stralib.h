

// stralib.h - header file per stralib.cpp

#define MAX_DIM 30
#define EPSILON 1e-6
#define MAX 500
#define DEBUGGING
#define IS_LINUX

double f(double x);
double eps();
int fatt(int n);
int fibo(int n);
double modulo(double x);
int parteintera(double n);
double pot(double a, int b);
double rad(double a);
double nepero();
double pi();
void divisori(int n, int& cont, int (&div)[MAX_DIM]);
bool primo(int n);
double logaritmo(double x);
double coseno(double x);
double seno(double x);
void toBinary(int n, int& k, int (&r)[MAX_DIM]);
void toDecimal(int& n, int cifre, int (&r)[MAX_DIM]);
void Bubblesort(int n, double (&v)[MAX_DIM]);
double Hoerner(int k, double (&a)[MAX_DIM], double x, double y);
double NormaVett(int n, double (&v)[MAX_DIM]);
double NormaEu(int n, double (&v)[MAX_DIM]);
double NormaMax(int m, int n, double (&A)[MAX_DIM][MAX_DIM]);
int MCD(int n, int (&numero)[MAX_DIM]);
int mcm(int n, int (&numero)[MAX_DIM]);
double prodScalare(int n, double (&a)[MAX_DIM], double (&b)[MAX_DIM]);
void prodMatriceVett(int m, int n, double (&A)[MAX_DIM][MAX_DIM], double (&b)[MAX_DIM], double (&p)[MAX_DIM]);
void prodMatrici(int m, int n, int l, double (&A)[MAX_DIM][MAX_DIM], double (&B)[MAX_DIM][MAX_DIM], double (&C)[MAX_DIM][MAX_DIM]);
void SwapRow(int ncol, int k0, int k1, double (&A)[MAX_DIM][MAX_DIM]);
void SwapRowGauss(int j, int max, int n, double (&a)[MAX_DIM][MAX_DIM], double (&b)[MAX_DIM]);
int FindMaxIndex(int jStart, double (&a)[MAX_DIM][MAX_DIM], int n);
void ZeroColumn(int j, int n, double (&a)[MAX_DIM][MAX_DIM], double (&b)[MAX_DIM]);
void SolveGauss(int n, double (&a)[MAX_DIM][MAX_DIM], double (&b)[MAX_DIM], double (&x)[MAX_DIM]);
void Gauss(int n, double (&A)[MAX_DIM][MAX_DIM], double (&b)[MAX_DIM], double (&x)[MAX_DIM]);
void Jacobi(int n, double (&A)[MAX_DIM][MAX_DIM], double (&b)[MAX_DIM], double (&x)[MAX_DIM]);
void DumpA(int n, double (&a)[MAX_DIM][MAX_DIM]);
void GetMatrix(int m, int n, double (&a)[MAX_DIM][MAX_DIM]);
void GetData(int& m, int& n, double (&a)[MAX_DIM][MAX_DIM], double (&b)[MAX_DIM]);
void GetVett(int,double (&a)[MAX_DIM]);
double CoefficienteBinomiale(int n, int k);
double MediaAritm(int n, double (&x)[MAX_DIM]);
double MediaGeom(int n, double (&x)[MAX_DIM]);
double MediaArm(int n, double (&x)[MAX_DIM]);
double MediaQuad(int n, double (&x)[MAX_DIM]);
//void Grafico();
double Bisezione(double a, double b);
//double Corde(double a, double b);
//double Newton(double a, double b);
double Secante(double a, double b);
double Falsi(double a, double b);
double PuntoMedio(int n, double a, double b);
double Trapezio(int n, double a, double b);
double Simpson(int n, double a, double b);
void Attesa();
