#include "pet_fera.h"

// Checagem do CPF do veterinário.
bool check_CPF(map <int, VETERINARIO> &vets, long int cpf){
	int cont = 0;

	for(auto it = vets.begin(); it != vets.end();it++){
		if(it->second.getCpf() == cpf){
			cont++;
		}
	}
	return cont;
}

// Checagem do CPF do tratador.
bool check_CPF(map <int, TRATADOR> &tratadores, long int cpf){
	int cont = 0;

	for(auto it = tratadores.begin(); it != tratadores.end();it++){
		if(it->second.getCpf() == cpf){
			cont++;
		}
	}
	return cont;
}

// Checagem do veterinario a partir de seu nome.
bool check_vet(map <int, VETERINARIO> &vets, string nome){
	int cont = 0;

	for(auto it = vets.begin(); it != vets.end();it++){
		if(it->second.getNome() == nome){
			cont++;
			break;
		}
	}
	return cont;
}

// Checagem do tratador a partir de seu nome.
bool check_tratador(map <int, TRATADOR> &tratadores, string nome){
	int cont = 0;

	for(auto it = tratadores.begin(); it != tratadores.end();it++){
		if(it->second.getNome() == nome){
			cont++;
			break;
		}
	}
	return cont;
}