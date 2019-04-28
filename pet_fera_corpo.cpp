#include "pet_fera.h"

//Animal
int ANIMAL::getId(){
	return id;
}
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

//Anfibio
void ANFIBIO::setUltima_muda(int *vetor){
	for(int i=0; i<3; i++){
		ultima_muda[i] = vetor[i];
	}
}

int ANFIBIO::getTotal_mudas(){
	return total_mudas;
}
int* ANFIBIO::getUltima_muda(){
	return ultima_muda;
}

ANFIBIO::ANFIBIO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, int mudas, int* data){
	id = i;
	classe = c;
	nome_cientifico = n;
	sexo = s;
	tamanho = tam;
	dieta = die;
	veterinario = vet;
	tratador = trat;
	nome_batismo = nome;
	total_mudas = mudas;
	setUltima_muda(data);
}

ANFIBIO::~ANFIBIO(){

}

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
void FUNCIONARIO::setTipo_sanguineo(char t){
	this->tipo_sanguineo = t;
}
void FUNCIONARIO::setFator_rh(char f){
	this->fator_rh = f;
}
void FUNCIONARIO::setEspecialidade(string e){
	this->especialidade = e;
}
		
int FUNCIONARIO::getId(){
	return id;
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
char FUNCIONARIO::getTipo_sanguineo(){
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

VETERINARIO::VETERINARIO(int i, string n, long int c, int ida, char t, char f, string e, string cr){
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

TRATADOR::TRATADOR(int i, string n, long int c, int ida, char t, char f, string e, int nivel){
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

