#include <stdlib.h>
#include <stdio.h>

typedef struct int_list {
	int key;
	struct int_list *next;
} int_list;

int_list* insert(int_list *, int_list**, int);    //crea lista
void stampa_lista(int_list*);

int main () {
	int val;
	int_list *L = NULL, *temp = NULL;
	printf("inserire elementi positivi della lista L:  (-1 per terminare)\n");
	do {
		scanf("%d", &val);
		if (val > 0)
			L = insert(L, &temp , val);
		}while (val > 0);
	stampa_lista(L);
	printf("\n\n");
	return 0;
	}
	
int_list* insert(int_list *head, int_list **temp, int x){
		int_list *p;
		p = (int_list*)malloc(sizeof(int_list));
		p->key = x;
		p->next = NULL;		
		if(head == NULL) {
			head = p;
			*temp = head;
		}else{
			(*temp)->next = p;
			*temp = p;
		}		
		return head;
	}

void stampa_lista(int_list *head){
	int_list *p;
	p = head;
	while(p != NULL){
		printf("%d -> ", p->key);
		p = p->next;
		if(p == NULL) printf("NULL");
	}
	return;
} 
	
	
	
