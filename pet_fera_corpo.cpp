#include "pet_fera.h"

// Implementação da classe Animal.
string ANIMAL::getClasse(){
	return classe;
}
string ANIMAL::getNome(){
	return nome;
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
ANIMAL::ANIMAL(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome){
	this->id = i;
	this->classe = c;
	this->nome = no;
	this->nome_cientifico = n;
	this->sexo = s;
	this->tamanho = tam;
	this->dieta = die;
	this->veterinario = vet;
	this->tratador = trat;
	this->nome_batismo = nome;
}
ANIMAL::~ANIMAL(){}

ANIMAL_SILVESTRE::ANIMAL_SILVESTRE(string aut){
	this->autorizacao_IBAMA = aut;
}

ANIMAL_SILVESTRE::~ANIMAL_SILVESTRE(){}


// Implementação da classe Animal Nativo.
string ANIMAL_NATIVO::getUf_origem(){
	return uf_origem;
}
string ANIMAL_NATIVO::getAutorizacao(){
	return autorizacao;
}
		
ANIMAL_NATIVO::ANIMAL_NATIVO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, string aut, string u, string a):ANIMAL(i, c, no,  n, s, tam, die, vet, trat, nome),ANIMAL_SILVESTRE(aut){
	this->uf_origem = u;
	this->autorizacao = a;
}

string ANIMAL_NATIVO::getAutorizacao_IBAMA(){
	return this->autorizacao_IBAMA;
}

ANIMAL_NATIVO::~ANIMAL_NATIVO(){}


// Implementação da classe Anfíbio Nativo.
ANFIBIO_NATIVO::ANFIBIO_NATIVO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, int mudas, string data, string aut, string u, string a):ANIMAL_NATIVO(i, c, nome, n, s, tam, die, vet, trat, nome, aut, u, a), ANFIBIO(mudas, data){}
ANFIBIO_NATIVO::~ANFIBIO_NATIVO(){}
int ANFIBIO_NATIVO::getId(){
	return id;
}


// Implementação da classe Anfíbio Exótico.
ANFIBIO_EXOTICO::ANFIBIO_EXOTICO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, int mudas, string data, string aut, string pais, string a):ANIMAL_EXOTICO(i, c, nome, n, s, tam, die, vet, trat, nome, aut, pais, a), ANFIBIO(mudas, data){}		
ANFIBIO_EXOTICO::~ANFIBIO_EXOTICO(){}
int ANFIBIO_EXOTICO::getId(){
	return id;
}

// Implementação da classe Mamífero Nativo.
MAMIFERO_NATIVO::MAMIFERO_NATIVO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, string cor, string aut, string u, string a):ANIMAL_NATIVO(i, c, no, n, s, tam, die, vet, trat, nome, aut, u, a), MAMIFERO(cor){}
MAMIFERO_NATIVO::~MAMIFERO_NATIVO(){}
int MAMIFERO_NATIVO::getId(){
	return id;
}

// Implementação da classe Mamífero Exótico.
MAMIFERO_EXOTICO::MAMIFERO_EXOTICO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, string cor, string aut, string pais, string a):ANIMAL_EXOTICO(i, c, no, n, s, tam, die, vet, trat, nome, aut, pais, a), MAMIFERO(cor){}
MAMIFERO_EXOTICO::~MAMIFERO_EXOTICO(){}
int MAMIFERO_EXOTICO::getId(){
	return id;
}

// Implementação da classe Réptil Nativo.
REPTIL_NATIVO::REPTIL_NATIVO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, bool v, string t, string aut, string u, string a):ANIMAL_NATIVO(i, c, no, n, s, tam, die, vet, trat, nome, aut, u, a), REPTIL(v, t){}
REPTIL_NATIVO::~REPTIL_NATIVO(){}
int REPTIL_NATIVO::getId(){
	return id;
}

// Implementação da classe Réptil Exótico.
REPTIL_EXOTICO::REPTIL_EXOTICO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, bool v, string t, string aut, string pais, string a): ANIMAL_EXOTICO(i, c, no, n, s, tam, die, vet, trat, nome, aut, pais, a), REPTIL(v, t){}
REPTIL_EXOTICO::~REPTIL_EXOTICO(){}
int REPTIL_EXOTICO::getId(){
	return id;
}

// Implementação da classe Ave Nativa.
AVE_NATIVO::AVE_NATIVO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, double t, double e, string aut, string u, string a):ANIMAL_NATIVO(i, c, no, n, s, tam, die, vet, trat, nome, aut, u, a), AVE(t, e){}
AVE_NATIVO::~AVE_NATIVO(){}
int AVE_NATIVO::getId(){
	return id;
}

// Implementação da classe Ave Exótica.
AVE_EXOTICO::AVE_EXOTICO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, double t, double e, string aut, string pais, string a): ANIMAL_EXOTICO(i, c, no, n, s, tam, die, vet, trat, nome, aut, pais, a), AVE(t, e){}
AVE_EXOTICO::~AVE_EXOTICO(){}
int AVE_EXOTICO::getId(){
	return id;
}



// Implementação da classe Animal Exótico.
string ANIMAL_EXOTICO::getPais_origem(){
	return pais_origem;
}
string ANIMAL_EXOTICO::getAutorizacao(){
	return autorizacao;
}

ANIMAL_EXOTICO::ANIMAL_EXOTICO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, string aut, string p, string a):ANIMAL(i, c, no, n, s, tam, die, vet, trat, nome),ANIMAL_SILVESTRE(aut){
	this->pais_origem = p;
	this->autorizacao = a;
}

string ANIMAL_EXOTICO::getAutorizacao_IBAMA(){
	return this->autorizacao_IBAMA;
}

ANIMAL_EXOTICO::~ANIMAL_EXOTICO(){}


// Implementação da classe Anfibio
int ANFIBIO::getTotal_mudas(){
	return total_mudas;
}
string ANFIBIO::getUltima_muda(){
	return ultima_muda;
}

ANFIBIO::ANFIBIO(int mudas, string data){
	total_mudas = mudas;
	ultima_muda = data;
}

// Implementação da sobrecarga de operador.
ostream& operator << (ostream &out, ANFIBIO_NATIVO &a){
	cout << endl;
	cout << "**ANFIBIO**" << endl << endl;
	out << "Id: " << a.getId() << endl;
	out << "Clase: " << a.getClasse() << endl;
	out << "Nome: " << a.getNome() << endl;
	out << "Nome Científico: " << a.getNome_cientifico() << endl;
	out << "Sexo: " << a.getSexo() << endl;
	out << "Tamanho: " << a.getTamanho() << endl;
	out << "Dieta: " << a.getDieta() << endl;
	out << "Veterinário: " << a.getVeterinario() << endl;
	out << "Nome de batismo: " << a.getTratador() << endl;
	out << "Total de mudas: " << a.getTotal_mudas() << endl;
	out << "Última muda: " << a.getUltima_muda() << endl;
	out << "Autorização IBAMA: " << a.getAutorizacao_IBAMA() << endl;
	out << "UF de origem: " << a.getUf_origem() << endl;
	out << "Autorização geral: " << a.getAutorizacao() << endl;
	cout << endl;
	return out;	
} 

// Implementação da sobrecarga de operador.
ostream& operator << (ostream &out, ANFIBIO_EXOTICO &a){
	cout << endl;
	cout << "**ANFIBIO**" << endl << endl;
	out << "Id: " << a.getId() << endl;
	out << "Clase: " << a.getClasse() << endl;
	out << "Nome: " << a.getNome() << endl;
	out << "Nome Científico: " << a.getNome_cientifico() << endl;
	out << "Sexo: " << a.getSexo() << endl;
	out << "Tamanho: " << a.getTamanho() << endl;
	out << "Dieta: " << a.getDieta() << endl;
	out << "Veterinário: " << a.getVeterinario() << endl;
	out << "Nome de batismo: " << a.getTratador() << endl;
	out << "Total de mudas: " << a.getTotal_mudas() << endl;
	out << "Última muda: " << a.getUltima_muda() << endl;
	out << "Autorização IBAMA: " << a.getAutorizacao_IBAMA() << endl;
	out << "Pais de origem: " << a.getPais_origem() << endl;
	out << "Autorização geral: " << a.getAutorizacao() << endl;
	cout << endl;
	return out;	
} 

// Escrevendo no arquivo "anfibios_nat.txt".
ofstream& operator << (ofstream &out, ANFIBIO_NATIVO &a){
	out << a.getId() << ";" << a.getClasse() << ";" << a.getNome() << ";" << a.getNome_cientifico() << ";" << a.getSexo() << ";" << a.getTamanho() << ";" << a.getDieta() << ";" <<
	a.getVeterinario() << ";" << a.getTratador() << ";" << a.getNome_batismo() << ";" << a.getTotal_mudas() << ";" << a.getUltima_muda() << ";" << a.getAutorizacao_IBAMA() << ";" << 
	a.getUf_origem() << ";" << a.getAutorizacao() << ";" << '\n';
	return out;
}

// Escrevendo no arquivo "anfibios_ex.txt".
ofstream& operator << (ofstream &out, ANFIBIO_EXOTICO &a){
	out << a.getId() << ";" << a.getClasse() << ";" << a.getNome() << ";" << a.getNome_cientifico() << ";" << a.getSexo() << ";" << a.getTamanho() << ";" << a.getDieta() << ";" <<
	a.getVeterinario() << ";" << a.getTratador() << ";" << a.getNome_batismo() << ";" << a.getTotal_mudas() << ";" << a.getUltima_muda() << ";" << a.getAutorizacao_IBAMA() << ";" << 
	a.getPais_origem() << ";" << a.getAutorizacao() << ";" << '\n';
	return out;
}

ANFIBIO::~ANFIBIO(){}


// Implementação da classe Mamífero.
string MAMIFERO::getCor_pelo(){
	return cor_pelo;
}
MAMIFERO::MAMIFERO(string cor){
	cor_pelo = cor;
}

// Implementação da sobrecarga de operador.
ostream& operator << (ostream &out, MAMIFERO_NATIVO &m){
	cout << endl;
	cout << "**MAMIFERO**" << endl << endl;
	out << "Id: " << m.getId() << endl;
	out << "Clase: " << m.getClasse() << endl;
	out << "Nome: " << m.getNome() << endl;
	out << "Nome Científico: " << m.getNome_cientifico() << endl;
	out << "Sexo: " << m.getSexo() << endl;
	out << "Tamanho: " << m.getTamanho() << endl;
	out << "Dieta: " << m.getDieta() << endl;
	out << "Veterinário: " << m.getVeterinario() << endl;
	out << "Tratador: " << m.getTratador() << endl;
	out << "Nome de batismo: " << m.getNome_batismo() << endl;
	out << "Cor do pelo: " << m.getCor_pelo() << endl;
	out << "Autorização IBAMA: " <<m.getAutorizacao_IBAMA() << endl;
	out << "UF de origem: " << m.getUf_origem() << endl;
	out << "Autorização geral: " << m.getAutorizacao() << endl;
	cout << endl;
	return out;
}

// Implementação da sobrecarga de operador.
ostream& operator << (ostream &out, MAMIFERO_EXOTICO &m){
	cout << endl;
	cout << "**MAMIFERO**" << endl << endl;
	out << "Id: " << m.getId() << endl;
	out << "Classe: " << m.getClasse() << endl;
	out << "Nome: " << m.getNome() << endl;
	out << "Nome Científico: " << m.getNome_cientifico() << endl;
	out << "Sexo: " << m.getSexo() << endl;
	out << "Tamanho: " << m.getTamanho() << endl;
	out << "Dieta: " << m.getDieta() << endl;
	out << "Veterinário: " << m.getVeterinario() << endl;
	out << "Tratador: " << m.getTratador() << endl;
	out << "Nome de batismo: " << m.getTratador() << endl;
	out << "Cor do pelo: " << m.getCor_pelo() << endl;
	out << "Autorização IBAMA: " <<m.getAutorizacao_IBAMA() << endl;
	out << "País de origem: " << m.getPais_origem() << endl;
	out << "Autorização geral: " << m.getAutorizacao() << endl;
	cout << endl;
	return out;
}

// Escrevendo no arquivo "mamiferos_nat.txt".
ofstream& operator << (ofstream &out, MAMIFERO_NATIVO &m){
	out << m.getId() << ";" << m.getClasse() << ";"  << m.getNome() << ";" << m.getNome_cientifico() << ";" << m.getSexo() << ";" << m.getTamanho() << ";" << m.getDieta() << ";" <<
	m.getVeterinario() << ";" << m.getTratador() << ";" << m.getNome_batismo() << ";"  << m.getCor_pelo() << ";" << m.getAutorizacao_IBAMA() << ";" << 
	m.getUf_origem() << ";" << m.getAutorizacao() << ";" << '\n';
	return out;
}

// Escrevendo no arquivo "mamiferos_ex.txt".
ofstream& operator << (ofstream &out, MAMIFERO_EXOTICO &m){
	out << m.getId() << ";" << m.getClasse() << ";" << m.getNome() << ";" << m.getNome_cientifico() << ";" << m.getSexo() << ";" << m.getTamanho() << ";" << m.getDieta() << ";" <<
	m.getVeterinario() << ";" << m.getTratador() << ";" << m.getNome_batismo() << ";"  << m.getCor_pelo() << ";" << m.getAutorizacao_IBAMA() << ";" << 
	m.getPais_origem() << ";" << m.getAutorizacao() << ";" << '\n';
	return out;
}

MAMIFERO::~MAMIFERO(){}



// Implementação da classe Réptil.
bool REPTIL::getVenenoso(){
	return venenoso;
}
string REPTIL::getTipo_veneno(){
	return tipo_veneno;
}

REPTIL::REPTIL(bool v, string t){
	venenoso = v;
	tipo_veneno = t;
}

// Implementação da sobrecarga de operador.
ostream& operator << (ostream &out, REPTIL_NATIVO &r){
	cout << endl;
	cout << "**REPTIL**" << endl << endl;
	out << "Id: " << r.getId() << endl;
	out << "Clase: " << r.getClasse() << endl;
	out << "Nome: " << r.getNome() << endl;
	out << "Nome Científico: " << r.getNome_cientifico() << endl;
	out << "Sexo: " << r.getSexo() << endl;
	out << "Tamanho: " << r.getTamanho() << endl;
	out << "Dieta: " << r.getDieta() << endl;
	out << "Veterinário: " << r.getVeterinario() << endl;
	out << "Tratador: " << r.getTratador() << endl;
	out << "Nome de batismo: " << r.getNome_batismo() << endl;
	out << "Venenoso: " << r.getVenenoso() << endl;
	out << "Tipo do Veneno: " << r.getTipo_veneno() << endl;
	out << "Autorização IBAMA: " << r.getAutorizacao_IBAMA() << endl;
	out << "UF de origem: " << r.getUf_origem() << endl;
	out << "Autorização geral: " << r.getAutorizacao() << endl;
	cout << endl;
	return out;
}

// Implementação da sobrecarga de operador.
ostream& operator << (ostream &out, REPTIL_EXOTICO &r){
	cout << endl;
	cout << "**REPTIL**" << endl << endl;
	out << "Id: " << r.getId() << endl;
	out << "Clase: " << r.getClasse() << endl;
	out << "Nome: " << r.getNome() << endl;
	out << "Nome Científico: " << r.getNome_cientifico() << endl;
	out << "Sexo: " << r.getSexo() << endl;
	out << "Tamanho: " << r.getTamanho() << endl;
	out << "Dieta: " << r.getDieta() << endl;
	out << "Veterinário: " << r.getVeterinario() << endl;
	out << "Tratador: " << r.getTratador() << endl;
	out << "Nome de batismo: " << r.getNome_batismo() << endl;
	out << "Venenoso: " << r.getVenenoso() << endl;
	out << "Tipo do Veneno: " << r.getTipo_veneno() << endl;
	out << "Autorização IBAMA: " << r.getAutorizacao_IBAMA() << endl;
	out << "País de origem: " << r.getPais_origem() << endl;
	out << "Autorização geral: " << r.getAutorizacao() << endl;
	cout << endl;
	return out;
}

// Escrevendo no arquivo "repteis_nat.txt".
ofstream& operator << (ofstream &out, REPTIL_NATIVO &r){
	out << r.getId() << ";" << r.getClasse() << ";" << r.getNome() << ";" << r.getNome_cientifico() << ";" << r.getSexo() << ";" << r.getTamanho() << ";" << r.getDieta() << ";" <<
	r.getVeterinario() << ";" << r.getTratador() << ";" << r.getNome_batismo() << ";"  << r.getVenenoso() <<  ";" << r.getTipo_veneno()  << ";" << r.getAutorizacao_IBAMA() << ";" << 
	r.getUf_origem() << ";" << r.getAutorizacao() << ";" << '\n';
	return out;
}

// Escrevendo no arquivo "repteis_ex.txt".
ofstream& operator << (ofstream &out, REPTIL_EXOTICO &r){
	out << r.getId() << ";" << r.getClasse() << ";" << r.getNome() << ";" << r.getNome_cientifico() << ";" << r.getSexo() << ";" << r.getTamanho() << ";" << r.getDieta() << ";" <<
	r.getVeterinario() << ";" << r.getTratador() << ";" << r.getNome_batismo() << ";"  << r.getVenenoso() <<  ";" << r.getTipo_veneno()  << ";" << r.getAutorizacao_IBAMA() << ";" << 
	r.getPais_origem() << ";" << r.getAutorizacao() << ";" << '\n';
	return out;
}

REPTIL::~REPTIL(){}


// Implementação da classe Ave.
double AVE::getTamanho_bico(){
	return tamanho_bico;
}
double AVE::getEnvergadura(){
	return envergadura;
}

AVE::AVE(double t, double e){
	tamanho_bico = t;
	envergadura = e;
}

// Implementação da sobrecarga de operador.
ostream& operator << (ostream &out, AVE_NATIVO &a){
	cout << endl;
	cout << "**AVE**" << endl << endl;
	out << "Id: " << a.getId() << endl;
	out << "Clase: " << a.getClasse() << endl;
	out << "Nome: " << a.getNome() << endl;
	out << "Nome Científico: " << a.getNome_cientifico() << endl;
	out << "Sexo: " << a.getSexo() << endl;
	out << "Tamanho: " << a.getTamanho() << endl;
	out << "Dieta: " << a.getDieta() << endl;
	out << "Veterinário: " << a.getVeterinario() << endl;
	out << "Tratador: " << a.getTratador() << endl;
	out << "Nome de batismo: " << a.getNome_batismo() << endl;
	out << "Tamanho do bico: " << a.getTamanho_bico() << endl;
	out << "Envergadura: " << a.getEnvergadura() << endl;
	out << "Autorização IBAMA: " << a.getAutorizacao_IBAMA() << endl;
	out << "UF de origem: " << a.getUf_origem() << endl;
	out << "Autorização geral: " << a.getAutorizacao() << endl;
	cout << endl;
	return out;

}

// Implementação da sobrecarga de operador.
ostream& operator << (ostream &out, AVE_EXOTICO &a){
	cout << endl;
	cout << "**AVE**" << endl << endl;
	out << "Id: " << a.getId() << endl;
	out << "Clase: " << a.getClasse() << endl;
	out << "Nome: " << a.getNome() << endl;
	out << "Nome Científico: " << a.getNome_cientifico() << endl;
	out << "Sexo: " << a.getSexo() << endl;
	out << "Tamanho: " << a.getTamanho() << endl;
	out << "Dieta: " << a.getDieta() << endl;
	out << "Veterinário: " << a.getVeterinario() << endl;
	out << "Tratador: " << a.getTratador() << endl;
	out << "Nome de batismo: " << a.getNome_batismo() << endl;
	out << "Tamanho do bico: " << a.getTamanho_bico() << endl;
	out << "Envergadura: " << a.getEnvergadura() << endl;
	out << "Autorização IBAMA: " << a.getAutorizacao_IBAMA() << endl;
	out << "País de origem: " << a.getPais_origem() << endl;
	out << "Autorização geral: " << a.getAutorizacao() << endl;
	cout << endl;
	return out;

}

// Escrevendo no arquivo "aves_nat.txt".
ofstream& operator << (ofstream &out, AVE_NATIVO &v){
	out << v.getId() << ";" << v.getClasse() << ";" << v.getNome() << ";" << v.getNome_cientifico() << ";" << v.getSexo() << ";" << v.getTamanho() << ";" << v.getDieta() << ";" <<
	v.getVeterinario() << ";" << v.getTratador() << ";" << v.getNome_batismo() << ";"  << v.getTamanho_bico() << ";" << v.getEnvergadura() << ";" << v.getAutorizacao_IBAMA() << ";" << 
	v.getUf_origem() << ";" << v.getAutorizacao() << ";" << '\n';
	return out;
}

// Escrevendo no arquivo "aves_ex.txt".
ofstream& operator << (ofstream &out, AVE_EXOTICO &v){
	out << v.getId() << ";" << v.getClasse() << ";" << v.getNome() << ";" << v.getNome_cientifico() << ";" << v.getSexo() << ";" << v.getTamanho() << ";" << v.getDieta() << ";" <<
	v.getVeterinario() << ";" << v.getTratador() << ";" << v.getNome_batismo() << ";"  << v.getTamanho_bico() << ";" << v.getEnvergadura() << ";" << v.getAutorizacao_IBAMA() << ";" << 
	v.getPais_origem() << ";" << v.getAutorizacao() << ";" << '\n';
	return out;
}

AVE::~AVE(){}


// Implementação da classe Funcionário.
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

// Implementação da classe Veterinário.
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
// Implementação da sobrecarga de operador.
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

// Escrevendo no arquivo "veterinarios.txt".
ofstream& operator << (ofstream &out, VETERINARIO &v){
	out << v.getId() << ";" << v.getNome() << ";" << v.getCpf() << ";" << v.getIdade() << ";" << v.getTipo_sanguineo() << ";" << v.getFator_rh() << ";" <<
	v.getEspecialidade() << ";" << v.getCrmv() << ";" << '\n';
	return out;
}


// Implementação da classe Tratador.
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

// Implementação da sobrecarga de operador
ostream& operator << (ostream &out, TRATADOR &t){
	cout << endl;
	cout << "**Tratador**" << endl << endl;
	out << "Id: " << t.getId() << endl;
	out << "Nome: " << t.getNome() << endl;
	out << "CPF: " << t.getCpf() << endl;
	out << "Idade: " << t.getIdade() << endl;
	out << "Tipo sanguineo: " << t.getTipo_sanguineo() << endl;
	out << "Fator RH: " << t.getFator_rh() << endl;
	out << "Especialidade: " << t.getEspecialidade() << endl;
	out << "Nivel de segurança: " << t.getNivel_seguranca() << endl;
	cout << endl;

	return out;
}

// Escrevendo no arquivo "tratadores.txt".
ofstream& operator << (ofstream &out, TRATADOR &t){
	out << t.getId() << ";" << t.getNome() << ";" << t.getCpf() << ";" << t.getIdade() << ";" << t.getTipo_sanguineo() << ";" << t.getFator_rh() << ";" <<
	t.getEspecialidade() << ";" << t.getNivel_seguranca() << ";" << '\n';
	return out;
}