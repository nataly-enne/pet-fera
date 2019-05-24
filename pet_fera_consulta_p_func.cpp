#include "pet_fera.h"

// Função que chama as funções de consulta de dados em relação aos animais do veterinário e tratador.
void consulta_p_func(map <int, VETERINARIO> &vets, map <int, TRATADOR>  &tratadores, map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
	char cargo, continuar;

	do{
		cout << "Deseja consultar por tratador ou veterinario: \n v - Veterinario \n t - Tratador" << endl;
		cin >> cargo;
		if(cargo != 'v' && cargo != 't'){
			cout << "Cargo inexistente!! Tente novamente." << endl << endl;
		}
		else if(cargo == 't'){
			consulta_p_tratador(tratadores, anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex);
		}
		else{
			consulta_p_veterinario(vets, anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex);
		}
	
		cout << "Deseja consultar novamente? \n s - SIM \n n - NÃO" << endl;
		cin >> continuar;
			
	}while(continuar == 's');	
}

// Função de consulta dos tratadores.
void consulta_p_tratador(map <int, TRATADOR> &tratadores, map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){	int count = 0;
	string nome;
	char tipo = 't';

	cout << "Digite o nome do tratador:" << endl;
	cin.ignore();
	getline(cin, nome);
	transform(nome.begin(), nome.end(), nome.begin(), ::toupper); // Converte a string "nome" para caracteres maiúsculos.
	cout << endl;
	
	for(auto it = tratadores.begin(); it != tratadores.end();it++){
		if(it->second.getNome() == nome){
			count ++;
		}
	}
	if(count == 0){
		cout << "Tratador não cadastrado!" << endl << endl;
	}
	else{
		cout << "Tratador cadastrado!" << endl << endl;
		cout << "***" << "Animais atendidos pelo Tratador " << nome << "***" << endl;
		imprime_animais(tipo,nome, anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex);
	}
}

// Função de consulta dos veterinários.
void consulta_p_veterinario(map <int, VETERINARIO> &vets, map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
	int count = 0;
	string nome;
	char tipo = 'v';
	cout << "Digite o nome do veterinario:" << endl;
	cin.ignore();
	getline(cin, nome);
	transform(nome.begin(), nome.end(), nome.begin(), ::toupper); // Converte a string "nome" para caracteres maiúsculos.
	cout << endl;
	
	for(auto it = vets.begin(); it != vets.end();it++){
		if(it->second.getNome() == nome){
			count ++;
		}
	}
	if(count == 0){
		cout << "Veterinario não cadastrado!" << endl << endl;
	}
	else{
		cout << "Veterinario cadastrado!" << endl << endl;
		cout << "***" << "Animais atendidos pelo Veterinário " << nome << "***" << endl;
		imprime_animais(tipo, nome, anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex);
	}
}

// Impressão dos animais por tratador ou veterinário.
void imprime_animais(char tipo, string nome, map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
	
	if(tipo == 't'){
		for(auto it = anfibios_nat.begin();it != anfibios_nat.end(); it++){
			if(it->second.getTratador() == nome){
				cout << it->second;
			}
		}
		for(auto it = anfibios_ex.begin();it != anfibios_ex.end(); it++){
			if(it->second.getTratador() == nome){
				cout << it->second;
			}
		}
		for(auto it = mamiferos_nat.begin();it != mamiferos_nat.end(); it++){
			if(it->second.getTratador() == nome){
				cout << it->second;
			}
		}
		for(auto it = mamiferos_ex.begin();it != mamiferos_ex.end(); it++){
			if(it->second.getTratador() == nome){
				cout << it->second;
			}
		}
		for(auto it = repteis_nat.begin();it != repteis_nat.end(); it++){
			if(it->second.getTratador() == nome){
				cout << it->second;
			}
		}
		for(auto it = repteis_ex.begin();it != repteis_ex.end(); it++){
			if(it->second.getTratador() == nome){
				cout << it->second;
			}
		}
		for(auto it = aves_nat.begin();it != aves_nat.end(); it++){
			if(it->second.getTratador() == nome){
				cout << it->second;
			}
		}
		for(auto it = aves_ex.begin();it != aves_ex.end(); it++){
			if(it->second.getTratador() == nome){
				cout << it->second;
			}
		}
	}
	else{
		for(auto it = anfibios_nat.begin();it != anfibios_nat.end(); it++){
			if(it->second.getVeterinario() == nome){
				cout << it->second;
			}
		}
		for(auto it = anfibios_ex.begin();it != anfibios_ex.end(); it++){
			if(it->second.getVeterinario() == nome){
				cout << it->second;
			}
		}
		for(auto it = mamiferos_nat.begin();it != mamiferos_nat.end(); it++){
			if(it->second.getVeterinario() == nome){
				cout << it->second;
			}
		}
		for(auto it = mamiferos_ex.begin();it != mamiferos_ex.end(); it++){
			if(it->second.getVeterinario() == nome){
				cout << it->second;
			}
		}
		for(auto it = repteis_nat.begin();it != repteis_nat.end(); it++){
			if(it->second.getVeterinario() == nome){
				cout << it->second;
			}
		}
		for(auto it = repteis_ex.begin();it != repteis_ex.end(); it++){
			if(it->second.getVeterinario() == nome){
				cout << it->second;
			}
		}
		for(auto it = aves_nat.begin();it != aves_nat.end(); it++){
			if(it->second.getVeterinario() == nome){
				cout << it->second;
			}
		}
		for(auto it = aves_ex.begin();it != aves_ex.end(); it++){
			if(it->second.getVeterinario() == nome){
				cout << it->second;
			}
		}
	}	
}
