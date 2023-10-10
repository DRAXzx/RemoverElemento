#include <iostream>

using namespace std;

struct No {
	int dado;
	No* proximo;
	No(int valor) : dado(valor), proximo(NULL) {}
};

int contarNos(No* head) {
	int contador = 0;
	No* atual = head;
	while (atual != NULL) {
		contador++;
		atual = atual->proximo;
	}
	return contador;
} 
void deleteLista(No*& head, int valorParaExcluir) {
    No* atual = head;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->dado == valorParaExcluir) {
            if (anterior == NULL) {
                head = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            No* temp = atual;
            atual = atual->proximo;
            delete temp;
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

int main() {
	No* head = new No(1);
	head->proximo = new No(2);
    head->proximo->proximo = new No(3);
    head->proximo->proximo->proximo = new No(4);
    head->proximo->proximo->proximo->proximo = new No(5);
    
    int tamanho = contarNos(head);
    
    cout << "O tamanho da lista é: " << tamanho << endl;
    
    int valorParaExcluir;
    cout << "Digite o valor do elemento que deseja excluir: ";
    cin >> valorParaExcluir;
    
    deleteLista(head, valorParaExcluir);
    tamanho = contarNos(head);
    cout << "O tamanho da lista após a exclusão é: " << tamanho << endl;
    
      while (head != NULL) {
        No* temp = head;
        head = head->proximo;
        delete temp;
    }

    
    return 0;
}
