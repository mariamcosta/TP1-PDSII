/*
    Exercício 01 -  Agenda de Compromissos
    Grupo:  Maria Tereza  Menezes Costa - 2018092892
    		Otávio Augusto Soares Oliveira - 2018042207
*/


#include "Agenda.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;


int main(int argc, char *argv[]){
  Lista *lista = new Lista();
  ofstream ofile;
  ifstream ifile;
  string buffer;
  int input;
  string in;
  stringstream compromisso;
  int hm, dia, mes, hora;

  ifile.open(argv[1]);
  while(getline(ifile, buffer)){
      insereDia(buffer, lista);

  }
  ifile.close();
  ofile.open(argv[1], std::ofstream::out | std::ofstream::trunc);

  while(ofile.is_open()){
    organizaCalendario(lista);
    cout << "           1. Abrir a agenda" << endl;
    cout << "           2. Inserir compromisso" << endl;
    cout << "           3. Remover compromisso" << endl;
    cout << "           4. Listar compromissos" << endl;
    cout << "           5. Verificar se existe compromisso agendado" << endl;
    cout << "           6. Salvar e fechar " << endl;
    cin >> input;
	
		switch(input)
		{
	      case 1:
	        break;
	
	      case 2:
	        cout << "Insira o mes (formato 00)" << endl;
	        cin >> in;
	        compromisso << in; // mes
	        cout << "Insira o dia (formato 00)" << endl;
	   	    cin >>in;
		    compromisso << in; //dia
	    	cout << "Insira a hora (formato 24:24)" << endl;
	        cin >> in;
			compromisso << in; //hora
	   		cout << "Insira o compromisso" << endl;
	    	compromisso << " ";
			cin >> in;
			compromisso << in; //compromisso
			getline(cin, in);
			compromisso << in; //compromisso
			insereDia(compromisso.str(), lista);
			compromisso.str("");       			
	        break;
	
	      case 3:
	
	        cout << "Insira o mes" << endl;
	        cin >> mes;
	        cout << "Insira o dia" << endl;
	        cin >> dia;
	        cout << "Insira a hora e o minuto (Formato 0000)" << endl;
	        cin >> hm;
	
	        if(removerCompromisso(dia, mes, hm, lista))
	          cout << "Compromisso Removido" << endl;
	        else{
	          cout << "Voce nao tem compromisso agendado para esse horario" << endl;
	        }
	        break;
	      case 4:
	        imprimeAgenda(lista);
	        break;
	      case 5:
	      cout << "Insira o mes" << endl;
	      cin >> mes;
	      cout << "Insira o dia" << endl;
	      cin >> dia;
	      cout << "Insira a hora sem os minutos" << endl;
	      cin >> hora;
	        temCompromisso(dia, mes, hora, lista);
	        break;
	      case 6:
	        escreverParaArquivo(ofile, lista);
	        ofile.close();
	        break;
	      default:
	        break;
		}
	}


  delete lista;
  return 0;

}
