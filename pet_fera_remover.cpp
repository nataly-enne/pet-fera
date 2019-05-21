#include "pet_fera.h"

// Função que faz a chamada das funções de remover os tipos animais escolhidos pelo usuário.
void remover_animal(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
	char tipo_animal;
	char resp, op = 'n';

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
			if(tipo_animal == 'a'){
				remover(anfibios_nat, anfibios_ex); // Função remover sobrecarregada.
			}
			else if(tipo_animal == 'm'){
				remover(mamiferos_nat, mamiferos_ex);
			}
			else if(tipo_animal == 'r'){
				remover(repteis_nat, repteis_ex);
			}
			else{
				remover(aves_nat, aves_ex);
			}
		
		} // Primeiro else.

	}while(op == 's');
}

// Remover anfíbio.
void remover(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex){
	char op, opcao, resp;
	int id_buscado;
	ofstream nativos;
	ofstream exoticos;
			
	do{
		cout << "É nativo ou exótico? \n n - NATIVO\n e - EXOTICO" << endl;
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
					anfibios_nat.erase(result);

					/* A condição do map não ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
					senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha. */
					nativos.open("anfibios_nat.txt");
					for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
						nativos << (*it).second;
					}
						nativos.close();
					//sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!" << endl;
				}
				cout << "Deseja remover outro? s/n" << endl;
				cin >> op;

			}
			else{
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = anfibios_ex.find(id_buscado);
					
				if(result != anfibios_ex.end()){
					cout << "ID existe!" << endl;
					anfibios_ex.erase(result);

					//A condição do map não ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
					//Senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha
					exoticos.open("anfibios_ex.txt");
					for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
						exoticos << (*it).second;
					}
					exoticos.close();
					//sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!" << endl;
				}
				cout << "Deseja remover outro? s/n" << endl;
				cin >> op;
			}
		} // Primeiro else.
	}while(op == 's');
}

// Remover mamífero.
void remover(map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex){
	char op, opcao, resp;
	int id_buscado;
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
					mamiferos_nat.erase(result);

					/*A condição do map não ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
					senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha. */
					nativos.open("mamiferos_nat.txt");
					for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
						nativos << (*it).second;
					}
						nativos.close();
					//sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!" << endl;
				}
				cout << "Deseja remover outro? s/n" << endl;
				cin >> op;

			}
			else{
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = mamiferos_ex.find(id_buscado);
					
				if(result != mamiferos_ex.end()){
					cout << "ID existe!" << endl;
					mamiferos_ex.erase(result);

					//A condição do map não ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
					//Senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha
					exoticos.open("mamiferos_ex.txt");
					for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
						exoticos << (*it).second;
					}
					exoticos.close();
					//sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!" << endl;
				}
				cout << "Deseja remover outro? s/n" << endl;
				cin >> op;
			}
		} // Primeiro else.
	}while(op == 's');
}

// Remover réptil.
void remover(map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex){
	char op, opcao, resp;
	int id_buscado;
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
					repteis_nat.erase(result);

					//A condição do map não ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
					//Senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha
					nativos.open("repteis_nat.txt");
					for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
						nativos << (*it).second;
					}
						nativos.close();
					//sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!" << endl;
				}
				cout << "Deseja remover outro? s/n" << endl;
				cin >> op;

			}
			else{
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = repteis_ex.find(id_buscado);
					
				if(result != repteis_ex.end()){
					cout << "ID existe!" << endl;
					repteis_ex.erase(result);

					/* A condição do map não ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
					senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha. */
					exoticos.open("repteis_ex.txt");
					for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
						exoticos << (*it).second;
					}
					exoticos.close();
					//sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!" << endl;
				}
				cout << "Deseja remover outro? s/n" << endl;
				cin >> op;
			}
		} // Primeiro else.
	}while(op == 's');
}

// Remover ave.
void remover(map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
	char op, opcao, resp;
	int id_buscado;
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
					aves_nat.erase(result);

					//A condição do map não ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
					//Senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha
					nativos.open("aves_nat.txt");
					for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
						nativos << (*it).second;
					}
						nativos.close();
					//sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!" << endl;
				}
				cout << "Deseja remover outro? s/n" << endl;
				cin >> op;

			}
			else{
				cout << "Insira o ID buscado: " << endl;
				cin >> id_buscado;

				auto result = aves_ex.find(id_buscado);
					
				if(result != aves_ex.end()){
					cout << "ID existe!" << endl;
					aves_ex.erase(result);

					/* A condição do map não ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
					senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha. */
					exoticos.open("aves_ex.txt");
					for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
						exoticos << (*it).second;
					}
					exoticos.close();
					// sucesso = 's';
				}
				else{
					cout << "Animal não cadastrado!" << endl;
				}
				cout << "Deseja remover outro? s/n" << endl;
				cin >> op;
			}
		} // Primeiro else.
	}while(op == 's');
}

// Função que faz a chamada das funções de remover veterinário e tratador.
void remover_funcionario(map <int, VETERINARIO> &vets, map <int, TRATADOR>  &tratadores){
	char tipo_func;
	char resp, op = 'n';

	do{  
		cout << "Qual funcionario deseja remover? \n v - veterinario\n t - tratador" << endl;
		cin >> tipo_func;
		if(tipo_func != 'v' && tipo_func != 't'){
			cout << "Opção inválida!! Tente novamente!\n" << endl;
			cout << endl;
			cout << "Deseja sair? s/n" << endl;
			cin >> resp;
			if(resp == 's'){
				break;
			}
		}
		else{
			if(tipo_func == 'v'){
				remover(vets); // Função remover sobrecarregada.
			}
			else{
				remover(tratadores);
			}
		} // Primeiro else.

	}while(op == 's');
}

// Remover veterinário.
void remover(map <int, VETERINARIO> &vets){
	char op;
	int id_buscado;
	ofstream veterinario;

	do{
		cout << "Insira o ID buscado: " << endl;
		cin >> id_buscado;

		auto result = vets.find(id_buscado);
					
		if(result != vets.end()){
			cout << "ID existe!" << endl;
			vets.erase(result);

			/* A condição do map não ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
			senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha. */
			veterinario.open("veterinarios.txt");
			for(auto it = vets.begin(); it != vets.end(); it++){
				veterinario << (*it).second;
			}
			veterinario.close();
					
		}
		else{
			cout << "Funcionario não cadastrado!" << endl;
		}
		cout << "Deseja remover outro? s/n" << endl;
		cin >> op;

	}while(op == 's');
}

// Remover tratador.
void remover(map <int, TRATADOR>  &tratadores){
	char op;
	int id_buscado;
	ofstream tratador;

	do{
		cout << "Insira o ID buscado: " << endl;
		cin >> id_buscado;

		auto result = tratadores.find(id_buscado);
					
		if(result != tratadores.end()){
			cout << "ID existe!" << endl;
			tratadores.erase(result);

			/* A condição do map não ser vazio para escrever no arquivo foi removido, para que mesmo quando o map estiver vazio escreva no arquivo
			senão, quando o arquivo só tiver uma linha e o usuário for apagar essa linha, mesmo assim o arquivo permacerá com essa linha. */
			tratador.open("tratadores.txt");
			for(auto it = tratadores.begin(); it != tratadores.end(); it++){
				tratador << (*it).second;
			}
			tratador.close();
					
		}
		else{
			cout << "Funcionario não cadastrado!" << endl;
		}
		cout << "Deseja remover outro? s/n" << endl;
		cin >> op;
	}while(op == 's');
}





