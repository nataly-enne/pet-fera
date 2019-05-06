#ifndef _PETFERA_H_
#define _PETFERA_H_

#include <iostream>
#include <string>
#include <vector>

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
		//construtor
		ANIMAL(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome);
		//destrutor
		~ANIMAL();
};

class ANIMAL_SILVESTRE{
	protected:
		string autorizacao_IBAMA;
	public:
		//Getter
		string getAutorizacao_IBAMA();
		//construtor
		ANIMAL_SILVESTRE(string aut);
		~ANIMAL_SILVESTRE();
};

class ANIMAL_NATIVO: public ANIMAL, ANIMAL_SILVESTRE{
	protected:
		string uf_origem;
		string autorizacao;
	public:
		//getters
		string getUf_origem();
		string getAutorizacao();
		int getId();
		//construtor
		ANIMAL_NATIVO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string aut, string u, string a);
		//destrutor
		~ANIMAL_NATIVO();
};
class ANIMAL_EXOTICO: public ANIMAL, ANIMAL_SILVESTRE{
	protected:
		string pais_origem;
		string autorizacao;
	public:
		//getters
		string getPais_origem();
		string getAutorizacao();
		int getId();
		//construtor
		ANIMAL_EXOTICO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string aut, string p, string a);
		~ANIMAL_EXOTICO();
};

class ANFIBIO: public ANIMAL{
	protected:
		int total_mudas;
		int ultima_muda[3];
	public:
		//setters
		//void setTotal_mudas(int m);
		//void setUltima_muda(int *vetor);
		//gettters
		int getTotal_mudas();
		int* getUltima_muda();
		int getId();
		//construtor
		ANFIBIO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, int mudas, int data[3]);
		//destrutor
		~ANFIBIO();
};

class MAMIFERO: public ANIMAL{
	protected:
		string cor_pelo;
	public:
		//setters
		void setCor_pelo(string c);
		//getters
		string getCor_pelo();
		int getId();
		//construtor
		MAMIFERO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string cor);
		//destrutor
		~MAMIFERO();
};

class REPTIL: public ANIMAL{
	protected:
		bool venenoso;
		string tipo_veneno;
	public:
		//setters
		void setVenenoso(bool v);
		void setTipo_veneno(string t);
		//getters
		bool getVenenoso();
		string getTipo_veneno();
		int getId();
		//construtor
		REPTIL(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, bool v, string t);
		//destrutor
		~REPTIL();
};

class AVE: public ANIMAL{
	private:
		double tamanho_bico;
		double envergadura;
	public:
		//setters
		void setTamanho_bico(double t);
		void setEnvergadura(double e);
		//getters
		double getTamanho_bico();
		double getEnvergadura();
		int getId();
		//construtor
		AVE(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, double t, double e);
		//destrutor
		~AVE();

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
		//setters
		void setId(int i);
		void setNome(string n);
		void setCpf(long int c);
		void setIdade(int i);
		void setTipo_sanguineo(string t);
		void setFator_rh(char f);
		void setEspecialidade(string e);
		//getters
		virtual int getId() = 0;
		string getNome();
		long int getCpf();
		int getIdade();
		string getTipo_sanguineo();
		char getFator_rh();
		string getEspecialidade();

};

class VETERINARIO: public FUNCIONARIO{
	protected:
		string crmv;
	public:
		//Construtor
		VETERINARIO(int i, string n, long int c, int ida, string t, char f, string e, string cr);
		//setters
		void setCrmv(string c);
		//getters
		string getCrmv();
		int getId();

		friend ostream& operator << (ostream &out, VETERINARIO &v);

};
class TRATADOR: public FUNCIONARIO{
	protected:
		int nivel_seguranca;
	public:
		//Construtor
		TRATADOR(int i, string n, long int c, int ida, string t, char f, string e, int nivel);
		~TRATADOR();
		//setters
		void setNivel_seguranca(int nivel);
		//getters
		int getNivel_seguranca();
		int getId();

		friend ostream& operator << (ostream &out, TRATADOR &t);

};

//funções

void cadastrar_func(vector <VETERINARIO> &vets, vector <TRATADOR> &tratadores);
void cadastrar_vet(vector <VETERINARIO> &vets);
void cadastrar_trat(vector <TRATADOR> &tratadores);
void cadastrar_animal(vector <ANFIBIO> &anfibios, vector <MAMIFERO> &mamiferos, vector <REPTIL> &repteis, vector <AVE> &aves);
void cadastrar_anfibio(vector <ANFIBIO> &anfibios);
void cadastrar_mamifero(vector <MAMIFERO> &mamiferos);
void cadastrar_reptil(vector <REPTIL> &repteis);
void cadastrar_ave(vector <AVE> &aves);

#endif