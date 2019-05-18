#include "pet_fera.h"

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
		cout << "Deseja editar mais funcionarios? s-sim n-nao" << endl;
		cin >> continuar;
	} while (continuar == 's'); // Parada 
}

void editar(map <int, VETERINARIO> &vets){
	int id_buscado;
	ofstream veterinarios;
	char sucesso;
	cout << "Insira o ID buscado: " << endl;
	cin >> id_buscado;

	auto result = vets.find(id_buscado);
	
	if(result != vets.end()){
		cout << "ID existe!" << endl;

		int idade;
		long int cpf;
		string nome, especialidade, crmv, tipo_sang;
		char fator_rh;
	
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

		(*result).second = VETERINARIO(id_buscado, nome, cpf, idade, tipo_sang, fator_rh, especialidade, crmv);
		sucesso = 's';
	}else{
		cout << "Funcionario nao cadastrado!!" << endl;
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

void editar(map <int, TRATADOR> &tratadores){
	int id_buscado;
	ofstream tratador;
	char sucesso;

	cout << "Insira o ID buscado: " << endl;
	cin >> id_buscado;

	auto result = tratadores.find(id_buscado);
	
	if(result != tratadores.end()){
		cout << "ID existe!" << endl;

		int idade,nivel_seg;
		long int cpf;
		string nome, especialidade, tipo_sang;
		char fator_rh;
	
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

		(*result).second = TRATADOR(id_buscado, nome, cpf, idade, tipo_sang, fator_rh, especialidade, nivel_seg);
		sucesso = 's';
	}else{
		cout << "Funcionario nao cadastrado!!" << endl;
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

void editar_animal(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
	char tipo_animal; //_animal
	char continuar = 'n', resp;

	do{
		cout << "Qual animal a ser editado? \n a - anfíbio\n m - mamífero \n r - repteis \n v - aves" << endl;
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
			if(tipo_animal == 'a'){
				editar(anfibios_nat, anfibios_ex);
			}
			else if(animal == 'm'){
				editar(mamiferos_nat, mamiferos_ex);
			}
			else if(animal == 'r'){
				editar(repteis_nat, repteis_ex);
			}		
			else{
				editar(aves_nat, aves_ex);
			}
		}
	} while (continuar == 's');
	
}

void editar(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex){
	char opcao;
	char resp, op = 's';

	cout << "O anfíbio é nativo ou exotico? \n n - NATIVO\n e - EXOTICO" << endl;
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
				cout << "Insira a data da última muda(dd/mm/aaaa)" << endl;
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

			}
		}
		else if(opcao == 'e'){
			int id_buscado;
			int total_mudas;
			string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, ultima_muda;
			char sexo;
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
	}
}