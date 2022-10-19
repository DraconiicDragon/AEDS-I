#ifndef PILHA_H
#define PILHA_H

#include "TAD_PilhaArranjo.cpp"

struct Item;
struct Pilha;

bool criaPilhaVazia(Pilha* pilha);
bool verificaPilhaVazia(Pilha* pilha);
bool verificaPilhaCheia(Pilha* pilha);
bool empilha(Pilha* pilha, Item item);
Item desempilha(Pilha* pilha);
void imprimePilha(Pilha pilha);
int getTamanho(Pilha* pilha);

#endif PILHA_H