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
ANIMAL::~ANIMAL(){}


//Animal Silvestre
// string ANIMAL_SILVESTRE::getAutorizacao_IBAMA(){
// 	return autorizacao_IBAMA;
// }

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

// int ANIMAL_NATIVO::getId(){
// 	return this->id;
// }
string ANIMAL_NATIVO::getAutorizacao_IBAMA(){
	return this->autorizacao_IBAMA;
}

ANIMAL_NATIVO::~ANIMAL_NATIVO(){}



//Anfibio Nativo
ANFIBIO_NATIVO::ANFIBIO_NATIVO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, int mudas, string data, string aut, string u, string a):ANIMAL_NATIVO(i, c, n, s, tam, die, vet, trat, nome, aut, u, a), ANFIBIO(mudas, data){}
ANFIBIO_NATIVO::~ANFIBIO_NATIVO(){}
int ANFIBIO_NATIVO::getId(){
	return id;
}


//Anfibio Exotico
ANFIBIO_EXOTICO::ANFIBIO_EXOTICO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, int mudas, string data, string aut, string pais, string a):ANIMAL_EXOTICO(i, c, n, s, tam, die, vet, trat, nome, aut, pais, a), ANFIBIO(mudas, data){}		
ANFIBIO_EXOTICO::~ANFIBIO_EXOTICO(){}
int ANFIBIO_EXOTICO::getId(){
	return id;
}

//MAmifero Nativo
MAMIFERO_NATIVO::MAMIFERO_NATIVO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string cor, string aut, string u, string a):ANIMAL_NATIVO(i, c, n, s, tam, die, vet, trat, nome, aut, u, a), MAMIFERO(cor){}
MAMIFERO_NATIVO::~MAMIFERO_NATIVO(){}
int MAMIFERO_NATIVO::getId(){
	return id;
}

//Mamifero Exotico
MAMIFERO_EXOTICO::MAMIFERO_EXOTICO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string cor, string aut, string pais, string a):ANIMAL_EXOTICO(i, c, n, s, tam, die, vet, trat, nome, aut, pais, a), MAMIFERO(cor){}
MAMIFERO_EXOTICO::~MAMIFERO_EXOTICO(){}
int MAMIFERO_EXOTICO::getId(){
	return id;
}

//Reptil Nativo
REPTIL_NATIVO::REPTIL_NATIVO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, bool v, string t, string aut, string u, string a):ANIMAL_NATIVO(i, c, n, s, tam, die, vet, trat, nome, aut, u, a), REPTIL(v, t){}
REPTIL_NATIVO::~REPTIL_NATIVO(){}
int REPTIL_NATIVO::getId(){
	return id;
}

//Reptil Exotico
REPTIL_EXOTICO::REPTIL_EXOTICO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, bool v, string t, string aut, string pais, string a): ANIMAL_EXOTICO(i, c, n, s, tam, die, vet, trat, nome, aut, pais, a), REPTIL(v, t){}
REPTIL_EXOTICO::~REPTIL_EXOTICO(){}
int REPTIL_EXOTICO::getId(){
	return id;
}

//Ave Nativo
AVE_NATIVO::AVE_NATIVO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, double t, double e, string aut, string u, string a):ANIMAL_NATIVO(i, c, n, s, tam, die, vet, trat, nome, aut, u, a), AVE(t, e){}
AVE_NATIVO::~AVE_NATIVO(){}
int AVE_NATIVO::getId(){
	return id;
}

//Ave Exotico
AVE_EXOTICO::AVE_EXOTICO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, double t, double e, string aut, string pais, string a): ANIMAL_EXOTICO(i, c, n, s, tam, die, vet, trat, nome, aut, pais, a), AVE(t, e){}
AVE_EXOTICO::~AVE_EXOTICO(){}
int AVE_EXOTICO::getId(){
	return id;
}



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

// int ANIMAL_EXOTICO::getId(){
// 	return this->id;
// }
string ANIMAL_EXOTICO::getAutorizacao_IBAMA(){
	return this->autorizacao_IBAMA;
}

ANIMAL_EXOTICO::~ANIMAL_EXOTICO(){}


//Anfibio
int ANFIBIO::getTotal_mudas(){
	return total_mudas;
}
string ANFIBIO::getUltima_muda(){
	return ultima_muda;
}
// int ANFIBIO::getId(){
// 	return id;
// }

ANFIBIO::ANFIBIO(int mudas, string data){
	total_mudas = mudas;
	ultima_muda = data;
}
ostream& operator << (ostream &out, ANFIBIO_NATIVO &a){
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
	out << "Total de mudas: " << a.getTotal_mudas() << endl;
	out << "Última muda: " << a.getUltima_muda()[0] << "-" << a.getUltima_muda()[1] << "-" << a.getUltima_muda()[2] << endl;
	out << "Autorização IBAMA: " << a.getAutorizacao_IBAMA() << endl;
	out << "UF de origem: " << a.getUf_origem() << endl;
	out << "Autorização geral: " << a.getAutorizacao() << endl;
	cout << endl;
	return out;	
} 
<<<<<<< HEAD

ANFIBIO::~ANFIBIO(){}


=======

ofstream& operator << (ofstream &out, ANFIBIO_NATIVO &a){
	out << a.getId() << ";" << a.getClasse() << ";" << a.getNome_cientifico() << ";" << a.getSexo() << ";" << a.getTamanho() << ";" << a.getDieta() << ";" <<
	a.getVeterinario() << ";" << a.getTratador() << ";" << a.getNome_batismo() << ";" << a.getTotal_mudas() << ";" << a.getUltima_muda() << ";" << a.getAutorizacao_IBAMA() << ";" << 
	a.getUf_origem() << ";" << a.getAutorizacao() << "\n";
	return out;
}

ANFIBIO::~ANFIBIO(){}


>>>>>>> Hilton
//Mamífero
string MAMIFERO::getCor_pelo(){
	return cor_pelo;
}
MAMIFERO::MAMIFERO(string cor){
	cor_pelo = cor;
}

// int MAMIFERO::getId(){
// 	return id;
// }

ostream& operator << (ostream &out, MAMIFERO_NATIVO &m){
	cout << endl;
	cout << "**MAMIFERO**" << endl << endl;
	out << "Id: " << m.getId() << endl;
	out << "Clase: " << m.getClasse() << endl;
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

ostream& operator << (ostream &out, MAMIFERO_EXOTICO &m){
	cout << endl;
	cout << "**MAMIFERO**" << endl << endl;
	out << "Id: " << m.getId() << endl;
	out << "Classe: " << m.getClasse() << endl;
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

MAMIFERO::~MAMIFERO(){}



//Réptil
bool REPTIL::getVenenoso(){
	return venenoso;
}
string REPTIL::getTipo_veneno(){
	return tipo_veneno;
}
// int REPTIL::getId(){
// 	return id;
// }

REPTIL::REPTIL(bool v, string t){
	venenoso = v;
	tipo_veneno = t;
}

ostream& operator << (ostream &out, REPTIL_NATIVO &r){
	cout << endl;
	cout << "**REPTIL**" << endl << endl;
	out << "Id: " << r.getId() << endl;
	out << "Clase: " << r.getClasse() << endl;
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

ostream& operator << (ostream &out, REPTIL_EXOTICO &r){
	cout << endl;
	cout << "**REPTIL**" << endl << endl;
	out << "Id: " << r.getId() << endl;
	out << "Clase: " << r.getClasse() << endl;
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

REPTIL::~REPTIL(){}





// Ave
double AVE::getTamanho_bico(){
	return tamanho_bico;
}
double AVE::getEnvergadura(){
	return envergadura;
}

// int AVE::getId(){
// 	return id;
// }
AVE::AVE(double t, double e){
	tamanho_bico = t;
	envergadura = e;
}

ostream& operator << (ostream &out, AVE_NATIVO &a){
	cout << endl;
	cout << "**AVE**" << endl << endl;
	out << "Id: " << a.getId() << endl;
	out << "Clase: " << a.getClasse() << endl;
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

<<<<<<< HEAD
}

ostream& operator << (ostream &out, AVE_EXOTICO &a){
	cout << endl;
	cout << "**AVE**" << endl << endl;
	out << "Id: " << a.getId() << endl;
	out << "Clase: " << a.getClasse() << endl;
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

=======
}

ostream& operator << (ostream &out, AVE_EXOTICO &a){
	cout << endl;
	cout << "**AVE**" << endl << endl;
	out << "Id: " << a.getId() << endl;
	out << "Clase: " << a.getClasse() << endl;
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

>>>>>>> Hilton

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

