#include "pet_fera.h"
//cadastro de funcionarios

void cadastrar_func(vector <VETERINARIO> &vets, vector <TRATADOR> &tratadores){
	char tipo_func;
	char continuar = 'n';
	do{
		cout << "Qual o tipo de funcionario a ser cadastrado? \n v - veterinario\n t - tratador" << endl;
		cin >> tipo_func;
		if(tipo_func != 'v' && tipo_func != 't'){
			cout << "Tipo de funcionario nao aceito!! Tente novamente!\n" << endl;
			continuar = 's';
			continue;
		}else{
			if(tipo_func == 'v'){
				cadastrar_vet(vets);
			}else{
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
	}else{
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
//void cadastrar_animal()

//void remover_animal()