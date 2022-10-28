#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int val;
	struct lista* next;
} lista;

lista* crea_lista(lista*);
void stampa_lista(lista*);
lista* fondi_liste(lista*,lista*);
lista* dividi_lista(lista**);

int main()
{
	lista* lista_a = NULL;
	lista* lista_b = NULL;
	lista* lista_res = NULL;
	
	printf("Inserisci valori per lista a (-1 per terminare)\n");
	lista_a = crea_lista(lista_a);

	printf("Inserisci valori per lista b (-1 per terminare)\n");
	lista_b = crea_lista(lista_b);

	stampa_lista(lista_a);
	stampa_lista(lista_b);

	lista_res = fondi_liste(lista_a, lista_b);

	printf("\nLista unica di elementi ordinati:");
	stampa_lista(lista_res);

	lista* lista_pari = NULL;
	lista* lista_dispari = NULL;

	lista_dispari = dividi_lista(&lista_res);

	printf("\nLista di elementi pari:");
	stampa_lista(lista_res);

	printf("\nLista di elementi dispari:");
	stampa_lista(lista_dispari);
}

lista* crea_lista(lista* lista_a)
{
	int x;
	lista* last_elem;
	
	while(1)
	{
		scanf("%d", &x);
		if(x == -1) break;

		lista* elem = malloc(sizeof(lista));
		elem->val = x;
		elem->next = NULL;
		
		if(lista_a == NULL)
		{
			last_elem = elem;
			lista_a = elem;
		}
		else
		{
			last_elem->next = elem;
			last_elem = elem;
		}
	}

	return lista_a;
}

void stampa_lista(lista* lista_a)
{
	printf("\n");

	if(lista_a == NULL)
	{
		printf("NULL\n");
		return;
	}

	int first_element = 1;
	
	while(lista_a != NULL)
	{
		if(first_element)
		{
			printf("%d",lista_a->val);
			first_element = 0;
		}
		else
			printf(" -> %d",lista_a->val);

		lista_a = lista_a->next;
	}

	printf(" -> NULL\n");
}

lista* fondi_liste(lista* lista_a, lista* lista_b)
{
	if(lista_a == NULL)
		return lista_b;
	if(lista_b == NULL)
		return lista_a;

	lista* lista_c;
	lista* lista_res;

	if(lista_a->val <= lista_b->val)
	{
		lista_res = lista_a;
		lista_c = lista_a;
		lista_a = lista_a->next;
	}
	else
	{
		lista_res = lista_b;
		lista_c = lista_b;
		lista_b = lista_b->next;
	}
	
	while(lista_a != NULL || lista_b != NULL)
	{
		if(lista_a == NULL)
		{
			lista_c->next = lista_b;
			lista_c = lista_b;
			lista_b = lista_b->next;

			continue;
		}
		
		if(lista_b == NULL)
		{
			lista_c->next = lista_a;
			lista_c = lista_a;
			lista_a = lista_a->next;

			continue;
		}
		
		if(lista_a->val <= lista_b->val)
		{
			lista_c->next = lista_a;
			lista_c = lista_a;
			lista_a = lista_a->next;
		}
		else
		{
			lista_c->next = lista_b;
			lista_c = lista_b;
			lista_b = lista_b->next;
		}
	}
	
	return lista_res;
}

lista* dividi_lista(lista** lista_ordinata)
{
	lista* lista_pari = NULL;
	lista* lista_dispari = NULL;

	lista* lista_pari_head = NULL;
	lista* lista_dispari_head = NULL;

	//la lista ordinata inizia con elemento pari
	if((*lista_ordinata)->val % 2 == 0)
	{
		lista_pari_head = *lista_ordinata;
		lista_pari = *lista_ordinata;

		while(lista_pari->next != NULL)
		{
			if(lista_pari->next->val % 2 == 0)
				lista_pari = lista_pari->next;
			else
				break;
		}
		//tutti gli elementi della lista sono pari
		if(lista_pari->next == NULL)
		{
			*lista_ordinata = lista_pari_head;
			return NULL;
		}
		else
		{
			lista_dispari_head = lista_pari->next;
			lista_dispari = lista_pari->next;
		}
	}
	//la lista ordinata inizia con elemento dispari
	else
	{
		lista_dispari_head = *lista_ordinata;
		lista_dispari = *lista_ordinata;

		while(lista_dispari->next != NULL)
		{
			if(lista_dispari->next->val % 2 == 1)
				lista_dispari = lista_dispari->next;
			else
				break;
		}
		//tutti gli elementi della lista sono dispari
		if(lista_dispari->next == NULL)
		{
			*lista_ordinata = NULL;
			return lista_dispari_head;
		}
		else
		{
			lista_pari_head = lista_dispari->next;
			lista_pari = lista_dispari->next;
		}
	}

	//completo le liste

	lista* lista_temp = lista_pari;

	while(lista_temp->next != NULL)
	{
		if(lista_temp->next->val % 2 == 0)
		{
			lista_pari->next = lista_temp->next;
			lista_pari = lista_temp->next;
		}
		else
		{
			lista_dispari->next = lista_temp->next;
			lista_dispari = lista_temp->next;
		}
		
		lista_temp = lista_temp->next;
	}
	lista_pari->next = NULL;
	lista_dispari->next = NULL;

	*lista_ordinata = lista_pari_head;
	return lista_dispari_head;
}