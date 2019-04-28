#ifndef Agenda
#define Agenda

#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <fstream>
using namespace std;

typedef struct Nodo{
	Nodo();
	~Nodo();
	struct Nodo *prox;
	int isEmpty;
	string compromisso;
}Nodo;


typedef struct Lista{
	Lista();
	~Lista();
	Nodo *l[12][31];
}Lista;

void imprimeAgenda(Lista *lista);

void organizaCalendario(Lista *lista);

void insereDia(string dia, Lista *lista);

void escreverParaArquivo(ofstream &file, Lista *lista);

bool temCompromisso(int dia, int mes, int hora, Lista *lista);

bool removerCompromisso(int dia, int mes, int hm, Lista *lista);

#endif
