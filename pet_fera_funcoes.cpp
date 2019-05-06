#include "pet_fera.h"
//cadastro de funcionarios

void cadastrar_func(vector <VETERINARIO> &vets, vector <TRATADOR> &tratadores){
	char tipo_func;
	char continuar = 'n';
	do{
		cout << "Qual o tipo de funcionario a ser cadastrado? \n v - veterinario\n t - tratador" << endl;
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
	}while (continuar == 's');
	
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
	cin >> nome;
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
	if (vets.size() == old_size){
		cout << "Falha no cadastro do funcionario!" << endl;
	}
	else{
		cout << "Cadastro efetuado com sucesso!!" << endl;
		cout << v << endl;
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
	cin >> nome;
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
	cout << "Digite o nivel de seguranca: "<< endl;
	cin >> nivel_seg;
	
	TRATADOR t(id, nome, cpf, idade, tipo_sang, fator_rh, especialidade, nivel_seg);
	tratadores.push_back(t);
	
	if (tratadores.size() == old_size){
		cout << "Falha no cadastro do funcionario!" << endl;
	}else{
		cout << "Cadastro efetuado com sucesso!!" << endl;
		cout << t << endl;
	}
}
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
	}while (continuar == 's');
	
}

void cadastrar_anfibio(vector <ANFIBIO> &anfibios){
	int id, total_mudas, ultima_muda[3];
	string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo;
	char sexo;
	double tamanho;
	unsigned int old_size;
	
	old_size = anfibios.size();

	cout << "Digite o id: " << endl;
	cin >> id;
	cout << "Digite a classe: " << endl;
	cin >> classe;
	cout << "Digite o nome científico: " << endl;
	cin >> nome_cientifico;
	cout << "Digite a dieta: " << endl;
	cin >> idade;
	cout << "Digite o nome do veterinario: " << endl;
	cin >> veterinario;
	cout << "Digite o nome do tratador: " << endl;
	cin >> tratador;
	cout << "Digite o nome de batismo: " << endl;
	cin >> nome_batismo;
	cout << "Digite o sexo do animal: " << endl;
	cin >> sexo;
	cout << "Digite o tamanho do animal: " << endl;
	cin >> tamanho;
	cout << "Insira o total de mudas:" << endl;
	cin >> total_mudas;
	// cout << "Insira a data da última muda" << endl;
	// cin >> ultima_muda;

	ANFIBIO a(id, classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, sexo, tamanho, total_mudas, *ultima_muda);
	anfibios.push_back(a);

	if (anfibios.size() == old_size){
		cout << "Falha no cadastro do animal!" << endl;
	}
	else{
		cout << "Cadastro efetuado com sucesso!!" << endl;
		cout << a << endl;
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
	cin >> classe;
	cout << "Digite o nome científico: " << endl;
	cin >> nome_cientifico;
	cout << "Digite a dieta: " << endl;
	cin >> idade;
	cout << "Digite o nome do veterinario: " << endl;
	cin >> veterinario;
	cout << "Digite o nome do tratador: " << endl;
	cin >> tratador;
	cout << "Digite o nome de batismo: " << endl;
	cin >> nome_batismo;
	cout << "Digite o sexo do animal: " << endl;
	cin >> sexo;
	cout << "Digite o tamanho do animal: " << endl;
	cin >> tamanho;
	cout << "Digite a cor do pelo do animal:" << endl;
	cin >> cor_pelo;

	MAMIFERO m(id, classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, sexo, tamanho, cor_pelo);
	mamiferos.push_back(a);

	if (mamiferos.size() == old_size){
		cout << "Falha no cadastro do animal!" << endl;
	}
	else{
		cout << "Cadastro efetuado com sucesso!!" << endl;
		cout << m << endl;
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
	cin >> classe;
	cout << "Digite o nome científico: " << endl;
	cin >> nome_cientifico;
	cout << "Digite a dieta: " << endl;
	cin >> idade;
	cout << "Digite o nome do veterinario: " << endl;
	cin >> veterinario;
	cout << "Digite o nome do tratador: " << endl;
	cin >> tratador;
	cout << "Digite o nome de batismo: " << endl;
	cin >> nome_batismo;
	cout << "Digite o sexo do animal: " << endl;
	cin >> sexo;
	cout << "Digite o tamanho do animal: " << endl;
	cin >> tamanho;
	cout << "Digite o tipo de veneno do animal:" << endl;
	cin >> tipo_veneno;
	cout << "Digite '1' para animal venenoso ou '0' para não-venenoso:"

	REPTIL r(id, classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, sexo, tamanho, venenoso, tipo_veneno);
	repteis.push_back(a);

	if (repteis.size() == old_size){
		cout << "Falha no cadastro do animal!" << endl;
	}
	else{
		cout << "Cadastro efetuado com sucesso!!" << endl;
		cout << r << endl;
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
	cin >> classe;
	cout << "Digite o nome científico: " << endl;
	cin >> nome_cientifico;
	cout << "Digite a dieta: " << endl;
	cin >> idade;
	cout << "Digite o nome do veterinario: " << endl;
	cin >> veterinario;
	cout << "Digite o nome do tratador: " << endl;
	cin >> tratador;
	cout << "Digite o nome de batismo: " << endl;
	cin >> nome_batismo;
	cout << "Digite o sexo do animal: " << endl;
	cin >> sexo;
	cout << "Digite o tamanho do animal: " << endl;
	cin >> tamanho;
	cout << "Digite o tamanho do bico:" << endl;
	cin >> tamanho_bico;
	cout << "Digite a envergadura:"

	AVE e(id, classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, sexo, tamanho, tamanho_bico, envergadura);
	repteis.push_back(a);

	if (repteis.size() == old_size){
		cout << "Falha no cadastro do animal!" << endl;
	}
	else{
		cout << "Cadastro efetuado com sucesso!!" << endl;
		cout << e << endl;
	}
}


//vector <ANIMAL_NATIVO> &nativos, vector <ANIMAL_EXOTICO> &exoticos, vector <ANIMAL_SILVESTRE> &silvestres


//void remover_animal()







