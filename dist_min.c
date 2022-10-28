#include <stdlib.h>
#include <stdio.h>

int distanza_min(int*, int*, int, int);

int main () {
	int *A, *B, n, m, i = 0;
	A=(int*)malloc(sizeof(int)*10);
	B=(int*)malloc(sizeof(int)*10);
	scanf("%d",&A[i]);
	while(A[i] != -1) {
		i++;
		//A=(int*)realloc(A,i+1);
		scanf("%d",&A[i]);
	}
	n = i;
	i = 0;
	scanf("%d",&B[i]);
	while(B[i] != -1) {
		i++;
		//B=(int*)realloc(B,i+1);
		scanf("%d",&B[i]);
	}
	printf("SONO UN COGLIONE \n");
	m = i;
	printf("%d\n",distanza_min(A, B, n, m));
	printf(" volte");
	return 0;
}

int distanza_min(int *A, int *B, int n, int m) {
	int i, j = 0, s = 0, min;
	if(n == m) {
		for(i = 0; i < n; i++) {
			if(B[i] > A[i]) 
				s = s + B[i] - A[i];
			else 
				s = s + A[i] - B[i];
		}
		return s;
	}
	if(m > n) {
		int appo;
		int *app;
		appo = n;
		n = m;
		m = appo;
		app = A;
		A = B;
		B = app;
	}
	if(n > m) {
		min = n * 10;
		while ( j < n - m + 1) {
			s = 0;
			for(i = 0; i < m; i++)	{
				if(B[i] > A[i + j]) 
					s = s + B[i] - A[i + j];
				else 
					s = s + A[i + j] - B[i];
			}
			s = s + (n - m) * 10;
			if (s < min)
				min = s;
			j = j + 1;
			}
		return min ;
	}
}
								
	
	
	
		
		
		
		
		
		
