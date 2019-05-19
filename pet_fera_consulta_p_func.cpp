#include "pet_fera.h"

void consulta_p_func(map <int, VETERINARIO> &vets, map <int, TRATADOR>  &tratadores, map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex)
{
	char cargo, continuar;

	do{
		cout << "Deseja consultar por tratador ou veterinario: \n t-tratador\n v-veterinario" << endl;
		cin >> cargo;
		if(cargo != 't' && cargo != 'v'){
			cout << "Cargo inexistente!! Tente novamente." << endl << endl;
			continuar = 's';
		}else if(cargo == 't'){
			consulta_p_tratador(tratadores, anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex);
		}else{
			consulta_p_veterinario(vets, anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex);
		}
		do{
			cout << "Deseja consultar novamente? \n s-sim \n n-nao" << endl;
			cin >> continuar;
		}while(continuar != 'n' && continuar != 's');
		
	}while(continuar != 'n');
	
}

void consulta_p_tratador(map <int, TRATADOR> &tratadores, map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex)
{	int count = 0;
	string nome;
	char tipo = 't';

	cout << "Digite o nome do tratador:" << endl;
	cin >> nome;
	cout << endl;
	for(auto it = tratadores.begin(); it != tratadores.end();it++){
		if(it->second.getNome() == nome){
			count ++;
		}
	}
	if(count == 0){
		cout << "Tratador nao cadastrado!" << endl << endl;
	}else{
		imprimeAnimais(tipo,nome, anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex);
	}
}

void consulta_p_veterinario(map <int, VETERINARIO> &vets, map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex)
{
	int count = 0;
	string nome;
	char tipo = 'v';
	cout << "Digite o nome do veterinario:" << endl;
	cin >> nome;
	cout << endl;
	for(auto it = vets.begin(); it != vets.end();it++){
		if(it->second.getNome() == nome){
			count ++;
		}
	}
	if(count == 0){
		cout << "Veterinario nao cadastrado!" << endl << endl;
	}else{
		imprimeAnimais(tipo,nome, anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex);
	}
}



void imprimeAnimais(char tipo, string nome, map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex)
{
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
	}else{
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
