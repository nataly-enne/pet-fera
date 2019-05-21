#include "pet_fera.h"

// Checagem dos CPF's.
bool check_CPF(map <int, VETERINARIO> &vets, long int cpf){
	int cont = 0;

	for(auto it = vets.begin(); it != vets.end();it++){
		if(it->second.getCpf() == cpf){
			cont++;
		}
	}
	return cont;
}

bool check_CPF(map <int, TRATADOR> &tratadores, long int cpf){
	int cont = 0;

	for(auto it = tratadores.begin(); it != tratadores.end();it++){
		if(it->second.getCpf() == cpf){
			cont++;
		}
	}
	return cont;
}

// Checagem dos veterinarios e tratadores a partir de seus nomes.
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