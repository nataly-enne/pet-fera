#include "pet_fera.h"

int main(){
	// int *data = new int[3];
	// data[0] = 2;
	// data[1] = 3;
	// data[2] = 4;
	// ANIMAL *A1 = new ANFIBIO(1,"anfibio","adsf",'f',2.9,"der","ver","der","Nataly",2,data);
	// cout << A1->getId() << endl;
	// 	int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, int mudas, int* data);

	int op;
	// int id, idade, nivel;
	// long int cpf;
	// string nome;
	// char tipo, fator;
	string especialidade, crmv;
	vector <ANFIBIO> anfibios;
	vector <MAMIFERO> mamiferos;
	vector <REPTIL> repteis;
	vector <AVE> aves;
	vector <ANIMAL_NATIVO> nativos;
	vector <ANIMAL_EXOTICO> exoticos;
	vector <ANIMAL_SILVESTRE> silvestres;
	vector <VETERINARIO> vets;
	vector <TRATADOR> tratadores;

	// int *data = new int[3];
	// data[0] = 12;
	// data[1] = 05;
	// data[2] = 2019;
	//teste
	// ANFIBIO *a1 = new ANFIBIO(1,"anfibio","adsf",'f',2.9,"der","ver","der","Nataly",2,data);
	// anfibios.push_back(*a1);
	// cout << "anfibios elementos: " << anfibios.size() << endl;
	// cout << "anfibios[0] id: " << anfibios[0].getNome_cientifico() << endl;;
	// vector <ANFIBIO>::iterator it;
	// it = anfibios.begin();
	// anfibios.erase(it);
	// delete a1;
	// cout << "anfibios elementos: " << anfibios.size() << endl;
	//fim teste
	do{
		cout << "***MENU INICIAL***" << endl << endl;
		cout << "0- Sair" << endl;
		cout << "1- Cadastrar novo funcionario" << endl;
		cout << "2- Remover um animal" << endl;
		cout << "3- Alterar dados de um animal" << endl;
		cout << "4- Consultar dados através da classe" << endl;
		cout << "5- Consultar dados de um animal sob responsabilidade de veterinario ou tratador" << endl;
		cout << "6- Todas as atividades de determinado veterinario ou tratador" << endl;
		cin >> op;

		switch (op){
			case 1: //TESTE
				cadastrar_func(vets, tratadores);
				// cout << "Digite o id: " << endl;
				// cin >> id;
				// cout << "Digite o nome: " << endl;
				// cin >> nome;
				// cout << "Digite o cpf: " << endl;
				// cin >> cpf;
				// cout << "Digite a idade: " << endl;
				// cin >> idade;
				// cout << "Insira o tipo sanguineo: " << endl;
				// cin >> tipo;
				// cout << "Insira o fator RH: " << endl;
				// cin >> fator;
				// cout << "Digite a especialidade: " << endl;
				// cin >> especialidade;
				// cout << "Digite o Nivel de Segurança: "<< endl;
				// cin >> nivel;
				// TRATADOR novo(id, nome, cpf, idade, tipo, fator, especialidade, nivel);
				
				
				//VETERINARIO novo(id, nome, cpf, idade, tipo, fator, especialidade, crmv);

				//cout << novo;
			break;

		}


	}while(op != 0);
	// delete [] data;

	return 0;
}