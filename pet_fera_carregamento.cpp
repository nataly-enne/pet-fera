#include "pet_fera.h"

// Carrega todos os arquivos pra seus respectivos maps, para assim ser utilizado de forma eficiente em todas as operações.
void carregar_arquivos(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex, map <int, VETERINARIO> &vets, map <int, TRATADOR> &tratadores){
	
	int id, total_mudas, nivel_seg, idade;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao_IBAMA, origem, autorizacao,  ultima_muda, cor, tipo_veneno, crmv, nome, tipo_sang, especialidade;
	char sexo, fator_rh;
	long int cpf;
	double tamanho, tamanho_bico, envergadura;
	bool venenoso; 
	string vetor_anfibios[15];
	string vetor_mamiferos[14];
	string vetor_repteis[15];
	string vetor_aves[15];
	string vetor_veterinarios[8];
	string vetor_tratadores[8];
	string line, tmp;
	int cont = 0, j;

	// Carregando o arquivo "anfibios_nat.txt" para o seu map.
	ifstream appFile("anfibios_nat.txt");

	if(appFile.is_open()){
		while(getline(appFile, line)){ 
			cont = 0;
			j = 0;
			for(int i = 0; i < (int)line.length(); i++){
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
			nome = vetor_anfibios[2];
			nome_cientifico = vetor_anfibios[3];
			sexo = (char) vetor_anfibios[4][0];
			tamanho = stod(vetor_anfibios[5]);
			dieta = vetor_anfibios[6];
			veterinario = vetor_anfibios[7];
			tratador = vetor_anfibios[8];
			nome_batismo = vetor_anfibios[9];
			total_mudas = stoi(vetor_anfibios[10]);
			ultima_muda = vetor_anfibios[11];
			autorizacao_IBAMA = vetor_anfibios[12];
			origem = vetor_anfibios[13];
			autorizacao = vetor_anfibios[14];

			anfibios_nat.insert(pair <int, ANFIBIO_NATIVO>(id, ANFIBIO_NATIVO(id, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile.close();
	}

	// Carregando o arquivo "anfibios_ex.txt" para o seu map.
	ifstream appFile2("anfibios_ex.txt");
	if(appFile2.is_open()){
		while(getline(appFile2, line)){
			cont = 0;
			j = 0;
			for(int i = 0; i < (int)line.length(); i++){
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
			nome = vetor_anfibios[2];
			nome_cientifico = vetor_anfibios[3];
			sexo = (char) vetor_anfibios[4][0];
			tamanho = stod(vetor_anfibios[5]);
			dieta = vetor_anfibios[6];
			veterinario = vetor_anfibios[7];
			tratador = vetor_anfibios[8];
			nome_batismo = vetor_anfibios[9];
			total_mudas = stoi(vetor_anfibios[10]);
			ultima_muda = vetor_anfibios[11];
			autorizacao_IBAMA = vetor_anfibios[12];
			origem = vetor_anfibios[13];
			autorizacao = vetor_anfibios[14];

			anfibios_ex.insert(pair <int, ANFIBIO_EXOTICO>(id, ANFIBIO_EXOTICO(id, classe,nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile2.close();
	}


	// Carregando o arquivo "mamiferos_nat.txt" para o seu map.
	ifstream appFile3("mamiferos_nat.txt");
	if(appFile3.is_open()){
		while(getline(appFile3, line)){
			cont = 0;
			j = 0;
			for(int i = 0; i < (int)line.length(); i++){
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
			nome = vetor_mamiferos[2];
			nome_cientifico = vetor_mamiferos[3];
			sexo = (char) vetor_mamiferos[4][0];
			tamanho = stod(vetor_mamiferos[5]);
			dieta = vetor_mamiferos[6];
			veterinario = vetor_mamiferos[7];
			tratador = vetor_mamiferos[8];
			nome_batismo = vetor_mamiferos[9];
			cor = vetor_mamiferos[10];
			autorizacao_IBAMA = vetor_mamiferos[11];
			origem = vetor_mamiferos[12];
			autorizacao = vetor_mamiferos[13];

			mamiferos_nat.insert(pair <int, MAMIFERO_NATIVO>(id, MAMIFERO_NATIVO(id, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile3.close();
	}

	// Carregando o arquivo "mamiferos_nat.txt" para o seu map.
	ifstream appFile4("mamiferos_ex.txt");
	if(appFile4.is_open()){
		while(getline(appFile4, line)){
			cont = 0;
			j = 0;
			for(int i = 0; i < (int)line.length(); i++){
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
			nome = vetor_mamiferos[2];
			nome_cientifico = vetor_mamiferos[3];
			sexo = (char) vetor_mamiferos[4][0];
			tamanho = stod(vetor_mamiferos[55]);
			dieta = vetor_mamiferos[6];
			veterinario = vetor_mamiferos[7];
			tratador = vetor_mamiferos[8];
			nome_batismo = vetor_mamiferos[9];
			cor = vetor_mamiferos[10];
			autorizacao_IBAMA = vetor_mamiferos[11];
			origem = vetor_mamiferos[12];
			autorizacao = vetor_mamiferos[13];

			mamiferos_ex.insert(pair <int, MAMIFERO_EXOTICO>(id, MAMIFERO_EXOTICO(id, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile4.close();
	}

	// Carregando o arquivo "repteis_nat.txt" para o seu map.
	ifstream appFile5("repteis_nat.txt");
	if(appFile5.is_open()){
		while(getline(appFile5, line)){
			cont = 0;
			j = 0;
			for(int i = 0; i < (int)line.length(); i++){
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
			nome = vetor_repteis[2];
			nome_cientifico = vetor_repteis[3];
			sexo = (char) vetor_repteis[4][0];
			tamanho = stod(vetor_repteis[5]);
			dieta = vetor_repteis[6];
			veterinario = vetor_repteis[7];
			tratador = vetor_repteis[8];
			nome_batismo = vetor_repteis[9];
			venenoso = stoi(vetor_repteis[10]);
			tipo_veneno = vetor_repteis[11];
			autorizacao_IBAMA = vetor_repteis[12];
			origem = vetor_repteis[13];
			autorizacao = vetor_repteis[14];

			repteis_nat.insert(pair <int, REPTIL_NATIVO>(id, REPTIL_NATIVO(id, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile5.close();
	}

	// Carregando o arquivo "repteis_ex.txt" para o seu map.
	ifstream appFile6("repteis_ex.txt");
	if(appFile6.is_open()){
		while(getline(appFile6, line)){
			cont = 0;
			j = 0;
			for(int i = 0; i < (int)line.length(); i++){
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
			nome = vetor_repteis[2];
			nome_cientifico = vetor_repteis[3];
			sexo = (char) vetor_repteis[4][0];
			tamanho = stod(vetor_repteis[5]);
			dieta = vetor_repteis[6];
			veterinario = vetor_repteis[7];
			tratador = vetor_repteis[8];
			nome_batismo = vetor_repteis[9];
			venenoso = stoi(vetor_repteis[10]);
			tipo_veneno = vetor_repteis[11];
			autorizacao_IBAMA = vetor_repteis[12];
			origem = vetor_repteis[13];
			autorizacao = vetor_repteis[14];

			repteis_ex.insert(pair <int, REPTIL_EXOTICO>(id, REPTIL_EXOTICO(id, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile6.close();
	}

	// Carregando o arquivo "anfibios_nat.txt" para o seu map.
	ifstream appFile7("aves_nat.txt");
	if(appFile7.is_open()){
		while(getline(appFile7, line)){
			cont = 0;;
			j = 0;
			for(int i = 0; i < (int)line.length(); i++){
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
			nome = vetor_aves[2];
			nome_cientifico = vetor_aves[3];
			sexo = (char) vetor_aves[4][0];
			tamanho = stod(vetor_aves[5]);
			dieta = vetor_aves[6];
			veterinario = vetor_aves[7];
			tratador = vetor_aves[8];
			nome_batismo = vetor_aves[9];
			tamanho_bico = stod(vetor_aves[10]);
			envergadura = stod(vetor_aves[11]);
			autorizacao_IBAMA = vetor_aves[12];
			origem = vetor_aves[13];
			autorizacao = vetor_aves[14];

			aves_nat.insert(pair <int, AVE_NATIVO>(id, AVE_NATIVO(id, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tamanho_bico, envergadura, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile7.close();
	}

	// Carregando o arquivo "aves_ex.txt" para o seu map.
	ifstream appFile8("aves_ex.txt");
	if(appFile8.is_open()){
		while(getline(appFile8, line)){
			cont = 0;
			j = 0;
			for(int i = 0; i < (int)line.length(); i++){
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
			nome = vetor_aves[2];
			nome_cientifico = vetor_aves[3];
			sexo = (char) vetor_aves[4][0];
			tamanho = stod(vetor_aves[5]);
			dieta = vetor_aves[6];
			veterinario = vetor_aves[7];
			tratador = vetor_aves[8];
			nome_batismo = vetor_aves[9];
			tamanho_bico = stod(vetor_aves[10]);
			envergadura = stod(vetor_aves[11]);
			autorizacao_IBAMA = vetor_aves[12];
			origem = vetor_aves[13];
			autorizacao = vetor_aves[14];

			aves_ex.insert(pair <int, AVE_EXOTICO>(id, AVE_EXOTICO(id, classe, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tamanho_bico, envergadura, autorizacao_IBAMA, origem, autorizacao)));
		}
		appFile8.close();
	}
	// Carregando arquivo "veterinarios.txt" para o seu map.
	ifstream appFile9("veterinarios.txt");
	if(appFile9.is_open()){
		while(getline(appFile9, line)){
			cont = 0;
			j = 0;
			for(int i = 0; i < (int)line.length(); i++){
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

	// Carregando arquivo "tratadores.txt" para o seu map.
	ifstream appFile10("tratadores.txt");
	if(appFile10.is_open()){
		while(getline(appFile10, line)){
			cont = 0;
			j = 0;
			for(int i = 0; i < (int)line.length(); i++){
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
