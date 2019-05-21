#include "pet_fera.h"

// Função geral que faz a chamada das funções de cadastrar os funcionarios.
void cadastrar_func(map <int, VETERINARIO> &vets, map <int, TRATADOR>  &tratadores){
	char tipo_func;
	char continuar = 'n';
	
	do{ // Enquanto o usuário quiser cadastrar (continuar != s), o programa roda. 
		cout << "Qual o tipo de funcionario a ser cadastrado? \n  v - Veterinário\n  t - Tratador" << endl;
		cin >> tipo_func;
		if(tipo_func != 'v' && tipo_func != 't'){
			cout << "Tipo de funcionario incorreto!! Tente novamente!\n" << endl;
			continuar = 's';
			continue;
		}
		else{
			if(tipo_func == 'v'){
				cadastrar(vets);
			}
			else{
				cadastrar(tratadores);
			}
		}
	}while (continuar == 's'); 	
}

// Função específica para cadastro dos veterinários.
void cadastrar(map <int, VETERINARIO> &vets){ 
	int id, idade;
	unsigned int old_size;
	long int cpf;
	string nome, especialidade, crmv, tipo_sang;
	char fator_rh, continuar;
	bool check;
	old_size = vets.size();
	ofstream veterinarios;
	
	do{
		cout << "Digite o id: " << endl;
		cin >> id;
		cout << "Digite o nome: " << endl;
		cin.ignore();
		getline(cin, nome);
		transform(nome.begin(), nome.end(), nome.begin(), ::toupper); // Converte a string nome para caracteres maiúsculos.
		cout << "Digite o cpf: " << endl;
		cin >> cpf;
		check = check_CPF(vets, cpf); // Checa se o CPF existe.
		if(check){
			cout << "CPF já cadastrado!" << endl;
			break;
		}
		cout << "Digite a idade: " << endl;
		cin >> idade;
		cout << "Insira o tipo sanguineo: " << endl;
		cin >> tipo_sang;
		cout << "Insira o fator RH: " << endl;
		cin >> fator_rh;
		cout << "Digite a especialidade: " << endl;
		cin.ignore();
		getline(cin, especialidade);
		cout << "Digite o crmv: "<< endl;
		getline(cin, crmv);

		// Armazenando os valores recebidos pelo usuário no map.
		vets.insert(pair <int, VETERINARIO> (id,VETERINARIO(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, crmv)));
		
		cout << "Deseja cadastrar um novo funcionario? s/n" << endl;
		cin >> continuar;
	}while(continuar == 's');

	if (vets.size() == old_size){ 
		cout << "Falha no cadastro do funcionario!" << endl;
	}
	else{
		if(!vets.empty()){
			veterinarios.open("veterinarios.txt");
			for(auto it = vets.begin(); it != vets.end(); it++){
				veterinarios << (*it).second;
			}
			veterinarios.close();
		}
		cout << "Cadastro efetuado com sucesso!!" << endl;
	}
}

// Função específica para cadastro dos tratadores.
void cadastrar(map <int, TRATADOR>  &tratadores){ 
	int id, idade,nivel_seg;
	unsigned int old_size;
	long int cpf;
	string nome, especialidade, tipo_sang;
	char fator_rh, continuar;
	bool check;
	old_size = tratadores.size();
	ofstream tratador;
	
	do{
		cout << "Digite o id: " << endl;
		cin >> id;
		cout << "Digite o nome: " << endl;
		cin.ignore();
		getline(cin, nome); 
		transform(nome.begin(), nome.end(), nome.begin(), ::toupper); // Converte a string nome para caracteres maiusculos.
		cout << "Digite o cpf: " << endl;
		cin >> cpf;
		check = check_CPF(tratadores, cpf); // Checa se o CPF existe.
		if(check){
			cout << "CPF já cadastrado!" << endl;
			break;
		}
		cout << "Digite a idade: " << endl;
		cin >> idade;
		cout << "Insira o tipo sanguineo: " << endl;
		cin.ignore();
		getline(cin, tipo_sang);
		cout << "Insira o fator RH: " << endl;
		cin >> fator_rh;
		cout << "Digite a especialidade: " << endl;
		cin.ignore();
		getline(cin, especialidade);
		cout << "Digite o nivel de seguranca: "<< endl;
		cin >> nivel_seg;
		
		// Armazenando os valores recebidos pelo usuário no map.
		tratadores.insert(pair <int, TRATADOR> (id, TRATADOR(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, nivel_seg)));
		
		cout << "Deseja cadastrar um novo funcionário? s/n" << endl;
		cin >> continuar;
	}while(continuar == 's');

	if (tratadores.size() == old_size){ 
		cout << "Falha no cadastro do funcionario!" << endl;
	}
	else{
		if(!tratadores.empty()){
			tratador.open("tratadores.txt");
			for(auto it = tratadores.begin(); it != tratadores.end(); it++){
				tratador << (*it).second;
			}
			tratador.close();
		}
		cout << "Cadastro efetuado com sucesso!!" << endl;
	}
}

// Função geral que faz a chamada das funções específicas para o cadastro dos animais.
void cadastrar_animal(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores){
	char tipo_func;
	char continuar = 'n', resp;

	do{
		cout << "Qual animal a ser cadastrado? \n a - anfíbio\n m - mamífero \n r - repteis \n v - aves" << endl;
		cin >> tipo_func;
		if(tipo_func != 'a' && tipo_func != 'm' && tipo_func != 'r' && tipo_func != 'v'){
			cout << "Tipo de animal incorreto!! Tente novamente!\n" << endl;
			cout << endl;
			cout << "Deseja sair? s/n" << endl;
			cin >> resp;
			if(resp == 's'){
				continuar = 'n';;
				break;
			}
			continuar = 's';
			continue;
		}else{
			if(tipo_func == 'a'){
				cadastrar(anfibios_nat, anfibios_ex, vets, tratadores);
			}
			else if(tipo_func == 'm'){
				cadastrar(mamiferos_nat, mamiferos_ex, vets, tratadores);
			}
			else if(tipo_func == 'r'){
				cadastrar(repteis_nat, repteis_ex, vets, tratadores);
			}		
			else{
				cadastrar(aves_nat, aves_ex, vets, tratadores);
			}
		}
	}while (continuar == 's');	
}

// Função especifica para cadastro dos anfíbios.
void cadastrar(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores){
	int id, total_mudas;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, ultima_muda, nome;
	bool check;
	char sexo, tipo_func, continuar;
	double tamanho;
	unsigned int old_size;
	ofstream nativos;
	ofstream exoticos;

	do{
		cout << "Deseja cadastrar um ANFIBIO NATIVO ou ANNFIBIO EXÓTICO? \n n - NATIVO\n e - EXÓTICO" << endl;
		cin >> tipo_func;
		if(tipo_func != 'n' && tipo_func != 'e'){
			cout << "Tipo invalido, tente novamente!" << endl;
			continuar = 's';
			continue;
		}
		else{
			continuar = 'n';
			cout << "Digite o id: " << endl;
			cin >> id;
			cout << "Digite a classe: " << endl;
			cin.ignore();
			getline(cin, classe);
			cout << "Digite o nome: " << endl;
			getline(cin, nome);
			cout << "Digite o nome científico: " << endl;
			getline(cin, nome_cientifico);
			cout << "Digite a dieta: " << endl;
			getline(cin, dieta);
			cout << "Digite o nome do veterinario: " << endl;
			getline(cin, veterinario);
			check = check_vet(vets, veterinario);
			if(!check){
				cout << endl;
				cout << "Veterinario não cadastrado!" << endl;
				break;
			}
			cout << "Digite o nome do tratador: " << endl;
			getline(cin, tratador);
			check = check_tratador(tratadores, tratador);
			if(!check){
				cout << endl;
				cout << "Tratador não cadastrado!" << endl;
				break;
			}
			cout << "Digite o nome de batismo: " << endl;
			getline(cin, nome_batismo);
			cout << "Digite o sexo do animal: " << endl;
			cin >> sexo;
			cout << "Digite o tamanho do animal: " << endl;
			cin >> tamanho;
			cout << "Insira o total de mudas:" << endl;
			cin >> total_mudas;
			cout << "Insira a data da última muda(dd/mm/aaaa)" << endl;
			cin.ignore();
			getline(cin, ultima_muda);
			cout << "Insira a autorizacao do IBAMA: " << endl;
			getline(cin, autorizacao_IBAMA);
			

			if(tipo_func == 'n'){
				old_size = anfibios_nat.size();
				cout << "Digite a UF de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);

				// Armazenando valores no map para tipo anfíbio nativo passados pelo usuário.
				anfibios_nat.insert(pair <int, ANFIBIO_NATIVO> (id, ANFIBIO_NATIVO(id, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao)));

				if (anfibios_nat.size() == old_size){
					cout << "Falha no cadastro do animal! Tente novamente." << endl;
					continuar = 's';
					continue;
				}
		
			}
			else{
				old_size = anfibios_ex.size();
				cout << "Digite o País de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);

				// Armazenando valores no map para tipo anfíbio exótico passados pelo usuário.
				anfibios_ex.insert(pair <int, ANFIBIO_EXOTICO> (id, ANFIBIO_EXOTICO(id, classe, nome, nome_cientifico,sexo, tamanho, dieta,veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao)));
							
				if (anfibios_ex.size() == old_size){
					cout << "Falha no cadastro do animal! Tente novamente" << endl;
					continuar = 's';
					continue;
				}	
			}
		}
		cout << "Deseja cadastrar um novo animal? s/n" << endl;
		cin >> continuar;
	}while(continuar == 's');
					
	if(!anfibios_nat.empty()){
		nativos.open("anfibios_nat.txt");
		for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
			nativos << (*it).second;
		}
		nativos.close();
	}
	if(!anfibios_ex.empty()){
		exoticos.open("anfibios_ex.txt");
		for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
			exoticos << (*it).second;
		}
		exoticos.close();
	}
}

// Função especifica para cadastro dos mamiferos.
void cadastrar(map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores){
	int id;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, cor, nome;
	char sexo, tipo_func, continuar = 's';
	double tamanho;
	bool check;
	unsigned int old_size;
	ofstream nativos;
	ofstream exoticos;

	do{
		cout << "Deseja cadastrar um MAMIFERO NATIVO ou MAMIFERO EXÓTICO? \n n - NATIVO\n e - EXÓTICO" << endl;
		cin >> tipo_func;
		if(tipo_func != 'n' && tipo_func != 'e'){
			continue;
		}
		else{
			continuar = 's';
			cout << "Digite o id: " << endl;
			cin >> id;
			cout << "Digite a classe: " << endl;
			cin.ignore();
			getline(cin, classe);
			cout << "Digite o nome: " << endl;
			getline(cin, nome);
			cout << "Digite o nome científico: " << endl;
			getline(cin, nome_cientifico);
			cout << "Digite a dieta: " << endl;
			getline(cin, dieta);
			cout << "Digite o nome do veterinario: " << endl;
			getline(cin, veterinario);
			check = check_vet(vets, veterinario);
			if(!check){
				cout << endl;
				cout << "Veterinario não cadastrado!" << endl;
				break;
			}
			cout << "Digite o nome do tratador: " << endl;
			getline(cin, tratador);
			check = check_tratador(tratadores, tratador);
			if(!check){
				cout << endl;
				cout << "Tratador não cadastrado!" << endl;
				break;
			}
			cout << "Digite o nome de batismo: " << endl;
			getline(cin, nome_batismo);
			cout << "Digite o sexo do animal: " << endl;
			cin >> sexo;
			cout << "Digite o tamanho do animal: " << endl;
			cin >> tamanho;
			cout << "Digite a cor do pelo: " << endl;
			cin.ignore();
			getline(cin, cor);
			cout << "Insira a autorizacao do IBAMA: " << endl;
			getline(cin, autorizacao_IBAMA);
			

			if(tipo_func == 'n'){
				old_size = mamiferos_nat.size();

				cout << "Digite a UF de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);

				// Armazenando no map dados do tipo mamífero nativo passados pelo usuário.
				mamiferos_nat.insert(pair <int, MAMIFERO_NATIVO> (id, MAMIFERO_NATIVO(id, classe, nome, nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao)));
				
				if (mamiferos_nat.size() == old_size){
					cout << "Falha no cadastro do animal! Tente novamente" << endl;
					continuar = 's';
					continue;
				}
			}
			else{
				old_size = mamiferos_ex.size();
				cout << "Digite o País de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);
				
				// Armazenando no map dados do tipo mamífero exótico passados pelo usuário.
				mamiferos_ex.insert(pair <int, MAMIFERO_EXOTICO> (id, MAMIFERO_EXOTICO(id, classe, nome, nome_cientifico,sexo, tamanho, dieta,veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao)));
				
				if (mamiferos_ex.size() == old_size){
					cout << "Falha no cadastro do animal! Tente novamente" << endl;
					continuar = 's';
					continue;
				}
			}
		}
	
		cout << "Deseja cadastrar um novo animal? s/n" << endl;
		cin >> continuar;
	}while(continuar == 's');

	if(!mamiferos_nat.empty()){
		nativos.open("mamiferos_nat.txt");
		for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
			nativos << (*it).second;
		}
		nativos.close();
	}
	if(!mamiferos_ex.empty()){
		exoticos.open("mamiferos_ex.txt");
		for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
			exoticos << (*it).second;
		}
		exoticos.close();
	}	
}

// Função especifica para cadastro dos répteis.
void cadastrar(map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores){
	int id;
	bool venenoso, check;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, tipo_veneno, nome;
	char sexo, tipo_func, continuar = 's';
	double tamanho;
	unsigned int old_size;
	ofstream nativos;
	ofstream exoticos;

	do{
		cout << "Deseja cadastrar um REPTIL NATIVO ou REPTIL EXÓTICO? \n n - NATIVO\n e - EXÓTICO" << endl;
		cin >> tipo_func;
		if(tipo_func != 'n' && tipo_func != 'e'){
			continuar = 's';
			continue;
		}
		else{
			continuar = 'n';
			cout << "Digite o id: " << endl;
			cin >> id;
			cout << "Digite a classe: " << endl;
			cin.ignore();
			getline(cin, classe);
			cout << "Digite o nome: " << endl;
			getline(cin, nome);
			cout << "Digite o nome científico: " << endl;
			getline(cin, nome_cientifico);
			cout << "Digite a dieta: " << endl;
			getline(cin, dieta);
			cout << "Digite o nome do veterinario: " << endl;
			getline(cin, veterinario);
			check = check_vet(vets, veterinario);
			if(!check){
				cout << endl;
				cout << "Veterinario não cadastrado!" << endl;
				break;
			}
			cout << "Digite o nome do tratador: " << endl;
			getline(cin, tratador);
			check = check_tratador(tratadores, tratador);
			if(!check){
				cout << endl;
				cout << "Tratador não cadastrado!" << endl;
				break;
			}
			cout << "Digite o nome de batismo: " << endl;
			getline(cin, nome_batismo);
			cout << "Digite o sexo do animal: " << endl;
			cin >> sexo;
			cout << "Digite o tamanho do animal: " << endl;
			cin >> tamanho;
			cout << "Digite 0-não venenoso / 1-venenoso: " << endl;
			cin >> venenoso;
			if(venenoso){
				cout << "Digite o tipo do veneno: " << endl;
				cin.ignore();
				getline(cin, tipo_veneno);
			}
			else{
				cin.ignore();
			}
			cout << "Insira a autorizacao do IBAMA: " << endl;
			getline(cin, autorizacao_IBAMA);
			

			if(tipo_func == 'n'){
				old_size = repteis_nat.size();
				cout << "Digite a UF de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);

				// Armazenando no map dados do tipo réptil nativo passados pelo usuário
				repteis_nat.insert(pair <int, REPTIL_NATIVO> (id, REPTIL_NATIVO(id, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao)));
				
				if (repteis_nat.size() == old_size){
					cout << "Falha no cadastro do animal! Tente novamente" << endl;
					continuar = 's';
					continue;
				}
			}
			else{
				old_size = repteis_ex.size();
				cout << "Digite o País de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);
				
				// Armazenando no map dados do tipo réptil exótico passados pelo usuário
				repteis_ex.insert(pair <int, REPTIL_EXOTICO> (id, REPTIL_EXOTICO(id, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao)));
				
				if (repteis_ex.size() == old_size){
					cout << "Falha no cadastro do animal! Tente novamente" << endl;
					continuar = 's';
					continue;
				}
			}
		}
	
		cout << "Deseja cadastrar um novo animal? s/n" << endl;
		cin >> continuar;
	}while(continuar == 's');
		
	if(!repteis_nat.empty()){
		nativos.open("repteis_nat.txt");
		for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
			nativos << (*it).second;
		}
		nativos.close();
	}
	if(!repteis_ex.empty()){
		exoticos.open("repteis_ex.txt");
		for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
			exoticos << (*it).second;
		}
		exoticos.close();
	}	
}

// Função especifica para cadastro das aves.
void cadastrar(map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores){
	int id;
	bool check;
	double tam_bico, envergadura, tamanho;;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, nome;
	char sexo, tipo_func, continuar = 's';
	unsigned int old_size;
	ofstream nativos;
	ofstream exoticos;

	do{
		cout << "Deseja cadastrar um AVE NATIVA ou AVE EXÓTICA? \n n - NATIVA\n e - EXÓTICA" << endl;
		cin >> tipo_func;
		if(tipo_func != 'n' && tipo_func != 'e'){
			continuar = 's';
			continue;
		}
		else{
			continuar = 'n';
			cout << "Digite o id: " << endl;
			cin >> id;
			cout << "Digite a classe: " << endl;
			cin.ignore();
			getline(cin, classe);
			cout << "Digite o nome: " << endl;
			getline(cin, nome);
			cout << "Digite o nome científico: " << endl;
			getline(cin, nome_cientifico);
			cout << "Digite a dieta: " << endl;
			getline(cin, dieta);
			cout << "Digite o nome do veterinario: " << endl;
			getline(cin, veterinario);
			check = check_vet(vets, veterinario);
			if(!check){
				cout << endl;
				cout << "Veterinario não cadastrado!" << endl;
				break;
			}
			cout << "Digite o nome do tratador: " << endl;
			getline(cin, tratador);
			check = check_tratador(tratadores, tratador);
			if(!check){
				cout << endl;
				cout << "Tratador não cadastrado!" << endl;
				break;
			}
			cout << "Digite o nome de batismo: " << endl;
			getline(cin, nome_batismo);
			cout << "Digite o sexo do animal: " << endl;
			cin >> sexo;
			cout << "Digite o tamanho do animal: " << endl;
			cin >> tamanho;
			cout << "Digite o tamanho do bico: " << endl;
			cin >> tam_bico;
			cout << "Digite a envergadura: " << endl;
			cin >> envergadura;
			cout << "Insira a autorizacao do IBAMA: " << endl;
			cin.ignore();
			getline(cin, autorizacao_IBAMA);
			

			if(tipo_func == 'n'){
				old_size = aves_nat.size();
				cout << "Digite a UF de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);

				// Armazenando valores do tipo ave nativa no map passado pelo usuário.
				aves_nat.insert(pair <int, AVE_NATIVO> (id, AVE_NATIVO(id, classe, nome, nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao)));
				
				if (aves_nat.size() == old_size){
					cout << "Falha no cadastro do animal! Tente novamente" << endl;
					continuar = 's';
					continue;
				}
			}
			else if(tipo_func == 'e'){
				old_size = aves_ex.size();
				cout << "Digite o País de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);

				// Armazenando valores de ave exótica no map passada pelo usuário.
				aves_ex.insert(pair <int, AVE_EXOTICO> (id, AVE_EXOTICO(id, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao)));
				
				if (aves_ex.size() == old_size){
					cout << "Falha no cadastro do animal! Tente novamente" << endl;
					continuar = 's';
					continue;
				}
			}
		}
	
		cout << "Deseja cadastrar um novo animal? s/n" << endl;
		cin >> continuar;
	}while(continuar == 's');
	
	if(!aves_nat.empty()){
		nativos.open("aves_nat.txt");
		for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
			nativos << (*it).second;
		}
		nativos.close();
	}
	if(!aves_ex.empty()){
		exoticos.open("aves_ex.txt");
		for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
			exoticos << (*it).second;
		}
		exoticos.close();
	}
}

