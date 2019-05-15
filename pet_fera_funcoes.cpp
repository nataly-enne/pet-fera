#include "pet_fera.h"

//***Falta implementar***

// 1- Remoção dos animais
// 2- Utilizar o vector melhor

void cadastrar_func(map <int, VETERINARIO> &vets, map <int, TRATADOR>  &tratadores){ //_func
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

void cadastrar(map <int, VETERINARIO> &vets){ //_vet
	int id, idade;
	unsigned int old_size;
	long int cpf;
	string nome, especialidade, crmv, tipo_sang;
	char fator_rh;
	old_size = vets.size();

	cout << "Digite o id: " << endl;
	cin >> id;
	cout << "Digite o nome: " << endl;
	cin.ignore();
	getline(cin, nome); //pegar o nome e sobrenome
	cout << "Digite o cpf: " << endl;
	cin >> cpf;
	cout << "Digite a idade: " << endl;
	cin >> idade;
	cout << "Insira o tipo sanguineo: " << endl;
	cin >> tipo_sang;
	cout << "Insira o fator RH: " << endl;
	cin >> fator_rh;
	cout << "Digite a especialidade: " << endl;
	cin >> especialidade;
	cout << "Digite o crmv: "<< endl;
	cin >> crmv;
	vets[id] = VETERINARIO(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, crmv);
	//vets.push_back(v);
	if (vets.size() == old_size){ //não adicionou ao vector, por isso continua com o tam antigo
		cout << "Falha no cadastro do funcionario!" << endl;
	}
	else{
		cout << "Cadastro efetuado com sucesso!!" << endl;
		//cout << v << endl;
	}
}

	void cadastrar(map <int, TRATADOR>  &tratadores){ //_trat
	int id, idade,nivel_seg;
	unsigned int old_size;
	long int cpf;
	string nome, especialidade, tipo_sang;
	char fator_rh;
	old_size = tratadores.size();

	cout << "Digite o id: " << endl;
	cin >> id;
	cout << "Digite o nome: " << endl;
	cin.ignore();
	getline(cin, nome);  //pegar o nome e sobrenome
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
	cout << "Digite o nivel de seguranca: "<< endl;
	cin >> nivel_seg;
	
	tratadores[id] = TRATADOR(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, nivel_seg);

	//tratadores.push_back(t);
	
	if (tratadores.size() == old_size){ //não adicionou ao vector, por isso continua com o tam antigo
		cout << "Falha no cadastro do funcionario!" << endl;
	}else{
		cout << "Cadastro efetuado com sucesso!!" << endl;
	}
}


//void remover funcionario();

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

void cadastrar(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex){
	int id, total_mudas, ultima_muda[3];
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem;
	char sexo, tipo_func, continuar = 's';
	double tamanho;
	unsigned int old_size;

	do{
		cout << "Deseja cadastrar um ANFIBIO NATIVO ou ANNFIBIO EXOTICO? \n n - NATIVO\n e - EXOTICO" << endl;
		cin >> tipo_func;
		if(tipo_func != 'n' && tipo_func != 'e'){
			//continuar = 's';
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
			cin >> ultima_muda[0] >> ultima_muda[1] >> ultima_muda[2];
			cout << "Insira a autorizacao do IBAMA: " << endl;
			cin.ignore();
			getline(cin, autorizacao_IBAMA);
			

			if(tipo_func == 'n'){
				old_size = anfibios_nat.size();

				cout << "Digite a UF de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);

				anfibios_nat[id] = ANFIBIO_NATIVO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao);

				//anfibios_nat.push_back(a);

				//Cria o arquivo se não houver
				ofstream appFile;
				appFile.open("anfibios_nativos.txt", ios::app);
				if(!appFile){
					cout << "Arquivo nao encontrado :( " << endl;
					exit(0);	
				}
				appFile << id << ';' << classe << ';' << nome_cientifico << ';' << sexo << ';' << tamanho << ';' << dieta << ';' << veterinario << ';' <<  tratador << ';' <<  nome_batismo << ';' << total_mudas << ';' << ultima_muda[0] << '/' << ultima_muda[1] << '/' << ultima_muda[2]  << ';' << autorizacao_IBAMA << ';' << origem << ';' << autorizacao << ';' << '\n';
				appFile.close();
				//Fecha o arquivo

				if (anfibios_nat.size() == old_size){
					cout << "Falha no cadastro do animal!" << endl;
				}
				else{
					cout << "Cadastro efetuado com sucesso!!" << endl;
				}
			}
			else if(tipo_func == 'e'){
				old_size = anfibios_ex.size();
				cout << "Digite o País de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);

				anfibios_ex[id] = ANFIBIO_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta,veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao);

				//anfibios_ex.push_back(a);

				//Cria o arquivo se não houver
				ofstream appFile;
				appFile.open("anfibios_exoticos.txt", ios::app);
				if(!appFile){
					cout << "Arquivo nao encontrado :( " << endl;
					exit(0);	
				}
				appFile << id << ';' << classe << ';' << nome_cientifico << ';' << sexo << ';' << tamanho << ';' << dieta << ';' << veterinario << ';' <<  tratador << ';' <<  nome_batismo << ';' << total_mudas << ';' << ultima_muda[0] << '/' << ultima_muda[1] << '/' << ultima_muda[2]  << ';' << autorizacao_IBAMA << ';' << origem << ';' << autorizacao << ';' << '\n';
				appFile.close();
				//Fecha o arquivo

				if (anfibios_nat.size() == old_size){
					cout << "Falha no cadastro do animal!" << endl;
				}
				else{
					cout << "Cadastro efetuado com sucesso!!" << endl;
				}
			}
		}
	

	}while(continuar == 's');
	
}

void cadastrar(map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex){
	int id;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, cor;
	char sexo, tipo_func, continuar = 's';
	double tamanho;
	unsigned int old_size;

	do{
		cout << "Deseja cadastrar um MAMIFERO NATIVO ou MAMIFERO EXOTICO? \n n - NATIVO\n e - EXOTICO" << endl;
		cin >> tipo_func;
		if(tipo_func != 'n' && tipo_func != 'e'){
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

				mamiferos_nat[id] = MAMIFERO_NATIVO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao);

				//mamiferos_nat.push_back(m);

				//Cria o arquivo se não houver
				ofstream appFile;
				appFile.open("mamiferos_nativos.txt", ios::app);
				if(!appFile){
					cout << "Arquivo nao encontrado :( " << endl;
					exit(0);	
				}
				appFile << id << ';' << classe << ';' << nome_cientifico << ';' << sexo << ';' << tamanho << ';' << dieta << ';' << veterinario << ';' <<  tratador << ';' <<  nome_batismo << ';' << cor  << ';' << autorizacao_IBAMA << ';' << origem << ';' << autorizacao << ';' << '\n';
				appFile.close();
				//Fecha o arquivo

				if (mamiferos_nat.size() == old_size){
					cout << "Falha no cadastro do animal!" << endl;
				}
				else{
					cout << "Cadastro efetuado com sucesso!!" << endl;
				}
			}
			else if(tipo_func == 'e'){
				old_size = mamiferos_ex.size();
				cout << "Digite o País de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);

				mamiferos_ex[id] = MAMIFERO_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta,veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao);

				//mamiferos_ex.push_back(m);

				//Cria o arquivo se não houver
				ofstream appFile;
				appFile.open("mamiferos_exoticos.txt", ios::app);
				if(!appFile){
					cout << "Arquivo nao encontrado :( " << endl;
					exit(0);	
				}
				appFile << id << ';' << classe << ';' << nome_cientifico << ';' << sexo << ';' << tamanho << ';' << dieta << ';' << veterinario << ';' <<  tratador << ';' <<  nome_batismo << ';' << cor  << ';' << autorizacao_IBAMA << ';' << origem << ';' << autorizacao << ';' << '\n';
				appFile.close();
				//Fecha o arquivo

				if (mamiferos_ex.size() == old_size){
					cout << "Falha no cadastro do animal!" << endl;
				}
				else{
					cout << "Cadastro efetuado com sucesso!!" << endl;
				}
			}
		}
	

	}while(continuar == 's');
	
}

void cadastrar(map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex){
	int id;
	bool venenoso;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, tipo_veneno;
	char sexo, tipo_func, continuar = 's';
	double tamanho;
	unsigned int old_size;

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
			cout << "Digite o tipo do veneno: " << endl;
			cin.ignore();
			getline(cin, tipo_veneno);
			cout << "Insira a autorizacao do IBAMA: " << endl;
			getline(cin, autorizacao_IBAMA);
			

			if(tipo_func == 'n'){
				old_size = repteis_nat.size();
				cout << "Digite a UF de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);

				repteis_nat[id] = REPTIL_NATIVO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao);

				//repteis_nat.push_back(r);
			
				//Cria o arquivo se não houver
				ofstream appFile;
				appFile.open("repteis_nativos.txt", ios::app);
				if(!appFile){
					cout << "Arquivo nao encontrado :( " << endl;
					exit(0);	
				}
				appFile << id << ';' << classe << ';' << nome_cientifico << ';' << sexo << ';' << tamanho << ';' << dieta << ';' << veterinario << ';' <<  tratador << ';' <<  nome_batismo << ';' << venenoso << ';' << tipo_veneno << ';'  << ';' << autorizacao_IBAMA << ';' << origem << ';' << autorizacao << ';' << '\n';
				appFile.close();
				//Fecha o arquivo
			
				if (repteis_nat.size() == old_size){
					cout << "Falha no cadastro do animal!" << endl;
				}
				else{
					cout << "Cadastro efetuado com sucesso!!" << endl;
				}
			}
			else if(tipo_func == 'e'){
				old_size = repteis_ex.size();
				cout << "Digite o País de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);

				repteis_ex[id] = REPTIL_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao);

				//repteis_ex.push_back(r);

				//Cria o arquivo se não houver
				ofstream appFile;
				appFile.open("repteis_nativos.txt", ios::app);
				if(!appFile){
					cout << "Arquivo nao encontrado :( " << endl;
					exit(0);	
				}
				appFile << id << ';' << classe << ';' << nome_cientifico << ';' << sexo << ';' << tamanho << ';' << dieta << ';' << veterinario << ';' <<  tratador << ';' <<  nome_batismo << ';' << venenoso << ';' << tipo_veneno << ';'  << ';' << autorizacao_IBAMA << ';' << origem << ';' << autorizacao << ';' << '\n';
				appFile.close();
				//Fecha o arquivo

				if (repteis_ex.size() == old_size){
					cout << "Falha no cadastro do animal!" << endl;
				}
				else{
					cout << "Cadastro efetuado com sucesso!!" << endl;
				}
			}
		}
	

	}while(continuar == 's');
	
}

void cadastrar(map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
	int id;
	double tam_bico, envergadura;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem;
	char sexo, tipo_func, continuar = 's';
	double tamanho;
	unsigned int old_size;

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

				aves_nat[id] = AVE_NATIVO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao);

				//aves_nat.push_back(a);

				//Cria o arquivo se não houver
				ofstream appFile;
				appFile.open("aves_nativas.txt", ios::app);
				if(!appFile){
					cout << "Arquivo nao encontrado :( " << endl;
					exit(0);	
				}
				appFile << id << ';' << classe << ';' << nome_cientifico << ';' << sexo << ';' << tamanho << ';' << dieta << ';' << veterinario << ';' <<  tratador << ';' <<  nome_batismo << ';' << tam_bico << ';' << envergadura << ';'  << ';' << autorizacao_IBAMA << ';' << origem << ';' << autorizacao << ';' << '\n';
				appFile.close();
				//Fecha o arquivo

				if (aves_nat.size() == old_size){
					cout << "Falha no cadastro do animal!" << endl;
				}
				else{
					cout << "Cadastro efetuado com sucesso!!" << endl;
				}
			}
			else if(tipo_func == 'e'){
				old_size = aves_ex.size();
				cout << "Digite o País de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);

				aves_ex[id] = AVE_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao);

				//aves_ex.push_back(a);

				//Cria o arquivo se não houver
				ofstream appFile;
				appFile.open("aves_exoticas.txt", ios::app);
				if(!appFile){
					cout << "Arquivo nao encontrado :( " << endl;
					exit(0);	
				}
				appFile << id << ';' << classe << ';' << nome_cientifico << ';' << sexo << ';' << tamanho << ';' << dieta << ';' << veterinario << ';' <<  tratador << ';' <<  nome_batismo << ';' << tam_bico << ';' << envergadura << ';'  << ';' << autorizacao_IBAMA << ';' << origem << ';' << autorizacao << ';' << '\n';
				appFile.close();
				//Fecha o arquivo

				if (aves_ex.size() == old_size){
					cout << "Falha no cadastro do animal!" << endl;
				}
				else{
					cout << "Cadastro efetuado com sucesso!!" << endl;
				}
			}
		}
	

	}while(continuar == 's');
	
}

void alterar_dados(){
	char tipo_animal, opcao;
	char continuar = 'n', resp;

	do{
		cout << "Alterar dados de um animal? \n s/n" << endl;
		cin >> opcao;
		if(opcao != 's'){
			cout << "Opção inválida!! Tente novamente!\n" << endl;
			cout << endl;
			cout << "Deseja sair? s/n" << endl;
			cin >> resp;
			if(resp == 's'){
				continuar = 'n';;
				break;
			}
			continuar = 's';
			continue;
		}
		else{
			cout << "Qual animal a ser editado? \n a - anfíbio\n m - mamífero \n r - reptil \n v - ave" << endl;
			cin >> tipo_animal;
			if(tipo_animal != 'a' && tipo_animal != 'm' && tipo_animal != 'r' && tipo_animal != 'v' ){
				cout << "Opção inválida!! Tente novamente!\n" << endl;
				cout << endl;
				cout << "Deseja sair? s/n" << endl;
				cin >> resp;
				if(resp == 's'){
					continuar = 'n';;
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
							continuar = 'n';
							break;
						}	
					}
					else{
						if(tipo_animal == 'a' && opcao == 'n'){
							fstream appFile("anfibios_nativos.txt", ios::in | ios::out); //Abrir para leitura e escrita ao mesmo tempo
							string str;
							int id_buscado, id;
							char delim = ';';

							//map<int, ANFIBIO_NATIVO>mp_anfibio_nat;
	
							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							while(appFile){
								if(!appFile.eof()){

									getline(appFile, str);
									for(int i=0; i<(int)str.size(); i++){

										if(str[i] == delim){
											int tmp = i;
											for(int j=0; j<tmp; j++){
												istringstream(str) >> id;
												if(id_buscado == id){
													cout << "Id encontrado" << endl;
													break;
												}
											}
											cout << endl;
											break;
										}


									}
									
								}else{
									appFile.close();
									break;
								}

							}
						

						}
						else if(tipo_animal == 'a' && opcao == 'e'){
							fstream appFile("anfibios_exoticos.txt", ios::in | ios::out); //Abrir apra leitura e escrita ao mesmo tempo

						}
						else if(tipo_animal == 'm' && opcao == 'n'){
							fstream appFile("mamiferos_nativos.txt", ios::in | ios::out); //Abrir apra leitura e escrita ao mesmo tempo

						}
						else if(tipo_animal == 'm' && opcao == 'e'){
							fstream appFile("mamiferos_exoticos.txt", ios::in | ios::out); //Abrir apra leitura e escrita ao mesmo tempo

						}
						else if(tipo_animal == 'r' && opcao == 'n'){
							fstream appFile("repteis_nativos.txt", ios::in | ios::out); //Abrir apra leitura e escrita ao mesmo tempo

						}
						else if(tipo_animal == 'r' && opcao == 'e'){
							fstream appFile("repteis_exoticos.txt", ios::in | ios::out); //Abrir apra leitura e escrita ao mesmo tempo

						}
						else if(tipo_animal == 'v' && opcao == 'n'){
							fstream appFile("aves_nativas.txt", ios::in | ios::out); //Abrir apra leitura e escrita ao mesmo tempo

						}
						else if(tipo_animal == 'v' && opcao == 'e'){
							fstream appFile("aves_exoticas.txt", ios::in | ios::out); //Abrir apra leitura e escrita ao mesmo tempo

						}

						//cout << "ok" << endl;
					}
			}
		}



	}while(continuar == 's');

}



/*

//vector <ANIMAL_NATIVO> &nativos, vector <ANIMAL_EXOTICO> &exoticos, vector <ANIMAL_SILVESTRE> &silvestres


//void remover_animal()

//menu listar animal */
/*
void listar_animal(vector <ANFIBIO> &list_a, vector <MAMIFERO> &list_m, vector <REPTIL> &list_r, vector <AVE> &list_v){

	char tipo_func;
	char continuar = 'n';

	do{
		cout << "Qual tipo de animal você quer listar? \n a - anfíbio\n m - mamífero \n r - repteis \n e - aves" << endl;
		cin >> tipo_func;
		if(tipo_func != 'a' && tipo_func != 'm' && tipo_func != 'r' && tipo_func != 'v'){
			cout << "Tipo de animal incorreto!! Tente novamente!\n" << endl;
			continuar = 's';
			continue;
		}else{
			if(tipo_func == 'a'){
				listar_anfibio(list_a);
			}
			else if(tipo_func == 'm'){
				listar_mamifero(list_m);
			}
			else if(tipo_func == 'r'){
				listar_reptil(list_r);
			}		
			else{
				listar_ave(list_v);
			}
		}
	} while (continuar == 's');
	
}


void listar_anfibio(vector <ANFIBIO> &lista_a){
	
	int i;
	for(i = 0; i < (int)list_a.size(); i++){
		cout << list_a[i];
	}
}

void listar_mamifero(vector <MAMIFERO> &lista_m){
	
	int i;
	for(i = 0; i < (int)list_m.size(); i++){
		cout << list_m[i];
	}
}

void listar_reptil(vector <REPTIL> &lista_r){
	
	int i;
	for(i = 0; i < (int)list_r.size(); i++){
		cout << list_r[i];
	}
}

void listar_ave(vector <AVE> &lista_v){
	
	int i;
	for(i = 0; i < (int)list_v.size(); i++){
		cout << list_v[i];
	}
}
 */












