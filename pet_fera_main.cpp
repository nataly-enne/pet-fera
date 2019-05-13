#include "pet_fera.h"

int main(){

	int op;
	string especialidade, crmv;
	// int i = 123;
	// string c = "sjss", n = "seila";
	// char s= 'M';
	// double tam=1.23;
	// string die= "carne", vet = "igor",trat = "igor", nome = "fred",aut = "dkdkd",u = "natal", a = "flago321";
	// int mudas = 2, data[3];
	// data[0] = 12;
	// data[1] = 02;
	// data[2] = 2019;

	// ANFIBIO_NATIVO X(i,c,n, s, tam,die,vet, trat, nome, mudas,data, aut,u, a);

	// map<int, ANFIBIO_NATIVO>mp_anfibio_nat;
	// mp_anfibio_nat.insert(0, X);

	vector <ANFIBIO_NATIVO> anfibios_nat;
	vector <ANFIBIO_EXOTICO> anfibios_ex;

	vector <MAMIFERO_NATIVO> mamiferos_nat;
	vector <MAMIFERO_EXOTICO> mamiferos_ex;

	vector <REPTIL_NATIVO> repteis_nat;
	vector <REPTIL_EXOTICO> repteis_ex;

	vector <AVE_NATIVO> aves_nat;
	vector <AVE_EXOTICO> aves_ex;

	vector <VETERINARIO> vets;
	vector <TRATADOR> tratadores;


	do{
		cout << "***MENU INICIAL***" << endl << endl;
		cout << "0- Sair" << endl;
		cout << "1- Cadastrar novo funcionario" << endl;
		cout << "2- Cadastrar novo animal" << endl;
		cout << "3- Remover um animal" << endl;
		cout << "4- Alterar dados de um animal" << endl;
		cout << "5- Consultar dados através da classe" << endl;
		cout << "6- Consultar dados de um animal sob responsabilidade de veterinario ou tratador" << endl;
		cout << "7- Todas as atividades de determinado veterinario ou tratador" << endl;
		cin >> op;

		switch (op){
			case 1: 
				cadastrar_func(vets, tratadores);
				break;
			case 2:
				cadastrar_animal(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex);
				/*
				for(int i=0; i< (int)repteis_nat.size(); i++){
					cout << repteis_nat[i] << " ";
				} 
				for(int i=0; i< (int)aves_nat.size(); i++){
					cout << aves_nat[i] << " ";
				} 
				*/
				break;



			case 4:
				alterar_dados();
				break;

		}


	}while(op != 0);

	// delete [] data;

	return 0;
}