#include "pet_fera.h"

//Animal
string ANIMAL::getClasse(){
	return classe;
}
string ANIMAL::getNome_cientifico(){
	return nome_cientifico;
}
char ANIMAL::getSexo(){
	return sexo;
}
double ANIMAL::getTamanho(){
	return tamanho;
}
string ANIMAL::getDieta(){
	return dieta;
}
string ANIMAL::getVeterinario(){
	return veterinario;
}
string ANIMAL::getTratador(){
	return tratador;
}
string ANIMAL::getNome_batismo(){
	return nome_batismo;
}
ANIMAL::ANIMAL(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome){
	this->id = i;
	this->classe = c;
	this->nome_cientifico = n;
	this->sexo = s;
	this->tamanho = tam;
	this->dieta = die;
	this->veterinario = vet;
	this->tratador = trat;
	this->nome_batismo = nome;
}
//destrutor
ANIMAL::~ANIMAL(){}


//Animal Silvestre
string ANIMAL_SILVESTRE::getAutorizacao_IBAMA(){
	return autorizacao_IBAMA;
}

ANIMAL_SILVESTRE::ANIMAL_SILVESTRE(string aut){
	this->autorizacao_IBAMA = aut;
}

ANIMAL_SILVESTRE::~ANIMAL_SILVESTRE(){}



//Animal Nativo
string ANIMAL_NATIVO::getUf_origem(){
	return uf_origem;
}
string ANIMAL_NATIVO::getAutorizacao(){
	return autorizacao;
}
		
ANIMAL_NATIVO::ANIMAL_NATIVO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string aut, string u, string a):ANIMAL(i, c, n, s, tam, die, vet, trat, nome),ANIMAL_SILVESTRE(aut){
	this->uf_origem = u;
	this->autorizacao = a;
}

int ANIMAL_NATIVO::getId(){
	return this->id;
}

ANIMAL_NATIVO::~ANIMAL_NATIVO(){}

//Animal Exotico
string ANIMAL_EXOTICO::getPais_origem(){
	return pais_origem;
}
string ANIMAL_EXOTICO::getAutorizacao(){
	return autorizacao;
}
		
ANIMAL_EXOTICO::ANIMAL_EXOTICO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string aut, string p, string a):ANIMAL(i, c, n, s, tam, die, vet, trat, nome),ANIMAL_SILVESTRE(aut){
	this->pais_origem = p;
	this->autorizacao = a;
}

int ANIMAL_EXOTICO::getId(){
	return this->id;
}

ANIMAL_EXOTICO::~ANIMAL_EXOTICO(){}


//Anfibio
/*(void ANFIBIO::setUltima_muda(int *vetor){
	for(int i = 0; i < 3; i++){
		ultima_muda[i] = vetor[i];
	}
}*/

int ANFIBIO::getTotal_mudas(){
	return total_mudas;
}
int* ANFIBIO::getUltima_muda(){
	return ultima_muda;
}

ANFIBIO::ANFIBIO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, int mudas, int data[3]):ANIMAL(i, c, n, s, tam, die, vet, trat, nome){
	total_mudas = mudas;
	ultima_muda[0] = data[0];
	ultima_muda[1] = data[1];
	ultima_muda[2] = data[2];
	//setUltima_muda(data);
}
ostream& operator << (ostream &out, ANFIBIO &a){
	cout << endl;
	cout << "**ANFIBIO**" << endl << endl;
	out << "Id: " << a.getId() << endl;
	out << "Clase: " << a.getClasse() << endl;
	out << "Nome Científico: " << a.getNome_cientifico() << endl;
	out << "Sexo: " << a.getSexo() << endl;
	out << "Tamanho: " << a.getTamanho() << endl;
	out << "Dieta: " << a.getDieta() << endl;
	out << "Veterinário: " << a.getVeterinario() << endl;
	out << "Nome de batismo: " << a.getTratador() << endl;
	out << "Total de mudas: " <<a.getTotal_mudas() << endl;
	out << "Última muda: " <<a.getUltima_muda() << endl;
	cout << endl;

}

int ANFIBIO::getId(){
	return this->id;
}

ANFIBIO::~ANFIBIO(){}

//Mamífero

void MAMIFERO::setCor_pelo(string c){
	cor_pelo = c;
}

string MAMIFERO::getCor_pelo(){
	return cor_pelo;
}

MAMIFERO::MAMIFERO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string cor):ANIMAL(i, c, n, s, tam, die, vet, trat, nome){
	cor_pelo = cor;
}

ostream& operator << (ostream &out, MAMIFERO &m){
	cout << endl;
	cout << "**MAMIFERO**" << endl << endl;
	out << "Id: " << m.getId() << endl;
	out << "Clase: " << m.getClasse() << endl;
	out << "Nome Científico: " << m.getNome_cientifico() << endl;
	out << "Sexo: " << m.getSexo() << endl;
	out << "Tamanho: " << m.getTamanho() << endl;
	out << "Dieta: " << m.getDieta() << endl;
	out << "Veterinário: " << m.getVeterinario() << endl;
	out << "Nome de batismo: " << m.getTratador() << endl;
	out << "Cor do pelo: " <<m.getCor_pelo() << endl;
	cout << endl;

}

int MAMIFERO::getId(){
	return this->id;
}

MAMIFERO::~MAMIFERO(){}

//Réptil
void REPTIL::setVenenoso(bool v){
	venenoso = v;
}
void REPTIL::setTipo_veneno(string t){
	tipo_veneno = t;
}

bool REPTIL::getVenenoso(){
	return true;
}
string REPTIL::getTipo_veneno(){
	return tipo_veneno;
}

REPTIL::REPTIL(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, bool v, string t):ANIMAL(i, c, n, s, tam, die, vet, trat, nome){
	venenoso = v;
	tipo_veneno = t;
}

ostream& operator << (ostream &out, REPTIL &r){
	cout << endl;
	cout << "**REPTIL**" << endl << endl;
	out << "Id: " << r.getId() << endl;
	out << "Clase: " << r.getClasse() << endl;
	out << "Nome Científico: " << r.getNome_cientifico() << endl;
	out << "Sexo: " << r.getSexo() << endl;
	out << "Tamanho: " << r.getTamanho() << endl;
	out << "Dieta: " << r.getDieta() << endl;
	out << "Veterinário: " << r.getVeterinario() << endl;
	out << "Nome de batismo: " << r.getTratador() << endl;
	out << "Venenoso: " <<r.getVenenoso() << endl;
	out << "Tipo de veneno: " <<r.getTipo_veneno() << endl;
	cout << endl;

}

int REPTIL::getId(){
	return this->id;
}

REPTIL::~REPTIL(){}

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

ostream& operator << (ostream &out, AVE &av){
	cout << endl;
	cout << "**AVE**" << endl << endl;
	out << "Id: " << av.getId() << endl;
	out << "Clase: " << av.getClasse() << endl;
	out << "Nome Científico: " << av.getNome_cientifico() << endl;
	out << "Sexo: " << av.getSexo() << endl;
	out << "Tamanho: " << av.getTamanho() << endl;
	out << "Dieta: " << av.getDieta() << endl;
	out << "Veterinário: " << av.getVeterinario() << endl;
	out << "Nome de batismo: " << av.getTratador() << endl;
	out << "Tamanho do bico: " <<av.getTamanho_bico() << endl;
	out << "Envergadura: " <<av.getEnvergadura() << endl;
	cout << endl;

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
	this->nome = n;
}
void FUNCIONARIO::setCpf(long int c){
	this->cpf = c;
}
void FUNCIONARIO::setIdade(int i){
	this->idade = i;
}
void FUNCIONARIO::setTipo_sanguineo(string t){
	this->tipo_sanguineo = t;
}
void FUNCIONARIO::setFator_rh(char f){
	this->fator_rh = f;
}
void FUNCIONARIO::setEspecialidade(string e){
	this->especialidade = e;
}

string FUNCIONARIO::getNome(){
	return nome;
}
long int FUNCIONARIO::getCpf(){
	return cpf;
}
int FUNCIONARIO::getIdade(){
	return idade;
}
string FUNCIONARIO::getTipo_sanguineo(){
	return tipo_sanguineo;
}
char FUNCIONARIO::getFator_rh(){
	return fator_rh;
}
string FUNCIONARIO::getEspecialidade(){
	return especialidade;
}

//Veterinário
void VETERINARIO::setCrmv(string c){
	this->crmv = c;
}
string VETERINARIO::getCrmv(){
	return crmv;
}

int VETERINARIO::getId(){
	return id;
}

VETERINARIO::VETERINARIO(int i, string n, long int c, int ida, string t, char f, string e, string cr){
	id = i;
	nome = n;
	cpf = c;
	idade = ida;
	tipo_sanguineo = t;
	fator_rh = f;
	especialidade = e;
	crmv = cr;
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

//Tratador
int TRATADOR::getNivel_seguranca(){
	return nivel_seguranca;
}

int TRATADOR::getId(){
	return id;
}

TRATADOR::TRATADOR(int i, string n, long int c, int ida, string t, char f, string e, int nivel){
	id = i;
	nome = n;
	cpf = c;
	idade = ida;
	tipo_sanguineo = t;
	fator_rh = f;
	especialidade = e;
	nivel_seguranca = nivel;
}
TRATADOR::~TRATADOR(){

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

