#include "pet_fera.h"

//Animal
string ANIMAL::getClasse(){
	return *classe;
}
string ANIMAL::getNome_cientifico(){
	return *nome_cientifico;
}
char ANIMAL::getSexo(){
	return sexo;
}
double ANIMAL::getTamanho(){
	return tamanho;
}
string ANIMAL::getDieta(){
	return *dieta;
}
string ANIMAL::getVeterinario(){
	return *veterinario;
}
string ANIMAL::getTratador(){
	return *tratador;
}
string ANIMAL::getNome_batismo(){
	return *nome_batismo;
}
ANIMAL::ANIMAL(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome){
	this->id = i;
	this->classe = new string(c);
	this->nome_cientifico = new string(n);
	this->sexo = s;
	this->tamanho = tam;
	this->dieta = new string(die);
	this->veterinario = new string(vet);
	this->tratador = new string(trat);
	this->nome_batismo = new string(nome);
}
//destrutor
ANIMAL::~ANIMAL(){
	delete classe;
	delete nome_cientifico;
	delete dieta;
	delete veterinario;
	delete tratador;
	delete nome_batismo;
}


//Animal Silvestre
string ANIMAL_SILVESTRE::getAutorizacao_IBAMA(){
	return *autorizacao_IBAMA;
}

ANIMAL_SILVESTRE::ANIMAL_SILVESTRE(string aut){
	this->autorizacao_IBAMA = new string(aut);
}

ANIMAL_SILVESTRE::~ANIMAL_SILVESTRE(){
	delete autorizacao_IBAMA;
}



//Animal Nativo
string ANIMAL_NATIVO::getUf_origem(){
	return *uf_origem;
}
string ANIMAL_NATIVO::getAutorizacao(){
	return *autorizacao;
}
		
ANIMAL_NATIVO::ANIMAL_NATIVO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string aut, string u, string a):ANIMAL(i, c, n, s, tam, die, vet, trat, nome),ANIMAL_SILVESTRE(aut){
	this->uf_origem = new string(u);
	this->autorizacao = new string(a);
}

int ANIMAL_NATIVO::getId(){
	return this->id;
}

ANIMAL_NATIVO::~ANIMAL_NATIVO(){
	delete uf_origem;
	delete autorizacao;
}

//Animal Exotico
string ANIMAL_EXOTICO::getPais_origem(){
	return *pais_origem;
}
string ANIMAL_EXOTICO::getAutorizacao(){
	return *autorizacao;
}
		
ANIMAL_EXOTICO::ANIMAL_EXOTICO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string aut, string p, string a):ANIMAL(i, c, n, s, tam, die, vet, trat, nome),ANIMAL_SILVESTRE(aut){
	this->pais_origem = new string(p);
	this->autorizacao = new string(a);
}

int ANIMAL_EXOTICO::getId(){
	return this->id;
}

ANIMAL_EXOTICO::~ANIMAL_EXOTICO(){
	delete pais_origem;
	delete autorizacao;
}


//Anfibio
void ANFIBIO::setUltima_muda(int *vetor){
	for(int i = 0; i < 3; i++){
		ultima_muda[i] = vetor[i];
	}
}

int ANFIBIO::getTotal_mudas(){
	return total_mudas;
}
int* ANFIBIO::getUltima_muda(){
	return ultima_muda;
}

ANFIBIO::ANFIBIO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, int mudas, int* data):ANIMAL(i, c, n, s, tam, die, vet, trat, nome){
	total_mudas = mudas;
	setUltima_muda(data);
}

int ANFIBIO::getId(){
	return this->id;
}

ANFIBIO::~ANFIBIO(){
}

//Mamífero

void MAMIFERO::setCor_pelo(string c){
	*cor_pelo = c;
}

string MAMIFERO::getCor_pelo(){
	return *cor_pelo;
}

MAMIFERO::MAMIFERO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string cor):ANIMAL(i, c, n, s, tam, die, vet, trat, nome){
	cor_pelo = new string(cor);
}

int MAMIFERO::getId(){
	return this->id;
}

MAMIFERO::~MAMIFERO(){
	delete cor_pelo;
}

//Réptil
void REPTIL::setVenenoso(bool v){
	venenoso = v;
}
void REPTIL::setTipo_veneno(string t){
	*tipo_veneno = t;
}

bool REPTIL::getVenenoso(){
	return true;
}
string REPTIL::getTipo_veneno(){
	return *tipo_veneno;
}

REPTIL::REPTIL(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, bool v, string t):ANIMAL(i, c, n, s, tam, die, vet, trat, nome){
	venenoso = v;
	tipo_veneno = new string(t);
}

int REPTIL::getId(){
	return this->id;
}

REPTIL::~REPTIL(){
	delete tipo_veneno;
}

// Ave

void AVE::setTamanho_bico(double t){
	tamanho_bico = t;
}
void AVE::setEnvergadura(double e){
	envergadura = e;
}
double AVE::getTamanho_bico(){
	return tamanho_bico;
}
double AVE::getEnvergadura(){
	return envergadura;
}

AVE::AVE(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, double t, double e):ANIMAL(i, c, n, s, tam, die, vet, trat, nome){
	tamanho_bico = t;
	envergadura = e;
}

int AVE::getId(){
	return this->id;
}

AVE::~AVE(){}

//Funcionário
void FUNCIONARIO::setId(int i){
	this->id = i;
}
void FUNCIONARIO::setNome(string n){
	*nome = n;
}
void FUNCIONARIO::setCpf(long int c){
	this->cpf = c;
}
void FUNCIONARIO::setIdade(int i){
	this->idade = i;
}
void FUNCIONARIO::setTipo_sanguineo(char t){
	this->tipo_sanguineo = t;
}
void FUNCIONARIO::setFator_rh(char f){
	this->fator_rh = f;
}
void FUNCIONARIO::setEspecialidade(string e){
	*especialidade = e;
}
string FUNCIONARIO::getNome(){
	return *nome;
}
long int FUNCIONARIO::getCpf(){
	return cpf;
}
int FUNCIONARIO::getIdade(){
	return idade;
}
char FUNCIONARIO::getTipo_sanguineo(){
	return tipo_sanguineo;
}
char FUNCIONARIO::getFator_rh(){
	return fator_rh;
}
string FUNCIONARIO::getEspecialidade(){
	return *especialidade;
}

//Veterinário
void VETERINARIO::setCrmv(string c){
	*crmv = c;
}
string VETERINARIO::getCrmv(){
	return *crmv;
}

int VETERINARIO::getId(){
	return this->id;
}

VETERINARIO::VETERINARIO(int i, string n, long int c, int ida, char t, char f, string e, string cr){
	id = i;
	nome = new string(n);
	cpf = c;
	idade = ida;
	tipo_sanguineo = t;
	fator_rh = f;
	especialidade = new string(e);
	crmv = new string(cr);
}
ostream& operator << (ostream &out, VETERINARIO &v){
	cout << endl;
	cout << "**Veterinário**" << endl << endl;;
	out << "Id: " << v.getId() << endl;
	out << "Nome: " << v.getNome() << endl;
	out << "CPF: " << v.getCpf() << endl;
	out << "Idade: " << v.getIdade() << endl;
	out << "Tipo sanguineo: " << v.getTipo_sanguineo() << endl;
	out << "Fator RH: " << v.getFator_rh() << endl;
	out << "Especialidade: " << v.getEspecialidade() << endl;
	out << "CRMV: " << v.getCrmv() << endl;
	cout << endl;

	return out;
}

VETERINARIO::~VETERINARIO(){
	delete nome;
	delete especialidade;
}

//Tratador
int TRATADOR::getNivel_seguranca(){
	return nivel_seguranca;
}

TRATADOR::TRATADOR(int i, string n, long int c, int ida, char t, char f, string e, int nivel){
	id = i;
	nome = new string(n);
	cpf = c;
	idade = ida;
	tipo_sanguineo = t;
	fator_rh = f;
	especialidade = new string(e);
	nivel_seguranca = nivel;
}
TRATADOR::~TRATADOR(){
	delete nome;
	delete especialidade;
}

int TRATADOR::getId(){
	return this->id;
}
ostream& operator << (ostream &out, TRATADOR &v){
	cout << endl;
	cout << "**Tratador**" << endl << endl;
	out << "Id: " << v.getId() << endl;
	out << "Nome: " << v.getNome() << endl;
	out << "CPF: " << v.getCpf() << endl;
	out << "Idade: " << v.getIdade() << endl;
	out << "Tipo sanguineo: " << v.getTipo_sanguineo() << endl;
	out << "Fator RH: " << v.getFator_rh() << endl;
	out << "Especialidade: " << v.getEspecialidade() << endl;
	out << "Nivel de segurança: " << v.getNivel_seguranca() << endl;
	cout << endl;

	return out;
}

