#include "pet_fera.h"


//Carrega todos os arquivos pra seus respectivos maps, para assim ser utilizado de forma eficiente em todas as operações
void carregar_arquivos(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex, map <int, VETERINARIO> &vets, map <int, TRATADOR> &tratadores){
	int id, total_mudas, nivel_seg, idade;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao_IBAMA, origem, autorizacao,  ultima_muda, cor, tipo_veneno, crmv, nome, tipo_sang, especialidade;
	char sexo, fator_rh;
	long int cpf;
	double tamanho, tamanho_bico, envergadura;
	bool venenoso; 
	string vetor_anfibios[14];
	string vetor_mamiferos[13];
	string vetor_repteis[14];
	string vetor_aves[14];
	string vetor_veterinarios[8];
	string vetor_tratadores[8];
	string line, tmp;
	int cont = 0, j;

	//Carregando o arquivo "anfibios_nat.txt" para o seu map
	ifstream appFile("anfibios_nat.txt");

	if(appFile.is_open()){
		while(getline(appFile, line)){ 
			cont = 0;
			j = 0;
			for(int i=0; i<(int)line.length(); i++){
				if(line[i]  == ';'){
					vetor_anfibios[cont] = tmp;
					//cout << "tmp: " << tmp <<endl;
					tmp.erase();
					cont++;
					j = 0;
				}
				else{
					tmp.push_back(line[i]);
					j++;
				}

			}

			id = stoi(vetor_anfibios[0]);
			classe = vetor_anfibios[1];
			nome_cientifico = vetor_anfibios[2];
			sexo = (char) vetor_anfibios[3][0];
			tamanho = stod(vetor_anfibios[4]);
			dieta = vetor_anfibios[5];
			veterinario = vetor_anfibios[6];
			tratador = vetor_anfibios[7];
			nome_batismo = vetor_anfibios[8];
			total_mudas = stoi(vetor_anfibios[9]);
			ultima_muda = vetor_anfibios[10];
			autorizacao_IBAMA = vetor_anfibios[11];
			origem = vetor_anfibios[12];
			autorizacao = vetor_anfibios[13];

			anfibios_nat.insert(pair <int, ANFIBIO_NATIVO>(id, ANFIBIO_NATIVO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile.close();
	}


	//Carregando o arquivo "anfibios_ex.txt" para o seu map
	ifstream appFile2("anfibios_ex.txt");
		if(appFile2.is_open()){
			while(getline(appFile2, line)){
				cont = 0;
				j = 0;
				for(int i=0; i<(int)line.length(); i++){
					if(line[i]  == ';'){
						vetor_anfibios[cont] = tmp;
						tmp.erase();
						cont++;
						j = 0;
					}
					else{
						tmp.push_back(line[i]);
						j++;
					}
				}

			id = stoi(vetor_anfibios[0]);
			classe = vetor_anfibios[1];
			nome_cientifico = vetor_anfibios[2];
			sexo = (char) vetor_anfibios[3][0];
			tamanho = stod(vetor_anfibios[4]);
			dieta = vetor_anfibios[5];
			veterinario = vetor_anfibios[6];
			tratador = vetor_anfibios[7];
			nome_batismo = vetor_anfibios[8];
			total_mudas = stoi(vetor_anfibios[9]);
			ultima_muda = vetor_anfibios[10];
			autorizacao_IBAMA = vetor_anfibios[11];
			origem = vetor_anfibios[12];
			autorizacao = vetor_anfibios[13];

			anfibios_ex.insert(pair <int, ANFIBIO_EXOTICO>(id, ANFIBIO_EXOTICO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile2.close();
	}


	//Carregando o arquivo "mamiferos_nat.txt" para o seu map
	ifstream appFile3("mamiferos_nat.txt");
	if(appFile3.is_open()){
		while(getline(appFile3, line)){
				cont = 0;
				j = 0;
				for(int i=0; i<(int)line.length(); i++){
					if(line[i]  == ';'){
						vetor_mamiferos[cont] = tmp;
						tmp.erase();
						cont++;
						j = 0;
					}
					else{
						tmp.push_back(line[i]);
						j++;
					}
				}

			id = stoi(vetor_mamiferos[0]);
			classe = vetor_mamiferos[1];
			nome_cientifico = vetor_mamiferos[2];
			sexo = (char) vetor_mamiferos[3][0];
			tamanho = stod(vetor_mamiferos[4]);
			dieta = vetor_mamiferos[5];
			veterinario = vetor_mamiferos[6];
			tratador = vetor_mamiferos[7];
			nome_batismo = vetor_mamiferos[8];
			cor = vetor_mamiferos[9];
			autorizacao_IBAMA = vetor_mamiferos[10];
			origem = vetor_mamiferos[11];
			autorizacao = vetor_mamiferos[12];

			mamiferos_nat.insert(pair <int, MAMIFERO_NATIVO>(id, MAMIFERO_NATIVO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile3.close();
	}

	
	//Carregando o arquivo "mamiferos_nat.txt" para o seu map
	ifstream appFile4("mamiferos_ex.txt");
	if(appFile4.is_open()){
		while(getline(appFile4, line)){
				cont = 0;
				j = 0;
				for(int i=0; i<(int)line.length(); i++){
					if(line[i]  == ';'){
						vetor_mamiferos[cont] = tmp;
						tmp.erase();
						cont++;
						j = 0;
					}
					else{
						tmp.push_back(line[i]);
						j++;
					}
				}

			id = stoi(vetor_mamiferos[0]);
			classe = vetor_mamiferos[1];
			nome_cientifico = vetor_mamiferos[2];
			sexo = (char) vetor_mamiferos[3][0];
			tamanho = stod(vetor_mamiferos[4]);
			dieta = vetor_mamiferos[5];
			veterinario = vetor_mamiferos[6];
			tratador = vetor_mamiferos[7];
			nome_batismo = vetor_mamiferos[8];
			cor = vetor_mamiferos[9];
			autorizacao_IBAMA = vetor_mamiferos[10];
			origem = vetor_mamiferos[11];
			autorizacao = vetor_mamiferos[12];

			mamiferos_ex.insert(pair <int, MAMIFERO_EXOTICO>(id, MAMIFERO_EXOTICO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile4.close();
	}

	//Carregando o arquivo "repteis_nat.txt" para o seu map
	ifstream appFile5("repteis_nat.txt");
	if(appFile5.is_open()){
		while(getline(appFile5, line)){
				cont = 0;
				j = 0;
				for(int i=0; i<(int)line.length(); i++){
					if(line[i]  == ';'){
						vetor_repteis[cont] = tmp;
						tmp.erase();
						cont++;
						j = 0;
					}
					else{
						tmp.push_back(line[i]);
						j++;
					}
				}

	
			id = stoi(vetor_repteis[0]);
			classe = vetor_repteis[1];
			nome_cientifico = vetor_repteis[2];
			sexo = (char) vetor_repteis[3][0];
			tamanho = stod(vetor_repteis[4]);
			dieta = vetor_repteis[5];
			veterinario = vetor_repteis[6];
			tratador = vetor_repteis[7];
			nome_batismo = vetor_repteis[8];
			venenoso = stoi(vetor_repteis[9]);
			tipo_veneno = vetor_repteis[10];
			autorizacao_IBAMA = vetor_repteis[11];
			origem = vetor_repteis[12];
			autorizacao = vetor_repteis[13];

			repteis_nat.insert(pair <int, REPTIL_NATIVO>(id, REPTIL_NATIVO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile5.close();
	}

	//Carregando o arquivo "repteis_ex.txt" para o seu map
	ifstream appFile6("repteis_ex.txt");
	if(appFile6.is_open()){
		while(getline(appFile6, line)){
				cont = 0;
				j = 0;
				for(int i=0; i<(int)line.length(); i++){
					if(line[i]  == ';'){
						vetor_repteis[cont] = tmp;
						tmp.erase();
						cont++;
						j = 0;
					}
					else{
						tmp.push_back(line[i]);
						j++;
					}
				}

	
			id = stoi(vetor_repteis[0]);
			classe = vetor_repteis[1];
			nome_cientifico = vetor_repteis[2];
			sexo = (char) vetor_repteis[3][0];
			tamanho = stod(vetor_repteis[4]);
			dieta = vetor_repteis[5];
			veterinario = vetor_repteis[6];
			tratador = vetor_repteis[7];
			nome_batismo = vetor_repteis[8];
			venenoso = stoi(vetor_repteis[9]);
			tipo_veneno = vetor_repteis[10];
			autorizacao_IBAMA = vetor_repteis[11];
			origem = vetor_repteis[12];
			autorizacao = vetor_repteis[13];

			repteis_ex.insert(pair <int, REPTIL_EXOTICO>(id, REPTIL_EXOTICO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile6.close();
	}

	//Carregando o arquivo "anfibios_nat.txt" para o seu map
	ifstream appFile7("aves_nat.txt");
	if(appFile7.is_open()){
		while(getline(appFile7, line)){
				cont = 0;;
				j = 0;
				for(int i=0; i<(int)line.length(); i++){
					if(line[i]  == ';'){
						vetor_aves[cont] = tmp;
						tmp.erase();
						cont++;
						j = 0;
					}
					else{
						tmp.push_back(line[i]);
						j++;
					}
				}
	
			id = stoi(vetor_aves[0]);
			classe = vetor_aves[1];
			nome_cientifico = vetor_aves[2];
			sexo = (char) vetor_aves[3][0];
			tamanho = stod(vetor_aves[4]);
			dieta = vetor_aves[5];
			veterinario = vetor_aves[6];
			tratador = vetor_aves[7];
			nome_batismo = vetor_aves[8];
			tamanho_bico = stod(vetor_aves[9]);
			envergadura = stod(vetor_aves[10]);
			autorizacao_IBAMA = vetor_aves[11];
			origem = vetor_aves[12];
			autorizacao = vetor_aves[13];

			aves_nat.insert(pair <int, AVE_NATIVO>(id, AVE_NATIVO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tamanho_bico, envergadura, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile7.close();
	}

	//Carregando o arquivo "aves_ex.txt" para o seu map
	ifstream appFile8("aves_ex.txt");
	if(appFile8.is_open()){
		while(getline(appFile8, line)){
				cont = 0;
				j = 0;
				for(int i=0; i<(int)line.length(); i++){
					if(line[i]  == ';'){
						vetor_aves[cont] = tmp;
						tmp.erase();
						cont++;
						j = 0;
					}
					else{
						tmp.push_back(line[i]);
						j++;
					}
				}
	
			id = stoi(vetor_aves[0]);
			classe = vetor_aves[1];
			nome_cientifico = vetor_aves[2];
			sexo = (char) vetor_aves[3][0];
			tamanho = stod(vetor_aves[4]);
			dieta = vetor_aves[5];
			veterinario = vetor_aves[6];
			tratador = vetor_aves[7];
			nome_batismo = vetor_aves[8];
			tamanho_bico = stod(vetor_aves[9]);
			envergadura = stod(vetor_aves[10]);
			autorizacao_IBAMA = vetor_aves[11];
			origem = vetor_aves[12];
			autorizacao = vetor_aves[13];

			aves_ex.insert(pair <int, AVE_EXOTICO>(id, AVE_EXOTICO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tamanho_bico, envergadura, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile8.close();
	}
	//carregando arquivo veterinarios.txt no map
	ifstream appFile9("veterinarios.txt");
	if(appFile9.is_open()){
		while(getline(appFile9, line)){
				cont = 0;
				j = 0;
				for(int i=0; i<(int)line.length(); i++){
					if(line[i]  == ';'){
						vetor_veterinarios[cont] = tmp;
						tmp.erase();
						cont++;
						j = 0;
					}
					else{
						tmp.push_back(line[i]);
						j++;
					}
				}
			
			id = stoi(vetor_veterinarios[0]);
			nome = vetor_veterinarios[1];
			cpf = stol(vetor_veterinarios[2]);
			idade = stoi(vetor_veterinarios[3]);
			tipo_sang = vetor_veterinarios[4];
			fator_rh = (char) vetor_veterinarios[5][0];
			especialidade = vetor_veterinarios[6];
			crmv = vetor_veterinarios[7];

			vets.insert(pair <int, VETERINARIO>(id, VETERINARIO(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, crmv)));
		}
		appFile9.close();
	}

	//carregando arquivo "tratadores.txt"
	ifstream appFile10("tratadores.txt");
	if(appFile10.is_open()){
		while(getline(appFile10, line)){
				cont = 0;
				j = 0;
				for(int i=0; i<(int)line.length(); i++){
					if(line[i]  == ';'){
						vetor_tratadores[cont] = tmp;
						tmp.erase();
						cont++;
						j = 0;
					}
					else{
						tmp.push_back(line[i]);
						j++;
					}
				}
			
			id = stoi(vetor_tratadores[0]);
			nome = vetor_tratadores[1];
			cpf = stol(vetor_tratadores[2]);
			idade = stoi(vetor_tratadores[3]);
			tipo_sang = vetor_tratadores[4];
			fator_rh = (char) vetor_tratadores[5][0];
			especialidade = vetor_tratadores[6];
			nivel_seg = stoi(vetor_tratadores[7]);

			tratadores.insert(pair <int, TRATADOR>(id, TRATADOR(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, nivel_seg)));
		}
		appFile10.close();
	}


}

//Função geral cadastrar os funcionarios
void cadastrar_func(map <int, VETERINARIO> &vets, map <int, TRATADOR>  &tratadores){
	char tipo_func;
	char continuar = 'n';
	do{
		cout << "Qual o tipo de funcionario a ser cadastrado? \n -> v - Veterinário\n -> t - Tratador" << endl;
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
	} while (continuar == 's');
	
}
//Função especifica para cadastro dos veterinarios
void cadastrar(map <int, VETERINARIO> &vets){ 
	int id, idade;
	unsigned int old_size;
	long int cpf;
	string nome, especialidade, crmv, tipo_sang;
	char fator_rh, continuar;
	old_size = vets.size();
	ofstream veterinarios;
	do{
		cout << "Digite o id: " << endl;
		cin >> id;
		cout << "Digite o nome: " << endl;
		cin.ignore();
		getline(cin, nome);
		cout << "Digite o cpf: " << endl;
		cin >> cpf;
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

		vets.insert(pair <int, VETERINARIO> (id,VETERINARIO(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, crmv)));
		

		cout << "Deseja cadastrar um novo animal? s/n" << endl;
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


//Função especifica para cadastro dos tratadores
void cadastrar(map <int, TRATADOR>  &tratadores){ 
	int id, idade,nivel_seg;
	unsigned int old_size;
	long int cpf;
	string nome, especialidade, tipo_sang;
	char fator_rh, continuar;
	old_size = tratadores.size();
	ofstream tratador;
	do{
		cout << "Digite o id: " << endl;
		cin >> id;
		cout << "Digite o nome: " << endl;
		cin.ignore();
		getline(cin, nome);  
		cout << "Digite o cpf: " << endl;
		cin >> cpf;
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
		
		tratadores.insert(pair <int, TRATADOR> (id, TRATADOR(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, nivel_seg)));
		
		cout << "Deseja cadastrar um novo animal? s/n" << endl;
		cin >> continuar;
	}while(continuar == 's');

		if (tratadores.size() == old_size){ 
			cout << "Falha no cadastro do funcionario!" << endl;
		}else{

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

//Função geral para cadastro dos animais
void cadastrar_animal(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
	char tipo_func; //_animal
	char continuar = 'n', resp;

	do{
		cout << "Qual animal a ser cadastrado? \n a - anfíbio\n m - mamífero \n r - repteis \n v - aves" << endl;
		cin >> tipo_func;
		if(tipo_func != 'a' && tipo_func != 'm' && tipo_func != 'r' && tipo_func != 'v'){
			cout << "Tipo de animal incorreto!! Tente novamente!\n" << endl;
			cout << endl;
			cout << "Deseja sair ?" << endl;
			cin >> resp;
			if(resp == 's'){
				continuar = 'n';;
				break;
			}
			continuar = 's';
			continue;
		}else{
			if(tipo_func == 'a'){
				cadastrar(anfibios_nat, anfibios_ex);
			}
			else if(tipo_func == 'm'){
				cadastrar(mamiferos_nat, mamiferos_ex);
			}
			else if(tipo_func == 'r'){
				cadastrar(repteis_nat, repteis_ex);
			}		
			else{
				cadastrar(aves_nat, aves_ex);
			}
		}
	} while (continuar == 's');
	
}

//Função especifica para cadastro dos anfibios
void cadastrar(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex){
	int id, total_mudas;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, ultima_muda;

	char sexo, tipo_func, continuar;
	double tamanho;
	unsigned int old_size;
	ofstream nativos;
	ofstream exoticos;

	do{
		cout << "Deseja cadastrar um ANFIBIO NATIVO ou ANNFIBIO EXOTICO? \n n - NATIVO\n e - EXOTICO" << endl;
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
			cout << "Digite o nome científico: " << endl;
			getline(cin, nome_cientifico);
			cout << "Digite a dieta: " << endl;
			getline(cin, dieta);
			cout << "Digite o nome do veterinario: " << endl;
			getline(cin, veterinario);
			cout << "Digite o nome do tratador: " << endl;
			getline(cin, tratador);
			cout << "Digite o nome de batismo: " << endl;
			getline(cin, nome_batismo);
			cout << "Digite o sexo do animal: " << endl;
			cin >> sexo;
			cout << "Digite o tamanho do animal: " << endl;
			cin >> tamanho;
			cout << "Insira o total de mudas:" << endl;
			cin >> total_mudas;
			cout << "Insira a data da última muda(D/M/A)" << endl;
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

				anfibios_nat.insert(pair <int, ANFIBIO_NATIVO> (id,ANFIBIO_NATIVO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao)));

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

				anfibios_ex.insert(pair <int, ANFIBIO_EXOTICO> (id, ANFIBIO_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta,veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao)));
							
				if (anfibios_nat.size() == old_size){
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

//Função especifica para cadastro dos mamiferos
void cadastrar(map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex){
	int id;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, cor;
	char sexo, tipo_func, continuar = 's';
	double tamanho;
	unsigned int old_size;
	ofstream nativos;
	ofstream exoticos;

	do{
		cout << "Deseja cadastrar um MAMIFERO NATIVO ou MAMIFERO EXOTICO? \n n - NATIVO\n e - EXOTICO" << endl;
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
			cout << "Digite o nome científico: " << endl;
			getline(cin, nome_cientifico);
			cout << "Digite a dieta: " << endl;
			getline(cin, dieta);
			cout << "Digite o nome do veterinario: " << endl;
			getline(cin, veterinario);
			cout << "Digite o nome do tratador: " << endl;
			getline(cin, tratador);
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

				mamiferos_nat.insert(pair <int, MAMIFERO_NATIVO> (id, MAMIFERO_NATIVO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao)));
				
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

				mamiferos_ex.insert(pair <int, MAMIFERO_EXOTICO> (id, MAMIFERO_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta,veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao)));
				
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

//Função especifica para cadastro dos reppteis
void cadastrar(map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex){
	int id;
	bool venenoso;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, tipo_veneno;
	char sexo, tipo_func, continuar = 's';
	double tamanho;
	unsigned int old_size;
	ofstream nativos;
	ofstream exoticos;

	do{
		cout << "Deseja cadastrar um REPTIL NATIVO ou REPTIL EXOTICO? \n n - NATIVO\n e - EXOTICO" << endl;
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
			cout << "Digite o nome científico: " << endl;
			getline(cin, nome_cientifico);
			cout << "Digite a dieta: " << endl;
			getline(cin, dieta);
			cout << "Digite o nome do veterinario: " << endl;
			getline(cin, veterinario);
			cout << "Digite o nome do tratador: " << endl;
			getline(cin, tratador);
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
			}else{
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

				repteis_nat.insert(pair <int, REPTIL_NATIVO> (id, REPTIL_NATIVO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao)));
				
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

				repteis_ex.insert(pair <int, REPTIL_EXOTICO> (id, REPTIL_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao)));
				
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

//Função especifica para cadastro das aves
void cadastrar(map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
	int id;
	double tam_bico, envergadura, tamanho;;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem;
	char sexo, tipo_func, continuar = 's';
	unsigned int old_size;
	ofstream nativos;
	ofstream exoticos;

	do{
		cout << "Deseja cadastrar um AVE NATIVA ou AVE EXOTICA? \n n - NATIVA\n e - EXOTICA" << endl;
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
			cout << "Digite o nome científico: " << endl;
			getline(cin, nome_cientifico);
			cout << "Digite a dieta: " << endl;
			getline(cin, dieta);
			cout << "Digite o nome do veterinario: " << endl;
			getline(cin, veterinario);
			cout << "Digite o nome do tratador: " << endl;
			getline(cin, tratador);
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

				aves_nat.insert(pair <int, AVE_NATIVO> (id, AVE_NATIVO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao)));
				
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

				aves_ex.insert(pair <int, AVE_EXOTICO> (id, AVE_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao)));
				
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


//Função para remover funcionarios
void remover_funcionario(map <int, VETERINARIO> &vets, map <int, TRATADOR>  &tratadores){
		char tipo_funcionario;
		char resp, op = 's';
		ofstream funcionarios;

		do{  
			cout << "Qual funcionario deseja remover? \n v - veterinario\n t - tratador" << endl;
			cin >> tipo_funcionario;
			if(tipo_funcionario != 'v' && tipo_funcionario != 't' ){
				cout << "Opção inválida!! Tente novamente!\n" << endl;
				cout << endl;
				cout << "Deseja sair? s/n" << endl;
				cin >> resp;
					if(resp == 's'){
						break;
					}
			}
			else{
				if(tipo_funcionario == 'v'){
						int id_buscado;

						cout << "Insira o ID buscado: " << endl;
						cin >> id_buscado;

						auto result = vets.find(id_buscado);
						
						if(result != vets.end()){
							cout << "ID existe!" << endl;
							vets.erase(result);

							//A condição do map nao ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
							//Senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha
							funcionarios.open("veterinarios.txt");
							for(auto it = vets.begin(); it != vets.end(); it++){
								funcionarios<< (*it).second;
							}
							funcionarios.close();
						}
						
						cout << "Deseja remover outro ? s/n" << endl;
						cin >> op;
					}
					
					else if(tipo_funcionario == 't'){
							int id_buscado;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = tratadores.find(id_buscado);
						
							if(result != tratadores.end()){
								cout << "ID existe!" << endl;
								tratadores.erase(result);

								//A condição do map nao ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
								//Senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha
								funcionarios.open("tratadores.txt");
								for(auto it = tratadores.begin(); it != tratadores.end(); it++){
									funcionarios << (*it).second;
								}
								funcionarios.close();
							}
						
						cout << "Deseja remover outro ? s/n" << endl;
						cin >> op;
					}

			}//ELSE INICIAL


		}while(op == 's');

}

//Função para remover os animais
void remover_animal(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
		char tipo_animal, opcao;
		char resp, op = 's';
		ofstream nativos;
		ofstream exoticos;

		do{  
			cout << "Qual animal deseja remover? \n a - anfíbio\n m - mamífero \n r - reptil \n v - ave" << endl;
			cin >> tipo_animal;
			if(tipo_animal != 'a' && tipo_animal != 'm' && tipo_animal != 'r' && tipo_animal != 'v' ){
				cout << "Opção inválida!! Tente novamente!\n" << endl;
				cout << endl;
				cout << "Deseja sair? s/n" << endl;
				cin >> resp;
					if(resp == 's'){
						break;
					}
			}
			else{
				cout << "É nativo ou exotico? \n n - NATIVO\n e - EXOTICO" << endl;
				cin >> opcao;
				if(opcao != 'n' && opcao != 'e'){
					cout << "Opção inválida!! Tente novamente!\n" << endl;
					cout << endl;
					cout << "Deseja sair? s/n" << endl;
					cin >> resp;
						if(resp == 's'){
							break;
						}	
				}


				else{ 
					if(tipo_animal == 'a' && opcao == 'n'){
							int id_buscado;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = anfibios_nat.find(id_buscado);
						
							if(result != anfibios_nat.end()){
								cout << "ID existe!" << endl;
								anfibios_nat.erase(result);

								//A condição do map nao ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
								//Senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha
								nativos.open("anfibios_nat.txt");
								for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
									nativos << (*it).second;
								}
								nativos.close();
							}
						
						cout << "Deseja remover outro ? s/n" << endl;
						cin >> op;
					}
					else if(tipo_animal == 'a' && opcao == 'e'){
							int id_buscado;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = anfibios_ex.find(id_buscado);
						
							if(result != anfibios_ex.end()){
								cout << "ID existe!" << endl;
								anfibios_ex.erase(result);

								//A condição do map nao ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
								//Senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha
								exoticos.open("anfibios_ex.txt");
								for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
									exoticos << (*it).second;
								}
								exoticos.close();
								
							}
							cout << "Deseja remover outro ? s/n" << endl;
							cin >> op;
			
					}
					else if(tipo_animal == 'm' && opcao == 'n'){
							int id_buscado;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = mamiferos_nat.find(id_buscado);
						
							if(result != mamiferos_nat.end()){
								cout << "ID existe!" << endl;
								mamiferos_nat.erase(result);

								//A condição do map nao ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
								//Senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha
								nativos.open("mamiferos_nat.txt");
								for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
									nativos << (*it).second;
								}
								nativos.close();
							}
						
						cout << "Deseja remover outro ? s/n" << endl;
						cin >> op;
					}
					else if(tipo_animal == 'm' && opcao == 'e'){
							int id_buscado;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = mamiferos_ex.find(id_buscado);
						
							if(result != mamiferos_ex.end()){
								cout << "ID existe!" << endl;
								mamiferos_ex.erase(result);

								//A condição do map nao ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
								//Senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha
								exoticos.open("mamiferos_ex.txt");
								for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
									exoticos << (*it).second;
								}
								exoticos.close();
							}
						
						cout << "Deseja remover outro ? s/n" << endl;
						cin >> op;
					}
					else if(tipo_animal == 'r' && opcao == 'n'){
							int id_buscado;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = repteis_nat.find(id_buscado);
						
							if(result != repteis_nat.end()){
								cout << "ID existe!" << endl;
								repteis_nat.erase(result);

								//A condição do map nao ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
								//Senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha
								nativos.open("repteis_nat.txt");
								for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
									nativos << (*it).second;
								}
								nativos.close();
							}
						
						cout << "Deseja remover outro ? s/n" << endl;
						cin >> op;
					}
					else if(tipo_animal == 'r' && opcao == 'e'){
							int id_buscado;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = repteis_ex.find(id_buscado);
						
							if(result != repteis_ex.end()){
								cout << "ID existe!" << endl;
								repteis_ex.erase(result);

								//A condição do map nao ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
								//Senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha
								exoticos.open("repteis_ex.txt");
								for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
									exoticos << (*it).second;
								}
								exoticos.close();
							}
						
						cout << "Deseja remover outro ? s/n" << endl;
						cin >> op;
					}
					else if(tipo_animal == 'v' && opcao == 'n'){
							int id_buscado;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = aves_nat.find(id_buscado);
						
							if(result != aves_nat.end()){
								cout << "ID existe!" << endl;
								aves_nat.erase(result);

								//A condição do map nao ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
								//Senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha
								nativos.open("aves_nat.txt");
								for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
									nativos << (*it).second;
								}
								nativos.close();
							}
						
						cout << "Deseja remover outro ? s/n" << endl;
						cin >> op;
					}
					else if(tipo_animal == 'v' && opcao == 'e'){
							int id_buscado;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = aves_ex.find(id_buscado);
						
							if(result != aves_ex.end()){
								cout << "ID existe!" << endl;
								aves_ex.erase(result);

								//A condição do map nao ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
								//Senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha
								exoticos.open("aves_ex.txt");
								for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
									exoticos << (*it).second;
								}
								exoticos.close();
							}
						
						cout << "Deseja remover outro ? s/n" << endl;
						cin >> op;
					}


				}//Else das condições tipo_animal & opcao
				

			}//ELSE INICIAL


		}while(op == 's');

}



void alterar_dados(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
		char tipo_animal, opcao;
		char resp, op='s';

		do{  
			cout << "Qual animal deseja editar? \n a - anfíbio\n m - mamífero \n r - reptil \n v - ave" << endl;
			cin >> tipo_animal;
			if(tipo_animal != 'a' && tipo_animal != 'm' && tipo_animal != 'r' && tipo_animal != 'v' ){
				cout << "Opção inválida!! Tente novamente!\n" << endl;
				cout << endl;
				cout << "Deseja sair? s/n" << endl;
				cin >> resp;
					if(resp == 's'){
						break;
					}
			}
				else{
					cout << "É nativo ou exotico? \n n - NATIVO\n e - EXOTICO" << endl;
					cin >> opcao;
					if(opcao != 'n' && opcao != 'e'){
						cout << "Opção inválida!! Tente novamente!\n" << endl;
						cout << endl;
						cout << "Deseja sair? s/n" << endl;
						cin >> resp;
						if(resp == 's'){
							break;
						}	
					}

					else{ 
						if(tipo_animal == 'a' && opcao == 'n'){
							int id_buscado;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = anfibios_nat.find(id_buscado);
						
							if(result != anfibios_nat.end()){
								cout << "ID existe!" << endl;

								int total_mudas;
								string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, ultima_muda;
								char sexo;;
								double tamanho;
								ofstream nativos;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
								cout << "Digite o nome de batismo: " << endl;
								getline(cin, nome_batismo);
								cout << "Digite o sexo do animal: " << endl;
								cin >> sexo;
								cout << "Digite o tamanho do animal: " << endl;
								cin >> tamanho;
								cout << "Insira o total de mudas:" << endl;
								cin >> total_mudas;
								cout << "Insira a data da última muda(D/M/A)" << endl;
								cin.ignore();
								getline(cin, ultima_muda);
								cout << "Insira a autorizacao do IBAMA: " << endl;
								getline(cin, autorizacao_IBAMA);
								cout << "Digite a UF de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);

								(*result).second = ANFIBIO_NATIVO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao);
								
								if(!anfibios_nat.empty()){
									nativos.open("anfibios_nat.txt");
									for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
										nativos << (*it).second;
									}
									nativos.close();
								}

								cout << "Editar outro ?" << endl;
								cin >> op;

							}
						}
						else if(tipo_animal == 'a' && opcao == 'e'){
							int id_buscado;
							int total_mudas;
							string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, ultima_muda;
							char sexo;;
							double tamanho;
							ofstream exoticos;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = anfibios_ex.find(id_buscado);
						
							if(result != anfibios_ex.end()){
								cout << "ID existe!" << endl;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
								cout << "Digite o nome de batismo: " << endl;
								getline(cin, nome_batismo);
								cout << "Digite o sexo do animal: " << endl;
								cin >> sexo;
								cout << "Digite o tamanho do animal: " << endl;
								cin >> tamanho;
								cout << "Insira o total de mudas:" << endl;
								cin >> total_mudas;
								cout << "Insira a data da última muda(D/M/A)" << endl;
								cin.ignore();
								getline(cin, ultima_muda);
								cout << "Insira a autorizacao do IBAMA: " << endl;
								getline(cin, autorizacao_IBAMA);
								cout << "Digiteo País de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);

								(*result).second = ANFIBIO_EXOTICO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao);
								
								if(!anfibios_ex.empty()){
									exoticos.open("anfibios_ex.txt");
									for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
										exoticos << (*it).second;
									}
									exoticos.close();
								}

								cout << "Deseja editar outro ? s/n" << endl;
								cin >> op;

							}
						}
						else if(tipo_animal == 'm' && opcao == 'n'){
							int id_buscado;
							string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, cor;
							char sexo;;
							double tamanho;
							ofstream nativos;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = mamiferos_nat.find(id_buscado);
						
							if(result != mamiferos_nat.end()){
								cout << "ID existe!" << endl;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
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
								cout << "Digite a UF de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);


								(*result).second = MAMIFERO_NATIVO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao);
								
								if(!mamiferos_nat.empty()){
									nativos.open("mamiferos_nat.txt");
									for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
										nativos << (*it).second;
									}
									nativos.close();
								}

								cout << "Deseja editar outro ? s/n" << endl;
								cin >> op;
								
								}
							}
						
						else if(tipo_animal == 'm' && opcao == 'e'){
							int id_buscado;
							string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, cor;
							char sexo;;
							double tamanho;
							ofstream exoticos;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = mamiferos_ex.find(id_buscado);
						
							if(result != mamiferos_ex.end()){
								cout << "ID existe!" << endl;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
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
								cout << "Digiteo País de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);


								(*result).second = MAMIFERO_EXOTICO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao);
								
								if(!mamiferos_ex.empty()){
									exoticos.open("mamiferos_ex.txt");
									for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
										exoticos << (*it).second;
									}
									exoticos.close();
								}
								cout << "Deseja editar outro ? s/n" << endl;
								cin >> op;
							}	
						}

						else if(tipo_animal == 'r' && opcao == 'n'){
							int id_buscado;
							string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, tipo_veneno;
							char sexo;
							double tamanho;
							bool venenoso;
							ofstream nativos;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = repteis_nat.find(id_buscado);
						
							if(result != repteis_nat.end()){
								cout << "ID existe!" << endl;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
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
								}else{
									cin.ignore();
								}
								cout << "Insira a autorizacao do IBAMA: " << endl;
								getline(cin, autorizacao_IBAMA);
								cout << "Digite a UF de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);

								(*result).second = REPTIL_NATIVO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao);
								
								if(!repteis_nat.empty()){
									nativos.open("repteis_nat.txt");
									for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
										nativos << (*it).second;
									}
									nativos.close();
								}

								cout << "Deseja editar outro ? s/n" << endl;
								cin >> op;
								
								}
						}
						else if(tipo_animal == 'r' && opcao == 'e'){
						int id_buscado;
							string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, tipo_veneno;
							char sexo;
							double tamanho;
							bool venenoso;
							ofstream exoticos;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = repteis_ex.find(id_buscado);
						
							if(result != repteis_ex.end()){
								cout << "ID existe!" << endl;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
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
								}else{
									cin.ignore();
								}
								cout << "Insira a autorizacao do IBAMA: " << endl;
								getline(cin, autorizacao_IBAMA);
								cout << "Digite o País de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);


								(*result).second = REPTIL_EXOTICO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao);
								
								if(!repteis_ex.empty()){
									exoticos.open("repteis_ex.txt");
									for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
										exoticos << (*it).second;
									}
									exoticos.close();
								}

								cout << "Deseja editar outro ? s/n" << endl;
								cin >> op;
								
								}
						}	

						
						else if(tipo_animal == 'v' && opcao == 'n'){
							int id_buscado;
							string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem;
							char sexo;
							double tamanho;
							double envergadura, tam_bico;
							ofstream nativos;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = aves_nat.find(id_buscado);
						
							if(result != aves_nat.end()){
								cout << "ID existe!" << endl;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
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
								cout << "Digite a UF de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);

								(*result).second = AVE_NATIVO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao);
								
								if(!aves_nat.empty()){
									nativos.open("aves_nat.txt");
									for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
										nativos << (*it).second;
									}
									nativos.close();
								}

								cout << "Deseja editar outro ? s/n" << endl;
								cin >> op;
								
								}
						}	

						else if(tipo_animal == 'v' && opcao == 'e'){
						int id_buscado;
							string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem;
							char sexo;
							double tamanho;
							double envergadura, tam_bico;
							ofstream exoticos;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = aves_ex.find(id_buscado);
						
							if(result != aves_ex.end()){
								cout << "ID existe!" << endl;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
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
								cout << "Digite o País de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);

								(*result).second = AVE_EXOTICO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao);
								
								if(!aves_ex.empty()){
									exoticos.open("aves_ex.txt");
									for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
										exoticos << (*it).second;
									}
									exoticos.close();
								}

								cout << "Deseja editar outro ? s/n" << endl;
								cin >> op;
								
								}
							}

					}
				}			

	}while(op == 's');

}
