#include "pet_fera.h"

int main(){
	int op;
	string especialidade, crmv;

	map <int, ANFIBIO_NATIVO> anfibios_nat;
	map <int, ANFIBIO_EXOTICO> anfibios_ex;

	map <int, MAMIFERO_NATIVO> mamiferos_nat;
	map <int, MAMIFERO_EXOTICO> mamiferos_ex;

	map <int, REPTIL_NATIVO> repteis_nat;
	map <int, REPTIL_EXOTICO> repteis_ex;

	map <int, AVE_NATIVO> aves_nat;
	map <int, AVE_EXOTICO> aves_ex;

	map <int, VETERINARIO> vets;
	map <int, TRATADOR> tratadores;

	carregar_arquivos(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, vets, tratadores);

		cout << ">>> Bem-Vindo ao Sistema da Pet Fera! <<<" << endl;

	do{
		cout << 	   "___________________________________________" << endl;
		cout << "|" << "-----------" <<"***MENU INICIAL***"  << "-----------" << " |" << endl;
		cout << "|" << "_________________________________________" << "|" << endl << endl;
		cout << "|"<<"0" << "|" << " - Sair" << endl;
		cout << "|"<<"1" << "|" << " - Cadastrar novo funcionario" << endl;
		cout << "|"<<"2" << "|" << " - Cadastrar novo animal" << endl;
		cout << "|"<<"3" << "|" << " - Remover um funcionario" << endl;
		cout << "|"<<"4" << "|" << " - Remover um animal" << endl;
		cout << "|"<<"5" << "|" << " - Alterar dados de um animal" << endl;
		cout << "|"<<"6" << "|" << " - Consultar dados através da classe" << endl;
		cout << "|"<<"7" << "|" << " - Consultar dados de um animal sob responsabilidade de um veterinario ou tratador" << endl;
		cout << "|"<<"8" << "|" << " - Todas as atividades de um determinado veterinario ou tratador" << endl;
		cin >> op;

		switch (op){
			case 0:
				cout << "Programa finalizado!!" << endl;
				break;
			case 1: 
				cadastrar_func(vets, tratadores);
				break;
			case 2:
				cadastrar_animal(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex);
				break;
			case 3:
				remover_funcionario(vets, tratadores);
				break;
			case 4:
				remover_animal(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex);
				break;
			case 5:
				alterar_dados(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex);
				break;
			case 6:
				pesquisarClasse(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex);
				break;
			default:
				cout << "Opcao indisponivel! Tente novamente." << endl;
		}


	}while(op != 0);
	

	return 0;
}
