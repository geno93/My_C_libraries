#include<stdio.h>
#include<stdlib.h>

typedef struct int_bin_tree {
	int key;
	struct int_bin_tree *left;
	struct int_bin_tree *right;
	} int_bin_tree;

int_bin_tree *crea_alb(int_bin_tree *root, int n);
void stampa_preorder(int_bin_tree *root);
void print_level_m(int_bin_tree *root, int m);

int main() {
	int n, m;
	int_bin_tree *A = NULL;
	printf("inserire n > 0\n");
	scanf("%d", &n);
	A = crea_alb(A, n);
	stampa_preorder(A);
	printf("\ninserire livello da stampare\n");
	scanf("%d", &m);
	print_level_m(A, m);
	printf("\n\n");
	return 0;
}

int_bin_tree *crea_alb(int_bin_tree *root, int n){
	if(n <= 0) return NULL;
	if(root == NULL){
		root = (int_bin_tree*)malloc(sizeof(int_bin_tree));
		root->key = n;
		root->left = NULL;
		root->right = NULL;
	}
	root->left = crea_alb(root->left, (int)n/2);
	root->right = crea_alb(root->right, n - 2);
	return root;
}

void stampa_preorder(int_bin_tree *root){
	if(root == NULL) return;
	printf("%d ", root->key);
	stampa_preorder(root->left);
	stampa_preorder(root->right);
	return;
} 
	
void print_level_m(int_bin_tree *root, int m) {
	if(root == NULL) return;
	if (m == 0) 
		printf("%d ", root->key);
	print_level_m(root->left, m-1);
	print_level_m(root->right, m-1);
	return;
}
	
	
	
		
	
	
	
	
