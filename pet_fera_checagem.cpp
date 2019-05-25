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

bool verifica_ID(string id_string, char &sucesso){
	int cont = 0, verificacao;
	char c;
	sucesso = 'n';
	for(int i=0; i < (int)id_string.size(); i++){
		c = id_string[i];
		verificacao = isdigit(c);
		if(!verificacao){
			cont--;
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			break;
		}
		else{
			cont++;
		}
	}

	if(cont == (int) id_string.size()){
		sucesso = 's';
		return 1;
	}else{
		return 0;
	}

}

bool verifica_Nome(string nome, char &sucesso){
	int cont = 0, verificacao;
	char c;
	sucesso = 'n';
	transform(nome.begin(), nome.end(), nome.begin(), ::toupper); // Converte a string nome para caracteres maiúsculos.
	for(int i=0; i < (int)nome.size(); i++){
		c = nome[i];
		verificacao = isalpha(c);
		if(!verificacao && c != ' '){
			cont--;
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			break;
		}
		else{
			cont++;
		}
		
	}

	if(cont == (int) nome.size()){
		sucesso = 's';
		return 1;
	}else{
		return 0;
	}

}

bool verifica_Cpf(string cpf_string, char &sucesso){
	int cont = 0, verificacao;
	char c;
	sucesso = 'n';
	for(int i=0; i < (int)cpf_string.size(); i++){
		c = cpf_string[i];
		verificacao = isdigit(c);
		if(!verificacao){
			cont--;
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			break;
		}
		else{
			cont++;
		}
		
	}

	if(cont == (int) cpf_string.size()){
		sucesso = 's';
		return 1;
	}else{
		return 0;
	}
}

bool verifica_Idade(string idade_string, char &sucesso){
	int cont = 0, verificacao;
	char c;
	sucesso = 'n';
	for(int i=0; i < (int)idade_string.size(); i++){
		c = idade_string[i];
		verificacao = isdigit(c);
		if(!verificacao){
			cont--;
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			break;
		}
		else{
			cont++;
		}
		
	}

	if(cont == (int) idade_string.size()){
		sucesso = 's';
		return 1;
	}else{
		return 0;
	}

}

bool verifica_Tiposang(string tipo_sang_string, char &sucesso){
	int cont = 0, cont_sangue = 0, verificacao;
	char c;
	sucesso = 'n';
	transform(tipo_sang_string.begin(), tipo_sang_string.end(), tipo_sang_string.begin(), ::toupper); // Converte a string nome para caracteres maiúsculos.
	for(int i=0; i < (int)tipo_sang_string.size(); i++){
		c = tipo_sang_string[i];
		verificacao = isalpha(c);
		cont_sangue++;
		if(!verificacao || cont_sangue > 2 || (tipo_sang_string != "O" && tipo_sang_string != "AB" && tipo_sang_string != "B" && tipo_sang_string != "A")){
			cont--;
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			break;
		}
		else{
			cont++;
		}
		
	}

	if(cont == (int)tipo_sang_string.size()){
		sucesso = 's';
		return 1;
	}else{
		return 0;
	}

}

bool verifica_Fator(string fator_rh_string, char &sucesso){
	int cont = 0, cont_carac = 0;
	char c;
	sucesso = 'n';

	for(int i=0; i < (int) fator_rh_string.size(); i++){
		c = fator_rh_string[i];
		cont_carac++;
		if((c != '-' && c != '+') || cont_carac > 1){
			cont--;
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			break;
		}
		else{
			cont++;
		}
		
	}

	if(cont == (int)fator_rh_string.size()){
		sucesso = 's';
		return 1;
	}else{
		return 0;
	}

}

bool verifica_Esp(string especialidade, char &sucesso){
	int cont = 0, verificacao;
	char c;
	sucesso = 'n';
	transform(especialidade.begin(), especialidade.end(), especialidade.begin(), ::toupper);
	for(int i=0; i < (int) especialidade.size(); i++){
		c = especialidade[i];
		verificacao = isalpha(c);
		if(!verificacao && c != ' '){
			cont--;
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			break;
		}
		else{
			cont++;
		}
		
	}

	if(cont == (int)especialidade.size()){
		sucesso = 's';
		return 1;
	}else{
		sucesso = 'n';
		return 0;
	}
}

bool verifica_Crmv(string crmv, char &sucesso){
	int cont = 0, verificacao, contador_de_traco = 0;
	char c;
	sucesso = 'n';
	transform(crmv.begin(), crmv.end(), crmv.begin(), ::toupper);
	for(int i=0; i < (int) crmv.size(); i++){
		c = crmv[i];
		verificacao = isalnum(c);
		if(c == '-'){
			contador_de_traco++;
		}
		if(!verificacao && c != ' ' && c != '-'){
			cont--;
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			break;
		}
		else{
			cont++;
		}
		
	}

	if(cont == (int)crmv.size() && (contador_de_traco == 1)){
		sucesso = 's';
		return 1;
	}else{
		return 0;
	}
}