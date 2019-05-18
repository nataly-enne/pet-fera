#include "pet_fera.h"

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




