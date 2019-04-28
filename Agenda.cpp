
#include "Agenda.hpp"
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

Lista::Lista(){
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 31; j++)
			l[i][j] = new Nodo();
	}
}
Lista::~Lista(){
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 31; j++)
		 delete l[i][j];

	}
}
Nodo::Nodo(){
	prox = (Nodo *)NULL;
	isEmpty = 1;
	compromisso = "";
}
Nodo::~Nodo(){
	delete prox;
}
void swap(Nodo *a, Nodo *b, Nodo *aprev, Nodo *bprev){
	Nodo *aux;
	bprev->prox = a;
	if(!aprev->isEmpty)
		aprev->prox = b;
	aux = a->prox;
	a->prox = b->prox;
	b->prox = aux;
}

bool removerCompromisso(int dia, int mes, int hm, Lista *lista){
	Nodo *compromissos, *aux;
	string hora;
	int h;
	bool p = true;
	compromissos = lista->l[mes-1][dia-1];
	while(!compromissos->isEmpty){
		hora.append(compromissos->compromisso.substr(0,2));
		hora.append(compromissos->compromisso.substr(3,2));
		h = stoi(hora);
		if(hm == h){
			if(p){
					lista->l[mes-1][dia-1] = compromissos->prox;
				}else{
					aux->prox = compromissos->prox;
				}
				compromissos->prox = new Nodo();
				delete compromissos;
				return true;
			}
			p = false;
			aux = compromissos;
			compromissos = compromissos->prox;
			hora = "";
		}
			return false;

}

bool temCompromisso(int dia, int mes, int hora, Lista *lista){
	Nodo *compromissos;
	int h;
	bool tem = false;
	compromissos = lista->l[mes-1][dia-1];
	if(compromissos->isEmpty){
	cout << "Voce nao tem compromisso agendado para esse dia" << endl;

		return false;
	}else{
		h = stoi(compromissos->compromisso.substr(0,2));
		while(!compromissos->isEmpty){
			h = stoi(compromissos->compromisso.substr(0,2));

			if(hora == h){
				if(!compromissos->isEmpty){
						if(!tem) cout << "Voce tem compromisso(s) agendado para esse horario:" << endl;
						cout << compromissos->compromisso << endl;
						tem = true;
					}else{
						if(tem == false){
							cout << "Voce nao tem compromisso agendado para esse horario" << endl;
							return false;
						}else{
							return true;
						}
					}
				}
				compromissos = compromissos->prox;

			}
		}
		return false;

	}





void sort(int a[], int c, Lista *lista, int m, int d){
	int auxi, menor;
	Nodo *aux, *aprev, *apdel, *aswap;
	Nodo *auxb, *bprev;
	Nodo *dia, *primeiro_horario;
	dia = lista->l[m][d];
	aux = dia;
	menor = a[0];
	auxb = dia;
	aprev = new Nodo();
	apdel = aprev;
	primeiro_horario = lista->l[m][d];
	for(int i = 0; i < c; i++){
		for(int j = i+1; j < c; j++){
			bprev = auxb;
			auxb = auxb->prox;

			if(a[j] < a[i]){
				if(menor > a[j]){
					menor = a[j];
					primeiro_horario = auxb;
				}
				auxi = a[i];
				a[i] = a[j];
				a[j] = auxi;
				swap(aux, auxb, aprev, bprev);
				aswap = aux;
				aux = auxb;
				auxb = aswap;

			}
		}
		aprev = aux;
		aux = aux->prox;
		auxb = aux;
	}
	lista->l[m][d] = primeiro_horario;
	delete apdel;
}



void organizaDia(Lista *lista, int m, int d){
	Nodo *aux, *dia;
	string comp;
	dia = lista->l[m][d];
	aux = dia;
	int c = 0;
	string hora;
	int horaInt[100];
	for(int i = 0; i<100;i++){
		horaInt[i] = 0;
	}

	while(!aux->isEmpty){
		comp = aux->compromisso;
		hora.append(comp.substr(0,2));
		hora.append(comp.substr(3,2));
		horaInt[c] = stoi(hora);
		aux = aux->prox;
		c++;
		hora = "";
		comp = "";

	}

	sort(horaInt, c, lista, m, d);

}

void organizaCalendario(Lista *lista){
	for(int i = 0; i < 12; i++){
		for(int j = 0;j < 31; j++){
			if(!lista->l[i][j]->isEmpty){
				organizaDia(lista, i, j);
			}

		}
	}
}

void inserir(string compromisso, int mes, int dia, Lista *lista){
	Nodo *aux, *waux;
	aux = lista->l[mes][dia];
		do{
			if(aux->isEmpty){
				aux->compromisso = compromisso;
				aux->prox = new Nodo();
				aux->isEmpty = 0;
				return;
			}
			waux = aux;
			aux = aux->prox;
	}while(!waux->isEmpty);
}
void insereDia(string dia, Lista *lista){
	int m = stoi(dia.substr(0,2));
	int d = stoi(dia.substr(2,2));
		string compromisso = dia.substr(4, dia.length());
  		inserir(compromisso, m-1, d-1, lista);
	
}
void imprimeAgenda(Lista *lista){
	Nodo *aux;
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 31; j++){
			aux = lista->l[i][j];
			if(aux->isEmpty == 0){
				cout << "-----------------------" << endl << "    ";
				switch (i) {
					case 0:
						cout << "##" << j + 1 << " de Janeiro" << "##" << endl << "-----------------------" << endl;
						break;

					case 1:
						cout << "##" << j + 1 << " de Fevereiro" << "##" << endl << "-----------------------" << endl;
						break;

					case 2:
						cout << "##" << j + 1 << " de Marco" << "##" << endl << "-----------------------" << endl;
						break;

					case 3:
						cout << "##" << j + 1 << " de Abril" << "##" << endl << "-----------------------" << endl;
						break;

					case 4:
						cout << "##" << j + 1 << " de Maio" << "##" << endl << "-----------------------" << endl;
						break;

					case 5:
						cout << "##" << j + 1 << " de Junho" << "##" << endl << "-----------------------" << endl;
						break;

					case 6:
						cout << "##" << j + 1 << " de Julho" << "##" << endl << "-----------------------" << endl;
						break;

					case 7:
						cout << "##" << j + 1 << " de Agosto" << "##" << endl << "-----------------------" << endl;
						break;

					case 8:
						cout << "##" << j + 1 << " de Setembro" << "##" << endl << "-----------------------" << endl;
						break;

					case 9:
						cout << "##" << j + 1 << " de Outubro" << "##" << endl << "-----------------------" << endl;
						break;

					case 10:
						cout << "##" << j + 1 << " de Novembro" << "##" << endl << "-----------------------" << endl;
						break;

					case 11:
						cout << "##" << j + 1 << " de Dezembro" << "##" << endl << "-----------------------" << endl;
						break;
				}
			}
			while(aux->isEmpty == 0){
				cout << aux->compromisso << endl;
				cout << endl;
				aux = aux->prox;
			}
		}
	}
}

void escreverParaArquivo(ofstream &file, Lista *lista){
	Nodo *aux;
	string dia, mes;
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 31; j++){
			aux = lista->l[i][j];
			while(aux->isEmpty == 0){
				if(i+1 < 10)
					mes = "0" + to_string(i+1);
				else
					mes = to_string(i+1);

				if(j+1 < 10)
					dia = "0" + to_string(j+1);
				else
				dia = to_string(j+1);

				file << mes << dia << aux->compromisso << "\n";
				aux = aux->prox;
			}
		}
	}
}
