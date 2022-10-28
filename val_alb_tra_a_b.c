#include <stdlib.h>
#include <stdio.h>

typedef struct albero {
	int key;
	struct albero *left;
	struct albero *right;
} albero;

albero* from_array_to_tree(int*,int,int);
void stampa_chiave(albero*,int,int);

int main() {
	int n,i,a,b;
	int*V;
	albero *A=NULL;
	printf("\nLeggi n:");
	scanf("%d",&n);
	printf("\ninserire elementi positivi e 0 per terminare il cammino\n");
	V=(int*)malloc(sizeof(int)*n);
	for (i=0; i<n; i++) 
		scanf("%d",&V[i]);
	A=from_array_to_tree(V,0,n);
	printf("\ninserire i valori a e b, a<b\n");
	scanf("%d",&a);
	scanf("%d",&b);
	stampa_chiave(A,a,b);
	printf("\n");
	return 0;
}

albero* from_array_to_tree(int *V,int start, int size) {
	albero *t;
	if (start>=size) return NULL;
	if(V[start]==0) return NULL;
	else {
		t=(albero*)malloc(sizeof(albero));
		t->key=V[start];
		t->left=NULL;
		t->right=NULL;
	}
	t->left=from_array_to_tree(V,2*start+1,size);
	t->right=from_array_to_tree(V,2*start+2,size);
	return t;
}

void stampa_chiave(albero *A,int a,int b) {
	if (A==NULL) return;
	if (A->key>=a && A->key<=b) printf("%d ",A->key);
	stampa_chiave(A->left,a,b);
	stampa_chiave(A->right,a,b);
	return;
}
