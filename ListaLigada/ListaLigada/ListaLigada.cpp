#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista j� possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;   
	}
	else
	{
		ultimo->prox = novo;
		ultimo = novo;       
	}
}

void excluirElemento()
{
	int valorDigitado = 0, nEncontrado = 0;
	cout << "Digite o elemento: "; cin >> valorDigitado;

	if (primeiro != NULL)
	{
		NO* aux = primeiro;
		NO* anterior = NULL;

		if (valorDigitado != primeiro->valor)
		{
			while (aux != NULL)
			{
				if (aux->valor == valorDigitado)
				{
					if (anterior != NULL)
					{
						anterior->prox = aux->prox;
					}
					free(aux);
					cout << "Elemento foi removido com sucesso.\n";
					return;
				}
				anterior = aux;
				aux = aux->prox;
			}
			cout << "Elemento n�o foi encontrado :(\n";
		}
		else
		{
			primeiro = primeiro->prox;
			free(aux);
			cout << "Elemento foi removido com sucesso.\n";
		}
	}
	else
	{
		cout << "Lista vazia, cabe�a de chap�u...\n";
	}
}

void buscarElemento()
{
	int valorDigitado = 0, nEncontrado = 0;
	cout << "Digite o elemento: "; cin >> valorDigitado;

	NO* aux = primeiro;

	while (primeiro == NULL) {
		if (aux->valor == valorDigitado) {
			aux = aux->prox;
			nEncontrado++;
		}
	}
	if (nEncontrado != 0) {
		cout << "Foram encontrados " << nEncontrado << "vezes esse n�mero na lista.";
	}
	else {
		cout << "Este n�mero n�o foi encontrado na lista.";

	}
}


