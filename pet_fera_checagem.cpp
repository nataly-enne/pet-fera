#include "pet_fera.h"

// Checagem do CPF do veterinário.
bool check_CPF(map <int, VETERINARIO> &vets, long int cpf){
	int cont = 0;

	for(auto it = vets.begin(); it != vets.end();it++){
		if(it->second.getCpf() == cpf){
			cont++;
			break;
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
	int cont_nome = 0, cont_nivel = 0;
	transform(nome.begin(), nome.end(), nome.begin(), ::toupper); // Converte a string nome para caracteres maiúsculos.
	for(auto it = tratadores.begin(); it != tratadores.end();it++){
		if(it->second.getNome() == nome){
			cont_nome++;
		}
		if(it->second.getNivel_seguranca() == 1){
			cont_nivel++;
			break;
		}
	}
	if(cont_nome >= 1 && cont_nivel == 1){
		return 1;
	}else{
		return 0;
	}
}

bool verifica_ID(map <int, VETERINARIO> &vets, string id_string, char &sucesso){
	int cont = 0, id, verificacao;
	char c;
	sucesso = 'n';
	for(int i = 0; i < (int)id_string.size(); i++){
		c = id_string[i];
		verificacao = isdigit(c);
		if(!verificacao){
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
		}
		else{
			cont++;
		}
	}

	if(cont == (int) id_string.size()){
		stringstream ss(id_string);
		ss >> id;
		if(vets.empty()){
			sucesso = 's';
			return 1;
		}else{
			for(auto it = vets.begin(); it != vets.end();it++){
				if(it->second.getId() == id){
					sucesso = 'n';
					cout << "ERRO: id já cadastrado!" << endl << endl;
					return 0;				
				}
			}
				
		}
			
	}else{
		cout << "ERRO: caracter inválido!" << endl << endl;
		return 0;
	}

	sucesso = 's';
	return 1;

}
bool verifica_ID(map <int, TRATADOR> &tratadores, string id_string, char &sucesso){
	int cont = 0, id, verificacao;
	char c;
	sucesso = 'n';
	for(int i = 0; i < (int)id_string.size(); i++){
		c = id_string[i];
		verificacao = isdigit(c);
		if(!verificacao){
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
		}
		else{
			cont++;
		}
	}

	if(cont == (int) id_string.size()){
		stringstream ss(id_string);
		ss >> id;
		if(tratadores.empty()){
			sucesso = 's';
			return 1;
		}else{
			for(auto it = tratadores.begin(); it != tratadores.end();it++){
				if(it->second.getId() == id){
					sucesso = 'n';
					cout << "ERRO: id já cadastrado!" << endl << endl;
					return 0;				
				}
			}
				
		}
			
	}else{
		cout << "ERRO: caracter inválido!" << endl << endl;
		return 0;
	}

	sucesso = 's';
	return 1;

}

bool verifica_ID(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, char tipo, string id_string, char &sucesso){
	int cont = 0, id, verificacao;
	char c;
	sucesso = 'n';
	for(int i = 0; i < (int)id_string.size(); i++){
		c = id_string[i];
		verificacao = isdigit(c);
		if(!verificacao){
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
		}
		else{
			cont++;
		}
	}

	if(cont == (int) id_string.size()){
		stringstream ss(id_string);
		ss >> id;
		if(tipo == 'n'){
			if(anfibios_nat.empty()){
				sucesso = 's';
				return 1;
			}else{
				for(auto it = anfibios_nat.begin(); it != anfibios_nat.end();it++){
					if(it->second.getId() == id){
						sucesso = 'n';
						cout << "ERRO: id já cadastrado!" << endl << endl;
						return 0;				
					}
				}
					
			}
		} //Anfibios_nat
		else{
			if(anfibios_ex.empty()){
				sucesso = 's';
				return 1;
			}else{
				for(auto it = anfibios_ex.begin(); it != anfibios_ex.end();it++){
					if(it->second.getId() == id){
						sucesso = 'n';
						cout << "ERRO: id já cadastrado!" << endl << endl;
						return 0;				
					}
				}	
			}
		}//Anfibios_ex
			
	}else{
		cout << "ERRO: caracter inválido!" << endl << endl;
		return 0;
	}

	sucesso = 's';
	return 1;	

}

bool verifica_seguranca(string nivel_seg_string, char &sucesso){
	int cont = 0, verificacao;
	char c;
	sucesso = 'n';
		for(int i = 0; i < (int)nivel_seg_string.size(); i++){
			c = nivel_seg_string[i];
			verificacao = isdigit(c);
			if(!verificacao || (nivel_seg_string != "0" && nivel_seg_string != "1" && nivel_seg_string != "2")){
				sucesso = 'n';
				cout << "Erro: caracter inválido!" << endl << endl;
				return 0;
			}
			else{
				cont++;
			}
				
		}
		if(cont == (int) nivel_seg_string.size()){
			sucesso = 's';
			return 1;
		}else{
			cout << "Erro: caracter inválido 2!" << endl << endl;
			sucesso = 'n';
			return 0;
		}
}

bool verifica_nome(string &nome, char &sucesso){
	int cont = 0, verificacao;
	char c;
	sucesso = 'n';
	transform(nome.begin(), nome.end(), nome.begin(), ::toupper); // Converte a string nome para caracteres maiúsculos.
	for(int i = 0; i < (int)nome.size(); i++){
		c = nome[i];
		verificacao = isalpha(c);
		if(!verificacao && c != ' '){
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
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

bool verifica_nome_cient(string &nome, char &sucesso){
	int cont = 0, verificacao;
	char c;
	sucesso = 'n';
	transform(nome.begin(), nome.end(), nome.begin(), ::toupper); // Converte a string nome para caracteres maiúsculos.
	for(int i = 0; i < (int)nome.size(); i++){
		c = nome[i];
		verificacao = isalpha(c);
		if(!verificacao && c != ' ' && c !='-'){
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
		}
		else{
			cont++;
		}
		
	}
	if(cont == (int) nome.size()){
		transform(nome.begin(), nome.end(), nome.begin(), ::tolower);
		sucesso = 's';
		return 1;
	}else{
		return 0;
	}

}
bool verifica_CPF(string cpf_string, char &sucesso){
	int cont = 0, verificacao;
	char c;
	sucesso = 'n';
	for(int i = 0; i < (int)cpf_string.size(); i++){
		c = cpf_string[i];
		verificacao = isdigit(c);
		if(!verificacao){
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
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

bool verifica_idade(string idade_string, char &sucesso){
	int cont = 0, verificacao;
	char c;
	sucesso = 'n';
	for(int i = 0; i < (int)idade_string.size(); i++){
		c = idade_string[i];
		verificacao = isdigit(c);
		if(!verificacao){
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
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

bool verifica_inteiro(string total_mudas_string, char &sucesso){
	int cont = 0, verificacao;
	char c;
	sucesso = 'n';
	for(int i = 0; i < (int)total_mudas_string.size(); i++){
		c = total_mudas_string[i];
		verificacao = isdigit(c);
		if(!verificacao){
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
		}
		else{
			cont++;
		}
		
	}

	if(cont == (int) total_mudas_string.size()){
		sucesso = 's';
		return 1;
	}else{
		return 0;
	}
}

bool verifica_tipo_sang(string &tipo_sang_string, char &sucesso){
	int cont = 0, cont_sangue = 0, verificacao;
	char c;
	sucesso = 'n';
	transform(tipo_sang_string.begin(), tipo_sang_string.end(), tipo_sang_string.begin(), ::toupper); // Converte a string nome para caracteres maiúsculos.
	for(int i = 0; i < (int)tipo_sang_string.size(); i++){
		c = tipo_sang_string[i];
		verificacao = isalpha(c);
		cont_sangue++;
		if(!verificacao || cont_sangue > 2 || (tipo_sang_string != "O" && tipo_sang_string != "AB" && tipo_sang_string != "B" && tipo_sang_string != "A")){
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
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

bool verifica_fator(string fator_rh_string, char &sucesso){
	int cont = 0, cont_carac = 0;
	char c;
	sucesso = 'n';

	for(int i = 0; i < (int) fator_rh_string.size(); i++){
		c = fator_rh_string[i];
		cont_carac++;
		if((c != '-' && c != '+') || cont_carac > 1){
			cont--;
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
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

bool verifica_especialidade(string especialidade, char &sucesso){
	int cont = 0, verificacao;
	char c;
	sucesso = 'n';
	transform(especialidade.begin(), especialidade.end(), especialidade.begin(), ::toupper);
	for(int i = 0; i < (int) especialidade.size(); i++){
		c = especialidade[i];
		verificacao = isalpha(c);
		if(!verificacao && c != ' '){
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
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

bool verifica_CRMV(map <int, VETERINARIO> &vets, string crmv, char &sucesso){
	int cont = 0, verificacao, contador_de_traco = 0;
	char c;
	sucesso = 'n';
	transform(crmv.begin(), crmv.end(), crmv.begin(), ::toupper);
	for(int i = 0; i < (int) crmv.size(); i++){
		c = crmv[i];
		verificacao = isalnum(c);
		if(c == '-'){
			contador_de_traco++;
		}
		if(!verificacao && c != ' ' && c != '-'){
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
		}
		else{
			cont++;

		}
		
	}
	
	if((cont == (int)crmv.size()) && (contador_de_traco >= 1)){
		transform(crmv.begin(), crmv.end(), crmv.begin(), ::tolower);
		if(vets.empty()){
			sucesso = 's';
			return 1;
		}else{
			for(auto it = vets.begin(); it != vets.end();it++){
				if(it->second.getCrmv() == crmv){
					cout << "ERRO: Crmv já cadastrado!" << endl << endl;
					sucesso = 'n';
					return 0;				
				}

			}
		}

	}
	sucesso = 's';
	return 1;
}

bool verifica_dieta(string &dieta, char &sucesso){
	int cont = 0, verificacao;
	char c;
	sucesso = 'n';
	transform(dieta.begin(), dieta.end(), dieta.begin(), ::toupper); // Converte a string nome para caracteres maiúsculos.
	for(int i = 0; i < (int)dieta.size(); i++){
		c = dieta[i];
		verificacao = isalpha(c);
		if(!verificacao && c != ' ' && c != ','){
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
		}
		else{
			cont++;
		}
		
	}
	if(cont == (int) dieta.size()){
		transform(dieta.begin(), dieta.end(), dieta.begin(), ::tolower);
		sucesso = 's';
		return 1;
	}else{
		return 0;
	}
}

bool verifica_tamanho(string tamanho_string, char &sucesso){
	int cont = 0, cont_ponto = 0, verificacao;
	char c;
	sucesso = 'n';
	for(int i = 0; i < (int)tamanho_string.size(); i++){
		c = tamanho_string[i];
		verificacao = isdigit(c);
		if(c == '.'){
			cont_ponto++;
		}
		if(!verificacao && c != '.'){
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
		}
		else{
			cont++;
		}
		
	}
	if(cont == (int) tamanho_string.size() && cont_ponto == 1){
		sucesso = 's';
		return 1;
	}else{
		return 0;
	}

}

bool verifica_data(string ultima_muda, char &sucesso){
	int cont = 0, cont_traco = 0, verificacao;
	char c;
	sucesso = 'n';
	for(int i = 0; i < (int)ultima_muda.size(); i++){
		c = ultima_muda[i];
		verificacao = isdigit(c);
		if(c == '-'){
			cont_traco++;
		}
		if(!verificacao && c != '-'){
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
		}
		else{
			cont++;
		}
		
	}
	if(cont == (int) ultima_muda.size() && cont_traco == 2){
		sucesso = 's';
		return 1;
	}else{
		return 0;
	}

}

bool verifica_autorizacao(string autorizacao, char &sucesso){
	int cont = 0, cont_traco = 0, verificacao;
	char c;
	sucesso = 'n';
	transform(autorizacao.begin(), autorizacao.end(), autorizacao.begin(), ::toupper); // Converte a string nome para caracteres maiúsculos.
	for(int i = 0; i < (int)autorizacao.size(); i++){
		c = autorizacao[i];
		verificacao = isalnum(c);
		if(c == '-'){
			cont_traco++;
		}
		if(!verificacao && c != '-'){
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
		}
		else{
			cont++;
		}
		
	}
	if(cont == (int) autorizacao.size() && cont_traco == 1){
		sucesso = 's';
		return 1;
	}else{
		return 0;
	}
}

bool verifica_origem(string &origem, char &sucesso){
	int cont = 0, verificacao;
	char c;
	sucesso = 'n';
	transform(origem.begin(), origem.end(), origem.begin(), ::toupper); // Converte a string nome para caracteres maiúsculos.
	for(int i = 0; i < (int)origem.size(); i++){
		c = origem[i];
		verificacao = isalpha(c);
		if(!verificacao && c != ' '){
			sucesso = 'n';
			cout << "Erro: caracter inválido!" << endl << endl;
			return 0;
		}
		else{
			cont++;
		}
		
	}
	if(cont == (int) origem.size()){
		transform(origem.begin(), origem.end(), origem.begin(), ::tolower);
		sucesso = 's';
		return 1;
	}else{
		return 0;
	}
}