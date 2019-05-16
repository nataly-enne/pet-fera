#include "pet_fera.h"

//***Falta implementar***

// 1- Remoção dos animais
// 2- Utilizar o vector melhor


void carregar_arquivos(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex, map <int, VETERINARIO> &vets, map <int, TRATADOR> &tratadores){
<<<<<<< HEAD
	int id, total_mudas, op = 1;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao_IBAMA, origem, autorizacao,  ultima_muda, cor, tipo_veneno;
	char sexo;
=======
	int id, total_mudas, nivel_seg, idade;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao_IBAMA, origem, autorizacao,  ultima_muda, cor, tipo_veneno, crmv, nome, tipo_sang, especialidade;
	char sexo, fator_rh;
	long int cpf;
>>>>>>> Hilton
	double tamanho, tamanho_bico, envergadura;
	bool venenoso; 
	string vetor_anfibios[14];
	string vetor_mamiferos[13];
	string vetor_repteis[14];
	string vetor_aves[14];
<<<<<<< HEAD

	//Carregando o arquivo "anfibios_nat.txt" para o seu map
	ifstream appFile("anfibios_nat.txt");
	if(!appFile.is_open()){
		cout << "ERROR: arquivo não existe!" << endl;
		op = 0;
	}
	if(op != 0){
			while(appFile.good()){
				getline(appFile, vetor_anfibios[0], ';');
				getline(appFile, vetor_anfibios[1], ';');
				getline(appFile, vetor_anfibios[2], ';');
				getline(appFile, vetor_anfibios[3], ';');
				getline(appFile, vetor_anfibios[4], ';');
				getline(appFile, vetor_anfibios[5], ';');
				getline(appFile, vetor_anfibios[6], ';');
				getline(appFile, vetor_anfibios[7], ';');
				getline(appFile, vetor_anfibios[8], ';');
				getline(appFile, vetor_anfibios[9], ';');
				getline(appFile, vetor_anfibios[10], ';');
				getline(appFile, vetor_anfibios[11], ';');
				getline(appFile, vetor_anfibios[12], ';'); 
				getline(appFile, vetor_anfibios[13], '\n');
=======
	string vetor_veterinarios[8];
	string vetor_tratadores[8];

	//Carregando o arquivo "anfibios_nat.txt" para o seu map
	ifstream appFile("anfibios_nat.txt");
	if(appFile.is_open()){
		while(appFile.good()){
			getline(appFile, vetor_anfibios[0], ';');
			getline(appFile, vetor_anfibios[1], ';');
			getline(appFile, vetor_anfibios[2], ';');
			getline(appFile, vetor_anfibios[3], ';');
			getline(appFile, vetor_anfibios[4], ';');
			getline(appFile, vetor_anfibios[5], ';');
			getline(appFile, vetor_anfibios[6], ';');
			getline(appFile, vetor_anfibios[7], ';');
			getline(appFile, vetor_anfibios[8], ';');
			getline(appFile, vetor_anfibios[9], ';');
			getline(appFile, vetor_anfibios[10], ';');
			getline(appFile, vetor_anfibios[11], ';');
			getline(appFile, vetor_anfibios[12], ';'); 
			getline(appFile, vetor_anfibios[13], '\n');
>>>>>>> Hilton
		
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

<<<<<<< HEAD
			//cout << "ID: " << id << endl;

			anfibios_nat.insert(pair <int, ANFIBIO_NATIVO>(id, ANFIBIO_NATIVO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao)));

			}
=======
			anfibios_nat.insert(pair <int, ANFIBIO_NATIVO>(id, ANFIBIO_NATIVO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao)));
		}
>>>>>>> Hilton
		appFile.close();
	}


	//Carregando o arquivo "anfibios_ex.txt" para o seu map
	ifstream appFile2("anfibios_ex.txt");
<<<<<<< HEAD
	if(!appFile2.is_open()){
		cout << "ERROR: arquivo não existe!" << endl;
		op = 0;
	}

	if(op != 0){
			while(appFile2.good()){
				getline(appFile2, vetor_anfibios[0], ';');
				getline(appFile2, vetor_anfibios[1], ';');
				getline(appFile2, vetor_anfibios[2], ';');
				getline(appFile2, vetor_anfibios[3], ';');
				getline(appFile2, vetor_anfibios[4], ';');
				getline(appFile2, vetor_anfibios[5], ';');
				getline(appFile2, vetor_anfibios[6], ';');
				getline(appFile2, vetor_anfibios[7], ';');
				getline(appFile2, vetor_anfibios[8], ';');
				getline(appFile2, vetor_anfibios[9], ';');
				getline(appFile2, vetor_anfibios[10], ';');
				getline(appFile2, vetor_anfibios[11], ';');
				getline(appFile2, vetor_anfibios[12], ';'); 
				getline(appFile2, vetor_anfibios[13], '\n');
		
=======
	if(appFile2.is_open()){
		while(appFile2.good()){
			getline(appFile2, vetor_anfibios[0], ';');
			getline(appFile2, vetor_anfibios[1], ';');
			getline(appFile2, vetor_anfibios[2], ';');
			getline(appFile2, vetor_anfibios[3], ';');
			getline(appFile2, vetor_anfibios[4], ';');
			getline(appFile2, vetor_anfibios[5], ';');
			getline(appFile2, vetor_anfibios[6], ';');
			getline(appFile2, vetor_anfibios[7], ';');
			getline(appFile2, vetor_anfibios[8], ';');
			getline(appFile2, vetor_anfibios[9], ';');
			getline(appFile2, vetor_anfibios[10], ';');
			getline(appFile2, vetor_anfibios[11], ';');
			getline(appFile2, vetor_anfibios[12], ';'); 
			getline(appFile2, vetor_anfibios[13], '\n');
	
>>>>>>> Hilton
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
<<<<<<< HEAD

			}
=======
		}
>>>>>>> Hilton
		appFile2.close();
	}


	//Carregando o arquivo "mamiferos_nat.txt" para o seu map
	ifstream appFile3("mamiferos_nat.txt");
<<<<<<< HEAD
	if(!appFile3.is_open()){
		cout << "ERROR: arquivo não existe!" << endl;
		op = 0;
	}
	if(op != 0){
			while(appFile3.good()){
				getline(appFile3, vetor_mamiferos[0], ';');
				getline(appFile3, vetor_mamiferos[1], ';');
				getline(appFile3, vetor_mamiferos[2], ';');
				getline(appFile3, vetor_mamiferos[3], ';');
				getline(appFile3, vetor_mamiferos[4], ';');
				getline(appFile3, vetor_mamiferos[5], ';');
				getline(appFile3, vetor_mamiferos[6], ';');
				getline(appFile3, vetor_mamiferos[7], ';');
				getline(appFile3, vetor_mamiferos[8], ';');
				getline(appFile3, vetor_mamiferos[9], ';');
				getline(appFile3, vetor_mamiferos[10], ';');
				getline(appFile3, vetor_mamiferos[11], ';');
				getline(appFile3, vetor_mamiferos[12], '\n'); 
		
=======
	if(appFile3.is_open()){
		while(appFile3.good()){
			getline(appFile3, vetor_mamiferos[0], ';');
			getline(appFile3, vetor_mamiferos[1], ';');
			getline(appFile3, vetor_mamiferos[2], ';');
			getline(appFile3, vetor_mamiferos[3], ';');
			getline(appFile3, vetor_mamiferos[4], ';');
			getline(appFile3, vetor_mamiferos[5], ';');
			getline(appFile3, vetor_mamiferos[6], ';');
			getline(appFile3, vetor_mamiferos[7], ';');
			getline(appFile3, vetor_mamiferos[8], ';');
			getline(appFile3, vetor_mamiferos[9], ';');
			getline(appFile3, vetor_mamiferos[10], ';');
			getline(appFile3, vetor_mamiferos[11], ';');
			getline(appFile3, vetor_mamiferos[12], '\n'); 
	
>>>>>>> Hilton
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
<<<<<<< HEAD

			}
=======
		}
>>>>>>> Hilton
		appFile3.close();
	}

	
	//Carregando o arquivo "mamiferos_nat.txt" para o seu map
	ifstream appFile4("mamiferos_ex.txt");
<<<<<<< HEAD
	if(!appFile4.is_open()){
		cout << "ERROR: arquivo não existe!" << endl;
		op = 0;
	}
	if(op != 0){
			while(appFile4.good()){
				getline(appFile4, vetor_mamiferos[0], ';');
				getline(appFile4, vetor_mamiferos[1], ';');
				getline(appFile4, vetor_mamiferos[2], ';');
				getline(appFile4, vetor_mamiferos[3], ';');
				getline(appFile4, vetor_mamiferos[4], ';');
				getline(appFile4, vetor_mamiferos[5], ';');
				getline(appFile4, vetor_mamiferos[6], ';');
				getline(appFile4, vetor_mamiferos[7], ';');
				getline(appFile4, vetor_mamiferos[8], ';');
				getline(appFile4, vetor_mamiferos[9], ';');
				getline(appFile4, vetor_mamiferos[10], ';');
				getline(appFile4, vetor_mamiferos[11], ';');
				getline(appFile4, vetor_mamiferos[12], '\n'); 
		
=======
	if(appFile4.is_open()){
		while(appFile4.good()){
			getline(appFile4, vetor_mamiferos[0], ';');
			getline(appFile4, vetor_mamiferos[1], ';');
			getline(appFile4, vetor_mamiferos[2], ';');
			getline(appFile4, vetor_mamiferos[3], ';');
			getline(appFile4, vetor_mamiferos[4], ';');
			getline(appFile4, vetor_mamiferos[5], ';');
			getline(appFile4, vetor_mamiferos[6], ';');
			getline(appFile4, vetor_mamiferos[7], ';');
			getline(appFile4, vetor_mamiferos[8], ';');
			getline(appFile4, vetor_mamiferos[9], ';');
			getline(appFile4, vetor_mamiferos[10], ';');
			getline(appFile4, vetor_mamiferos[11], ';');
			getline(appFile4, vetor_mamiferos[12], '\n'); 
	
>>>>>>> Hilton
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
<<<<<<< HEAD

			}
=======
		}
>>>>>>> Hilton
		appFile4.close();
	}

	//Carregando o arquivo "repteis_nat.txt" para o seu map
	ifstream appFile5("repteis_nat.txt");
<<<<<<< HEAD
	if(!appFile5.is_open()){
		cout << "ERROR: arquivo não existe!" << endl;
		op = 0;
	}
	if(op != 0){
			while(appFile5.good()){
				getline(appFile5, vetor_repteis[0], ';');
				getline(appFile5, vetor_repteis[1], ';');
				getline(appFile5, vetor_repteis[2], ';');
				getline(appFile5, vetor_repteis[3], ';');
				getline(appFile5, vetor_repteis[4], ';');
				getline(appFile5, vetor_repteis[5], ';');
				getline(appFile5, vetor_repteis[6], ';');
				getline(appFile5, vetor_repteis[7], ';');
				getline(appFile5, vetor_repteis[8], ';');
				getline(appFile5, vetor_repteis[9], ';');
				getline(appFile5, vetor_repteis[10], ';');
				getline(appFile5, vetor_repteis[11], ';');
				getline(appFile5, vetor_repteis[12], ';');
				getline(appFile5, vetor_repteis[13], '\n'); 
		
=======
	if(appFile5.is_open()){
		while(appFile5.good()){
			getline(appFile5, vetor_repteis[0], ';');
			getline(appFile5, vetor_repteis[1], ';');
			getline(appFile5, vetor_repteis[2], ';');
			getline(appFile5, vetor_repteis[3], ';');
			getline(appFile5, vetor_repteis[4], ';');
			getline(appFile5, vetor_repteis[5], ';');
			getline(appFile5, vetor_repteis[6], ';');
			getline(appFile5, vetor_repteis[7], ';');
			getline(appFile5, vetor_repteis[8], ';');
			getline(appFile5, vetor_repteis[9], ';');
			getline(appFile5, vetor_repteis[10], ';');
			getline(appFile5, vetor_repteis[11], ';');
			getline(appFile5, vetor_repteis[12], ';');
			getline(appFile5, vetor_repteis[13], '\n'); 
	
>>>>>>> Hilton
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
<<<<<<< HEAD

		
			}
=======
		}
>>>>>>> Hilton
		appFile5.close();
	}

	//Carregando o arquivo "repteis_ex.txt" para o seu map
	ifstream appFile6("repteis_ex.txt");
<<<<<<< HEAD
	if(!appFile6.is_open()){
		cout << "ERROR: arquivo não existe!" << endl;
		op = 0;
	}
	if(op != 0){
			while(appFile6.good()){
				getline(appFile6, vetor_repteis[0], ';');
				getline(appFile6, vetor_repteis[1], ';');
				getline(appFile6, vetor_repteis[2], ';');
				getline(appFile6, vetor_repteis[3], ';');
				getline(appFile6, vetor_repteis[4], ';');
				getline(appFile6, vetor_repteis[5], ';');
				getline(appFile6, vetor_repteis[6], ';');
				getline(appFile6, vetor_repteis[7], ';');
				getline(appFile6, vetor_repteis[8], ';');
				getline(appFile6, vetor_repteis[9], ';');
				getline(appFile6, vetor_repteis[10], ';');
				getline(appFile6, vetor_repteis[11], ';');
				getline(appFile6, vetor_repteis[12], ';');
				getline(appFile6, vetor_repteis[13], '\n'); 
		
=======
	if(appFile6.is_open()){
		while(appFile6.good()){
			getline(appFile6, vetor_repteis[0], ';');
			getline(appFile6, vetor_repteis[1], ';');
			getline(appFile6, vetor_repteis[2], ';');
			getline(appFile6, vetor_repteis[3], ';');
			getline(appFile6, vetor_repteis[4], ';');
			getline(appFile6, vetor_repteis[5], ';');
			getline(appFile6, vetor_repteis[6], ';');
			getline(appFile6, vetor_repteis[7], ';');
			getline(appFile6, vetor_repteis[8], ';');
			getline(appFile6, vetor_repteis[9], ';');
			getline(appFile6, vetor_repteis[10], ';');
			getline(appFile6, vetor_repteis[11], ';');
			getline(appFile6, vetor_repteis[12], ';');
			getline(appFile6, vetor_repteis[13], '\n'); 
	
>>>>>>> Hilton
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
<<<<<<< HEAD

			}
=======
		}
>>>>>>> Hilton
		appFile6.close();
	}

	//Carregando o arquivo "anfibios_nat.txt" para o seu map
	ifstream appFile7("aves_nat.txt");
<<<<<<< HEAD
	if(!appFile7.is_open()){
		cout << "ERROR: arquivo não existe!" << endl;
		op = 0;
	}
	if(op != 0){
			while(appFile.good()){
				getline(appFile7, vetor_anfibios[0], ';');
				getline(appFile7, vetor_anfibios[1], ';');
				getline(appFile7, vetor_anfibios[2], ';');
				getline(appFile7, vetor_anfibios[3], ';');
				getline(appFile7, vetor_anfibios[4], ';');
				getline(appFile7, vetor_anfibios[5], ';');
				getline(appFile7, vetor_anfibios[6], ';');
				getline(appFile7, vetor_anfibios[7], ';');
				getline(appFile7, vetor_anfibios[8], ';');
				getline(appFile7, vetor_anfibios[9], ';');
				getline(appFile7, vetor_anfibios[10], ';');
				getline(appFile7, vetor_anfibios[11], ';');
				getline(appFile7, vetor_anfibios[12], ';'); 
				getline(appFile7, vetor_anfibios[13], '\n');
		
=======
	if(appFile7.is_open()){
		while(appFile.good()){
			getline(appFile7, vetor_anfibios[0], ';');
			getline(appFile7, vetor_anfibios[1], ';');
			getline(appFile7, vetor_anfibios[2], ';');
			getline(appFile7, vetor_anfibios[3], ';');
			getline(appFile7, vetor_anfibios[4], ';');
			getline(appFile7, vetor_anfibios[5], ';');
			getline(appFile7, vetor_anfibios[6], ';');
			getline(appFile7, vetor_anfibios[7], ';');
			getline(appFile7, vetor_anfibios[8], ';');
			getline(appFile7, vetor_anfibios[9], ';');
			getline(appFile7, vetor_anfibios[10], ';');
			getline(appFile7, vetor_anfibios[11], ';');
			getline(appFile7, vetor_anfibios[12], ';'); 
			getline(appFile7, vetor_anfibios[13], '\n');
	
>>>>>>> Hilton
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
<<<<<<< HEAD

			}
=======
		}
>>>>>>> Hilton
		appFile7.close();
	}

	//Carregando o arquivo "aves_ex.txt" para o seu map
	ifstream appFile8("aves_ex.txt");
<<<<<<< HEAD
	if(!appFile8.is_open()){
		cout << "ERROR: arquivo não existe!" << endl;
		op = 0;
	}
	if(op != 0){
			while(appFile.good()){
				getline(appFile8, vetor_anfibios[0], ';');
				getline(appFile8, vetor_anfibios[1], ';');
				getline(appFile8, vetor_anfibios[2], ';');
				getline(appFile8, vetor_anfibios[3], ';');
				getline(appFile8, vetor_anfibios[4], ';');
				getline(appFile8, vetor_anfibios[5], ';');
				getline(appFile8, vetor_anfibios[6], ';');
				getline(appFile8, vetor_anfibios[7], ';');
				getline(appFile8, vetor_anfibios[8], ';');
				getline(appFile8, vetor_anfibios[9], ';');
				getline(appFile8, vetor_anfibios[10], ';');
				getline(appFile8, vetor_anfibios[11], ';');
				getline(appFile8, vetor_anfibios[12], ';'); 
				getline(appFile8, vetor_anfibios[13], '\n');
		
=======
	if(appFile8.is_open()){
		while(appFile.good()){
			getline(appFile8, vetor_anfibios[0], ';');
			getline(appFile8, vetor_anfibios[1], ';');
			getline(appFile8, vetor_anfibios[2], ';');
			getline(appFile8, vetor_anfibios[3], ';');
			getline(appFile8, vetor_anfibios[4], ';');
			getline(appFile8, vetor_anfibios[5], ';');
			getline(appFile8, vetor_anfibios[6], ';');
			getline(appFile8, vetor_anfibios[7], ';');
			getline(appFile8, vetor_anfibios[8], ';');
			getline(appFile8, vetor_anfibios[9], ';');
			getline(appFile8, vetor_anfibios[10], ';');
			getline(appFile8, vetor_anfibios[11], ';');
			getline(appFile8, vetor_anfibios[12], ';'); 
			getline(appFile8, vetor_anfibios[13], '\n');
	
>>>>>>> Hilton
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
<<<<<<< HEAD

			}
		appFile8.close();
	}



=======
		}
		appFile8.close();
	}
	//carregando arquivo veterinarios.txt no map
	ifstream appFile9("veterinarios.txt");
	if(appFile9.is_open()){
		while(appFile9.good()){
			getline(appFile9, vetor_veterinarios[0], ';');
			getline(appFile9, vetor_veterinarios[1], ';');
			getline(appFile9, vetor_veterinarios[2], ';');
			getline(appFile9, vetor_veterinarios[3], ';');
			getline(appFile9, vetor_veterinarios[4], ';');
			getline(appFile9, vetor_veterinarios[5], ';');
			getline(appFile9, vetor_veterinarios[6], ';');
			getline(appFile9, vetor_veterinarios[7], '\n');
			
			id = stoi(vetor_veterinarios[0]);
			nome = vetor_veterinarios[1];
			cpf = stol(vetor_veterinarios[2]);
			idade = stoi(vetor_veterinarios[3]);
			tipo_sang = vetor_veterinarios[4];
			fator_rh = vetor_veterinarios[5][1];
			especialidade = vetor_veterinarios[6];
			crmv = vetor_veterinarios[7];

			vets.insert(pair <int, VETERINARIO>(id, VETERINARIO(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, crmv)));
		}
		appFile9.close();
	}

	//carregando arquivo "tratadores.txt"
	ifstream appFile10("veterinarios.txt");
	if(appFile10.is_open()){
		while(appFile10.good()){
			getline(appFile10, vetor_tratadores[0], ';');
			getline(appFile10, vetor_tratadores[1], ';');
			getline(appFile10, vetor_tratadores[2], ';');
			getline(appFile10, vetor_tratadores[3], ';');
			getline(appFile10, vetor_tratadores[4], ';');
			getline(appFile10, vetor_tratadores[5], ';');
			getline(appFile10, vetor_tratadores[6], ';');
			getline(appFile10, vetor_tratadores[7], '\n');
			
			id = stoi(vetor_tratadores[0]);
			nome = vetor_tratadores[1];
			cpf = stol(vetor_tratadores[2]);
			idade = stoi(vetor_tratadores[3]);
			tipo_sang = vetor_tratadores[4];
			fator_rh = vetor_tratadores[5][1];
			especialidade = vetor_tratadores[6];
			nivel_seg = stoi(vetor_tratadores[7]);
			tratadores.insert(pair <int, TRATADOR>(id, TRATADOR(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, nivel_seg)));
		}
		appFile10.close();
	}
>>>>>>> Hilton



}

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
	vets.insert(pair <int, VETERINARIO> (id,VETERINARIO(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, crmv)));
	//vets[id] = VETERINARIO(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, crmv);
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
	
	tratadores.insert(pair <int, TRATADOR> (id, TRATADOR(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, nivel_seg)));
	//tratadores[id] = TRATADOR(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, nivel_seg);

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

	int id, total_mudas;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, ultima_muda;

<<<<<<< HEAD
	char sexo, tipo_func, continuar = 's';
	double tamanho;
	unsigned int old_size;
=======
	char sexo, tipo_func, continuar;
	double tamanho;
	unsigned int old_size;
	ofstream nativos;
	ofstream exoticos;
>>>>>>> Hilton

	do{
		cout << "Deseja cadastrar um ANFIBIO NATIVO ou ANNFIBIO EXOTICO? \n n - NATIVO\n e - EXOTICO" << endl;
		cin >> tipo_func;
		if(tipo_func != 'n' && tipo_func != 'e'){
<<<<<<< HEAD
			//continuar = 's';
			continue;
		}
		else{
			continuar = 'n';
=======
			cout << "Tipo invalido, tente novamente!" << endl;
			continuar = 's';
			continue;
		}
		else{
			//continuar = 'n';
>>>>>>> Hilton
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
<<<<<<< HEAD
=======
			cin.ignore();
>>>>>>> Hilton
			getline(cin, ultima_muda);
			cout << "Insira a autorizacao do IBAMA: " << endl;
			cin.ignore();
			getline(cin, autorizacao_IBAMA);
			

			if(tipo_func == 'n'){
				old_size = anfibios_nat.size();

				cout << "Digite a UF de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);

<<<<<<< HEAD

				

				anfibios_nat.insert(pair <int, ANFIBIO_NATIVO> (id,ANFIBIO_NATIVO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao)));

				//anfibios_nat[id] = ANFIBIO_NATIVO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao);

				//anfibios_nat.push_back(a);

				//Cria o arquivo se não houver
				/*ofstream appFile;
				appFile.open("anfibios_nativos.txt", ios::app);
				if(!appFile){
					cout << "Arquivo nao encontrado :( " << endl;
					exit(0);	
				}
				appFile << id << ';' << classe << ';' << nome_cientifico << ';' << sexo << ';' << tamanho << ';' << dieta << ';' << veterinario << ';' <<  tratador << ';' <<  nome_batismo << ';' << total_mudas << ';' << ultima_muda[0] << '/' << ultima_muda[1] << '/' << ultima_muda[2]  << ';' << autorizacao_IBAMA << ';' << origem << ';' << autorizacao << ';' << '\n';
				appFile.close(); */
				//Fecha o arquivo

				if (anfibios_nat.size() == old_size){
					cout << "Falha no cadastro do animal!" << endl;
				}
				else{
					cout << "Cadastro efetuado com sucesso!!" << endl;
				}
			}
			else if(tipo_func == 'e'){
=======
				anfibios_nat.insert(pair <int, ANFIBIO_NATIVO> (id,ANFIBIO_NATIVO(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao)));

				if (anfibios_nat.size() == old_size){
					cout << "Falha no cadastro do animal! Tente novamente." << endl;
					continuar = 's';
					continue;
				}
		
			}
			else{
>>>>>>> Hilton
				old_size = anfibios_ex.size();
				cout << "Digite o País de origem: " << endl;
				getline(cin, origem);
				cout << "Insira a autorizacao do animal: " << endl;
				getline(cin, autorizacao);

				anfibios_ex.insert(pair <int, ANFIBIO_EXOTICO> (id, ANFIBIO_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta,veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao)));
<<<<<<< HEAD
				//anfibios_ex[id] = ANFIBIO_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta,veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao);

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
	
=======
							
				if (anfibios_nat.size() == old_size){
					cout << "Falha no cadastro do animal! Tente novamente" << endl;
					continuar = 's';
					continue;
				}	
			}
		}
		cout << "Deseja cadastrar um novo animal? s-sim n-nao" << endl;
		cin >> continuar;
	}while(continuar == 's');
	if(!anfibios_nat.empty()){
		nativos.open("anfibios_nat.txt");
		for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
			nativos << (*it).second;
			//nativos << (*it).second.getId() << ";" << (*it).second.getClasse() << ";" << (*it).second.getNome_cientifico() << ";" << (*it).second.getSexo();
		}
		nativos.close();
	}
>>>>>>> Hilton
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

				mamiferos_nat.insert(pair <int, MAMIFERO_NATIVO> (id, MAMIFERO_NATIVO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao)));
				//mamiferos_nat[id] = MAMIFERO_NATIVO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao);

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

				mamiferos_ex.insert(pair <int, MAMIFERO_EXOTICO> (id, MAMIFERO_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta,veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao)));
				//mamiferos_ex[id] = MAMIFERO_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta,veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao);

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

				repteis_nat.insert(pair <int, REPTIL_NATIVO> (id, REPTIL_NATIVO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao)));
				//repteis_nat[id] = REPTIL_NATIVO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao);

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

				repteis_ex.insert(pair <int, REPTIL_EXOTICO> (id, REPTIL_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao)));
				//repteis_ex[id] = REPTIL_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao);

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

				aves_nat.insert(pair <int, AVE_NATIVO> (id, AVE_NATIVO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao)));
				//aves_nat[id] = AVE_NATIVO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao);

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

				aves_ex.insert(pair <int, AVE_EXOTICO> (id, AVE_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao)));
				//aves_ex[id] = AVE_EXOTICO(id,classe,nome_cientifico,sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao);

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












