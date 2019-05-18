#ifndef _PETFERA_H_
#define _PETFERA_H_

#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <sstream> // Converter cadeias de caracters em int
#include <fstream> // Arquivo

using namespace std;

class ANIMAL{
	protected:
		int id;
		string classe;
		string nome_cientifico;
		char sexo;
		double tamanho;
		string dieta;
		string veterinario;
		string tratador;
		string nome_batismo;
	public:
		virtual int getId() = 0;
		string getClasse();
		string getNome_cientifico();
		char getSexo();
		double getTamanho();
		string getDieta();
		string getVeterinario();
		string getTratador();
		string getNome_batismo();
		//  Construtor
		ANIMAL(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome);
		//  Destrutor
		~ANIMAL();
};

class ANIMAL_SILVESTRE{
	protected:
		string autorizacao_IBAMA;
	public:
		// Getter
		virtual string getAutorizacao_IBAMA() = 0;
		//  Construtor
		ANIMAL_SILVESTRE(string aut);
		~ANIMAL_SILVESTRE();
};

class ANIMAL_NATIVO: public ANIMAL, ANIMAL_SILVESTRE{
	protected:
		string uf_origem;
		string autorizacao;
	public:
		//  Getters
		string getUf_origem();
		string getAutorizacao();
		string getAutorizacao_IBAMA();
		virtual int getId() = 0;
		//  Construtor
		ANIMAL_NATIVO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string aut, string u, string a);
		//  Destrutor
		~ANIMAL_NATIVO();
};
class ANIMAL_EXOTICO: public ANIMAL, ANIMAL_SILVESTRE{
	protected:
		string pais_origem;
		string autorizacao;
	public:
		//  Getters
		string getPais_origem();
		string getAutorizacao();
		string getAutorizacao_IBAMA();
		// virtual int getId() = 0;
		//  Construtor
		ANIMAL_EXOTICO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string aut, string p, string a);
		~ANIMAL_EXOTICO();
};

class ANFIBIO{
	protected:
		int total_mudas;
		string ultima_muda;
	public:
		//gettters
		// int getId();
		int getTotal_mudas();
		string getUltima_muda();
		// Construtor
		ANFIBIO(int mudas, string data); 
		// Destrutor
		~ANFIBIO();

};
class ANFIBIO_NATIVO: public ANIMAL_NATIVO, ANFIBIO{
	public:
		// Construtor
		ANFIBIO_NATIVO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, int mudas, string data, string aut, string u, string a);
		ANFIBIO_NATIVO();
		// Destrutor
		~ANFIBIO_NATIVO();
		friend ostream& operator << (ostream &out, ANFIBIO_NATIVO &m);
		friend ofstream& operator << (ofstream &out, ANFIBIO_NATIVO &m);
		int getId();
};
class ANFIBIO_EXOTICO: public ANIMAL_EXOTICO, ANFIBIO{
	public:
		// Construtor
		ANFIBIO_EXOTICO();

		ANFIBIO_EXOTICO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, int mudas, string data, string aut, string pais, string a);

		// Destrutor
		~ANFIBIO_EXOTICO();
		friend ostream& operator << (ostream &out, ANFIBIO_EXOTICO &m);
		friend ofstream& operator << (ofstream &out, ANFIBIO_EXOTICO &m);
		int getId();

};


class MAMIFERO{
	protected:
		string cor_pelo;
	public:
		//  Getters
		//int getId();
		string getCor_pelo();
		//  Construtor
		MAMIFERO(string cor);
		//  Destrutor
		~MAMIFERO();

		//friend ostream& operator << (ostream &out, MAMIFERO &m);
};
class MAMIFERO_NATIVO: public ANIMAL_NATIVO, MAMIFERO{
	public:
		//  Construtor
		MAMIFERO_NATIVO();
		MAMIFERO_NATIVO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string cor, string aut, string u, string a);
		//  Destrutor
		~MAMIFERO_NATIVO();
		int getId();

		friend ostream& operator << (ostream &out, MAMIFERO_NATIVO &m);
		friend ofstream& operator << (ofstream &out, MAMIFERO_NATIVO &m);
};
class MAMIFERO_EXOTICO: public ANIMAL_EXOTICO, MAMIFERO{
	public:
		// Construtor
		MAMIFERO_EXOTICO();
		MAMIFERO_EXOTICO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string cor, string aut, string pais, string a);
		// Destrutor
		~MAMIFERO_EXOTICO();
		int getId();

		friend ostream& operator << (ostream &out, MAMIFERO_EXOTICO &m);
		friend ofstream& operator << (ofstream &out, MAMIFERO_EXOTICO &m);
};


class REPTIL{
	protected:
		bool venenoso;
		string tipo_veneno;
	public:
		// Getters
		//int getId();
		bool getVenenoso();
		string getTipo_veneno();
		// Construtor
		REPTIL(bool v, string t);
		// Destrutor
		~REPTIL();

		friend ostream& operator << (ostream &out, REPTIL &r);
};
class REPTIL_NATIVO: public ANIMAL_NATIVO, REPTIL{
	public:
		// Construtor
		REPTIL_NATIVO();
		REPTIL_NATIVO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, bool v, string t, string aut, string u, string a);
		// Destrutor
		~REPTIL_NATIVO();
		int getId();

		friend ostream& operator << (ostream &out, REPTIL_NATIVO &r);
		friend ofstream& operator << (ofstream &out, REPTIL_NATIVO &r);
};
class REPTIL_EXOTICO: public ANIMAL_EXOTICO, REPTIL{
	public:
		// Construtor
		REPTIL_EXOTICO();
		REPTIL_EXOTICO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, bool v, string t, string aut, string pais, string a);
		// Destrutor
		~REPTIL_EXOTICO();
		int getId();

		friend ostream& operator << (ostream &out, REPTIL_EXOTICO &r);
		friend ofstream& operator << (ofstream &out, REPTIL_EXOTICO &r);
};


class AVE{
	private:
		double tamanho_bico;
		double envergadura;
	public:
		// Getters
		//int getId();
		double getTamanho_bico();
		double getEnvergadura();
		// Construtor
		AVE(double t, double e);
		// Destrutor
		~AVE();

};

class AVE_NATIVO: public ANIMAL_NATIVO, AVE{
	public:
		// Construtor
		AVE_NATIVO();
		AVE_NATIVO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, double t, double e, string aut, string u, string a);
		// Destrutor
		~AVE_NATIVO();
		int getId();
		friend ostream& operator << (ostream &out, AVE_NATIVO &a);
		friend ofstream& operator << (ofstream &out, AVE_NATIVO &v);
};
class AVE_EXOTICO: public ANIMAL_EXOTICO, AVE{
	public:
		// Construtor
		AVE_EXOTICO();
		AVE_EXOTICO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, double t, double e, string aut, string pais, string a);
		// Destrutor
		~AVE_EXOTICO();
		int getId();

		friend ostream& operator << (ostream &out, AVE_EXOTICO &a);
		friend ofstream& operator << (ofstream &out, AVE_EXOTICO &v);
};



class FUNCIONARIO{
	protected:
		int id;
		string nome;
		long int cpf;
		int idade;
		string tipo_sanguineo;
		char fator_rh;
		string especialidade;
	public:
		// Setters
		void setId(int i);
		void setNome(string n);
		void setCpf(long int c);
		void setIdade(int i);
		void setTipo_sanguineo(string t);
		void setFator_rh(char f);
		void setEspecialidade(string e);
		// Getters
		virtual int getId() = 0;
		string getNome();
		long int getCpf();
		int getIdade();
		string getTipo_sanguineo();
		char getFator_rh();
		string getEspecialidade();

};

class VETERINARIO: public FUNCIONARIO{
	private:
		string crmv;
	public:
		// Construtor
		VETERINARIO(int i, string n, long int c, int ida, string t, char f, string e, string cr);
		VETERINARIO();
		// Setters
		void setCrmv(string c);
		// Getters
		string getCrmv();
		int getId();

		friend ostream& operator << (ostream &out, VETERINARIO &v);
		friend ofstream& operator << (ofstream &out, VETERINARIO &v);

};
class TRATADOR: public FUNCIONARIO{
	private:
		int nivel_seguranca;
	public:
		// Construtor
		TRATADOR(int i, string n, long int c, int ida, string t, char f, string e, int nivel);
		TRATADOR();
		// Setters
		void setNivel_seguranca(int nivel);
		// Getters
		int getNivel_seguranca();
		int getId();

		friend ostream& operator << (ostream &out, TRATADOR &t);
		friend ofstream& operator << (ofstream &out, TRATADOR &t);

};

// Carregamento de todos os arquivos necessários para o funcionamento do programa
void carregar_arquivos(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex, map <int, VETERINARIO> &vets, map <int, TRATADOR> &tratadores);

// Cadastramento 
void cadastrar_func(map <int, VETERINARIO> &vets, map <int, TRATADOR>  &tratadores);
void cadastrar(map <int, VETERINARIO> &vets); //_vet(
void cadastrar(map <int, TRATADOR>  &tratadores); //_trat
void cadastrar_animal(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex); 
void cadastrar(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex);
void cadastrar(map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex);
void cadastrar(map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex);
void cadastrar(map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex);

// Edição
void alterar_dados(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex);
void editar_func(map <int, VETERINARIO> &vets, map <int, TRATADOR> &tratadores);
void editar(map <int, VETERINARIO> &vets);
void editar(map <int, TRATADOR> &tratadores);
void editar_animal(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex);
void editar(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex){


// Remoção
void remover_animal(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex);
void remover_funcionario(map <int, VETERINARIO> &vets, map <int, TRATADOR>  &tratadores);

// Pesquisa e impressão 
void pesquisar_classe(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex);
void imprimir_classe(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex);
void imprimir_classe(map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex);
void imprimir_classe(map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex);
void imprimir_classe(map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex );

#endif