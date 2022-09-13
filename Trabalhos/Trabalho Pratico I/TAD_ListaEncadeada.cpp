#include <iostream>
#include "TAD_ListaArranjo.hpp"

using namespace std;

bool listaCriada = false;

typedef struct Endereco {
    char numero[10];
    char rua[50];
    char bairro[50];
    char cidade[50];
    char estado[50];
};

typedef struct Funcionario{
    int id;
    char nome[50];
    Endereco endereco;
    int dependentes;
    ListaProjetos projetos;
};

typedef struct Elemento* Apontador;

typedef struct Elemento{
    Funcionario item;
    struct Elemento *prox;
};

typedef struct ListaFuncionarios{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho = 0;
};

void CriaListaVazia(ListaFuncionarios *lista)
{
        lista->primeiro = new Elemento;
        lista->ultimo = lista->primeiro;
        lista->ultimo->prox = NULL;
        listaCriada = true;
}

bool VerificaListaVazia(ListaFuncionarios *lista)
{
    return (lista->primeiro == lista->ultimo);
}

int TamanhoLista(ListaFuncionarios *lista)
{
    return lista->tamanho;
}

void AtualizaUltimo(ListaFuncionarios *lista)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    lista->ultimo = aux;
}

void InsereListaPrimeiro(ListaFuncionarios *lista, Funcionario *item)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = new Elemento;
    lista->primeiro->prox->prox = aux;
    lista->primeiro->prox->item = *item;
    lista->tamanho++;
    AtualizaUltimo(lista);
}

void InsereListaUltimo(ListaFuncionarios *lista, Funcionario *item)
{
    lista->ultimo->prox = new Elemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->prox = NULL;
    lista->ultimo->item = *item;
    lista->tamanho++;
}

void InsereListaAposElemento(ListaFuncionarios *lista, Funcionario *item, int id)
{
    Apontador aux, pAux, x;
    bool find = false;
    pAux = lista->primeiro->prox;
    while (pAux != NULL)
    {
        if (pAux->item.id == id)
        {
            find = true;
            x = pAux;
            aux = x->prox;
            x->prox = new Elemento;
            x->prox->prox = aux;
            x->prox->item = *item;
            break;
        }
        pAux = pAux->prox; /* próxima célula */
    }
    if (find)
    {
        cout << "Funcionario inserido com sucesso!";
        AtualizaUltimo(lista);
        lista->tamanho++;
    }
    else
    {
        cout << "Elemento anterior não encontrado na lista.";
    }
}

void ImprimeLista(ListaFuncionarios lista)
{
    if (VerificaListaVazia(&lista))
    {
        cout << "ListaFuncionarios vazia!\n";
        return;
    }
    Apontador aux;
    aux = lista.primeiro->prox;
    while (aux != NULL)
    {
        cout << "ID: " << aux->item.id << endl;
        cout << "Nome: " << aux->item.nome << endl
             << endl;
        aux = aux->prox;
    }
    system("pause");
}

Apontador PesquisaItem(ListaFuncionarios *lista, int id)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            return aux;
        }
        aux = aux->prox;
    }
    return aux;
}

void ImprimeItemRecebido(Funcionario funcionario) {
    cout << "ID: " << funcionario.id << endl;
    cout << "Nome: " << funcionario.nome << endl;
    cout << "Endereco: ";
    cout << funcionario.endereco.rua << "," << funcionario.endereco.numero << "," << funcionario.endereco.bairro 
         << "," << funcionario.endereco.cidade << "," << funcionario.endereco.estado << endl;
    cout << "Dependentes: " << funcionario.dependentes << endl << endl;
}

void ImprimeItemRecebidoComProjetos(Funcionario funcionario) {
    ImprimeItemRecebido(funcionario);
    cout << "Projetos" << endl;
    imprimeLista(funcionario.projetos);
}

void ImprimeContraCheque(Funcionario funcionario) {
    float horasSemanais = 0;
    for(int i = 0; i < funcionario.projetos.tamanho; i++) {
        horasSemanais += funcionario.projetos.projeto[i].horasSemanais;
    }
    float salarioBruto, inss, ir, salarioLiquido;
    salarioBruto = (45 * horasSemanais) + (35 * funcionario.dependentes);
    inss = 0.085 * salarioBruto;
    ir = 0.15 * salarioBruto;
    salarioLiquido = salarioBruto - inss - ir;

    cout << "ID: " << funcionario.id << endl;
    cout << "Nome: " << funcionario.nome << endl;
    cout << "Horas Semanais: " << horasSemanais << endl;
    cout << "Salario Bruto: R$ " << salarioBruto << endl;
    cout << "INSS: R$ " << inss << endl;
    cout << "IR: R$ " << ir << endl;
    cout << "Salario Liquido: R$ " << salarioLiquido << endl << endl;
}

void RemoveListaPrimeiro(ListaFuncionarios *lista)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}

void RemoveListaUltimo(ListaFuncionarios *lista)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }
    Apontador aux, atual;
    atual = lista->primeiro->prox;
    aux = lista->ultimo;
    while (atual->prox != lista->ultimo)
    {
        atual = atual->prox;
    }
    atual->prox = NULL;
    lista->ultimo = atual;
    delete aux;
    lista->tamanho--;
}

void RemoveItemPorId(ListaFuncionarios *lista, int id)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }

    Apontador aux, anterior, x;

    x = lista->primeiro;

    while (x != NULL)
    {
        if (x->prox->item.id == id)
        {
            anterior = x;
            break;
        }
        x = x->prox;
    }
    aux = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}

int RemoveFuncionariosSemProjetos(ListaFuncionarios *lista) {
    Apontador aux;
    int i = 0;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.projetos.tamanho == 0)
        {
            RemoveItemPorId(lista, aux->item.id);
            i++;
        }
        aux = aux->prox;
    }
    return i;
}

void DesalocaLista(ListaFuncionarios *lista) {
    Apontador aux, excluido;
    aux = lista->primeiro->prox;
    while(aux != NULL) {
        excluido = aux;
        aux = aux->prox;
        delete excluido;
    }
    delete aux;
}