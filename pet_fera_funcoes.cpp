#include "pet_fera.h"

//***Falta implementar***
// 1- Cadastrar animais exoticos e nativos
// 2- Inserir no arquivo

void cadastrar_func(vector <VETERINARIO> &vets, vector <TRATADOR> &tratadores){
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
				cadastrar_vet(vets);
			}
			else{
				cadastrar_trat(tratadores);
			}
		}
	} while (continuar == 's');
	
}

void cadastrar_vet(vector <VETERINARIO> &vets){
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
	VETERINARIO v(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, crmv);
	vets.push_back(v);
	if (vets.size() == old_size){ //não adicionou ao vector, por isso continua com o tam antigo
		cout << "Falha no cadastro do funcionario!" << endl;
	}
	else{
		cout << "Cadastro efetuado com sucesso!!" << endl;
		//cout << v << endl;
	}
}

void cadastrar_trat(vector <TRATADOR> &tratadores){
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
	
	TRATADOR t(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, nivel_seg);

	tratadores.push_back(t);
	
	if (tratadores.size() == old_size){ //não adicionou ao vector, por isso continua com o tam antigo
		cout << "Falha no cadastro do funcionario!" << endl;
	}else{
		cout << "Cadastro efetuado com sucesso!!" << endl;
		cout << t << endl;
	}
}


//void remover funcionario();

void cadastrar_animal(vector <ANFIBIO> &anfibios, vector <MAMIFERO> &mamiferos, vector <REPTIL> &repteis, vector <AVE> &aves){

	char tipo_func;
	char continuar = 'n';

	do{
		cout << "Qual animal a ser cadastrado? \n a - anfíbio\n m - mamífero \n r - repteis \n e - aves" << endl;
		cin >> tipo_func;
		if(tipo_func != 'a' && tipo_func != 'm' && tipo_func != 'r' && tipo_func != 'v'){
			cout << "Tipo de animal incorreto!! Tente novamente!\n" << endl;
			continuar = 's';
			continue;
		}else{
			if(tipo_func == 'a'){
				cadastrar_anfibio(anfibios);
			}
			else if(tipo_func == 'm'){
				cadastrar_mamifero(mamiferos);
			}
			else if(tipo_func == 'r'){
				cadastrar_reptil(repteis);
			}		
			else{
				cadastrar_ave(aves);
			}
		}
	} while (continuar == 's');
	
}

void cadastrar_anfibio(vector <ANFIBIO> &anfibios){
	int id, idade, total_mudas, ultima_muda[3];
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo;
	char sexo;
	double tamanho;
	unsigned int old_size;
	
	old_size = anfibios.size();

	cout << "Digite o id: " << endl;
	cin >> id;
	cout << "Digite a classe: " << endl;
	cin.ignore();
	getline(cin, classe);
	cout << "Digite o nome científico: " << endl;
	cin.ignore();
	getline(cin, nome_cientifico);
	cout << "Digite a dieta: " << endl;
	cin >> idade;
	cout << "Digite o nome do veterinario: " << endl;
	cin.ignore();
	getline(cin, veterinario);
	cout << "Digite o nome do tratador: " << endl;
	cin.ignore();
	getline(cin, tratador);
	cout << "Digite o nome de batismo: " << endl;
	cin.ignore();
	getline(cin, nome_batismo);
	cout << "Digite o sexo do animal: " << endl;
	cin >> sexo;
	cout << "Digite o tamanho do animal: " << endl;
	cin >> tamanho;
	cout << "Insira o total de mudas:" << endl;
	cin >> total_mudas;
	cout << "Insira a data da última muda(D/M/A)" << endl;
	cin >> ultima_muda[0] >> ultima_muda[1] >> ultima_muda[2];

	ANFIBIO a(id,classe,nome_cientifico,sexo, tamanho, dieta,veterinario, tratador, nome_batismo, total_mudas, ultima_muda);

	anfibios.push_back(a);

	if (anfibios.size() == old_size){
		cout << "Falha no cadastro do animal!" << endl;
	}
	else{
		cout << "Cadastro efetuado com sucesso!!" << endl;
		//cout << a << endl;
	}

}

void cadastrar_mamifero(vector <MAMIFERO> &mamiferos){
	int id;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, cor_pelo;
	char sexo;
	double tamanho;
	unsigned int old_size;
	old_size = mamiferos.size();

	cout << "Digite o id: " << endl;
	cin >> id;
	cout << "Digite a classe: " << endl;
	cin.ignore();
	getline(cin, classe);
	cout << "Digite o nome científico: " << endl;
	cin.ignore();
	getline(cin, nome_cientifico);
	cout << "Digite o nome do veterinario: " << endl;
	cin.ignore();
	getline(cin, veterinario);
	cout << "Digite o nome do tratador: " << endl;
	cin.ignore();
	getline(cin, tratador);
	cout << "Digite o nome de batismo: " << endl;
	cin.ignore();
	getline(cin, nome_batismo);
	cout << "Digite o sexo do animal: " << endl;
	cin >> sexo;
	cout << "Digite o tamanho do animal: " << endl;
	cin >> tamanho;
	cout << "Digite a cor do pelo do animal:" << endl;
	cin.ignore();
	getline(cin, cor_pelo);

	MAMIFERO m(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor_pelo);

	mamiferos.push_back(m);

	if (mamiferos.size() == old_size){
		cout << "Falha no cadastro do animal!" << endl;
	}
	else{
		cout << "Cadastro efetuado com sucesso!!" << endl;
		//cout << m << endl;
	}
}
void cadastrar_reptil(vector <REPTIL> &repteis){
	bool venenoso;
	int id;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, tipo_veneno;
	char sexo;
	double tamanho;
	unsigned int old_size;
	old_size = repteis.size();

	cout << "Digite o id: " << endl;
	cin >> id;
	cout << "Digite a classe: " << endl;
	cin.ignore();
	getline(cin, classe);
	cout << "Digite o nome científico: " << endl;
	cin.ignore();
	getline(cin, nome_cientifico);
	cout << "Digite o nome do veterinario: " << endl;
	cin.ignore();
	getline(cin, veterinario);
	cout << "Digite o nome do tratador: " << endl;
	cin.ignore();
	getline(cin, tratador);
	cout << "Digite o nome de batismo: " << endl;
	cin.ignore();
	getline(cin, nome_batismo);
	cout << "Digite o sexo do animal: " << endl;
	cin >> sexo;
	cout << "Digite o tamanho do animal: " << endl;
	cin >> tamanho;
	cout << "Digite o tipo de veneno do animal:" << endl;
	cin >> tipo_veneno;
	cout << "Digite '1' para animal venenoso ou '0' para não-venenoso:";
	cin >> venenoso;

	REPTIL r(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno);

	repteis.push_back(r);

	if (repteis.size() == old_size){
		cout << "Falha no cadastro do animal!" << endl;
	}
	else{
		cout << "Cadastro efetuado com sucesso!!" << endl;
		//cout << r << endl;
	}
}
void cadastrar_ave(vector <AVE> &aves){
	int id;
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo;
	char sexo;
	double tamanho, tamanho_bico, envergadura;
	unsigned int old_size;
	old_size = aves.size();

	cout << "Digite o id: " << endl;
	cin >> id;
	cout << "Digite a classe: " << endl;
	cin.ignore();
	getline(cin, classe);
	cout << "Digite o nome científico: " << endl;
	cin.ignore();
	getline(cin, nome_cientifico);
	cout << "Digite o nome do veterinario: " << endl;
	cin.ignore();
	getline(cin, veterinario);
	cout << "Digite o nome do tratador: " << endl;
	cin.ignore();
	getline(cin, tratador);
	cout << "Digite o nome de batismo: " << endl;
	cin.ignore();
	getline(cin, nome_batismo);
	cout << "Digite o sexo do animal: " << endl;
	cin >> sexo;
	cout << "Digite o tamanho do animal: " << endl;
	cin >> tamanho;
	cout << "Digite o tamanho do bico:" << endl;
	cin >> tamanho_bico;
	cout << "Digite a envergadura:";
	cin >> envergadura;	

	AVE e(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tamanho_bico, envergadura);

	aves.push_back(e);

	if (aves.size() == old_size){
		cout << "Falha no cadastro do animal!" << endl;
	}
	else{
		cout << "Cadastro efetuado com sucesso!!" << endl;
		//cout << e << endl;
	}
}


//vector <ANIMAL_NATIVO> &nativos, vector <ANIMAL_EXOTICO> &exoticos, vector <ANIMAL_SILVESTRE> &silvestres


//void remover_animal()

//menu listar animal
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













