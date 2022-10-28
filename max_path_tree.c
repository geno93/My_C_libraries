#include <stdlib.h>
#include <stdio.h>

typedef struct albero {
	int key;
	struct albero *left;
	struct albero *right;
} albero;

albero* from_array_to_tree(int*,int,int);
int max_val_cam(albero*);
int max(int,int);

int main() {
	int n,i,s;
	int*V;
	albero *A=NULL;
	printf("\nLeggi n:");
	scanf("%d",&n);
	printf("\ninserire elementi positivi e 0 per terminare il cammino\n");
	V=(int*)malloc(sizeof(int)*n);
	for (i=0; i<n; i++) 
		scanf("%d",&V[i]);
	A=from_array_to_tree(V,0,n);
	s=max_val_cam(A);
	printf("\n%d\n",s);
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

int max_val_cam(albero *A) {
	if (A==NULL) return 0;
	if ((A->left==NULL) && (A->right==NULL)) return A->key;
	return max(A->key+max_val_cam(A->left),A->key+max_val_cam(A->right));
}

int max (int a,int b) {
	if (a>b) return a;
	else return b;
}
	
	
	
