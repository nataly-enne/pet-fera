#include "pet_fera.h"

// Função que chama as funções de edição de cada tipo de animal.
void editar_animais(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores){
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
				editar(anfibios_nat, anfibios_ex, vets, tratadores);
			}
			else if(tipo_animal == 'm'){
				editar(mamiferos_nat, mamiferos_ex, vets, tratadores);
			}
			else if(tipo_animal == 'r'){
				editar(repteis_nat, repteis_ex, vets, tratadores);
			}
			else{
				editar(aves_nat, aves_ex, vets, tratadores);
			}	

		} // Primeiro else.
	}while(op == 's');
}

// Editar anfíbio.
void editar(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores){
	char opcao, resp, op, sucesso, sexo, tipo = 'a';
	int total_mudas, id_buscado;;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, ultima_muda, nome, id_string, tamanho_string, sexo_string, total_mudas_string;
	bool check;
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

					//Classe dos anfibios.
					classe = "Amphibia";

					//Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome:" << endl;
						cin.ignore();
						getline(cin, nome);
						if(!verifica_nome(nome, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						else{
							transform(nome.begin(), nome.end(), nome.begin(), ::tolower); // Converte a string nome para caracteres minusculos.
						}
					}while(sucesso == 'n');

			
					//Recebe o nome cientifico e verifica se é valido.
					do{
						cout << "Digite o nome científico:" << endl;
						getline(cin, nome_cientifico);
						if(!verifica_nome_cient(nome_cientifico, sucesso)){
							cout << "ERRO: só pode ser inserido letra, espaço ou traço!" << endl << endl;
						}
					}while(sucesso == 'n');

					//Recebe a dieta e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite a dieta: " << endl;
						getline(cin, dieta);
						if(!verifica_dieta(dieta, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
					}while(sucesso == 'n');
					
					//Recebe o nome do veterinario e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite o nome do veterinario: " << endl;
						getline(cin, veterinario);
						
						if(!verifica_nome(veterinario, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_vet(vets, veterinario);
						if(!check){
							cout << endl;
							cout << "ERRO: Veterinario não cadastrado!" << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');
					
					//Recebe o nome do tratador e verifica se não possui caracteres proibido, se já foi cadastrado ou se possui nivel de segurança adequado.
					do{
						cout << "Digite o nome do tratador: " << endl;
						getline(cin, tratador);
						if(!verifica_nome(tratador, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_tratador(0, tratadores, tratador, tipo);
						if(!check){
							cout << endl;
							cout << "ERRO: Tratador não cadastrado ou não se adequa!" << endl << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');

					
					//Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome de batismo: " << endl;
						getline(cin, nome_batismo);
						if(!verifica_nome(nome_batismo, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						transform(nome_batismo.begin(), nome_batismo.end(), nome_batismo.begin(), ::tolower); // Converte a string nome para caracteres maiúsculos.
					}while(sucesso == 'n');

					//Recebe o sexo do animal e verifica se é F ou M.
					do{
						cout << "Digite o sexo do animal: " << endl;
						getline(cin, sexo_string);
						transform(sexo_string.begin(), sexo_string.end(), sexo_string.begin(), ::toupper); // Converte a string nome para caracteres maiúsculos.
						if(sexo_string != "F" && sexo_string != "M" ){
							sucesso = 'n';
							cout << "ERRO: só são permitidos F ou M!" << endl << endl;
						}
						else{
							sexo = (char)sexo_string[0];
							sucesso = 's';
						}

					}while(sucesso == 'n');
					
					//Recebe o tamanho do animal e verifica se não caracteres pproibidos.
					do{
						cout << "Digite o tamanho do animal: " << endl;
						getline(cin, tamanho_string);
						if(!verifica_tamanho(tamanho_string, sucesso)){
							cout << "ERRO: o tamanho do animal tem que ter apenas um '.' " << endl << endl;
						}
						tamanho = stod(tamanho_string);
					}while(sucesso == 'n');
					
					//Recebe o total de mudas e verifica se é um inteiro positivo.
					do{
						cout << "Insira o total de mudas:" << endl;
						getline(cin, total_mudas_string);
						if(!verifica_inteiro(total_mudas_string, sucesso)){
							cout << "ERRO: O total de mudas deve conter apenas inteiros positivos!" << endl << endl;
						}
						else{
							stringstream ss(total_mudas_string);
							ss >> total_mudas;
						}
					}while(sucesso == 'n');
					
					//Recebe a ultima muda e verifica se está no formato correto.
					do{
						cout << "Insira a data da última muda(dd-mm-aaaa)" << endl;
						getline(cin, ultima_muda);
						if(!verifica_data(ultima_muda, sucesso)){
							cout << "ERRO: A ultima muda deve ser nesse formato ex.: 12-03-2019" << endl << endl;
						}
					}while(sucesso == 'n');

					//Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do IBAMA: " << endl;
						getline(cin, autorizacao_IBAMA);
						if(!verifica_autorizacao(autorizacao_IBAMA, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros e '-'"<< endl << endl;
						}
					}while(sucesso == 'n');


					//Verifica se foi passado uma string.
					do{
						cout << "Digite a UF de origem: " << endl;
						getline(cin, origem);
						if(!verifica_origem(origem, sucesso)){
							cout << "ERRO: Deve-se colocar apenas letras!" << endl << endl;
						}
					}while(sucesso == 'n');

					//Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do animal: " << endl;
						getline(cin, autorizacao);
						if(!verifica_autorizacao(autorizacao, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros e '-'" << endl << endl;
						}
					}while(sucesso == 'n');

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

				cout << "\nDeseja editar outro? s/n" << endl;
				cin >> op;
				
			}
			else{
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = anfibios_ex.find(id_buscado);
			
				if(result != anfibios_ex.end()){
					cout << "ID existe!" << endl;

					//Classe dos anfibios.
					classe = "Amphibia";

					//Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome:" << endl;
						cin.ignore();
						getline(cin, nome);
						if(!verifica_nome(nome, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						else{
							transform(nome.begin(), nome.end(), nome.begin(), ::tolower); // Converte a string nome para caracteres minusculos.
						}
					}while(sucesso == 'n');

			
					//Recebe o nome cientifico e verifica se é valido.
					do{
						cout << "Digite o nome científico:" << endl;
						getline(cin, nome_cientifico);
						if(!verifica_nome_cient(nome_cientifico, sucesso)){
							cout << "ERRO: só pode ser inserido letra, espaço ou traço!" << endl << endl;
						}
					}while(sucesso == 'n');

					//Recebe a dieta e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite a dieta: " << endl;
						getline(cin, dieta);
						if(!verifica_dieta(dieta, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
					}while(sucesso == 'n');
					
					//Recebe o nome do veterinario e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite o nome do veterinario: " << endl;
						getline(cin, veterinario);
						
						if(!verifica_nome(veterinario, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_vet(vets, veterinario);
						if(!check){
							cout << endl;
							cout << "ERRO: Veterinario não cadastrado!" << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');
					
					//Recebe o nome do tratador e verifica se não possui caracteres proibido, se já foi cadastrado ou se possui nivel de segurança adequado.
					do{
						cout << "Digite o nome do tratador: " << endl;
						getline(cin, tratador);
						if(!verifica_nome(tratador, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_tratador(0, tratadores, tratador, tipo);
						if(!check){
							cout << endl;
							cout << "ERRO: Tratador não cadastrado ou não se adequa!" << endl << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');

					
					//Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome de batismo: " << endl;
						getline(cin, nome_batismo);
						if(!verifica_nome(nome_batismo, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						transform(nome_batismo.begin(), nome_batismo.end(), nome_batismo.begin(), ::tolower); // Converte a string nome para caracteres maiúsculos.
					}while(sucesso == 'n');

					//Recebe o sexo do animal e verifica se é F ou M.
					do{
						cout << "Digite o sexo do animal: " << endl;
						getline(cin, sexo_string);
						transform(sexo_string.begin(), sexo_string.end(), sexo_string.begin(), ::toupper); // Converte a string nome para caracteres maiúsculos.
						if(sexo_string != "F" && sexo_string != "M" ){
							sucesso = 'n';
							cout << "ERRO: só são permitidos F ou M!" << endl << endl;
						}
						else{
							sexo = (char)sexo_string[0];
							sucesso = 's';
						}

					}while(sucesso == 'n');
					
					//Recebe o tamanho do animal e verifica se não caracteres pproibidos.
					do{
						cout << "Digite o tamanho do animal: " << endl;
						getline(cin, tamanho_string);
						if(!verifica_tamanho(tamanho_string, sucesso)){
							cout << "ERRO: o tamanho do animal tem que ter apenas um '.' " << endl << endl;
						}
						tamanho = stod(tamanho_string);
					}while(sucesso == 'n');
					
					//Recebe o total de mudas e verifica se é um inteiro positivo.
					do{
						cout << "Insira o total de mudas:" << endl;
						getline(cin, total_mudas_string);
						if(!verifica_inteiro(total_mudas_string, sucesso)){
							cout << "ERRO: O total de mudas deve conter apenas inteiros positivos!" << endl << endl;
						}
						else{
							stringstream ss(total_mudas_string);
							ss >> total_mudas;
						}
					}while(sucesso == 'n');
					
					//Recebe a ultima muda e verifica se está no formato correto.
					do{
						cout << "Insira a data da última muda(dd-mm-aaaa)" << endl;
						getline(cin, ultima_muda);
						if(!verifica_data(ultima_muda, sucesso)){
							cout << "ERRO: A ultima muda deve ser nesse formato ex.: 12-03-2019" << endl << endl;
						}
					}while(sucesso == 'n');

					//Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do IBAMA: " << endl;
						getline(cin, autorizacao_IBAMA);
						if(!verifica_autorizacao(autorizacao_IBAMA, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros e '-'" << endl << endl;
						}
					}while(sucesso == 'n');


					//Verifica se foi passado uma string.
					do{
						cout << "Digite o País de origem: " << endl;
						getline(cin, origem);
						if(!verifica_origem(origem, sucesso)){
							cout << "ERRO: Deve-se colocar apenas letras!" << endl << endl;
						}
					}while(sucesso == 'n');

					//Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do animal: " << endl;
						getline(cin, autorizacao);
						if(!verifica_autorizacao(autorizacao, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros e '-'" << endl << endl;
						}
					}while(sucesso == 'n');

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

				cout << "\nDeseja editar outro? s/n" << endl;
				cin >> op;
			}	
		} // Primeiro else.
	}while(op == 's');
}

// Editar mamífero.
void editar(map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores){
	char resp, op, sucesso, sexo, tipo_animal, tipo = 'm';;
	int id_buscado;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, cor, nome, id_string, sexo_string, tamanho_string;
	double tamanho;
	bool check;
	ofstream nativos;
	ofstream exoticos;
			
	do{
		cout << "É nativo ou exotico? \n n - NATIVO\n e - EXOTICO" << endl;
		cin >> tipo_animal;
		if(tipo_animal != 'n' && tipo_animal != 'e'){
			cout << "Opção inválida!! Tente novamente!\n" << endl;
			cout << endl;
			cout << "Deseja sair? s/n" << endl;
			cin >> resp;
			if(resp == 's'){
				break;
			}	
		}
		else{ 
			if(tipo_animal == 'n'){
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = mamiferos_nat.find(id_buscado);
			
				if(result != mamiferos_nat.end()){
					cout << "ID existe!" << endl;

					classe = "Mammalia";

					//Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome:" << endl;
						cin.ignore();
						getline(cin, nome);
						if(!verifica_nome(nome, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						transform(nome.begin(), nome.end(), nome.begin(), ::tolower); // Converte a string nome para caracteres maiúsculos.
					}while(sucesso == 'n');

					//Recebe o nome cientifico e verifica se é valido.
					do{
						cout << "Digite o nome científico:" << endl;
						getline(cin, nome_cientifico);
						if(!verifica_nome_cient(nome_cientifico, sucesso)){
							cout << "ERRO: só pode ser inserido letra, espaço ou traço!" << endl << endl;
						}
					}while(sucesso == 'n');

					//Recebe a dieta e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite a dieta: " << endl;
						getline(cin, dieta);
						if(!verifica_dieta(dieta, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
					}while(sucesso == 'n');

					//Recebe o nome do veterinario e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite o nome do veterinario: " << endl;
						getline(cin, veterinario);
						
						if(!verifica_nome(veterinario, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_vet(vets, veterinario);
						if(!check){
							cout << endl;
							cout << "ERRO: Veterinario não cadastrado!" << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');

					//Recebe o nome do tratador e verifica se não possui caracter proibido, se já foi cadastrado ou se possui nivel de segurança adequado.
					do{
						cout << "Digite o nome do tratador: " << endl;
						getline(cin, tratador);
						if(!verifica_nome(tratador, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_tratador(0, tratadores, tratador, tipo);
						if(!check){
							cout << endl;
							cout << "ERRO: Tratador não cadastrado ou não se adequa!" << endl << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');

					//Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome de batismo: " << endl;
						getline(cin, nome_batismo);
						if(!verifica_nome(nome_batismo, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						transform(nome_batismo.begin(), nome_batismo.end(), nome_batismo.begin(), ::tolower); // Converte a string nome_batismo para caracteres minusculos.
					}while(sucesso == 'n');

					//Recebe o sexo do animal e verifica se é F ou M.
					do{
						cout << "Digite o sexo do animal: " << endl;
						getline(cin, sexo_string);
						transform(sexo_string.begin(), sexo_string.end(), sexo_string.begin(), ::toupper); // Converte a string sexo para caracteres maiúsculos.
						if(sexo_string != "F" && sexo_string != "M" ){
							sucesso = 'n';
							cout << "ERRO: só são permitidos F ou M!" << endl << endl;
						}
						else{
							sexo = (char)sexo_string[0];
							sucesso = 's';
						}
					}while(sucesso == 'n');

					//Recebe o tamanho do animal e verifica se não caracteres pproibidos.
					do{
						cout << "Digite o tamanho do animal: " << endl;
						getline(cin, tamanho_string);
						if(!verifica_tamanho(tamanho_string, sucesso)){
							cout << "ERRO: o tamanho do animal tem que ter apenas um '.' " << endl << endl;
						}
						tamanho = stod(tamanho_string);
					}while(sucesso == 'n');

					do{
						cout << "Digite a cor do pelo: " << endl;
						getline(cin, cor);
						if(!verifica_cor(cor, sucesso)){
							cout << "ERRO: a cor do animal deve conter letras, espaço ou '-'" << endl << endl;
						}
					}while(sucesso == 'n');
					
					//Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do IBAMA: " << endl;
						getline(cin, autorizacao_IBAMA);
						if(!verifica_autorizacao(autorizacao_IBAMA, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros ou '-'" << endl << endl;
						}
					}while(sucesso == 'n');


					//Verifica se foi passado uma string.
					do{
						cout << "Digite a UF de origem: " << endl;
						getline(cin, origem);
						if(!verifica_origem(origem, sucesso)){
							cout << "ERRO: Deve-se colocar apenas letras!" << endl << endl;
						}
					}while(sucesso == 'n');
					
					//Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do animal: " << endl;
						getline(cin, autorizacao);
						if(!verifica_autorizacao(autorizacao, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros e '-'" << endl << endl;
						}
					}while(sucesso == 'n');

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

					classe = "Mammallia";

					//Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome:" << endl;
						cin.ignore();
						getline(cin, nome);
						if(!verifica_nome(nome, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						transform(nome.begin(), nome.end(), nome.begin(), ::tolower); // Converte a string nome para caracteres maiúsculos.
					}while(sucesso == 'n');

					//Recebe o nome cientifico e verifica se é valido.
					do{
						cout << "Digite o nome científico:" << endl;
						getline(cin, nome_cientifico);
						if(!verifica_nome_cient(nome_cientifico, sucesso)){
							cout << "ERRO: só pode ser inserido letra, espaço ou traço!" << endl << endl;
						}
					}while(sucesso == 'n');

					//Recebe a dieta e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite a dieta: " << endl;
						getline(cin, dieta);
						if(!verifica_dieta(dieta, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
					}while(sucesso == 'n');

					//Recebe o nome do veterinario e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite o nome do veterinario: " << endl;
						getline(cin, veterinario);
						
						if(!verifica_nome(veterinario, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_vet(vets, veterinario);
						if(!check){
							cout << endl;
							cout << "ERRO: Veterinario não cadastrado!" << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');

					//Recebe o nome do tratador e verifica se não possui caracter proibido, se já foi cadastrado ou se possui nivel de segurança adequado.
					do{
						cout << "Digite o nome do tratador: " << endl;
						getline(cin, tratador);
						if(!verifica_nome(tratador, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_tratador(0, tratadores, tratador, tipo);
						if(!check){
							cout << endl;
							cout << "ERRO: Tratador não cadastrado ou não se adequa!" << endl << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');

					//Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome de batismo: " << endl;
						getline(cin, nome_batismo);
						if(!verifica_nome(nome_batismo, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						transform(nome_batismo.begin(), nome_batismo.end(), nome_batismo.begin(), ::tolower); // Converte a string nome_batismo para caracteres minusculos.
					}while(sucesso == 'n');

					//Recebe o sexo do animal e verifica se é F ou M.
					do{
						cout << "Digite o sexo do animal: " << endl;
						getline(cin, sexo_string);
						transform(sexo_string.begin(), sexo_string.end(), sexo_string.begin(), ::toupper); // Converte a string sexo para caracteres maiúsculos.
						if(sexo_string != "F" && sexo_string != "M" ){
							sucesso = 'n';
							cout << "ERRO: só são permitidos F ou M!" << endl << endl;
						}
						else{
							sexo = (char)sexo_string[0];
							sucesso = 's';
						}
					}while(sucesso == 'n');

					//Recebe o tamanho do animal e verifica se não caracteres pproibidos.
					do{
						cout << "Digite o tamanho do animal: " << endl;
						getline(cin, tamanho_string);
						if(!verifica_tamanho(tamanho_string, sucesso)){
							cout << "ERRO: o tamanho do animal tem que ter apenas um '.' " << endl << endl;
						}
						tamanho = stod(tamanho_string);
					}while(sucesso == 'n');

					do{
						cout << "Digite a cor do pelo: " << endl;
						getline(cin, cor);
						if(!verifica_cor(cor, sucesso)){
							cout << "ERRO: a cor do animal deve conter letras, espaço ou '-'" << endl << endl;
						}
					}while(sucesso == 'n');
					
					//Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do IBAMA: " << endl;
						getline(cin, autorizacao_IBAMA);
						if(!verifica_autorizacao(autorizacao_IBAMA, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros ou '-'" << endl << endl;
						}
					}while(sucesso == 'n');

					//Verifica se foi passado uma string.
					do{
						cout << "Digiteo País de origem: " << endl;
						getline(cin, origem);
						if(!verifica_origem(origem, sucesso)){
							cout << "ERRO: Deve-se colocar apenas letras!" << endl << endl;
						}
					}while(sucesso == 'n');
					
					//Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do animal: " << endl;
						getline(cin, autorizacao);
						if(!verifica_autorizacao(autorizacao, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros e '-'" << endl << endl;
						}
					}while(sucesso == 'n');

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
void editar(map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores){
	char resp, op, sucesso, sexo, tipo_animal, tipo = 'r';;
	int id_buscado;
	double tamanho;
	bool venenoso, check;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, tipo_veneno, nome, id_string, sexo_string, tamanho_string, venenoso_string;
	ofstream nativos;
	ofstream exoticos;
			
	do{
		cout << "É nativo ou exotico? \n n - NATIVO\n e - EXOTICO" << endl;
		cin >> tipo_animal;
		if(tipo_animal != 'n' && tipo_animal != 'e'){
			cout << "Opção inválida!! Tente novamente!\n" << endl;
			cout << endl;
			cout << "Deseja sair? s/n" << endl;
			cin >> resp;
			if(resp == 's'){
				break;
			}	
		}
		else{ 
			if(tipo_animal == 'n'){
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = repteis_nat.find(id_buscado);
			
				if(result != repteis_nat.end()){
					cout << "ID existe!" << endl;

					classe = "Reptilia";

					// Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome:" << endl;
						cin.ignore();
						getline(cin, nome);
						if(!verifica_nome(nome, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						transform(nome.begin(), nome.end(), nome.begin(), ::tolower); // Converte a string nome para caracteres maiúsculos.
					}while(sucesso == 'n');

					// Recebe o nome cientifico e verifica se é valido.
					do{
						cout << "Digite o nome científico:" << endl;
						getline(cin, nome_cientifico);
						if(!verifica_nome_cient(nome_cientifico, sucesso)){
							cout << "ERRO: só pode ser inserido letra, espaço ou traço!" << endl << endl;
						}
					}while(sucesso == 'n');

					// Recebe a dieta e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite a dieta: " << endl;
						getline(cin, dieta);
						if(!verifica_dieta(dieta, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
					}while(sucesso == 'n');


					do{
						cout << "Digite 0 - não venenoso / 1 - venenoso: " << endl;
						cin >> venenoso_string;
						if(!verifica_venenoso(venenoso_string,sucesso)){
							cout << "ERRO: Digite apenas 0 para não venenoso OU 1 para venenoso!" << endl << endl;
						}
						else{
							stringstream ss(venenoso_string);
							ss >> venenoso;
							sucesso = 's';
							if(venenoso){
								cout << "Digite o tipo do veneno: " << endl;
								cin.ignore();
								getline(cin, tipo_veneno); 
							}
						}
					}while(sucesso == 'n');

					// Recebe o nome do veterinario e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite o nome do veterinario: " << endl;
						getline(cin, veterinario);
						
						if(!verifica_nome(veterinario, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_vet(vets, veterinario);
						if(!check){
							cout << endl;
							cout << "ERRO: Veterinario não cadastrado!" << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');

					//Recebe o nome do tratador e verifica se não possui caracteres proibido, se já foi cadastrado ou se possui nivel de segurança adequado.
					do{
						cout << "Digite o nome do tratador: " << endl;
						getline(cin, tratador);
						if(!verifica_nome(tratador, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_tratador(venenoso, tratadores, tratador, tipo);
						if(!check){
							cout << endl;
							cout << "ERRO: Tratador não cadastrado ou não se adequa!" << endl << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');

					// Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome de batismo: " << endl;
						getline(cin, nome_batismo);
						if(!verifica_nome(nome_batismo, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						transform(nome_batismo.begin(), nome_batismo.end(), nome_batismo.begin(), ::tolower); // Converte a string nome_batismo para caracteres minusculos.
					}while(sucesso == 'n');

					// Recebe o sexo do animal e verifica se é F ou M.
					do{
						cout << "Digite o sexo do animal: " << endl;
						getline(cin, sexo_string);
						transform(sexo_string.begin(), sexo_string.end(), sexo_string.begin(), ::toupper); // Converte a string sexo para caracteres maiúsculos.
						if(sexo_string != "F" && sexo_string != "M" ){
							sucesso = 'n';
							cout << "ERRO: só são permitidos F ou M!" << endl << endl;
						}
						else{
							sexo = (char)sexo_string[0];
							sucesso = 's';
						}
					}while(sucesso == 'n');

					// Recebe o tamanho do animal e verifica se não caracteres pproibidos.
					do{
						cout << "Digite o tamanho do animal: " << endl;
						getline(cin, tamanho_string);
						if(!verifica_tamanho(tamanho_string, sucesso)){
							cout << "ERRO: o tamanho do animal tem que ter apenas um '.' " << endl << endl;
						}
						tamanho = stod(tamanho_string);
					}while(sucesso == 'n');

					
					
					// Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do IBAMA: " << endl;
						getline(cin, autorizacao_IBAMA);
						if(!verifica_autorizacao(autorizacao_IBAMA, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros ou '-'" << endl << endl;
						}
					}while(sucesso == 'n');

					
					// Verifica se foi passado uma string.
					do{
						cout << "Digite a UF de origem: " << endl;
						getline(cin, origem);
						if(!verifica_origem(origem, sucesso)){
							cout << "ERRO: Deve-se colocar apenas letras!" << endl << endl;
						}
					}while(sucesso == 'n');
					
					// Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do animal: " << endl;
						getline(cin, autorizacao);
						if(!verifica_autorizacao(autorizacao, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros e '-'" << endl << endl;
						}
					}while(sucesso == 'n');

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

					classe = "Reptillia";

					// Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome:" << endl;
						cin.ignore();
						getline(cin, nome);
						if(!verifica_nome(nome, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						transform(nome.begin(), nome.end(), nome.begin(), ::tolower); // Converte a string nome para caracteres maiúsculos.
					}while(sucesso == 'n');

					// Recebe o nome cientifico e verifica se é valido.
					do{
						cout << "Digite o nome científico:" << endl;
						getline(cin, nome_cientifico);
						if(!verifica_nome_cient(nome_cientifico, sucesso)){
							cout << "ERRO: só pode ser inserido letra, espaço ou traço!" << endl << endl;
						}
					}while(sucesso == 'n');

					// Recebe a dieta e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite a dieta: " << endl;
						getline(cin, dieta);
						if(!verifica_dieta(dieta, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
					}while(sucesso == 'n');


					do{
						cout << "Digite 0 - não venenoso / 1 - venenoso: " << endl;
						cin >> venenoso_string;
						if(!verifica_venenoso(venenoso_string,sucesso)){
							cout << "ERRO: Digite apenas 0 para não venenoso OU 1 para venenoso!" << endl << endl;
						}
						else{
							stringstream ss(venenoso_string);
							ss >> venenoso;
							sucesso = 's';
							if(venenoso){
								cout << "Digite o tipo do veneno: " << endl;
								cin.ignore();
								getline(cin, tipo_veneno); 
							}
						}
					}while(sucesso == 'n');

					// Recebe o nome do veterinario e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite o nome do veterinario: " << endl;
						getline(cin, veterinario);
						
						if(!verifica_nome(veterinario, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_vet(vets, veterinario);
						if(!check){
							cout << endl;
							cout << "ERRO: Veterinario não cadastrado!" << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');

					//Recebe o nome do tratador e verifica se não possui caracteres proibido, se já foi cadastrado ou se possui nivel de segurança adequado.
					do{
						cout << "Digite o nome do tratador: " << endl;
						getline(cin, tratador);
						if(!verifica_nome(tratador, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_tratador(venenoso, tratadores, tratador, tipo);
						if(!check){
							cout << endl;
							cout << "ERRO: Tratador não cadastrado ou não se adequa!" << endl << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');

					// Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome de batismo: " << endl;
						getline(cin, nome_batismo);
						if(!verifica_nome(nome_batismo, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						transform(nome_batismo.begin(), nome_batismo.end(), nome_batismo.begin(), ::tolower); // Converte a string nome_batismo para caracteres minusculos.
					}while(sucesso == 'n');

					// Recebe o sexo do animal e verifica se é F ou M.
					do{
						cout << "Digite o sexo do animal: " << endl;
						getline(cin, sexo_string);
						transform(sexo_string.begin(), sexo_string.end(), sexo_string.begin(), ::toupper); // Converte a string sexo para caracteres maiúsculos.
						if(sexo_string != "F" && sexo_string != "M" ){
							sucesso = 'n';
							cout << "ERRO: só são permitidos F ou M!" << endl << endl;
						}
						else{
							sexo = (char)sexo_string[0];
							sucesso = 's';
						}
					}while(sucesso == 'n');

					// Recebe o tamanho do animal e verifica se não caracteres pproibidos.
					do{
						cout << "Digite o tamanho do animal: " << endl;
						getline(cin, tamanho_string);
						if(!verifica_tamanho(tamanho_string, sucesso)){
							cout << "ERRO: o tamanho do animal tem que ter apenas um '.' " << endl << endl;
						}
						tamanho = stod(tamanho_string);
					}while(sucesso == 'n');

					
					
					// Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do IBAMA: " << endl;
						getline(cin, autorizacao_IBAMA);
						if(!verifica_autorizacao(autorizacao_IBAMA, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros ou '-'" << endl << endl;
						}
					}while(sucesso == 'n');

					
					// Verifica se foi passado uma string.
					do{
						cout << "Digite o País de origem: " << endl;
						getline(cin, origem);
						if(!verifica_origem(origem, sucesso)){
							cout << "ERRO: Deve-se colocar apenas letras!" << endl << endl;
						}
					}while(sucesso == 'n');
					
					// Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do animal: " << endl;
						getline(cin, autorizacao);
						if(!verifica_autorizacao(autorizacao, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros e '-'" << endl << endl;
						}
					}while(sucesso == 'n');

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
				cout << "\nDeseja editar outro? s/n" << endl;
				cin >> op;
			}
		} // Primeiro else.
	}while(op == 's');
}

// Editar ave.
void editar(map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores){
	char resp, op, sexo, tipo_animal, sucesso, tipo = 'v';
	int id_buscado;;
	double tamanho, envergadura, tam_bico;
	bool check;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, nome, id_string, sexo_string, tamanho_string, tam_bico_string, envergadura_string;
	ofstream nativos;
	ofstream exoticos;
			

	do{
		cout << "É nativo ou exotico? \n n - NATIVO\n e - EXOTICO" << endl;
		cin >> tipo_animal;
		if(tipo_animal != 'n' && tipo_animal != 'e'){
			cout << "Opção inválida!! Tente novamente!\n" << endl;
			cout << endl;
			cout << "Deseja sair? s/n" << endl;
			cin >> resp;
			if(resp == 's'){
				break;
			}	
		}
		else{ 
			if(tipo_animal == 'n'){
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = aves_nat.find(id_buscado);
			
				if(result != aves_nat.end()){
					cout << "ID existe!" << endl;

					classe = "Aves";

					// Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome:" << endl;
						cin.ignore();
						getline(cin, nome);
						if(!verifica_nome(nome, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						transform(nome.begin(), nome.end(), nome.begin(), ::tolower); // Converte a string nome para caracteres maiúsculos.
					}while(sucesso == 'n');


					// Recebe o nome cientifico e verifica se é valido.
					do{
						cout << "Digite o nome científico:" << endl;
						getline(cin, nome_cientifico);
						if(!verifica_nome_cient(nome_cientifico, sucesso)){
							cout << "ERRO: só pode ser inserido letra, espaço ou traço!" << endl << endl;
						}
					}while(sucesso == 'n');

					// Recebe a dieta e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite a dieta: " << endl;
						getline(cin, dieta);
						if(!verifica_dieta(dieta, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
					}while(sucesso == 'n');

					// Recebe o nome do veterinario e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite o nome do veterinario: " << endl;
						getline(cin, veterinario);
						
						if(!verifica_nome(veterinario, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_vet(vets, veterinario);
						if(!check){
							cout << endl;
							cout << "ERRO: Veterinario não cadastrado!" << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');

					//Recebe o nome do tratador e verifica se não possui caracteres proibido, se já foi cadastrado ou se possui nivel de segurança adequado.
					do{
						cout << "Digite o nome do tratador: " << endl;
						getline(cin, tratador);
						if(!verifica_nome(tratador, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_tratador(0, tratadores, tratador, tipo);
						if(!check){
							cout << endl;
							cout << "ERRO: Tratador não cadastrado ou não se adequa!" << endl << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');

					// Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome de batismo: " << endl;
						getline(cin, nome_batismo);
						if(!verifica_nome(nome_batismo, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						transform(nome_batismo.begin(), nome_batismo.end(), nome_batismo.begin(), ::tolower); // Converte a string nome_batismo para caracteres minusculos.
					}while(sucesso == 'n');

					// Recebe o sexo do animal e verifica se é F ou M.
					do{
						cout << "Digite o sexo do animal: " << endl;
						getline(cin, sexo_string);
						transform(sexo_string.begin(), sexo_string.end(), sexo_string.begin(), ::toupper); // Converte a string sexo para caracteres maiúsculos.
						if(sexo_string != "F" && sexo_string != "M" ){
							sucesso = 'n';
							cout << "ERRO: só são permitidos F ou M!" << endl << endl;
						}
						else{
							sexo = (char)sexo_string[0];
							sucesso = 's';
						}
					}while(sucesso == 'n');

					// Recebe o tamanho do animal e verifica se não caracteres pproibidos.
					do{
						cout << "Digite o tamanho do animal: " << endl;
						getline(cin, tamanho_string);
						if(!verifica_tamanho(tamanho_string, sucesso)){
							cout << "ERRO: o tamanho do animal tem que ter apenas um '.' " << endl << endl;
							continue;
						}
						else{
							tamanho = stod(tamanho_string);
						}
					}while(sucesso == 'n');
						
					// Recebe o tamanho do bico do animal e verifica se não caracteres pproibidos.
					do{
						cout << "Digite o tamanho do bico: " << endl;
						getline(cin, tam_bico_string);
						if(!verifica_tamanho(tam_bico_string, sucesso)){
							cout << "ERRO: o tamanho do animal tem que ter apenas um '.' " << endl << endl;
						}
						tam_bico = stod(tam_bico_string);
					}while(sucesso == 'n');
					
					// Recebe a envergadura do animal e verifica se não caracteres pproibidos.
					do{
						cout << "Digite a envergadura: " << endl;
						getline(cin, envergadura_string);
						if(!verifica_tamanho(envergadura_string, sucesso)){
							cout << "ERRO: o tamanho do animal tem que ter apenas um '.' " << endl << endl;
						}
						envergadura = stod(envergadura_string);
					}while(sucesso == 'n');
					
					// Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do IBAMA: " << endl;
						getline(cin, autorizacao_IBAMA);
						if(!verifica_autorizacao(autorizacao_IBAMA, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros ou '-'" << endl << endl;
						}
					}while(sucesso == 'n');

					// Verifica se foi passado uma string.
					do{
						cout << "Digite a UF de origem: " << endl;
						getline(cin, origem);
						if(!verifica_origem(origem, sucesso)){
							cout << "ERRO: Deve-se colocar apenas letras!" << endl << endl;
						}
					}while(sucesso == 'n');
					
					// Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do animal: " << endl;
						getline(cin, autorizacao);
						if(!verifica_autorizacao(autorizacao, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros e '-'" << endl << endl;
						}
					}while(sucesso == 'n');

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

					classe = "Aves";

					// Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome:" << endl;
						cin.ignore();
						getline(cin, nome);
						if(!verifica_nome(nome, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						transform(nome.begin(), nome.end(), nome.begin(), ::tolower); // Converte a string nome para caracteres maiúsculos.
					}while(sucesso == 'n');


					// Recebe o nome cientifico e verifica se é valido.
					do{
						cout << "Digite o nome científico:" << endl;
						getline(cin, nome_cientifico);
						if(!verifica_nome_cient(nome_cientifico, sucesso)){
							cout << "ERRO: só pode ser inserido letra, espaço ou traço!" << endl << endl;
						}
					}while(sucesso == 'n');

					// Recebe a dieta e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite a dieta: " << endl;
						getline(cin, dieta);
						if(!verifica_dieta(dieta, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
					}while(sucesso == 'n');

					// Recebe o nome do veterinario e verifica se não possui caracteres proibidos.
					do{
						cout << "Digite o nome do veterinario: " << endl;
						getline(cin, veterinario);
						
						if(!verifica_nome(veterinario, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_vet(vets, veterinario);
						if(!check){
							cout << endl;
							cout << "ERRO: Veterinario não cadastrado!" << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');

					//Recebe o nome do tratador e verifica se não possui caracteres proibido, se já foi cadastrado ou se possui nivel de segurança adequado.
					do{
						cout << "Digite o nome do tratador: " << endl;
						getline(cin, tratador);
						if(!verifica_nome(tratador, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						check = check_tratador(0, tratadores, tratador, tipo);
						if(!check){
							cout << endl;
							cout << "ERRO: Tratador não cadastrado ou não se adequa!" << endl << endl;
							sucesso = 'n';
						}
					}while(sucesso == 'n');

					// Recebe o nome e verifica se é valido.
					do{
						cout << "Digite o nome de batismo: " << endl;
						getline(cin, nome_batismo);
						if(!verifica_nome(nome_batismo, sucesso)){
							cout << "ERRO: só pode ser inserido letra ou espaço!" << endl << endl;
						}
						transform(nome_batismo.begin(), nome_batismo.end(), nome_batismo.begin(), ::tolower); // Converte a string nome_batismo para caracteres minusculos.
					}while(sucesso == 'n');

					// Recebe o sexo do animal e verifica se é F ou M.
					do{
						cout << "Digite o sexo do animal: " << endl;
						getline(cin, sexo_string);
						transform(sexo_string.begin(), sexo_string.end(), sexo_string.begin(), ::toupper); // Converte a string sexo para caracteres maiúsculos.
						if(sexo_string != "F" && sexo_string != "M" ){
							sucesso = 'n';
							cout << "ERRO: só são permitidos F ou M!" << endl << endl;
						}
						else{
							sexo = (char)sexo_string[0];
							sucesso = 's';
						}
					}while(sucesso == 'n');

					// Recebe o tamanho do animal e verifica se não caracteres pproibidos.
					do{
						cout << "Digite o tamanho do animal: " << endl;
						getline(cin, tamanho_string);
						if(!verifica_tamanho(tamanho_string, sucesso)){
							cout << "ERRO: o tamanho do animal tem que ter apenas um '.' " << endl << endl;
						}
						tamanho = stod(tamanho_string);
					}while(sucesso == 'n');
						
					// Recebe o tamanho do bico do animal e verifica se não caracteres pproibidos.
					do{
						cout << "Digite o tamanho do bico: " << endl;
						getline(cin, tam_bico_string);
						if(!verifica_tamanho(tam_bico_string, sucesso)){
							cout << "ERRO: o tamanho do animal tem que ter apenas um '.' " << endl << endl;
						}
						tam_bico = stod(tam_bico_string);
					}while(sucesso == 'n');
					
					// Recebe a envergadura do animal e verifica se não caracteres pproibidos.
					do{
						cout << "Digite a envergadura: " << endl;
						getline(cin, envergadura_string);
						if(!verifica_tamanho(envergadura_string, sucesso)){
							cout << "ERRO: o tamanho do animal tem que ter apenas um '.' " << endl << endl;
						}
						envergadura = stod(envergadura_string);
					}while(sucesso == 'n');
					
					// Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do IBAMA: " << endl;
						getline(cin, autorizacao_IBAMA);
						if(!verifica_autorizacao(autorizacao_IBAMA, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros ou '-'" << endl << endl;
						}
					}while(sucesso == 'n');

					// Verifica se foi passado uma string.
					do{
						cout << "Digite o País de origem: " << endl;
						getline(cin, origem);
						if(!verifica_origem(origem, sucesso)){
							cout << "ERRO: Deve-se colocar apenas letras!" << endl << endl;
						}
					}while(sucesso == 'n');
					
					// Verifica se a autorizacao está no formato correto.
					do{
						cout << "Insira a autorizacao do animal: " << endl;
						getline(cin, autorizacao);
						if(!verifica_autorizacao(autorizacao, sucesso)){
							cout << "ERRO: A autorizacao deve conter letras, numeros e '-'" << endl << endl;
						}
					}while(sucesso == 'n');


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
				cout << "\nDeseja editar outro? s/n" << endl;
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
