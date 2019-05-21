#include "pet_fera.h"

// Função que chama as funções de edição de cada tipo de animal.
void editar_animais(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
	char tipo_animal;
	char resp, op = 'n';

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
			if(tipo_animal == 'a'){
				editar(anfibios_nat, anfibios_ex);
			}
			else if(tipo_animal == 'm'){
				editar(mamiferos_nat, mamiferos_ex);
			}
			else if(tipo_animal == 'r'){
				editar(repteis_nat, repteis_ex);
			}
			else{
				editar(aves_nat, aves_ex);
			}	

		} // Primeiro else.
	}while(op == 's');
}

// Editar anfíbio.
void editar(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex){
	char opcao, resp, op, sucesso, sexo;
	int total_mudas, id_buscado;;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, ultima_muda, nome;
	double tamanho;
	ofstream nativos;
	ofstream exoticos;
			
	do{
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
			if(opcao == 'n'){
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = anfibios_nat.find(id_buscado);
			
				if(result != anfibios_nat.end()){
					cout << "ID existe!" << endl;

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
					cout << "Insira a data da última muda(dd/mm/aaaa)" << endl;
					cin.ignore();
					getline(cin, ultima_muda);
					cout << "Insira a autorizacao do IBAMA: " << endl;
					getline(cin, autorizacao_IBAMA);
					cout << "Digite a UF de origem: " << endl;
					getline(cin, origem);
					cout << "Insira a autorizacao do animal: " << endl;
					getline(cin, autorizacao);

					(*result).second = ANFIBIO_NATIVO(id_buscado, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao);
					sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!!" << endl;
					sucesso = 'n';
				}
				if(sucesso == 's'){
					nativos.open("anfibios_nat.txt");
					for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
						nativos << (*it).second;
					}
					nativos.close();
				}

				cout << "Deseja editar outro? s/n" << endl;
				cin >> op;
				
			}
			else{
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = anfibios_ex.find(id_buscado);
			
				if(result != anfibios_ex.end()){
					cout << "ID existe!" << endl;

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

					(*result).second = ANFIBIO_EXOTICO(id_buscado, classe,nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao);
					sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!!" << endl;
					sucesso = 'n';
				}
				if(sucesso == 's'){
					exoticos.open("anfibios_ex.txt");
					for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
						exoticos << (*it).second;
					}
					exoticos.close();
				}

				cout << "Deseja editar outro? s/n" << endl;
				cin >> op;
			}	
		} // Primeiro else.
	}while(op == 's');
}

// Editar mamífero.
void editar(map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex){
	char opcao, resp, op, sucesso, sexo;
	int id_buscado;;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, cor, nome;
	double tamanho;
	ofstream nativos;
	ofstream exoticos;
			
	do{
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
			if(opcao == 'n'){
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = mamiferos_nat.find(id_buscado);
			
				if(result != mamiferos_nat.end()){
					cout << "ID existe!" << endl;

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


					(*result).second = MAMIFERO_NATIVO(id_buscado, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao);
					sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!!" << endl;
					sucesso = 'n';
				}
				if(sucesso == 's'){
					nativos.open("mamiferos_nat.txt");
					for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
						nativos << (*it).second;
					}
					nativos.close();
				}

				cout << "Deseja editar outro? s/n" << endl;
				cin >> op;
			}
			else{
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = mamiferos_ex.find(id_buscado);
			
				if(result != mamiferos_ex.end()){
					cout << "ID existe!" << endl;

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


					(*result).second = MAMIFERO_EXOTICO(id_buscado, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao);
					sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!!" << endl;
					sucesso = 'n';
				}
				if(sucesso == 's'){
					exoticos.open("mamiferos_ex.txt");
					for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
						exoticos << (*it).second;
					}
					exoticos.close();
				}
				cout << "Deseja editar outro? s/n" << endl;
				cin >> op;
			}
		} // Primeiro else.
	}while(op == 's');
}

// Editar réptil.
void editar(map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex){
	char opcao, resp, op, sucesso, sexo;
	int id_buscado;;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, tipo_veneno, nome;
	double tamanho;
	bool venenoso;
	ofstream nativos;
	ofstream exoticos;
			
	do{
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
			if(opcao == 'n'){
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = repteis_nat.find(id_buscado);
			
				if(result != repteis_nat.end()){
					cout << "ID existe!" << endl;

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
					cout << "Digite o nome do tratador: " << endl;
					getline(cin, tratador);
					cout << "Digite o nome de batismo: " << endl;
					getline(cin, nome_batismo);
					cout << "Digite o sexo do animal: " << endl;
					cin >> sexo;
					cout << "Digite o tamanho do animal: " << endl;
					cin >> tamanho;
					cout << "Digite 0 - não venenoso / 1 - venenoso: " << endl;
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
					cout << "Digite a UF de origem: " << endl;
					getline(cin, origem);
					cout << "Insira a autorizacao do animal: " << endl;
					getline(cin, autorizacao);

					(*result).second = REPTIL_NATIVO(id_buscado, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao);
					sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!!" << endl;
					sucesso = 'n';
				}
				if(sucesso == 's'){
					nativos.open("repteis_nat.txt");
					for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
						nativos << (*it).second;
					}
					nativos.close();
				}

				cout << "Deseja editar outro? s/n" << endl;
				cin >> op;
			}
			else{
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = repteis_ex.find(id_buscado);
			
				if(result != repteis_ex.end()){
					cout << "ID existe!" << endl;

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
					}
					else{
						cin.ignore();
					}
					cout << "Insira a autorizacao do IBAMA: " << endl;
					getline(cin, autorizacao_IBAMA);
					cout << "Digite o País de origem: " << endl;
					getline(cin, origem);
					cout << "Insira a autorizacao do animal: " << endl;
					getline(cin, autorizacao);


					(*result).second = REPTIL_EXOTICO(id_buscado, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao);
					sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!!" << endl;
					sucesso = 'n';
				}
				if(sucesso == 's'){
					exoticos.open("repteis_ex.txt");
					for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
						exoticos << (*it).second;
					}
					exoticos.close();
				}
				cout << "Deseja editar outro? s/n" << endl;
				cin >> op;
			}
		} // Primeiro else.
	}while(op == 's');
}

// Editar ave.
void editar(map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
	char opcao, resp, op, sucesso, sexo;
	int id_buscado;;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, nome;
	double tamanho, envergadura, tam_bico;
	ofstream nativos;
	ofstream exoticos;
			

	do{
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
			if(opcao == 'n'){
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = aves_nat.find(id_buscado);
			
				if(result != aves_nat.end()){
					cout << "ID existe!" << endl;

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

					(*result).second = AVE_NATIVO(id_buscado, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao);
					sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!!" << endl;
					sucesso = 'n';
				}
				if(sucesso == 's'){
					nativos.open("aves_nat.txt");
					for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
						nativos << (*it).second;
					}
					nativos.close();
				}
				cout << "Deseja editar outro? s/n" << endl;
				cin >> op;

			} // IF nativo.
			else{
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = aves_ex.find(id_buscado);
			
				if(result != aves_ex.end()){
					cout << "ID existe!" << endl;

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

					(*result).second = AVE_EXOTICO(id_buscado, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao);
					sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!!" << endl;
					sucesso = 'n';
				}
				if(sucesso == 's'){
					exoticos.open("aves_ex.txt");
					for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
						exoticos << (*it).second;
					}
					exoticos.close();
				}
				cout << "Deseja editar outro? s/n" << endl;
				cin >> op;
			} // Else exótico.
		} // Primeiro else.
	}while(op == 's');
}

// Função que chama as funções de edição de veterinário e tratador.
void editar_func(map <int, VETERINARIO> &vets, map <int, TRATADOR> &tratadores){
	char tipo_func;
	char continuar = 'n';
	
	do{ // Enquanto o usuário quiser editar (continuar != s), o programa roda. 
		cout << "Qual o tipo de funcionario a ser editado? \n -> v - Veterinário\n -> t - Tratador" << endl;
		cin >> tipo_func;
		if(tipo_func != 'v' && tipo_func != 't'){
			cout << "Tipo de funcionario incorreto!! Tente novamente!\n" << endl;
			continuar = 's';
			continue;
		}
		else{
			if(tipo_func == 'v'){
				editar(vets);
			}
			else{
				editar(tratadores);
			}
		}
		cout << "Deseja editar mais funcionarios? s - SIM n - NÃO" << endl;
		cin >> continuar;
	} while (continuar == 's'); // Parada.
}

// Editar veterinário.
void editar(map <int, VETERINARIO> &vets){
	int id_buscado, idade;
	long int cpf;
	string nome, especialidade, crmv, tipo_sang;
	char fator_rh, sucesso;
	ofstream veterinarios;

	cout << "Insira o ID buscado: " << endl;
	cin >> id_buscado;

	auto result = vets.find(id_buscado);
	
	if(result != vets.end()){
		cout << "ID existe!" << endl;

		cout << "Digite o nome: " << endl;
		cin.ignore();
		getline(cin, nome);
		transform(nome.begin(), nome.end(), nome.begin(), ::toupper); //Converte a string nome para caracteres maiusculos
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

		(*result).second = VETERINARIO(id_buscado, nome, cpf, idade, tipo_sang, fator_rh, especialidade, crmv);
		sucesso = 's';
	}
	else{
		cout << "Funcionario não cadastrado!!" << endl;
		sucesso = 'n';
	}

	if(sucesso == 's'){
		veterinarios.open("veterinarios.txt");
		for(auto it = vets.begin(); it != vets.end(); it++){
			veterinarios << (*it).second;
		}
		veterinarios.close();
	}
}

// Editar tratador.
void editar(map <int, TRATADOR> &tratadores){
	int id_buscado, idade,nivel_seg;
	long int cpf;
	string nome, especialidade, tipo_sang;
	char fator_rh, sucesso;
	ofstream tratador;

	cout << "Insira o ID buscado: " << endl;
	cin >> id_buscado;

	auto result = tratadores.find(id_buscado);
	
	if(result != tratadores.end()){
		cout << "ID existe!" << endl;

		cout << "Digite o nome: " << endl;
		cin.ignore();
		getline(cin, nome); 
		transform(nome.begin(), nome.end(), nome.begin(), ::toupper); //Converte a string nome para caracteres maiusculos
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

		(*result).second = TRATADOR(id_buscado, nome, cpf, idade, tipo_sang, fator_rh, especialidade, nivel_seg);
		sucesso = 's';
	}
	else{
		cout << "Funcionario não cadastrado!!" << endl;
		sucesso = 'n';
	}

	if(sucesso == 's'){
		tratador.open("tratadores.txt");
		for(auto it = tratadores.begin(); it != tratadores.end(); it++){
			tratador << (*it).second;
		}
		tratador.close();
	}
}
