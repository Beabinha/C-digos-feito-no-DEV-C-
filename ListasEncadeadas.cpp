#include <iostream>
using namespace std;
/*
	Criado por Beatriz Almeida
	03/11/2020
	beatrizdealmeida1997@gmail.com
*/
struct noLista {
	int chave;
	noLista *ant, *prox;
};

struct Lista {
	noLista *ultimo, *proxUltimo;
};

// Inicializa a lista
void inicializaLista(Lista &L) {
	L.ultimo = NULL;
	L.proxUltimo = NULL;
}

// Verifica se a lista esta vazia ou não
bool listaVazia(Lista L) {
	return L.ultimo == NULL;
}

// Faz uma busca na lista
noLista *buscaLista(Lista L, int x) {
	noLista *aux;

	if (listaVazia(L)) {
		aux = NULL;
	} else {
		aux = L.ultimo->prox;
		while (aux != L.ultimo && aux->chave != x) {
			aux = aux->prox;
		}

		if (aux->chave != x) {
			aux = NULL;
		}
	}
	return aux;
}
// Imprima a Lista
void imprimeLista(Lista L) {
	if (listaVazia(L)) {
		cout << "\nLista vazia: \n";
	} else {
		cout << "Lista de elementos: ";
		noLista *aux = L.ultimo->prox;

		while (aux != L.ultimo) {
			cout << aux->chave << " ";
			aux = aux->prox;
		}
		cout << aux->chave << "\n";
	}
}

// Insere na Lista no Inicio
void insereInicio(Lista &L, int x) {
	noLista *novo = new noLista();

	if (novo == NULL) {
		cout << "\nOVERFLOW!\n";
	} else {
		novo->chave = x;
		if (listaVazia(L)) {
			L.ultimo = novo;
			novo->prox = novo;
			novo->ant = novo;
		} else {
			novo->prox = L.ultimo->prox;
			L.ultimo->prox = novo;
			novo->prox->ant = novo;
			novo->ant = L.ultimo;
		}
	}
}

// Insere na Lista no Final
void insereFim(Lista &L, int x) {
	noLista *novo = new noLista();

	if (novo == NULL) {
		cout << "\nOVERFLOW!\n";
	} else {
		novo->chave = x;
		if (listaVazia(L)) {
			L.ultimo = novo;
			novo->prox = novo;
			novo->ant = novo;
		} else {
			novo->prox = L.ultimo->prox;
			L.ultimo->prox = novo;
			novo->prox->ant = novo;
			novo->ant = L.ultimo;
			L.ultimo = novo;
		}
	}
}

// Insere de forma ordenada
void insereOrdenado(Lista &L, int x) {
	if (listaVazia(L) || x <= L.ultimo->prox->chave) {
		insereInicio(L, x);
	} else if (x >= L.ultimo->chave) {
		insereFim(L, x);
	} else {
		noLista *novo = new noLista();
		if (novo == NULL) {
			cout << "\nOVERFLOW!\n";
		} else {
			novo->chave = x;
			noLista *aux = L.ultimo->prox;
			while (x <= aux->prox->chave) {
				aux = aux->prox;
			}
			novo->prox = aux->prox;
			aux->prox = novo;
			novo->prox->ant = novo;
			novo->ant = aux;
		}
	}
}

noLista *removeLista(Lista &L, int x) {
	noLista *no = NULL;
	if (listaVazia(L)) {
		cout << "\nUNDERFLOW!\n";
	} else if (x == L.ultimo->prox->chave) {
		no = L.ultimo->prox;
		if (no == L.ultimo) {
			L.ultimo = NULL;
		} else {
			L.ultimo->prox = no->prox;
			no->prox->ant = L.ultimo;
		}
		delete no;
	} else {
		noLista *aux = L.ultimo->prox;
		while (aux->prox != L.ultimo && aux->prox->chave != x) {
			aux = aux->prox;
		}
		if (aux->prox->chave == x) {
			no = aux->prox;
			aux->prox = no->prox;
			no->prox->ant = aux;
			delete no;
		}
	}
	return no;
}

int main() {
	Lista L1,L2,L3;

	inicializaLista(L1);
	inicializaLista(L2);


	insereInicio(L1, 10);
	insereInicio(L1, 20);
	insereInicio(L1, 30);
	insereInicio(L1,15);
	insereFim(L1,20);
	insereOrdenado(L1,16);

	imprimeLista(L1);
	imprimeLista(L2);
	
	
	
	cout << "\n\n";

	return 0;
}
