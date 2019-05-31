#include <iostream>
#include "pet_fera.h"

void exportacao_classe_vet_trat(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string classe, string veterinario, string tratador, string saida);

void exportacao_classe_vet(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string classe, string veterinario, string saida);

void exportacao_classe_trat(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string classe, string tratador, string saida);

void exportacao_vet_trat(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string veterinario, string tratador, string saida);

void exportacao_vet(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string veterinario, string saida);

void exportacao_trat(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string tratador, string saida);

void exportacao_classe(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string classe, string saida);

void exportacao(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string saida);

int main(int argc, char *argv[]){
	string classe, vet, tratador, saida, nome, sobrenome;

	// Declarando o map das classes.
	map <int, ANFIBIO_NATIVO> anfibios_nat;
	map <int, ANFIBIO_EXOTICO> anfibios_ex;

	map <int, MAMIFERO_NATIVO> mamiferos_nat;
	map <int, MAMIFERO_EXOTICO> mamiferos_ex;

	map <int, REPTIL_NATIVO> repteis_nat;
	map <int, REPTIL_EXOTICO> repteis_ex;

	map <int, AVE_NATIVO> aves_nat;
	map <int, AVE_EXOTICO> aves_ex;

	map <int, VETERINARIO> vets;
	map <int, TRATADOR> tratadores;

	carregar_arquivos(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, vets, tratadores);
	
	// Se for passado classe, veterinario, tratador e nome do arquivo de saida, ex: ./exportar -c reptilia -v hilton silva -t igor bento saida.txt.
	if(argc == 10 && argv[1][1] == 'c' && argv[3][1] == 'v' && argv[6][1] == 't' && argv[9][0] != '-'){
		classe = argv[2];
		nome = argv[4];
		sobrenome = argv[5];
		vet = nome + " " + sobrenome;
		nome = argv[7];
		sobrenome = argv[8];
		tratador = nome + " " + sobrenome;
		saida = argv[9];
		exportacao_classe_vet_trat(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, classe, vet, tratador, saida);
	}
	// Se for passado classe, veterinario, tratador e nome do arquivo de saida, ex: ./exportar -c reptilia -v hilton -t igor saida.txt.
	else if(argc == 8 && argv[1][1] == 'c' && argv[3][1] == 'v' && argv[5][1] == 't' && argv[7][0] != '-'){
		classe = argv[2];
		vet = argv[4];
		tratador = argv[6];
		saida = argv[7];

		exportacao_classe_vet_trat(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, classe, vet, tratador, saida);
	}

	// Se for passado classe, veterinario, tratador e nome do arquivo de saida, ex: ./exportar -c reptilia -v hilton silva -t igor saida.txt.
	else if(argc == 9 && argv[1][1] == 'c' && argv[3][1] == 'v' && argv[6][1] == 't' && argv[8][0] != '-'){
		classe = argv[2];
		nome = argv[4];
		sobrenome = argv[5];
		vet = nome + " " + sobrenome;
		tratador = argv[7];
		saida = argv[8];

		exportacao_classe_vet_trat(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, classe, vet, tratador, saida);
	}

	// Se for passado classe, veterinario, tratador e nome do arquivo de saida, ex: ./exportar -c reptilia -v hilton -t igor silva saida.txt.
	else if(argc == 9 && argv[1][1] == 'c' && argv[3][1] == 'v' && argv[5][1] == 't' && argv[8][0] != '-'){
		classe = argv[2];
		vet = argv[4];
		nome = argv[6];
		sobrenome = argv[7];
		tratador = nome + " " + sobrenome;
		saida = argv[8];

		exportacao_classe_vet_trat(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, classe, vet, tratador, saida);
	}

	// Se for passado classe,veterinario e nome do arquivo de saida, ex: ./exportar -c reptilia -v hilton silva saida.txt.
	else if(argc == 7 && argv[1][1] == 'c' && argv[3][1] == 'v' && argv[5][0] != '-'){
		classe = argv[2];
		nome = argv[4];
		sobrenome = argv[5];
		vet = nome + " " + sobrenome;
		saida = argv[6];

		exportacao_classe_vet(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, classe, vet, saida);
	}

	// Se for passado classe, veterinario e nome do arquivo de saida, ex: ./exportar -c reptilia -v hilton saida.txt.
	else if(argc == 6 && argv[3][1] == 'v' && argv[5][0] != '-'){
		classe = argv[2];
		vet = argv[4];
		saida = argv[5];

		exportacao_classe_vet(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, classe, vet, saida);
	}

	// Se for passado classe, tratador e nome do arquivo de saida, ex: ./exportar -c reptilia -t igor silva saida.txt.
	else if(argc == 7 && argv[1][1] == 'c' && argv[3][1] == 't' && argv[5][0] != '-'){
		classe = argv[2];
		nome = argv[4];
		sobrenome = argv[5];
		tratador = nome + " " + sobrenome;
		saida = argv[6];

		exportacao_classe_trat(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, classe, tratador, saida);
	}

	// Se for passado classe, tratador e nome do arquivo de saida, ex: ./exportar -c reptilia -t igor saida.txt.
	else if(argc == 6 && argv[1][1] == 'c' && argv[3][1] == 't' && argv[5][0] != '-'){
		classe = argv[2];
		tratador = argv[4];
		saida = argv[5];

		exportacao_classe_trat(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, classe, tratador, saida);
	}

	// Se for passado veterinario, tratador e nome do arquivo de saida, ex: ./exportar -v hilton -t igor saida.txt.
	else if(argc == 6 && argv[1][1] == 'v' && argv[3][1] == 't' && argv[5][0] != '-'){
		vet = argv[2];
		tratador = argv[4];
		saida = argv[5];

		exportacao_vet_trat(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, vet, tratador, saida);
	}

	// Se for passado veterinario, tratador e nome do arquivo de saida, ex: ./exportar -v hilton silva -t igor bento saida.txt.
	else if(argc == 8 && argv[1][1] == 'v' && argv[4][1] == 't' && argv[7][0] != '-'){
		nome = argv[2];
		sobrenome = argv[3];
		vet = nome + " " + sobrenome;
		nome = argv[5];
		sobrenome = argv[6];
		tratador = nome + " " + sobrenome;
		saida = argv[7];

		exportacao_vet_trat(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, vet, tratador, saida);
	}

	// Se for passado veterinario, tratador e nome do arquivo de saida, ex: ./exportar -v igor silva -t hilton saida.txt.
	else if(argc == 7 && argv[1][1] == 'v' && argv[4][1] == 't' && argv[6][0] != '-'){
		nome = argv[2];
		sobrenome = argv[3];
		vet = nome + " " + sobrenome;
		tratador = argv[5];
		saida = argv[6];

		exportacao_vet_trat(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, vet, tratador, saida);
	}

	// Se for passado veterinario, tratador e nome do arquivo de saida, ex: ./exportar -v igor -t hilton silva saida.txt.
	else if(argc == 7 && argv[1][1] == 'v' && argv[3][1] == 't' && argv[5][0] != '-'){ cout << "entrou" << endl; // 
		vet = argv[2];
		nome = argv[4];
		sobrenome = argv[5];
		tratador = nome + " " + sobrenome;
		saida = argv[6];

		exportacao_vet_trat(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, vet, tratador, saida);
	}

	// Se for passado veterinario e nome do arquivo de saida, ex: ./exportar -v hilton saida.txt.
	else if(argc == 4 && argv[1][1] == 'v' && argv[3][0] != '-'){
		vet = argv[2];
		saida = argv[3];

		exportacao_vet(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, vet, saida);
	}

	// Se for passado veterinario e nome do arquivo de saida, ex: ./exportar -v igor silva saida.txt.
	else if(argc == 5 && argv[1][1] == 'v' && argv[3][0] != '-'){
		nome = argv[2];
		sobrenome = argv[3];
		vet = nome + " " + sobrenome;
		saida = argv[4];

		exportacao_vet(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, vet, saida);
	}

	// Se for passado tratador e nome do arquivo de saida, ex: ./exportar -t hilton saida.txt.
	else if(argc == 4 && argv[1][1] == 't' && argv[3][0] != '-'){
		tratador = argv[2];
		saida = argv[3];

		exportacao_trat(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, tratador, saida);
	}

	// Se for passado tratador e nome do arquivo de saida, ex: ./exportar -t igor silva saida.txt.
	else if(argc == 5 && argv[1][1] == 't' && argv[3][0] != '-'){
		nome = argv[2];
		sobrenome = argv[3];
		tratador = nome + " " + sobrenome;
		saida = argv[4];

		exportacao_trat(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, tratador, saida);
	}

	// Se for passado classe e nome do arquivo de saida, ex: ./exportar -c reptilia saida.txt.
	else if(argc == 4 && argv[1][1] == 'c' && argv[3][0] != '-'){
		classe = argv[2];
		saida = argv[3];

		exportacao_classe(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, classe, saida);
	}

	// Se for passado o nome do arquivo de saida, ex: ./exportar saida.txt.
	else if(argc == 2 && argv[1][0] != '-'){ 
		saida = argv[1];

		exportacao(anfibios_nat, anfibios_ex, mamiferos_nat, mamiferos_ex, repteis_nat, repteis_ex, aves_nat, aves_ex, saida);
	}
	else{
		cout << "ERRO: Entrada inválida" << endl << endl;
	}
	return 0;
}
void exportacao(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string saida){
	transform(saida.begin(), saida.end(), saida.begin(), ::tolower);

	ofstream animais;
	animais.open(saida);

	for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
		animais << (*it).second;
	}
	for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
		animais << (*it).second;		
	}
	for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
		animais << (*it).second;
	}
	for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
		animais << (*it).second;	
	}
	for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
		animais << (*it).second;
	}
	for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
		animais << (*it).second;		
	}
	for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
		animais << (*it).second;		
	}
	for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
		animais << (*it).second;		
	}
	animais.close();
}

void exportacao_classe_vet_trat(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string classe, string veterinario, string tratador, string saida){

	transform(classe.begin(), classe.end(), classe.begin(), ::tolower);
	transform(saida.begin(), saida.end(), saida.begin(), ::tolower);
	transform(veterinario.begin(), veterinario.end(), veterinario.begin(), ::toupper);
	transform(tratador.begin(), tratador.end(), tratador.begin(), ::toupper);

	if(classe == "anfibio" || classe == "amphibia"){
		ofstream anfibios;
		anfibios.open(saida);
		for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
			if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
				anfibios << (*it).second;
			}
		}
		for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
			if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
				anfibios << (*it).second;
			}
		}
		anfibios.close();
	}
	else if(classe == "mamifero" || classe == "mamallia"){
		ofstream mamiferos;
		mamiferos.open(saida);
		for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
			if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
				mamiferos << (*it).second;
			}
		}
		for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
			if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
				mamiferos << (*it).second;
			}
		}
		mamiferos.close();
	}
	else if(classe == "reptil" || classe == "reptilia"){
		ofstream repteis;
		repteis.open(saida);
		for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
			if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
				repteis << (*it).second;
			}
		}
		for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
			if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
				repteis << (*it).second;
			}
		}
		repteis.close();
	}
	else if(classe == "ave" || classe == "aves"){
		ofstream aves;
		aves.open(saida);
		for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
			if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
				aves << (*it).second;
			}
		}
		for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
			if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
				aves << (*it).second;
			}
		}
		aves.close();
	}
}

void exportacao_classe_vet(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string classe, string veterinario, string saida){

	transform(classe.begin(), classe.end(), classe.begin(), ::tolower);
	transform(veterinario.begin(), veterinario.end(), veterinario.begin(), ::toupper);

	if(classe == "anfibio" || classe == "amphibia"){
		ofstream anfibios;
		anfibios.open(saida);
		for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
			if(it->second.getVeterinario() == veterinario){
				anfibios << (*it).second;
			}
		}
		for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
			if(it->second.getVeterinario() == veterinario){
				anfibios << (*it).second;
			}
		}
		anfibios.close();
	}
	else if(classe == "mamifero" || classe == "mamallia"){
		ofstream mamiferos;
		mamiferos.open(saida);
		for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
			if(it->second.getVeterinario() == veterinario){
				mamiferos << (*it).second;
			}
		}
		for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
			if(it->second.getVeterinario() == veterinario){
				mamiferos << (*it).second;
			}
		}
		mamiferos.close();
	}
	else if(classe == "reptil" || classe == "reptilia"){
		ofstream repteis;
		repteis.open(saida);
		for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
			if(it->second.getVeterinario() == veterinario){
				repteis << (*it).second;
			}
		}
		for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
			if(it->second.getVeterinario() == veterinario){
				repteis << (*it).second;
			}
		}
		repteis.close();
	}
	else if(classe == "ave" || classe == "aves"){
		ofstream aves;
		aves.open(saida);
		for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
			if(it->second.getVeterinario() == veterinario){
				aves << (*it).second;
			}
		}
		for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
			if(it->second.getVeterinario() == veterinario){
				aves << (*it).second;
			}
		}
		aves.close();
	}
}

// Exporta através da classe, tratador e nome do arquivo de saida.
void exportacao_classe_trat(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string classe, string tratador, string saida){

	transform(classe.begin(), classe.end(), classe.begin(), ::tolower);
	transform(tratador.begin(), tratador.end(), tratador.begin(), ::toupper);

	if(classe == "anfibio" || classe == "amphibia"){
		ofstream anfibios;
		anfibios.open(saida);
		for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
			if(it->second.getTratador() == tratador){
				anfibios << (*it).second;
			}
		}
		for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
			if(it->second.getTratador() == tratador){
				anfibios << (*it).second;
			}
		}
		anfibios.close();
	}
	else if(classe == "mamifero" || classe == "mamallia"){
		ofstream mamiferos;
		mamiferos.open(saida);
		for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
			if(it->second.getTratador() == tratador){
				mamiferos << (*it).second;
			}
		}
		for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
			if(it->second.getTratador() == tratador){
				mamiferos << (*it).second;
			}
		}
		mamiferos.close();
	}
	else if(classe == "reptil" || classe == "reptilia"){
		ofstream repteis;
		repteis.open(saida);
		for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
			if(it->second.getTratador() == tratador){
				repteis << (*it).second;
			}
		}
		for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
			if(it->second.getTratador() == tratador){
				repteis << (*it).second;
			}
		}
		repteis.close();
	}
	else if(classe == "ave" || classe == "aves"){
		ofstream aves;
		aves.open(saida);
		for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
			if(it->second.getTratador() == tratador){
				aves << (*it).second;
			}
		}
		for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
			if(it->second.getTratador() == tratador){
				aves << (*it).second;
			}
		}
		aves.close();
	}
}

// Exportacao através da classe e nome do arquivo de saida.
void exportacao_classe(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string classe, string saida){
	ofstream anfibios;
	ofstream mamiferos;
	ofstream repteis;
	ofstream aves;

	transform(classe.begin(), classe.end(), classe.begin(), ::tolower);

	if(classe == "anfibio" || classe == "amphibia"){
		anfibios.open(saida);
		for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
			anfibios << (*it).second;	
		}
		for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
			anfibios << (*it).second;
		}
		anfibios.close();
	}
	else if(classe == "mamifero" || classe == "mamallia"){
		mamiferos.open(saida);
		for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
			mamiferos << (*it).second;
		}
		for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
			mamiferos << (*it).second;	
		}
		mamiferos.close();
	}
	else if(classe == "reptil" || classe == "reptilia"){
		repteis.open(saida);
		for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
			repteis << (*it).second;
		}
		for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
			repteis << (*it).second;	
		}
		repteis.close();
	}
	else if(classe == "ave" || classe == "aves"){
		aves.open(saida);
		for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
			aves << (*it).second;
		}
		for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
			aves << (*it).second;
		}
		aves.close();
	}
}

void exportacao_vet_trat(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string veterinario, string tratador, string saida){
	transform(veterinario.begin(), veterinario.end(), veterinario.begin(), ::toupper);
	transform(tratador.begin(), tratador.end(), tratador.begin(), ::toupper);

	ofstream animais;
	animais.open(saida);

	for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
		if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
			animais << (*it).second;
		}	
	}
	for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
		if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
			animais << (*it).second;
		}		
	}
	for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
		if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
			animais << (*it).second;
		}
	}
	for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
		if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
			animais << (*it).second;
		}	
	}
	for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
		if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
			animais << (*it).second;
		}
	}
	for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
		if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
			animais << (*it).second;
		}	
	}
	for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
		if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
			animais << (*it).second;
		}	
	}
	for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
		if(it->second.getVeterinario() == veterinario && it->second.getTratador() == tratador){
			animais << (*it).second;
		}	
	}
	animais.close();
}

void exportacao_vet(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string veterinario, string saida){
	transform(veterinario.begin(), veterinario.end(), veterinario.begin(), ::toupper);

	ofstream animais;
	animais.open(saida);

	for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
		if(it->second.getVeterinario() == veterinario){
			animais << (*it).second;
		}	
	}
	for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
		if(it->second.getVeterinario() == veterinario){
			animais << (*it).second;
		}		
	}
	for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
		if(it->second.getVeterinario() == veterinario){
			animais << (*it).second;
		}
	}
	for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
		if(it->second.getVeterinario() == veterinario){
			animais << (*it).second;
		}	
	}
	for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
		if(it->second.getVeterinario() == veterinario){
			animais << (*it).second;
		}
	}
	for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
		if(it->second.getVeterinario() == veterinario){
			animais << (*it).second;
		}	
	}
	for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
		if(it->second.getVeterinario() == veterinario){
			animais << (*it).second;
		}	
	}
	for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
		if(it->second.getVeterinario() == veterinario){
			animais << (*it).second;
		}	
	}
	animais.close();
}

void exportacao_trat(map <int, ANFIBIO_NATIVO> anfibios_nat, map <int, ANFIBIO_EXOTICO> anfibios_ex, map <int, MAMIFERO_NATIVO> mamiferos_nat, map <int, MAMIFERO_EXOTICO> mamiferos_ex, map <int, REPTIL_NATIVO> repteis_nat, map <int, REPTIL_EXOTICO> repteis_ex, map <int, AVE_NATIVO> aves_nat, map <int, AVE_EXOTICO> aves_ex, string tratador, string saida){
	transform(tratador.begin(), tratador.end(), tratador.begin(), ::toupper);

	ofstream animais;
	animais.open(saida);

	for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
		if(it->second.getTratador() == tratador){
			animais << (*it).second;
		}	
	}
	for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
		if(it->second.getTratador() == tratador){
			animais << (*it).second;
		}		
	}
	for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
		if(it->second.getTratador() == tratador){
			animais << (*it).second;
		}
	}
	for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
		if(it->second.getTratador() == tratador){
			animais << (*it).second;
		}	
	}
	for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
		if(it->second.getTratador() == tratador){
			animais << (*it).second;
		}
	}
	for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
		if(it->second.getTratador() == tratador){
			animais << (*it).second;
		}	
	}
	for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
		if(it->second.getTratador() == tratador){
			animais << (*it).second;
		}	
	}
	for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
		if(it->second.getTratador() == tratador){
			animais << (*it).second;
		}	
	}
	animais.close();
}