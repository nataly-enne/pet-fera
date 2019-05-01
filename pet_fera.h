#ifndef _PETFERA_H_
#define _PETFERA_H_

#include <iostream>
#include <string>

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
		//setters
		void setId(int i);
		void setClasse(string c);
		void setNome_cientifico(string n);
		void setSexo(char s);
		void setTamanho(double t);
		void setDieta(string d);
		void setVeterinario(string v);
		void setTratador(string t);
		void setNome_batismo(string nome);
		//getters
		int getId();
		string getClasse();
		string getNome_cientifico();
		char getSexo();
		double getTamanho();
		string getDieta();
		string getVeterinario();
		string getTratador();
		string getNome_batismo();

};
class ANFIBIO: public ANIMAL{
	private:
		int total_mudas;
		int ultima_muda[3];
	public:
		//setters
		//void setTotal_mudas(int m);
		void setUltima_muda(int *vetor);
		//gettters
		int getTotal_mudas();
		int* getUltima_muda();
		//construtor
		ANFIBIO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, int mudas, int* data);
		//destrutor
		~ANFIBIO();
};

class MAMIFERO: public ANIMAL{
	private:
		string cor_pelo;
	public:
		//setters
		void setCor_pelo(string c);
		//getters
		string getCor_pelo();
		//construtor
		MAMIFERO(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, string cor);
		//destrutor
		~MAMIFERO();
}

class REPTIL: public ANIMAL{
	private:
		bool venenoso;
		string tipo_veneno;
	public:
		//setters
		void setVenenoso(bool v);
		void setTipo_veneno(string t);
		//getters
		bool getVenenoso();
		string getTipo_veneno();
		//construtor
		REPTIL(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, bool v, string t);
		//destrutor
		~REPTIL();
}

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
		//construtor
		AVE(int i, string c, string n, char s, double tam, string die, string vet, string trat, string nome, double t, double e);
		//destrutor
		~AVE();

}

class FUNCIONARIO{
	protected:
		int id;
		string nome;
		long int cpf;
		int idade;
		char tipo_sanguineo;
		char fator_rh;
		string especialidade;
	public:
		//setters
		void setId(int i);
		void setNome(string n);
		void setCpf(long int c);
		void setIdade(int i);
		void setTipo_sanguineo(char t);
		void setFator_rh(char f);
		void setEspecialidade(string e);
		//getters
		int getId();
		string getNome();
		long int getCpf();
		int getIdade();
		char getTipo_sanguineo();
		char getFator_rh();
		string getEspecialidade();

};

class VETERINARIO: public FUNCIONARIO{
	protected:
		string crmv;
	public:
		//Construtor
		VETERINARIO(int i, string n, long int c, int ida, char t, char f, string e, string cr);
		//setters
		void setCrmv(string c);
		//getters
		string getCrmv();

		friend ostream& operator << (ostream &out, VETERINARIO &v);

};
class TRATADOR: public FUNCIONARIO{
	protected:
		int nivel_seguranca;
	public:
		//Construtor
		TRATADOR(int i, string n, long int c, int ida, char t, char f, string e, int nivel);
		~TRATADOR();
		//setters
		void setNivel_seguranca(int nivel);
		//getters
		int getNivel_seguranca();

		friend ostream& operator << (ostream &out, TRATADOR &t);

};


#endif