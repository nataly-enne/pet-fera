#include "pet_fera.h"

// Função que faz a chamada das impressões de cada classe de animais.
void pesquisar_classe(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
	int classe;
	char sucesso = 'n';

	do{
		cout << "Digite a opção referente a classe que deseja pesquisar: \n  1-Amphibia\n  2-Mammalia\n  3-Reptilia\n  4-Aves" << endl;
		cin >> classe;
		switch (classe){
			case 1:
				imprimir_classe(anfibios_nat, anfibios_ex); // Chama função que imprime a classe anfíbio.
				sucesso = 's';
				break;
			case 2:
				imprimir_classe(mamiferos_nat, mamiferos_ex); // Chama função que imprime a classe mamífero.
				sucesso = 's';
				break;
			case 3:
				imprimir_classe(repteis_nat, repteis_ex); // Chama função que imprime a classe réptil.
				sucesso = 's';
				break;
			case 4:
				imprimir_classe(aves_nat, aves_ex); // Chama função que imprime a classe ave.
				sucesso = 's';
				break;
			default:
				cout << "Opcao nao existe!! Tente novamente." << endl;
				cout << "Deseja sair ? s/n" << endl;
				cin >> sucesso;	
		}
	}while(sucesso != 's');
}

// Imprime a classe Amphibia.
void imprimir_classe(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex){
	cout << endl;
	cout << "Anfíbios Nativos:" << endl;
	for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
		cout << it -> second;
	}
	cout << endl;
	cout << "Anfíbios Exóticos:" << endl;
	for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
		cout << it -> second;
	}
}

// Imprime a classe Mammalia.
void imprimir_classe(map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex){
	cout << endl;
	cout << "Mamiferos Nativos:" << endl;
	for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
		cout << it -> second;
	}
	cout << endl;
	cout << "Mamiferos Exóticos:" << endl;
	for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
		cout << it -> second;
	}
}

// Imprime a classe Reptilia.
void imprimir_classe(map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex){
	cout << endl;
	cout << "Répteis Nativos:" << endl;
	for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
		cout << it -> second;
	}
	cout << endl;
	cout << "Répteis Exóticos:" << endl;
	for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
		cout << it -> second;
	}
}

// Imprime a classe Aves.
void imprimir_classe(map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
	cout << endl;
	cout << "Aves Nativas:" << endl;
	for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
		cout << it -> second;
	}
	cout << endl;
	cout << "Aves Exóticas:" << endl;
	for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
		cout << it -> second;
	}
}
